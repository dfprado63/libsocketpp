#include <iostream>
#include <string>
#include "ClientSocket.hpp"

using namespace std;

int main(void)
{
  std::string temporario ("Olá, eu sou o cliente");
  cout << "Iniciando testes com ClientSocket" << endl;
  cout << "Instanciando ClientSocket e preparando conexão" << endl;
  ClientSocket csocket(8081, "127.0.0.1");
  if (csocket.isReady()) {
    cout << "Socket instanciado com sucesso. Conectando com servidor" << endl;
    csocket.connect();
    if (csocket.isConnected()) {
      cout << "Conectado com sucesso. Enviando dados e recebendo dados" << endl << endl;
      csocket << temporario;
      csocket >> temporario;
      cout << "RESPOSTA DO SERVIDOR: " << temporario << endl;
    } else
      cout << "Falha na conexão. Certifique de que o servidor está ouvindo na porta 8081." << endl;
  }
  else
    cout << "Não foi possível instanciar o socket." << endl;
  
  cout << "Finalizando aplicação. " << endl;
  return 0;
}
