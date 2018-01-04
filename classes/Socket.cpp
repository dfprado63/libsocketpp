#include "Socket.hpp"
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

Socket::Socket() : fd_created(false), temp_socket(0)
{
  // cria o socket
  fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd != -1)
    fd_created=true;
}

Socket::~Socket()
{
  if (fd) {
    ::close(fd);
  }
}

bool Socket::isOk()
{
  return fd_created;
}

void Socket::operator<<(std::string &to_send)
{
  send(temp_socket, to_send.c_str(), to_send.length(), 0);
}

void Socket::operator>>(std::string &to_receive)
{
  char buffer[1024];
  int b_readed=0, bytes;
  to_receive="";

  // enquanto receber os dados
  bytes=recv(temp_socket, buffer, sizeof(buffer), 0);
  while (bytes > 0) {
    to_receive+=buffer; // adiciona os recebidos à string
    b_readed+=bytes; // soma quantos bytes já foram processados
    if (bytes < sizeof(buffer))
      break;
    bytes=recv(temp_socket, buffer, sizeof(buffer), 0);
  }

  // se a leitura deu certo, retorna os dados recebidos. Caso contrário, retorna um erro
  if (bytes)
    to_receive=to_receive.substr(0, b_readed);
  else if (bytes == -1)
    to_receive="ERR";
  else
    to_receive="FIN";
}

void Socket::close()
{
  if (temp_socket) {
    ::close(temp_socket);
  }
  temp_socket=0;
}
