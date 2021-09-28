#include <iostream>
using std::string;
using std::cout;
using std::endl;

#include "ImovelVelho.h"

ImovelVelho::ImovelVelho(float _preco, string _endereco, float _desconto): Imovel(_preco, _endereco) {
  setDesconto(_desconto);
};

float ImovelVelho::getPreco() {
  return preco - getDesconto();
};

float ImovelVelho::getDesconto() {
  return desconto;
};

void ImovelVelho::setDesconto(float _desconto) {
  desconto = _desconto;
};