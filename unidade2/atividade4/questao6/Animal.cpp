#include <iostream>
using std::string;
using std::cout;
using std::endl;

#include "Animal.h"

Animal::Animal() {
  nome = "Animal";
}

Animal::Animal(string _nome) {
  nome = _nome;
}

string Animal::getNome() {
  return nome;
}

void Animal::caminha() {
  cout << getNome() << " está caminhando..." << endl;
}