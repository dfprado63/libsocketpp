#include <iostream>
#include <string>
#include "ClientSocket.hpp"

int main(void)
{
  std::string message;
  ClientSocket csocket (8081, "127.0.0.1");
  if (csocket.isReady()) {
    csocket.connect();
    // conecta
    if (csocket.isConnected()) {
      std::cout << "Para finalizar a comunicação, digite EXIT;;. Você começa a conversa" << std::endl;
      // continua o chat até que o cliente digite EXIT;;"
      while ( true ) {

	// Envio  de mensagem por parte do cliente
	std::cout << "Envie a mensagem: ";
	std::getline(std::cin, message);
	if (!message.empty()) {

	  // comando para encerrar o cliente
	  if (message == "EXIT;;") {
	    break;
	  }
	  csocket << message;

	  // recebimento da mensagem do servidor
	  csocket >> message;
	  if (message == "SHUTDOWN") // servidor pediu para encerrar a comunicação
	    break;
	  std::cout << "MENSAGEM DO SERVIDOR: " << message << std::endl;
	} else std::cout << "Não se pode enviar mensagens vazias!!!" << std::endl;
      }
    } else {
      std::cout << "Não foi possível conectar ao servidor 127.0.0.1 na porta 8081" << std::endl;
      return 2;
    }
    return 0;
  } else {
    std::cout << "Não foi possível abrir um socket de conexão." << std::endl;
    return 1;
  }
}
