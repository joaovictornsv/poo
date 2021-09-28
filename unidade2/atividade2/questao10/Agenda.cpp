#include <string>
#include "../questao8/Pessoa.h"
#include "Agenda.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl;

Agenda::Agenda(int tPessoas) {
  max = tPessoas;
  pessoas = new Pessoa[max];
};

Agenda::~Agenda() {
  delete [] pessoas;
};

void Agenda::armazenaPessoa(string nome, int idade, float altura) {
  Pessoa *p = new Pessoa(nome, idade, altura);
  pessoas[qtdePessoas] = *p;
  qtdePessoas += 1;
  delete p;
};

void Agenda::armazenaPessoa(const Pessoa &p) {
  if (qtdePessoas == max) {
    cout << "Impossível armazenar, Agenda cheia." << endl;
  }
  pessoas[qtdePessoas] = p;
  qtdePessoas += 1;
};

void Agenda::removePessoa(string nome) {
  bool found = false;

  for(int i = 0; i < qtdePessoas; i++) {
    if (pessoas[i].getNome() == nome) {
      int index = i;
      for (int j = index; j < qtdePessoas-1; j++) {
        pessoas[j] = pessoas[j+1];
      }
      qtdePessoas -= 1;
      found = true;
    };
  }
  if (!found) {
    cout << "Não foi encontrado nenhum registro com esse nome" << endl;
  }
};

int Agenda::buscaPessoa(string nome) const {
  for(int i = 0; i < qtdePessoas; i++) {
    if (pessoas[i].getNome() == nome) return i+1;
  }
  return 0;
}; // informa em que posição da agenda está a pessoa

void Agenda::imprimePovo() const {
  for(int i = 0; i < qtdePessoas; i++) {
    pessoas[i].info();
  }
}; // imprime todos os dados de todas as pessoas da agenda

void Agenda::imprimePessoa(int i) const {
  pessoas[i-1].info();
}; // imprime os dados da pessoa que está na posição 'i' da agenda