#ifndef PESSOA_FISICA_H
#define PESSOA_FISICA_H

#include <iostream>
#include "Pessoa.h"

class PessoaFisica: public Pessoa
{
public:
  PessoaFisica(
    std::string _nome,
    std::string _endereco,
    std::string _email,
    std::string _cpf,
    std::string _dataNascimento,
    std::string _estadoCivil
  ): Pessoa(_nome, _endereco, _email),
    cpf(_cpf), dataNascimento(_dataNascimento), estadoCivil(_estadoCivil) {}

  virtual void exibirDados() {
    std::cout << "Tipo: Pessoa Fisica" << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Endereco: " << endereco << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "CPF: " << cpf << std::endl;
    std::cout << "Data de nascimento: " << dataNascimento << std::endl;
    std::cout << "Estado civil: " << estadoCivil << std::endl;
  };

  virtual std::string getCpf() { return cpf; }
  virtual std::string getCnpj() { return cnpj; }


protected:
  std::string cpf;
  std::string cnpj = "Sem CNPJ";
  std::string dataNascimento;
  std::string estadoCivil;
};

#endif