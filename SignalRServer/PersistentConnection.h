/*
 * Copyright (c) 2014, p3root - Patrik Pfaffenbauer (patrik.pfaffenbauer@p3.co.at) and
 * Norbert Kleininger
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef PERSISTENTCONNECTION_H
#define PERSISTENTCONNECTION_H

#include <string>
#include <list>


#include "Request.h"

/*
            ConnectionTimeout = TimeSpan.FromSeconds(110);
            DisconnectTimeout = TimeSpan.FromSeconds(30);
            DefaultMessageBufferSize = 1000;
            MaxIncomingWebSocketMessageSize = 64 * 1024; // 64 KB
            TransportConnectTimeout = TimeSpan.FromSeconds(5);
            LongPollDelay = TimeSpan.Zero;

 */

// Note: this parameters must be configurable over properties

#define DEFAULT_TRANSPORT_CONNECTIONTIMEOUT 5    // seconds
#define DEFAULT_KEEPALIVE_TIMEOUT           30   // seconds
#define DEFAULT_DISCONNECT_TIMEOUT          30   // seconds
#define DEFAULT_LONGPOLLDELAY               0    // seconds
#define DEFAULT_TRYWEBSOCKETS               false


#define SIGNALR_VER_MIN 12
#define SIGNALR_VER_MAX 14

#include "Variant.h"



using namespace std;
namespace P3 { namespace SignalR { namespace Server {

class ClientMessage;
class Group;

class SignalRServer;

class Connection
{
public:
    Connection(const char* connId);

public:
    string m_connectionId;

};

class PersistentConnection
{
public:
    int _connfd;
    SignalRServer* _server;

    int _keepAliveTimeout;
    int _disconnectTimeout;
    int _transportConnectTimeout;
    int _longPollDelay;
    bool _tryWebSockets;

    Connection* _innerConnection;
    string _connectionId;
    string _groupsToken;

public:
    PersistentConnection();
    virtual ~PersistentConnection();

public:
    void processRequest(Request* request);
    bool writeData(const char* buffer="", int retcode=200);

private:
    bool isStartRequest(Request* request);
    bool isNegotiationRequest(Request* request);
    bool isPingRequest(Request* request);
    void processNegotiationRequest(Request* request);
    void processPingRequest(Request* request);
    void processConnectRequest(Request* request);
    void processStartRequest(Request* request);
    string getUserIdentity(Request* request);
    int resolveClientProtocol(const char* ver);
    string assemblyVersion(int ver);
    void failResponse(const char* errormsg, int retcode=400);
    void processMessages(Request* request);
    Connection* newConnection(const char* connectionId);
    std::string protectGroupsToken(const char* token);
    std::string unprotectGroupsToken(const char* token);
    std::string encodeGroupsToken(std::list<std::string>* groups);
    std::list<string> splitGroupsToken(const char* token);
    std::list<string> findRemovedGroups(std::list<std::string>* oldGroups, std::list<std::string>* newGroups);
    std::list<string> findAddedGroups(std::list<std::string>* oldGroups, std::list<std::string>* newGroups);

public:
    void writeResponse(Request* request, bool bInitializing=false, bool bReconnect=false, std::list<std::string> *groups=NULL, int longPollDelay=0, list<ClientMessage*>* messages = NULL);
    void handleConnected(Request* request, const char* connectionId);
    void handleReconnected(Request* request, const char* connectionId);
    string handleReceived(Request* request, const char* connectionId, const char* data);
    void handleDisconnected(Request* request, const char* connectionId);

protected:
    virtual bool authorizeRequest(Request* requ);
    virtual void onConnected(Request *request, const char* connectionId);
    virtual void onReconnected(Request *request, const char* connectionId);
    virtual string onReceived(Request *request, const char* connectionId, const char* data);
    virtual void onDisconnected(Request *request, const char* connectionId);

};

}}}
#endif // PERSISTENTCONNECTION_H

