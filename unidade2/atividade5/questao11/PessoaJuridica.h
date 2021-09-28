#ifndef PESSOA_JURIDICA_H
#define PESSOA_JURIDICA_H

#include <iostream>
#include "Pessoa.h"

class PessoaJuridica: public Pessoa
{
public:
  PessoaJuridica(
    std::string _nome,
    std::string _endereco,
    std::string _email,
    std::string _cnpj,
    std::string _inscricaoEstadual,
    std::string _razaoSocial
  ): Pessoa(_nome, _endereco, _email),
    cnpj(_cnpj), inscricaoEstadual(_inscricaoEstadual), razaoSocial(_razaoSocial) {}

  virtual void exibirDados() {
    std::cout << "Tipo: Pessoa Juridica" << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Endereco: " << endereco << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "CNPJ: " << cnpj << std::endl;
    std::cout << "Inscricao estadual: " << inscricaoEstadual << std::endl;
    std::cout << "Razao social: " << razaoSocial << std::endl;
  };

  virtual std::string getCpf() { return cpf; }
  virtual std::string getCnpj() { return cnpj; }


protected:
  std::string cpf = "Sem CPF";
  std::string cnpj;
  std::string inscricaoEstadual;
  std::string razaoSocial;
};

#endif