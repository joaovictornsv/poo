#ifndef PESSOA_FISICA_H
#define PESSOA_FISICA_H

#include <iostream>
using std::string;

#include "Pessoa.h"


class PessoaFisica: public Pessoa
{
public:
  PessoaFisica();
  PessoaFisica(string _nome, string _cpf);

  string getCPF();
  void setCPF(string _cpf);
 
private:
  string cpf;
};

#endif