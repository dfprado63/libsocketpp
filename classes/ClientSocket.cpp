#include "ClientSocket.hpp"
#include <arpa/inet.h>

ClientSocket::ClientSocket(unsigned short port, char *ip) : Socket(), ready(false), connected(false) { assignSocket(port, ip); }
ClientSocket::ClientSocket(unsigned short port, const char *ip) : Socket(), ready(false), connected(false) { assignSocket(port, (char*)ip); }

void ClientSocket::assignSocket(unsigned short port, char *ip)
{
  // só prossegue se o socket for criado com sucesso
  if (isOk()) {
    // configura a estrutura de endereço
    addr_in.sin_family=AF_INET;
    addr_in.sin_port=htons(port);
    if (inet_aton(ip, &(addr_in.sin_addr)) != -1) {
      ready=true;
    }
  }
}

void ClientSocket::connect()
{
  if (::connect(fd, (const struct sockaddr*) &addr_in, sizeof(addr_in)) != -1) {
    temp_socket=fd;
    connected=true;
  }
}

bool ClientSocket::isReady()
{
  return ready;
}

bool ClientSocket::isConnected()
{
  return connected;
}
