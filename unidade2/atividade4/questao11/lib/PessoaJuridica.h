#ifndef PESSOA_JURIDICA_H
#define PESSOA_JURIDICA_H

#include <iostream>
using std::string;

#include "Pessoa.h"


class PessoaJuridica: public Pessoa
{
public:
  PessoaJuridica(string _nome, string _cnpj, string _razaoSocial);

  string getCNPJ();
  void setCNPJ(string _cnpj);

  string getRazaoSocial();
  void setRazaoSocial(string _razaoSocial);
 
private:
  string cnpj;
  string razaoSocial;
};

#endif