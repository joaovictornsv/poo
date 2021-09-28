#ifndef IMOVEL_H
#define IMOVEL_H

#include <iostream>
using std::string;

class Imovel
{
public:
  Imovel(float _preco, string _endereco);

  float getPreco();
  string getEndereco();

  void setPreco(float _preco);
  void setEndereco(string _endereco);
 
protected:
  float preco;
  string endereco;
};

#endif