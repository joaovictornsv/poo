#include <iostream>

using std::cout;
using std::endl;

#include "Pessoa.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"

int main() {
  Pessoa pessoa("João Victor");
  PessoaFisica pessoaFisica("Vinicius", "123.456.789-10");
  PessoaJuridica pessoaJuridica("Lucas", "12.345.678/0001-91", "Lucas Tech");

  cout << "> Pessoa" << endl;
  cout <<  "Nome: " << pessoa << endl;
  cout << "==============" << endl;


  cout << "> Pessoa Fisica" << endl;
  cout << "Nome: " << pessoaFisica << endl;
  cout << "CPF: " << pessoaFisica.getCPF() << endl;
  cout << "==============" << endl;


  cout << "> Pessoa Juridica" << endl;
  cout <<  "Nome: " << pessoaJuridica << endl;
  cout <<  "CNPJ: " << pessoaJuridica.getCNPJ() << endl;
  cout <<  "Razao Social: " << pessoaJuridica.getRazaoSocial() << endl;
  cout << "==============" << endl;

  return 0;
}