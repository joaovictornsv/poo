#include <iostream>
using std::cout;
using std::endl;

#include "Gato.h"

Gato::Gato() {
  nome = "Gato";
}

Gato::Gato(string _nome) {
  nome = _nome;
}

void Gato::mia() {
  cout << getNome() << " diz: miau" << endl;
}