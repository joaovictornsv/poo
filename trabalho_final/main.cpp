#include <iostream>

#include "./entities/Pessoa/Pessoa.h"
#include "./entities/Pessoa/PessoaFisica.h"
#include "./entities/Pessoa/PessoaJuridica.h"

#include "./entities/Banco/Banco.h"

#include "./entities/Conta/Conta.h"
#include "./entities/Conta/ContaCorrente.h"
#include "./entities/Conta/ContaCorrenteLimite.h"
#include "./entities/Conta/ContaPoupanca.h"

#include "./entities/Transacao/Transacao.h"

#include "./exceptions/ExcedeLimite.h"
#include "./exceptions/SaldoInsuficiente.h"
#include "./exceptions/ExceptionCatch.h"
#include "./exceptions/PrecisaSerString.h"
#include "./exceptions/PrecisaSerNumero.h"
#include "./exceptions/OpcaoInvalida.h"

#include "./validation/isNumber.h"
#include "./validation/isString.h"

#include "./menus/menus.h"

#include <fstream>

void lerLinha(std::string *s) {
  std::fflush(stdin);
  std::getline(std::cin, *s);
}

int main() {
  Banco banco("Banco Azul", "banco@email.com", "40.332.583/0001-72");

  
  while(true) {
    menuVisaoInicial();
    std::string escolha;
    std::cin >> escolha;
    try {
      if (!isNumber(escolha)) throw PrecisaSerNumero();
      
        if (escolha == "0") {
          
          break;
        } else

        if (escolha == "1") {
          std::cout << "Visao Cliente\n";
          break;
        } else

        if (escolha == "2") {
          std::cout << "Até mais!" << std::endl;
          exit(0);
        } else{ throw OpcaoInvalida(); }

    } catch(std::runtime_error &e) {
      ExceptionCatch(e);
    }
    

  }

  

  return 0;
}