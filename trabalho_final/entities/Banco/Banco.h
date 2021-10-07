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

#include "../../constants/identificadores.h"
#include "../../constants/arquivos.h"

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

    c->registrar();
    c->getCorrentista()->registrar();

    listaContas.push_back(c);
    listaCorrentistas.push_back(c->getCorrentista());
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

  void atualizarConta(std::string numeroConta, std::string chavePix) {
    if (contaExiste(numeroConta) == false) throw ContaNaoExiste();

    for(int i=0; i < listaContas.size(); i++) {
      if (listaContas[i]->getNumeroConta() == numeroConta) {
        listaContas[i]->setChavePix(chavePix);
        break;
      }
    }

    atualizarRegistros();
  }

  void removerConta(std::string numeroConta) {
    if (contaExiste(numeroConta) == false) throw ContaNaoExiste();
    Conta* conta = getConta(numeroConta);

    int index = 0;
    for(int i=0; i < listaContas.size(); i++) {
      if (listaContas[i]->getNumeroConta() == numeroConta) {
        index = i;
        break;
      }
    }

    std::ifstream file(FILE_PATH);
    std::ofstream tempFile(TEMP_FILE_PATH);

    std::string output;
    while (std::getline (file, output)) {
      if (output != conta->getLineFormat()) {
        tempFile << output << std::endl;
      }
    }

    file.close();
    tempFile.close();
    remove(FILE_PATH);
    rename(TEMP_FILE_PATH, FILE_PATH);
    listaContas.erase(listaContas.begin() + index);
  }

  void atualizarRegistros() {
    std::ifstream file(FILE_PATH);
    std::ofstream tempFile(TEMP_FILE_PATH);

    std::string output;

    for(int i=0; i < listaCorrentistas.size(); i++) {
      tempFile <<listaCorrentistas[i]->getLineFormat() << std::endl;
    }

    for(int i=0; i < listaContas.size(); i++) {
      tempFile <<listaContas[i]->getLineFormat() << std::endl;
    }

    for(int i=0; i < listaContas.size(); i++) {
      listaContas[i]->registrarTransacoes(&tempFile);
    }

    file.close();
    tempFile.close();
    remove(FILE_PATH);
    rename(TEMP_FILE_PATH, FILE_PATH);
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
    std::fstream file(FILE_PATH, std::ios::out | std::ios::in);

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
    std::fstream file(FILE_PATH, std::ios::out | std::ios::in);

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
    std::fstream file(FILE_PATH, std::ios::out | std::ios::in);

    std::string delimiter = ";";
    std::string output;
    while (std::getline (file, output)) {
      std::string tipoDado;
      std::string tipoConta;
      std::string nomeCorrentista;
      std::string chavePix;
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

        end = output.find(delimiter);
        chavePix = output.substr(0, end);
        output.erase(0, end+1);

        if (tipoConta == ID_CCL) {
          end = output.find(delimiter);
          limite = std::stoi(output.substr(0, end).c_str());
          output.erase(0, end+1);
          listaContas.push_back(new ContaCorrenteLimite(correntista, numeroConta, saldo, chavePix, limite));
        } else if (tipoConta == ID_CP) {
          end = output.find(delimiter);
          aniversarioConta = output.substr(0, end);
          output.erase(0, end+1);
          listaContas.push_back(new ContaPoupanca(correntista, numeroConta, saldo, chavePix, aniversarioConta));
        } else if (tipoConta == ID_CC) {
          listaContas.push_back(new ContaCorrente(correntista, numeroConta, saldo, chavePix));

        }
      }
    }
  }
};

#endif