#include <iostream>

#include "./entities/Pessoa/Pessoa.h"
#include "./entities/Pessoa/PessoaFisica.h"
#include "./entities/Pessoa/PessoaJuridica.h"

#include "./entities/Conta/Conta.h"
#include "./entities/Conta/ContaCorrente.h"
#include "./entities/Conta/ContaCorrenteLimite.h"
#include "./entities/Conta/ContaPoupanca.h"

#include "./entities/Transacao/Transacao.h"

#include "./exceptions/ExcedeLimite.h"
#include "./exceptions/SaldoInsuficiente.h"

int main() {
  PessoaFisica pf("Joao Victor", "706.083.0440-84");
  PessoaJuridica pj("Joao Victor", "40.332.583/0001-72");

  ContaCorrente cc(&pf, "123", 0);
  ContaCorrenteLimite ccl(&pj, "432", 0, 100);

  cc << 100;
  ccl << 100;

  cc.transferir(10, &ccl);
  ccl.transferir(90, &cc);
  
  ccl.transferir(90, &cc);
  cc.transferir(900, &ccl);

  cc.extrato();
  ccl.extrato();

  return 0;
}