#include "ServerSocket.hpp"
#include <arpa/inet.h>

ServerSocket::ServerSocket(unsigned short port, char *ip) : Socket(), connected(false) {assignSocket(port, ip); }
ServerSocket::ServerSocket(unsigned short port, const char *ip) : Socket(), connected(false) { assignSocket(port, (char*) ip); }

void ServerSocket::assignSocket(unsigned short port, char *ip)
{
  // Só prossegue se o socket foi criado com sucesso
  if (isOk()) {
    // configura a estrutura sockaddr_in
    addr_in.sin_family=AF_INET;
    addr_in.sin_port=htons(port);
    if (inet_aton(ip, &(addr_in.sin_addr)) != -1) {
      
      if (bind(fd, (struct sockaddr*) &addr_in, sizeof(addr_in)) != -1) {
	addr_in_len = sizeof(addr_in);
      
	// Inicia escuta para conexões
	if (listen(fd, 1) != -1)
	  connected=true;
      }
    }
  }
}

bool ServerSocket::isConnected()
{
  return connected;
}

bool ServerSocket::accept()
{
  temp_socket = ::accept(fd, (struct sockaddr *) &addr_in, (socklen_t *) &addr_in_len);
  if (temp_socket != -1)
    return true;
  else
    return false;
}
