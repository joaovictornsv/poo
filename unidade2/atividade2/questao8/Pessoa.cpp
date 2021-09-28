#include <iostream>
#include <string>
#include "Pessoa.h"
using std::string;
using std::cout;
using std::endl;

Pessoa::Pessoa() {
  nome = "";
  idade = -1;
  altura = 0;
};

Pessoa::Pessoa(string nome, int idade, float altura) {
  setNome(nome);
  setIdade(idade);
  setAltura(altura);
};

void Pessoa::setNome(string _nome) { nome = _nome; };
void Pessoa::setIdade(int _idade) { idade = _idade; };
void Pessoa::setAltura(float _altura) { altura = _altura; };

void Pessoa::info() const {
  cout << nome << ", " << idade << " anos, " << altura << "m" << endl;
};
