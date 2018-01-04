#ifndef __CPP_CLIENTSOCKET_HPP
#define __CPP_CLIENTSOCKET_HPP

#include "Socket.hpp"
#include <netinet/ip.h>

class ClientSocket : public Socket
{
private:
  struct sockaddr_in addr_in;
  bool ready, connected;

  void assignSocket(unsigned short port, char *ip);

public:
  ClientSocket(unsigned short port, char *ip);
  ClientSocket(unsigned short port, const char *ip);
  
  void connect();
  bool isReady();
  bool isConnected();
};

#endif
