#include <iostream>

using std::cout;
using std::endl;

#include "Cliente.h"

int main() {
  Cliente cliente(
    "João Victor",
    "123.456.789-10",
    "8399886633",
    "Rua José Rodrigues de Almeida, 32"
  );

  cout << "> Cliente" << endl;
  cout <<  "Dados: " << endl;
  cout << cliente;
  cout << "==============" << endl;

  return 0;
}