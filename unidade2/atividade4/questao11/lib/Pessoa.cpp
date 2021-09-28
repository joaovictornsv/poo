#include <iostream>
using std::string;
using std::cout;
using std::endl;

#include "Pessoa.h"

Pessoa::Pessoa() {
  setNome("Sem nome");
};


Pessoa::Pessoa(string _nome) {
  setNome(_nome);
};

void Pessoa::setNome(string _nome) {
  nome = _nome;
};

string Pessoa::getNome() {
  return nome;
};

ostream &operator<<(ostream &out, Pessoa p) {
  cout << p.getNome();
  return out;
};