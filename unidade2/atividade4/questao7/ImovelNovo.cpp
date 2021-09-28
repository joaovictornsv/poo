#include <iostream>
using std::string;
using std::cout;
using std::endl;

#include "ImovelNovo.h"

ImovelNovo::ImovelNovo(float _preco, string _endereco, float _adicional): Imovel(_preco, _endereco) {
  setAdicional(_adicional);
};

float ImovelNovo::getPreco() {
  return preco + getAdicional();
};

float ImovelNovo::getAdicional() {
  return adicional;
};

void ImovelNovo::setAdicional(float _adicional) {
  adicional = _adicional;
};