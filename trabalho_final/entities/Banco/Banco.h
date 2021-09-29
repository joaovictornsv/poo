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
      if (listaContas[i].correntista->getNome() == nome) {
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
    if (contaExiste(c.numeroConta) == false) throw ContaJaExiste();

    listaContas.push_back(c);
  }

  void consultarConta(std::string numeroConta) {
    if (contaExiste(numeroConta) == false) throw ContaNaoExiste();

    int index = 0;
    for(int i=0; i < listaContas.size(); i++) {
      if (listaContas[i].numeroConta == numeroConta) {
        index = i;
        break;
      }
    }

    listaContas[index].info();
  }

  void atualizarConta(std::string numeroConta) {
    if (contaExiste(numeroConta) == false) throw ContaNaoExiste();
  }

  void removerConta(std::string numeroConta) {
    if (contaExiste(numeroConta) == false) throw ContaNaoExiste();

    int index = 0;
    for(int i=0; i < listaContas.size(); i++) {
      if (listaContas[i].numeroConta == numeroConta) {
        index = i;
        break;
      }
    }

    listaContas.erase(listaContas.begin() + index);
  }

  bool contaExiste(std::string numeroConta) {
    bool contaExiste = false;
    for(int i=0; i < listaContas.size(); i++) {
      if (listaContas[i].numeroConta == numeroConta) {
        contaExiste = true;
        break;
      }
    }
    return contaExiste;
  }

  bool correntistaExiste(std::string nome) {
    bool correntistaExiste = false;
    for(int i=0; i < listaCorrentistas.size(); i++) {
      if (listaCorrentistas[i].nome == nome) {
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