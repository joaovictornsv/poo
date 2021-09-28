#include <iostream>
using std::string;
using std::cout;
using std::endl;

#include "PessoaFisica.h"

PessoaFisica::PessoaFisica(): Pessoa() {
  setCPF("Sem CPF");
};

PessoaFisica::PessoaFisica(string _nome, string _cpf): Pessoa(_nome) {
  setCPF(_cpf);
};

void PessoaFisica::setCPF(string _cpf) {
  cpf = _cpf;
};

string PessoaFisica::getCPF() {
  return cpf;
};