#ifndef SOCKET_H
#define SOCKET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>

class ServerSocket;

class Socket
{
    public:
        Socket();
        
        void Connect (const char IpAdress[], unsigned short Port);
        void Close();
        
        void Send (const char& data);
        void Send (const long& data);
        void Send (const short& data);
        void Send (const unsigned long& data);
        void Send (const unsigned short& data);
        void Send (const char data[], size_t size);
        void Send (const bool& data);
        
        void Receive (long& data);
        void Receive (short& data);
        void Receive (unsigned long& data);
        void Receive (unsigned short& data);
        void Receive (char data[], size_t size);
        void Receive (bool& data);
        void Receive (char& data);
        
        bool isValid() const;
        explicit operator bool() const;
        
        unsigned short Port() const;
        std::string IpAdress() const;
        
    private :
        friend ServerSocket;
        
        std::string _ipAdress;
        unsigned short _port;
        
        long _status;
        int _sock;
};

#endif // SOCKET_H