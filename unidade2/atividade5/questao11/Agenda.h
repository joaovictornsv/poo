#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include "Pessoa.h"

class Agenda
{
public:
  Agenda(int num): maxContatos(num) {}

  void exibirAgendaExpandida() {
    std::cout << "================== Agenda ==================" << std::endl;
    for (int i = 0; i < quantContatos; i++) {
      this->contatos[i]->exibirDados();
      std::cout << "--------------------------------------------" << std::endl;
    }
    
    std::cout << "============================================" << std::endl;
  };

  void exibirAgendaCompacta() {
    std::cout << "================== Agenda ==================" << std::endl;
    for (int i = 0; i < quantContatos; i++) {
      std::cout << this->contatos[i]->getNome() << std::endl;
    }
    
    std::cout << "============================================" << std::endl;
  };

  void adicionarContato(Pessoa* p) {
    if (quantContatos == maxContatos) {
      std::cout << "Impossivel adicionar! Agenda cheia." << std::endl;
      return;
    }

    this->contatos[quantContatos] = p;
    quantContatos += 1;
    std::cout << "Contato adicionado!" << std::endl;
  };

  void removerContato(std::string _valor) {
    if (quantContatos == 0) {
      std::cout << "Impossivel remover! Agenda vazia." << std::endl;
      return;
    }

    int index = -1;
    for (int i = 0; i < quantContatos; i++) {
      if (this->contatos[i]->getNome() == _valor || this->contatos[i]->getCpf() == _valor || this->contatos[i]->getCnpj() == _valor) {
        index = i;
        break;
      }
    }

    if (index == -1) {
      std::cout << "Impossivel remover! Usuário não encontrado!" << std::endl;
      return;
    }

    delete contatos[index];

    for (int j = index; j < quantContatos-1; j++) {
      this->contatos[index] = this->contatos[index+1];
    }

    quantContatos -= 1;
    std::cout << "Contato removido!" << std::endl;
  }
    
  
  void pesquisarContato(std::string _valor) {

    for (int i = 0; i < quantContatos; i++) {
      if (this->contatos[i]->getNome() == _valor || this->contatos[i]->getCpf() == _valor || this->contatos[i]->getCnpj() == _valor) {
        std::cout << "Usuário encontrado!" << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        this->contatos[i]->exibirDados();
        std::cout << "--------------------------------------------" << std::endl;
        return;
      }
    }

    std::cout << "Usuário não encontrado!" << std::endl;
  };

private:
  int maxContatos;
  int quantContatos = 0;
  Pessoa *contatos[];

};

#endif