#ifndef BANC0_H
#define BANC0_H
#include <iostream>

#include "../Pessoa/Pessoa.h"
#include "../Pessoa/PessoaJuridica.h"

#include "../Conta/Conta.h"

#include "../../exceptions/ContaNaoExiste.h"
#include "../../exceptions/ContaJaExiste.h"
#include "../../exceptions/CorrentistaNaoExiste.h"

#include <vector>
using std::vector;

#define TIPO_CC "ContaCorrente"
#define TIPO_CCL "ContaCorrenteLimite"
#define TIPO_CP "ContaPoupanca"
#define DIGITO_CC 1
#define DIGITO_CCL 2
#define DIGITO_CP 3

class Banco: public PessoaJuridica
{
public:
  void listarContasCorrentista(std::string nome) {
    if (correntistaExiste(nome) == false) throw CorrentistaNaoExiste();

    std::cout << "============================================" << std::endl;
    std::cout << "Listando contas de " << nome << std::endl;
    std::cout << "============================================" << std::endl;
    bool haContas = false;
    for(int i=0; i < listaContas.size(); i++) {
      if (listaContas[i].getCorrentista()->getNome() == nome) {
        listaContas[i].basicInfo();
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
      listaContas[i].basicInfo();
      std::cout << "--------------------------------------------" << std::endl;
    }
    std::cout << "============================================" << std::endl;
  }

  void cadastrarConta(Conta& c) {
    if (contaExiste(c.getNumeroConta()) == true) throw ContaJaExiste();

    int digito;
    if(c.getTipoConta() == TIPO_CC) digito = DIGITO_CC;
    if(c.getTipoConta() == TIPO_CCL) digito = DIGITO_CCL;
    if(c.getTipoConta() == TIPO_CP) digito = DIGITO_CP;

    

    listaContas.push_back(c);
  }

  void consultarConta(std::string numeroConta) {
    if (contaExiste(numeroConta) == false) throw ContaNaoExiste();

    int index = 0;
    for(int i=0; i < listaContas.size(); i++) {
      if (listaContas[i].getNumeroConta() == numeroConta) {
        index = i;
        break;
      }
    }

    listaContas[index].info();
  }

  void atualizarConta(std::string numeroConta, std::string email) {
    if (contaExiste(numeroConta) == false) throw ContaNaoExiste();
    if (correntistaExiste(email) == false) throw CorrentistaNaoExiste();

    for(int i=0; i < listaCorrentistas.size(); i++) {
      if (listaCorrentistas[i].getEmail() == email) {
        listaCorrentistas[i].setEmail(email);
        break;
      }
    }

  }

  void removerConta(std::string numeroConta) {
    if (contaExiste(numeroConta) == false) throw ContaNaoExiste();

    int index = 0;
    for(int i=0; i < listaContas.size(); i++) {
      if (listaContas[i].getNumeroConta() == numeroConta) {
        index = i;
        break;
      }
    }

    listaContas.erase(listaContas.begin() + index);
  }

  bool contaExiste(std::string numeroConta) {
    bool contaExiste = false;
    for(int i=0; i < listaContas.size(); i++) {
      if (listaContas[i].getNumeroConta() == numeroConta) {
        contaExiste = true;
        break;
      }
    }
    return contaExiste;
  }

  bool correntistaExiste(std::string email) {
    bool correntistaExiste = false;
    for(int i=0; i < listaCorrentistas.size(); i++) {
      if (listaCorrentistas[i].getEmail() == email) {
        correntistaExiste = true;
        break;
      }
    }
    return correntistaExiste;
  }

private:
  vector<Pessoa> listaCorrentistas;
  vector<Conta> listaContas;
};

#endif