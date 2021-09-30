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
#include "./exceptions/ExceptionCatch.h"

#include <fstream>

int main() {
  std::fstream file("./database/contas.txt", std::ios::out | std::ios::in);

  if (!file) {
    std::cout << "Ocorreu um erro ao iniciar o arquivo!" << std::endl;
    return 0;
  }



  std::string output;
  while (std::getline (file, output)) {
  // Output the text from the file
    std::string delimiter = ";";
    int contaId;
    std::string nomeCorrentista;
    double saldo;
    int limite;
    std::string aniversarioConta;
    std::string numeroConta;

    int end = output.find(delimiter);
    contaId =  std::stoi(output.substr(0, end).c_str());
    output.erase(0, end+1);

    end = output.find(delimiter);
    nomeCorrentista = output.substr(0, end);
    output.erase(0, end+1);

    end = output.find(delimiter);
    numeroConta = output.substr(0, end);
    output.erase(0, end+1);

    end = output.find(delimiter);
    saldo = std::stod(output.substr(0, end).c_str());
    output.erase(0, end+1);

    std::cout << contaId << " ";
    std::cout << nomeCorrentista << " ";
    std::cout << numeroConta << " ";
    std::cout << saldo << " ";
    if (contaId == 2) {
      end = output.find(delimiter);
      limite = std::stoi(output.substr(0, end).c_str());
      output.erase(0, end+1);
      std::cout << limite << " ";
    } else if (contaId == 3) {
      end = output.find(delimiter);
      aniversarioConta = output.substr(0, end);
      std::cout << aniversarioConta << " ";
      output.erase(0, end+1);
    }
    std::cout << std::endl;
  }




  // PessoaFisica pf("Joao Victor", "joao@email.com", "706.083.0440-84");
  // PessoaJuridica pj("Joao Victor", "joao@email.com", "40.332.583/0001-72");

  // ContaCorrente cc(&pf, "123", 0);
  // ContaCorrenteLimite ccl(&pj, "432", 0, 100);

  // try {
  //   cc << 100;
  //   ccl << 100;

  //   cc.transferir(10, &ccl);
  //   ccl.transferir(90, &cc);
    
  //   ccl.transferir(90, &cc);
  //   // cc.transferir(900, &ccl);

  //   cc.info();
  //   ccl.info();

  // } catch (std::runtime_error &e) {
  //   ExceptionCatch(e);
  // }

  return 0;
}