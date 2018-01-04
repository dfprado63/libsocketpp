# libsocketpp
Biblioteca C++ de abstração da API de socket do C

Biblioteca que abstrai a API de socket do C para o C++.

Classes:
 + Socket: classe abstrata que cuida da gestão do descritor de arquivo de socket
 + ServerSocket: classe herdeira de Socket que trata de abrir uma comunicação do tipo servidor (ouvinte)
 + ClientSocket: classe herdeira de Socket que trata de realizar uma conexão com um servidor
