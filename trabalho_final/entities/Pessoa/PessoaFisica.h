#ifndef PESSOA_FISICA_H
#define PESSOA_FISICA_H

#include <iostream>
#include "Pessoa.h"

class PessoaFisica: public Pessoa
{
public:
  PessoaFisica(
    std::string _nome,
    std::string _cpf
  ): Pessoa(_nome),
    cpf(_cpf) {}

  // void exibirDados() {
  //   std::cout << "Tipo: Pessoa Fisica" << std::endl;
  //   std::cout << "Nome: " << nome << std::endl;
  //   std::cout << "CPF: " << cpf << std::endl;
  // };

  std::string getCpf() { return cpf; }
  std::string getCnpj() { return cnpj; }


protected:
  std::string cpf;
  std::string cnpj = "Sem CNPJ";
};

#endif