#ifndef __CPP_SOCKET_CLASS
#define __CPP_SOCKET_CLASS

#include <string>

#include <netinet/ip.h>

class Socket
{
private:
  bool fd_created;

protected:
  int fd, temp_socket;
  bool isOk();
  
public:
  Socket();
  ~Socket();
  void operator>>(std::string&);
  void operator<<(std::string&);
  void close();
};

#endif
