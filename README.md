SignalR-cpp
==========

This is an C++ implementation of Microsofts ASP.Net SignalR-Server. (https://github.com/SignalR).

For questions please send me an email (patrik.pfaffenbauer@p3.co.at) or conatct me via skype (patrik.pfaffenbauer)

Please clone the repository recursive. Otherwise the submodules will not be cloned, and you can't build the libs.

git clone --recursive https://github.com/p3root/signalr-cpp

Then just run qmake and make. The Signalr-Server has no dependencies to any Qt Library. I just have developed it using QtCreator. I need to change the build process using automake.

Server
======
Please see the documentation in the src/SignalRServer/Doc/

Client
=======
I currently have implemented a SignalR Client using the Qt Framework. Maybe I'm going to implement an C++ client using the stl.

LICENSE
======

Copyright (c) 2014, p3root - Patrik Pfaffenbauer (patrik.pfaffenbauer@p3.co.at) and
Norbert Kleininger
All rights reserved.
 
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

  Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

  Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.

  Neither the name of the {organization} nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

