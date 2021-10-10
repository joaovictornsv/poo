#include <iostream>
#include "./entities/Banco/Banco.h"
#include "./exceptions/ExceptionCatch.h"
#include "./exceptions/PrecisaSerNumero.h"
#include "./exceptions/OpcaoInvalida.h"
#include "./menus/visaoGerente.h"


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
          // menuVisaoCliente();
          // std::string escolhaVisaoCliente;
          // std::cin >> escolhaVisaoCliente;
          // if (!isNumber(escolhaVisaoCliente)) throw PrecisaSerNumero();

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