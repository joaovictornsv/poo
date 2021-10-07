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
    // VISAO INICIAL
    menuVisaoInicial();
    std::string escolha;
    std::cin >> escolha;
    try {
      if (!isNumber(escolha)) throw PrecisaSerNumero();
      

        // VISAO GERENTE
        if (escolha == "0") {
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

                while (true) {
                  menuCadastrarConta();
                  std::string escolhaCadastrarConta;
                  std::cin >> escolhaCadastrarConta;
                  try {
                    if (!isNumber(escolhaVisaoGerente)) throw PrecisaSerNumero();

                    // CADASTRAR CLIENTE
                    if (escolhaCadastrarConta == "0") {
                      // CADASTRAR PESSOA FISICA
                      while (true) {
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

                            banco.cadastrarPessoaFisica(&pf);
                            stpcpy(&nomeCliente[0], &nome[0]);
                            correntista = &pf;
                            std::cout << "Cadastro feito!" << std::endl;
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

                            banco.cadastrarPessoaJuridica(&pj);
                            stpcpy(&nomeCliente[0], &nome[0]);
                            correntista = &pj;
                            std::cout << "Cadastro feito!" << std::endl;

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
                          correntista = banco.getCorrentista(nomeCliente);
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
                while(true) {
                  menuTipoDeConta();
                  std::string escolhaTipoDeConta;
                  std::cin >> escolhaTipoDeConta;
                  try {
                    if (!isNumber(escolhaTipoDeConta)) throw PrecisaSerNumero();
                    std::string numeroConta = banco.gerarNumeroConta();
                    std::string chavePix;
                    double saldo = 0;

                    std::cout << "Escolha sua chave PIX: ";
                    std::cin >> chavePix;

                    if (escolhaTipoDeConta == "0") {
                      ContaCorrente cc(correntista, numeroConta, saldo, chavePix);

                      banco.cadastrarConta(&cc);
                      Conta* c = banco.getConta(numeroConta);

                      std::cout << "Conta criada!" << std::endl;
                      c->info();

                    } else
                    if (escolhaTipoDeConta == "1") {
                      double limite;
                      std::cout << "Limite da conta: ";
                      std::cin >> limite;

                      ContaCorrenteLimite ccl(correntista, numeroConta, saldo, chavePix, limite);

                      banco.cadastrarConta(&ccl);
                      Conta* c = banco.getConta(numeroConta);

                      std::cout << "Conta criada!" << std::endl;
                      c->info();

                    } else 
                    if (escolhaTipoDeConta == "2") {
                      time_t now = time(0);
                      std::string date_time = ctime(&now);
                      ContaPoupanca cp(correntista, numeroConta, saldo, chavePix, date_time);

                      banco.cadastrarConta(&cp);
                      Conta* c = banco.getConta(numeroConta);

                      std::cout << "Conta criada!" << std::endl;
                      c->info();

                    } else{ throw OpcaoInvalida(); }

                  } catch(std::runtime_error &e) {
                    ExceptionCatch(e);
                  }
                }
              } else

              // CONSULTAR CONTA
              if (escolhaVisaoGerente == "1") {

              } else

              // ATUALIZAR CONTA
              if (escolhaVisaoGerente == "2") {

              } else

              // FECHAR CONTA
              if (escolhaVisaoGerente == "3") {

              } else              
              
              // LISTAR CONTAS
              if (escolhaVisaoGerente == "4") {

              } else

              // LISTAR CONTAS DO CLIENTE
              if (escolhaVisaoGerente == "5") {

              } else{ throw OpcaoInvalida(); }
            } catch(std::runtime_error &e) {
              ExceptionCatch(e);
            }
          }

          break;
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