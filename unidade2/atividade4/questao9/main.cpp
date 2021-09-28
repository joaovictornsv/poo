#include <iostream>

using std::cout;
using std::endl;

#include "Funcionario.h"

int main() {
  Funcionario funcionario(
    "João Victor",
    "123.456.789-10",
    "2021001",
    1500,
    160,
    150
  );

  cout << "> Funcionario" << endl;
  cout <<  "Dados: " << endl;
  cout << funcionario;
  cout << "==============" << endl;


  cout << "> Salario bruto" << endl;
  cout << "R$" << funcionario.calculaSalarioBruto() << endl;
  cout << "==============" << endl;

  return 0;
}