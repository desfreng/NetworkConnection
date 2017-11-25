#include "socket.h"

Socket::Socket()
{
    _sock = socket (AF_INET, SOCK_STREAM, 0);
}

void Socket::Connect (const char IpAdress[], unsigned short Port)
{
    _ipAdress = IpAdress;
    _port = Port;
    
    sockaddr_in sin;
    sin.sin_addr.s_addr = inet_addr (IpAdress);
    sin.sin_family = AF_INET;
    sin.sin_port = htons (Port);
    
    _status =  connect (_sock, (sockaddr *)&sin, sizeof (sin));
}

void Socket::Close()
{
    _status =  close (_sock);
}

void Socket::Send (const char& data)
{
    _status =  send (_sock, &data, sizeof (char), 0);
}
void Socket::Send (const char data[], size_t size)
{
    for (size_t i = 0; i < size; i++) {
        Send (data[i]);
    }
}
void Socket::Send (const long& data)
{
    _status =  send (_sock, &data, sizeof (long), 0);
}
void Socket::Send (const short& data)
{
    _status =  send (_sock, &data, sizeof (short), 0);
}
void Socket::Send (const unsigned long& data)
{
    _status =  send (_sock, &data, sizeof (unsigned long), 0);
}
void Socket::Send (const unsigned short& data)
{
    _status =  send (_sock, &data, sizeof (unsigned short), 0);
}
void Socket::Send (const bool& data)
{
    _status =  send (_sock, &data, sizeof (bool), 0);
}

void Socket::Receive (char& data)
{
    _status = recv (_sock, &data, sizeof (data), 0);
}
void Socket::Receive (char data[], size_t size)
{
    char temp;
    
    for (size_t i = 0; i < size; i++) {
        Receive (temp);
        data[i] = temp;
    }
}
void Socket::Receive (long& data)
{
    _status = recv (_sock, &data, sizeof (data), 0);
}
void Socket::Receive (short& data)
{
    _status = recv (_sock, &data, sizeof (data), 0);
}
void Socket::Receive (unsigned long& data)
{
    _status = recv (_sock, &data, sizeof (data), 0);
}
void Socket::Receive (unsigned short& data)
{
    _status = recv (_sock, &data, sizeof (data), 0);
}
void Socket::Receive (bool& data)
{
    _status = recv (_sock, &data, sizeof (data), 0);
}

bool Socket::isValid() const
{
    return _status != -1;
}
Socket::operator bool() const
{
    return isValid();
}

std::string Socket::IpAdress() const
{
    return  _ipAdress;
}
unsigned short Socket::Port() const
{
    return _port;
}
