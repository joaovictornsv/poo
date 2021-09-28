#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
using std::string;
using std::ostream;

class Pessoa
{
public:
  Pessoa(string _nome);

  string getNome();
  void setNome(string _nome);

  friend ostream &operator<<(ostream &, Pessoa p);

 
protected:
  string nome;
};

#endif