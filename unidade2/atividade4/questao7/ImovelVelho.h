#ifndef IMOVEL_VELHO_H
#define IMOVEL_VELHO_H

#include <iostream>
#include "Imovel.h"
using std::string;

class ImovelVelho: public Imovel
{
public:
  ImovelVelho(float _preco, string _endereco, float _desconto);

  float getDesconto();
  void setDesconto(float _Desconto);

  float getPreco();

protected:
  float desconto;
};

#endif