#include <iostream>
using std::string;
using std::cout;
using std::endl;

#include "Imovel.h"

Imovel::Imovel(float _preco, string _endereco) {
  setPreco(_preco);
  setEndereco(_endereco);
};

float Imovel::getPreco() {
  return preco;
};

string Imovel::getEndereco() {
  return endereco;
};

void Imovel::setPreco(float _preco) {
  preco = _preco;
};

void Imovel::setEndereco(string _endereco) {
  endereco = _endereco;
};
