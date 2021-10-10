#include <iostream>

#include "../entities/Pessoa/Pessoa.h"
#include "../entities/Pessoa/PessoaFisica.h"
#include "../entities/Pessoa/PessoaJuridica.h"

#include "../entities/Banco/Banco.h"

#include "../entities/Conta/Conta.h"
#include "../entities/Conta/ContaCorrente.h"
#include "../entities/Conta/ContaCorrenteLimite.h"
#include "../entities/Conta/ContaPoupanca.h"

#include "../entities/Transacao/Transacao.h"

#include "../exceptions/ExcedeLimite.h"
#include "../exceptions/SaldoInsuficiente.h"
#include "../exceptions/ExceptionCatch.h"
#include "../exceptions/PrecisaSerString.h"
#include "../exceptions/PrecisaSerNumero.h"
#include "../exceptions/OpcaoInvalida.h"

#include "../validation/isNumber.h"
#include "../validation/isString.h"

#include "./menus.h"

void visaoCliente(Banco* banco, Conta *conta) {
  while (true) {
    menuVisaoCliente();
    std::string escolhaVisaoCliente;
    std::cin >> escolhaVisaoCliente;
    try {
      if (!isNumber(escolhaVisaoCliente)) throw PrecisaSerNumero();
      
      // DEPOSITO
      if (escolhaVisaoCliente == "0") {
      } else

      // SAQUE
      if (escolhaVisaoCliente == "1") {

      } else

      // TRANSFERENCIA
      if (escolhaVisaoCliente == "2") {

      } else

      // EXTRATO
      if (escolhaVisaoCliente == "3") {

      } else              
      
      // SALDO
      if (escolhaVisaoCliente == "4") {
       
      } else

      // VOLTAR AO MENU
      if (escolhaVisaoCliente == "5") {
      } else{ throw OpcaoInvalida(); }
    } catch(std::runtime_error &e) {
      ExceptionCatch(e);
    }
  }

}