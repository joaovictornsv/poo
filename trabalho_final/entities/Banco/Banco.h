#ifndef BANC0_H
#define BANC0_H
#include <iostream>

#include "../Pessoa/Pessoa.h"
#include "../Pessoa/PessoaFisica.h"
#include "../Pessoa/PessoaJuridica.h"

#include "../Conta/Conta.h"
#include "../Conta/ContaCorrente.h"
#include "../Conta/ContaCorrenteLimite.h"
#include "../Conta/ContaPoupanca.h"

#include "../../exceptions/ContaNaoExiste.h"
#include "../../exceptions/ContaJaExiste.h"
#include "../../exceptions/CorrentistaNaoExiste.h"

#include <vector>
using std::vector;

#define TIPO_CC "ContaCorrente"
#define TIPO_CCL "ContaCorrenteLimite"
#define TIPO_CP "ContaPoupanca"

#define ID_C "C"
#define ID_CC "CC"
#define ID_CCL "CCL"
#define ID_CP "CP"

#define ID_P "P"
#define ID_PF "PF"
#define ID_PJ "PJ"

#define ID_T "T"

#include <fstream>

class Banco: public PessoaJuridica
{
public:
  Banco(std::string _nome,
    std::string _email,
    std::string _cnpj):
    PessoaJuridica(_nome, _email, _cnpj) {
      carregarPessoas();
      carregarContas();
      carregarTransacoes();
    };

  

  void listarContasCorrentista(std::string nome) {
    if (correntistaExiste(nome) == false) throw CorrentistaNaoExiste();

    std::cout << "============================================" << std::endl;
    std::cout << "Listando contas de " << nome << std::endl;
    std::cout << "============================================" << std::endl;
    bool haContas = false;
    for(int i=0; i < listaContas.size(); i++) {
      if (listaContas[i]->getCorrentista()->getNome() == nome) {
        listaContas[i]->basicInfo();
        haContas = true;
        std::cout << "--------------------------------------------" << std::endl;
      }
    }
    if (haContas == false) std::cout << "Nao ha contas" << std::endl;
    std::cout << "============================================" << std::endl;
  }

  void listarContas() {
    std::cout << "============================================" << std::endl;
    for(int i=0; i < listaContas.size(); i++) {
      listaContas[i]->basicInfo();
      std::cout << "--------------------------------------------" << std::endl;
    }
    std::cout << "============================================" << std::endl;
  }


  void listarCorrentistas() {
    std::cout << "============================================" << std::endl;
    for(int i=0; i < listaCorrentistas.size(); i++) {
      std::cout << listaCorrentistas[i]->getNome() << std::endl;
      std::cout << "--------------------------------------------" << std::endl;
    }
    std::cout << "============================================" << std::endl;
  }

  void cadastrarConta(Conta* c) {
    if (contaExiste(c->getNumeroConta()) == true) throw ContaJaExiste();

    std::string subtipo;
    if(c->getTipoConta() == TIPO_CC) subtipo = ID_CC;
    if(c->getTipoConta() == TIPO_CCL) subtipo = ID_CCL;
    if(c->getTipoConta() == TIPO_CP) subtipo = ID_CP;



    listaContas.push_back(c);
  }

  void consultarConta(std::string numeroConta) {
    if (contaExiste(numeroConta) == false) throw ContaNaoExiste();

    int index = 0;
    for(int i=0; i < listaContas.size(); i++) {
      if (listaContas[i]->getNumeroConta() == numeroConta) {
        index = i;
        break;
      }
    }

    listaContas[index]->extrato();
  }

  Conta* getConta(std::string numeroConta) {
    if (contaExiste(numeroConta) == false) throw ContaNaoExiste();

    int index = 0;
    for(int i=0; i < listaContas.size(); i++) {
      if (listaContas[i]->getNumeroConta() == numeroConta) {
        index = i;
        break;
      }
    }

    return listaContas[index];
  }

  void atualizarConta(std::string numeroConta, std::string email) {
    if (contaExiste(numeroConta) == false) throw ContaNaoExiste();
    if (correntistaExiste(email) == false) throw CorrentistaNaoExiste();

    for(int i=0; i < listaCorrentistas.size(); i++) {
      if (listaCorrentistas[i]->getEmail() == email) {
        listaCorrentistas[i]->setEmail(email);
        break;
      }
    }

  }

  void removerConta(std::string numeroConta) {
    if (contaExiste(numeroConta) == false) throw ContaNaoExiste();

    int index = 0;
    for(int i=0; i < listaContas.size(); i++) {
      if (listaContas[i]->getNumeroConta() == numeroConta) {
        index = i;
        break;
      }
    }

    listaContas.erase(listaContas.begin() + index);
  }

  bool contaExiste(std::string numeroConta) {
    bool contaExiste = false;
    for(int i=0; i < listaContas.size(); i++) {
      if (listaContas[i]->getNumeroConta() == numeroConta) {
        contaExiste = true;
        break;
      }
    }
    return contaExiste;
  }

  bool correntistaExiste(std::string nome) {
    bool correntistaExiste = false;
    for(int i=0; i < listaCorrentistas.size(); i++) {
      if (listaCorrentistas[i]->getNome() == nome) {
        correntistaExiste = true;
        break;
      }
    }
    return correntistaExiste;
  }

  Pessoa* getCorrentista(std::string nome) {
    for(int i=0; i < listaCorrentistas.size(); i++) {
      if (listaCorrentistas[i]->getNome() == nome) {
        return listaCorrentistas[i];
        break;
      }
    }
    return NULL;
  }

private:
  vector<Pessoa*> listaCorrentistas;
  vector<Conta*> listaContas;
  std::string nomeDoBanco;

  void carregarTransacoes() {
    std::fstream file("./database/contas.txt", std::ios::out | std::ios::in);

    std::string delimiter = ";";
    std::string output;
    while (std::getline (file, output)) {
      std::string tipoDado;
      std::string numeroConta;
      std::string data;
      double valor;
      std::string descricao;
      std::string contaDestino;

      int end = output.find(delimiter);
      tipoDado = output.substr(0, end);
      output.erase(0, end+1);

      if (tipoDado == ID_T) {
        int end = output.find(delimiter);
        numeroConta = output.substr(0, end);
        output.erase(0, end+1);

        Conta* conta = getConta(numeroConta);

        end = output.find(delimiter);
        data = output.substr(0, end);
        output.erase(0, end+1);

        end = output.find(delimiter);
        valor = std::stod(output.substr(0, end).c_str());
        output.erase(0, end+1);

        end = output.find(delimiter);
        descricao = output.substr(0, end);
        output.erase(0, end+1);


        if (descricao == "Transferencia") {
          end = output.find(delimiter);
          contaDestino = output.substr(0, end);
          output.erase(0, end+1);
          conta->adicionarTransacao(data, valor, descricao, contaDestino);
        } else {
          conta->adicionarTransacao(data, valor, descricao, "0");
        }
      }
    }
  }

  void carregarPessoas() {
    std::fstream file("./database/contas.txt", std::ios::out | std::ios::in);

    std::string delimiter = ";";
    std::string output;
    while (std::getline (file, output)) {
      std::string tipoDado;
      std::string tipoPessoa;
      std::string nome;
      std::string email;
      std::string cpf;
      std::string cnpj;

      int end = output.find(delimiter);
      tipoDado = output.substr(0, end);
      output.erase(0, end+1);

      if (tipoDado == ID_P) {

        int end = output.find(delimiter);
        tipoPessoa = output.substr(0, end);
        output.erase(0, end+1);

        end = output.find(delimiter);
        nome = output.substr(0, end);
        output.erase(0, end+1);

        end = output.find(delimiter);
        email = output.substr(0, end);
        output.erase(0, end+1);


        if (tipoPessoa == ID_PF) {
          end = output.find(delimiter);
          cpf = output.substr(0, end);
          output.erase(0, end+1);
          listaCorrentistas.push_back(new PessoaFisica(nome, email, cpf));
        } else if (tipoPessoa == ID_PJ) {
          end = output.find(delimiter);
          cnpj = output.substr(0, end);
          output.erase(0, end+1);
          listaCorrentistas.push_back(new PessoaJuridica(nome, email, cnpj));
        }
      }
    }
  }

  void carregarContas() {
    std::fstream file("./database/contas.txt", std::ios::out | std::ios::in);

    std::string delimiter = ";";
    std::string output;
    while (std::getline (file, output)) {
      std::string tipoDado;
      std::string tipoConta;
      std::string nomeCorrentista;
      double saldo;
      int limite;
      std::string aniversarioConta;
      std::string numeroConta;

      int end = output.find(delimiter);
      tipoDado = output.substr(0, end);
      output.erase(0, end+1);

      if (tipoDado == ID_C) {

        int end = output.find(delimiter);
        tipoConta = output.substr(0, end);
        output.erase(0, end+1);

        end = output.find(delimiter);
        nomeCorrentista = output.substr(0, end);
        output.erase(0, end+1);

        if (correntistaExiste(nomeCorrentista) == false) throw CorrentistaNaoExiste();
        Pessoa* correntista = getCorrentista(nomeCorrentista);

        end = output.find(delimiter);
        numeroConta = output.substr(0, end);
        output.erase(0, end+1);

        end = output.find(delimiter);
        saldo = std::stod(output.substr(0, end).c_str());
        output.erase(0, end+1);

        if (tipoConta == ID_CCL) {
          end = output.find(delimiter);
          limite = std::stoi(output.substr(0, end).c_str());
          output.erase(0, end+1);
          listaContas.push_back(new ContaCorrenteLimite(correntista, numeroConta, saldo, limite));
        } else if (tipoConta == ID_CP) {
          end = output.find(delimiter);
          aniversarioConta = output.substr(0, end);
          output.erase(0, end+1);
          listaContas.push_back(new ContaPoupanca(correntista, numeroConta, saldo, aniversarioConta));
        } else if (tipoConta == ID_CC) {
          listaContas.push_back(new ContaCorrente(correntista, numeroConta, saldo));

        }
      }
    }
  }
};

#endif