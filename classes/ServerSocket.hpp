#ifndef __CPP_SERVERSOCKET_CLASS
#define __CPP_SERVERSOCKET_CLASS

#include "Socket.hpp"
#include <netinet/ip.h>

class ServerSocket : public Socket
{
private:
  int server_socket, addr_in_len;
  struct sockaddr_in addr_in;
  bool connected;

  void assignSocket(unsigned short port, char *ip);
  
public:
  // public methods
  ServerSocket(unsigned short port, char *ip);
  ServerSocket(unsigned short port, const char *ip);
  bool isConnected();
  bool accept();
};

#endif
