#include <iostream>


void visaoCliente(Banco* banco, Conta *conta) {
  while (true) {
    menuVisaoCliente();
    std::string escolhaVisaoCliente;
    std::cin >> escolhaVisaoCliente;
    try {
      if (!isNumber(escolhaVisaoCliente)) throw PrecisaSerNumero();
      
      // DEPOSITO
      if (escolhaVisaoCliente == "0") {
        while (true) {
          menuDeposito();
          std::string valorDeposito;
          std::cin >> valorDeposito;
          try {
            if (isNumber(valorDeposito) == 0) throw PrecisaSerNumero();

            (*conta) << std::atof(valorDeposito.c_str());
            break;
          } catch(std::runtime_error &e) {
            ExceptionCatch(e);
          }
        }
      } else

      // SAQUE
      if (escolhaVisaoCliente == "1") {
        while (true) {
          menuSaque();
          std::string valorSaque;
          std::cin >> valorSaque;
          try {
            if (isNumber(valorSaque) == 0) throw PrecisaSerNumero();

            (*conta) >> std::atof(valorSaque.c_str());
            break;
          } catch(std::runtime_error &e) {
            ExceptionCatch(e);
          }
        }
      } else

      // TRANSFERENCIA
      if (escolhaVisaoCliente == "2") {
        while (true) {
          menuTransferencia();
          std::string numeroContaDestino;
          std::cin >> numeroContaDestino;

          try {
            Conta* contaDestino = banco->getConta(numeroContaDestino);
            std::string valorTransferencia;
            std::cout << "Valor da transferencia: ";
            std::cin >> valorTransferencia;
            if (isNumber(valorTransferencia) == 0) throw PrecisaSerNumero();

            conta->transferir(std::atof(valorTransferencia.c_str()), contaDestino);
            break;
          } catch(std::runtime_error &e) {
            ExceptionCatch(e);
          }
        }
      } else

      // EXTRATO
      if (escolhaVisaoCliente == "3") {
        menuExtrato();
        conta->extrato();
        std::string pressToExit;
        std::cout << "Pressione qualquer tecla pra voltar ao menu:";
        lerLinha(&pressToExit);
      } else              
      
      // SALDO
      if (escolhaVisaoCliente == "4") {
        menuSaldo();
        std::cout << conta->getSaldo() << std::endl;
        std::string pressToExit;
        std::cout << "Pressione qualquer tecla pra voltar ao menu:";
        lerLinha(&pressToExit);
      } else

      // VOLTAR AO MENU
      if (escolhaVisaoCliente == "5") {
        break;
      } else{ throw OpcaoInvalida(); }
    } catch(std::runtime_error &e) {
      ExceptionCatch(e);
    }
  }

}