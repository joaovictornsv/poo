#include <iostream>
using std::cout;
using std::endl;

#include "Cachorro.h"

Cachorro::Cachorro() {
  nome = "Cachorro";
}

Cachorro::Cachorro(string _nome) {
  nome = _nome;
}

void Cachorro::late() {
  cout << getNome() << " diz: au, au, au" << endl;
}