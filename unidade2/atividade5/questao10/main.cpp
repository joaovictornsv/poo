#include <iostream>

#include "Conta.h"
#include "ContaCorrente.h"
#include "ContaCorrenteLimite.h"
#include "ContaPoupanca.h"

int main() {
  ContaCorrente *cCorrente = new ContaCorrente("João Victor Negreiros", "8185813", 1000);
  ContaCorrenteLimite *cCorrenteLimite = new ContaCorrenteLimite("João Victor Negreiros", "1747687", 0, 2000);
  ContaPoupanca *cPoupanca = new ContaPoupanca("João Victor Negreiros", "3146870", 100, "01/09/2021");

  Conta *contasPessoais[] = {cCorrente, cCorrenteLimite, cPoupanca};
  std::cout << "## Conta corrente comum ##" << std::endl;
  contasPessoais[0]->deposito(1000);
  contasPessoais[0]->retirada(200);
  std::cout << "Extrato:" << std::endl;
  contasPessoais[0]->extrato();

  std::cout << std::endl;

  std::cout << "## Conta corrente com limite ##" << std::endl;
  contasPessoais[1]->deposito(200);
  contasPessoais[1]->retirada(400);
  contasPessoais[1]->retirada(3000);
  std::cout << "Extrato:" << std::endl;
  contasPessoais[1]->extrato();

  std::cout << std::endl;

  std::cout << "## Conta poupanca ##" << std::endl;
  contasPessoais[2]->deposito(200);
  contasPessoais[2]->retirada(400);
  contasPessoais[2]->deposito(800);
  std::cout << "Extrato:" << std::endl;
  contasPessoais[2]->extrato();


  return 0;
}