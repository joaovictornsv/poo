#ifndef PESSOA_FISICA_H
#define PESSOA_FISICA_H

#include <iostream>
#include "Pessoa.h"

class PessoaFisica: public Pessoa
{
public:
  PessoaFisica(
    std::string _nome,
    std::string _email,
    std::string _cpf
  ): Pessoa(_nome, _email),
    cpf(_cpf) {}

  // void exibirDados() {
  //   std::cout << "Tipo: Pessoa Fisica" << std::endl;
  //   std::cout << "Nome: " << nome << std::endl;
  //   std::cout << "CPF: " << cpf << std::endl;
  // };

  virtual std::string getCpf() { return cpf; }
  virtual std::string getCnpj() { return cnpj; }

  virtual void registrar() {
    std::fstream file(FILE_PATH, std::ios::out | std::ios::in | std::ios::app);

    std::string delimiter = ";";
    std::string data = ID_P+delimiter+ID_PF+delimiter+getNome()+delimiter+getEmail()+delimiter+cpf;

    file << data << std::endl;
  }

  virtual std::string getLineFormat() {
    std::string delimiter = ";";
    std::string data = ID_P+delimiter+ID_PF+delimiter+getNome()+delimiter+getEmail()+delimiter+cpf;
    return data;
  }

  
protected:
  std::string cpf;
  std::string cnpj = "Sem CNPJ";
};

#endif