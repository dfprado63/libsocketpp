#include <iostream>
#include <string>
#include "ServerSocket.hpp"

int main(void)
{
  std::string message;
  bool shutdown (false);
  ServerSocket ssocket(8081, "127.0.0.1");
  if (ssocket.isConnected()) {

    // Mantém o chat aberto até que o programa seja encerrado
    while ( true ) {
      if (ssocket.accept()) {
	std::cout << "send \"SHUTDOWN\" to close server." << std::endl;
	while ( true ) {
	  // escuta do cliente
	  ssocket >> message;
	  if (message == "FIN") {
	    std::cout << "O cliente encerrou a conexão." << std::endl;
	    ssocket.close();
	    break;
	  }

	  // recebimento de mensagem e envio de resposta
	  std::cout << "MENSAGEM DO CLIENTE: " << message << std::endl << "Envie uma resposta: ";
	  std::getline(std::cin, message);
	  ssocket << message;

	  // preparando para encerrar o servidor
	  if (message == "SHUTDOWN")
	    shutdown=true;
	}
      } else {
	std::cout << "Houve uma tentativa de conexão sem sucesso. " << std::endl;
      }

      if (shutdown)
	break;
    }
    
  } else
    std::cout << "Não foi possível abrir um socket de comunicação." << std::endl;
}
