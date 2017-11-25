#include "server.h"
#include "socket.h"

ServerSocket::ServerSocket ()
{
    _sock = socket (AF_INET, SOCK_STREAM, 0);
}

void ServerSocket::Listen (unsigned short port)
{
    _port = port;
    sockaddr_in sin;
    sin.sin_addr.s_addr = htonl (INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons (port);
    _status = bind (_sock, (sockaddr *)&sin, sizeof (sin));
    _status = listen (_sock, 1);
    
}
Socket& ServerSocket::Accept ()
{
    sockaddr_in csin;
    socklen_t recsize = sizeof (csin);
    
    _buffer._sock = accept (_sock, (sockaddr *)&csin, &recsize);
    _buffer._status = 0;
    _buffer._ipAdress = inet_ntoa (csin.sin_addr);
    _buffer._port = ntohs (csin.sin_port);
    
    return _buffer;
}
void ServerSocket::Close()
{
    _buffer.Close();
    _status = close (_sock);
}

bool ServerSocket::isValid() const
{
    return _status != -1;
}
ServerSocket::operator bool() const
{
    return isValid();
}

unsigned short ServerSocket::Port() const
{
    return _port;
}