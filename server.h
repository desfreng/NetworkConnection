#ifndef SERVER_H
#define SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "socket.h"

class ServerSocket
{
    public:
        ServerSocket ();
        
        void Listen (unsigned short port);
        Socket& Accept();
        void Close();
        
        bool isValid() const;
        explicit operator bool() const;
        
        unsigned short Port() const;
    private :
        unsigned short _port;
        Socket _buffer;
        long _status;
        int _sock;
};

#endif // SERVER_H