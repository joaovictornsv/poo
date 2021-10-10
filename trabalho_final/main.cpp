#include <iostream>
#include "./entities/Banco/Banco.h"
#include "./exceptions/ExceptionCatch.h"
#include "./exceptions/PrecisaSerNumero.h"
#include "./exceptions/OpcaoInvalida.h"
#include "./menus/visaoGerente.h"
#include "./menus/visaoCliente.h"


int main() {
  Banco banco("Banco Azul", "banco@email.com", "40.332.583/0001-72");

  
  while(true) {
    // VISAO INICIAL
    menuVisaoInicial();
    std::string escolha;
    std::cin >> escolha;
    try {
      if (!isNumber(escolha)) throw PrecisaSerNumero();
      

        // VISAO GERENTE
        if (escolha == "0") {
          visaoGerente(&banco);
        } else

        if (escolha == "1") {
          while(true) { 
            menuEntrarComConta();
            std::string numeroConta;
            std::cin >> numeroConta;

            try {
              if (numeroConta == "-1") {
                break;
              } else {
                Conta* conta = banco.getConta(numeroConta);

                visaoCliente(&banco, conta);
              } 
            } catch(std::runtime_error &e) {
              ExceptionCatch(e);
            }
          }


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