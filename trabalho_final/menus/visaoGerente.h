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

void visaoGerente(Banco* banco) {
  while (true) {
    menuVisaoGerente();
    std::string escolhaVisaoGerente;
    std::cin >> escolhaVisaoGerente;
    try {
      if (!isNumber(escolhaVisaoGerente)) throw PrecisaSerNumero();
      
      // CADASTRAR CONTA
      if (escolhaVisaoGerente == "0") {
        // ESCOLHER SE CADASTRA OU USA CLIENTE
        std::string nomeCliente;
        Pessoa* correntista;

        bool cadastrouPessoa = false;
        while (!cadastrouPessoa) {
          menuCadastrarConta();
          std::string escolhaCadastrarConta;
          std::cin >> escolhaCadastrarConta;
          try {
            if (!isNumber(escolhaVisaoGerente)) throw PrecisaSerNumero();

            // CADASTRAR CLIENTE
            if (escolhaCadastrarConta == "0") {
              // CADASTRAR PESSOA FISICA
              while (!cadastrouPessoa) {
                menuCriarCliente();
                std::string escolhaCriarCliente;
                std::cin >> escolhaCriarCliente;
                try {
                  if (!isNumber(escolhaCriarCliente)) throw PrecisaSerNumero();

                  // PESSOA FISICA
                  if (escolhaCriarCliente == "0") {
                    std::string nome;
                    std::string email;
                    std::string cpf;

                    std::cout << "Nome: ";
                    lerLinha(&nome);

                    std::cout << "Email: ";
                    std::cin >> email;

                    std::cout << "CPF (sem pontuacao): ";
                    std::cin >> cpf;
                    PessoaFisica pf(nome, email, cpf);

                    banco->cadastrarPessoaFisica(&pf);
                    stpcpy(&nomeCliente[0], &nome[0]);
                    correntista = &pf;
                    std::cout << "Cadastro feito!" << std::endl;
                    cadastrouPessoa = true;
                    break;
                  } else

                  // PESSOA JURIDICA
                  if (escolhaCriarCliente == "1") {
                    std::string nome;
                    std::string email;
                    std::string cnpj;

                    std::cout << "Nome: ";
                    lerLinha(&nome);

                    std::cout << "Email: ";
                    std::cin >> email;

                    std::cout << "CNPJ (sem pontuacao): ";
                    std::cin >> cnpj;
                    PessoaJuridica pj(nome, email, cnpj);

                    banco->cadastrarPessoaJuridica(&pj);
                    stpcpy(&nomeCliente[0], &nome[0]);
                    correntista = &pj;
                    std::cout << "Cadastro feito!" << std::endl;
                    cadastrouPessoa = true;
                    break;

                  } else{ throw OpcaoInvalida(); }
                } catch(std::runtime_error &e) {
                  ExceptionCatch(e);
                }

              }
            } else
            
            // USAR CLIENTE
            if (escolhaCadastrarConta == "1") {
              while(true) {
                menuUsarCliente();
                lerLinha(&nomeCliente);
                try {
                  correntista = banco->getCorrentista(nomeCliente);
                  cadastrouPessoa = true;
                  break;
                } catch(std::runtime_error &e) {
                  ExceptionCatch(e);
                }
              }
            } else{ throw OpcaoInvalida(); }

          } catch(std::runtime_error &e) {
            ExceptionCatch(e);
          }
        }

        // CRIACAO DA CONTA
        bool cadastrouConta = false;
        while(!cadastrouConta) {
          menuTipoDeConta();
          std::string escolhaTipoDeConta;
          std::cin >> escolhaTipoDeConta;
          try {
            if (!isNumber(escolhaTipoDeConta)) throw PrecisaSerNumero();
            std::string numeroConta = banco->gerarNumeroConta();
            std::string chavePix;
            double saldo = 0;

            if (escolhaTipoDeConta == "0") {
              std::cout << "Escolha sua chave PIX: ";
              std::cin >> chavePix;
              ContaCorrente *cc = new ContaCorrente(correntista, numeroConta, saldo, chavePix);

              banco->cadastrarConta(cc);
              Conta* c = banco->getConta(numeroConta);

              std::cout << "Conta criada!" << std::endl;
              cadastrouConta = true;
              break;
              c->info();

            } else
            if (escolhaTipoDeConta == "1") {
              std::cout << "Escolha sua chave PIX: ";
              std::cin >> chavePix;
              double limite;
              std::cout << "Limite da conta: ";
              std::cin >> limite;


              ContaCorrenteLimite* ccl = new ContaCorrenteLimite(correntista, numeroConta, saldo, chavePix, limite);

              banco->cadastrarConta(ccl);

              Conta* c = banco->getConta(numeroConta);

              std::cout << "Conta criada!" << std::endl;
              cadastrouConta = true;
              break;
              c->info();

            } else 
            if (escolhaTipoDeConta == "2") {
              std::cout << "Escolha sua chave PIX: ";
              std::cin >> chavePix;
              time_t now = time(0);
              std::string date_time = ctime(&now);
              date_time.replace(date_time.find("\n"), 1, "");
              ContaPoupanca *cp = new ContaPoupanca(correntista, numeroConta, saldo, chavePix, date_time);


              banco->cadastrarConta(cp);
              Conta* c = banco->getConta(numeroConta);

              std::cout << "Conta criada!" << std::endl;
              cadastrouConta = true;
              break;
              c->info();

            } else{ throw OpcaoInvalida(); }

          } catch(std::runtime_error &e) {
            ExceptionCatch(e);
          }
        }
      } else

      // CONSULTAR CONTA
      if (escolhaVisaoGerente == "1") {
        menuConsultarConta();
        std::string numeroConta;
        std::cin >> numeroConta;
        banco->consultarConta(numeroConta);
        std::string pressToExit;
        std::cout << "Pressione qualquer tecla pra voltar ao menu:";
        lerLinha(&pressToExit);

      } else

      // ATUALIZAR CONTA
      if (escolhaVisaoGerente == "2") {

      } else

      // FECHAR CONTA
      if (escolhaVisaoGerente == "3") {

      } else              
      
      // LISTAR CONTAS
      if (escolhaVisaoGerente == "4") {
        menuListarContas();
        banco->listarContas();
        std::string pressToExit;
        std::cout << "Pressione qualquer tecla pra voltar ao menu:";
        lerLinha(&pressToExit);
      } else

      // LISTAR CONTAS DO CLIENTE
      if (escolhaVisaoGerente == "5") {
        menuListarContasCliente();
        std::string nomeCorrentista;
        lerLinha(&nomeCorrentista);
        banco->listarContasCorrentista(nomeCorrentista);
        std::string pressToExit;
        std::cout << "Pressione qualquer tecla pra voltar ao menu:";
        lerLinha(&pressToExit);
      } else 
      
      if (escolhaVisaoGerente == "6") {
        break;
      } else{ throw OpcaoInvalida(); }
    } catch(std::runtime_error &e) {
      ExceptionCatch(e);
    }
  }

}