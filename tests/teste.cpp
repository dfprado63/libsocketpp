#include <iostream>
#include <string>
#include "ServerSocket.hpp"

using namespace std;

int main(void)
{
  std::string temporario ("Olá, eu sou o servidor");
  cout << "Iniciando teste com classe ServerSocket.hpp" << endl;
  cout << "Instanciando classe e iniciando comunicação" << endl;
  ServerSocket ssocket(8081, "127.0.0.1");
  if (ssocket.isConnected()) {
    cout << "Abertura de conexão ok. Iniciando escuta" << endl;
    if (ssocket.accept()) {
      cout << "Aceitamos uma conexão. Enviando dados e recebendo dados:" << endl << endl;
      ssocket >> temporario;
      cout << "RESPOSTA DO CLIENTE: " << temporario << endl;
      temporario="Olá, eu sou o servidor.";
      ssocket << temporario;
    } else
      cout << "Não foi possível aceitar a conexão" << endl;
  } else
    cout << "Não foi possível abrir uma conexão." << endl;

  cout << "Finalizando programa..." << endl;
  return 0;
}
