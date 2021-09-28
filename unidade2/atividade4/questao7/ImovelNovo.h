#ifndef IMOVEL_NOVO_H
#define IMOVEL_NOVO_H

#include <iostream>
#include "Imovel.h"
using std::string;

class ImovelNovo: public Imovel
{
public:
  ImovelNovo(float _preco, string _endereco, float _adicional);

  float getAdicional();
  void setAdicional(float _adicional);

  float getPreco();

protected:
  float adicional;
};

#endif