#include <string>
#include "../questao8/Pessoa.h"
#include "Agenda.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl;

void Agenda::armazenaPessoa(string nome, int idade, float altura) {
  pessoas[qtd].setNome(nome);
  pessoas[qtd].setIdade(idade);
  pessoas[qtd].setAltura(altura);
  qtd += 1;
};
void Agenda::armazenaPessoa(const Pessoa &p) {
  pessoas[qtd] = p;
  qtd += 1;
};

void Agenda::removePessoa(string nome) {
  bool found = false;

  for(int i = 0; i < qtd; i++) {
    if (pessoas[i].getNome() == nome) {
      int index = i;
      for (int j = index; j < qtd-1; j++) {
        pessoas[j] = pessoas[j+1];
      }
      qtd -= 1;
      found = true;
    };
  }
  if (!found) {
    cout << "Não foi encontrado nenhum registro com esse nome" << endl;
  }
};

int Agenda::buscaPessoa(string nome) const {
  for(int i = 0; i < qtd; i++) {
    if (pessoas[i].getNome() == nome) return i+1;
  }
  return 0;
}; // informa em que posição da agenda está a pessoa

void Agenda::imprimePovo() const {
  for(int i = 0; i < qtd; i++) {
    pessoas[i].info();
  }
}; // imprime todos os dados de todas as pessoas da agenda

void Agenda::imprimePessoa(int i) const {
  pessoas[i-1].info();
}; // imprime os dados da pessoa que está na posição 'i' da agenda