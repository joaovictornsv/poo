#include <iostream>
using std::string;
using std::cout;
using std::endl;

#include "PessoaJuridica.h"

PessoaJuridica::PessoaJuridica(string _nome, string _cnpj, string _razaoSocial): Pessoa(_nome) {
  setCNPJ(_cnpj);
  setRazaoSocial(_razaoSocial);
};

void PessoaJuridica::setCNPJ(string _cnpj) {
  cnpj = _cnpj;
};

string PessoaJuridica::getCNPJ() {
  return cnpj;
};

void PessoaJuridica::setRazaoSocial(string _razaoSocial) {
  razaoSocial = _razaoSocial;
};

string PessoaJuridica::getRazaoSocial() {
  return razaoSocial;
};