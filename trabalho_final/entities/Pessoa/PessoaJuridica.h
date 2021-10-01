#ifndef PESSOA_JURIDICA_H
#define PESSOA_JURIDICA_H

#include <iostream>
#include "Pessoa.h"

class PessoaJuridica: public Pessoa
{
public:
  PessoaJuridica(
    std::string _nome,
    std::string _email,
    std::string _cnpj
  ): Pessoa(_nome, _email),
    cnpj(_cnpj) {}

  // virtual void exibirDados() {
  //   std::cout << "Tipo: Pessoa Juridica" << std::endl;
  //   std::cout << "Nome: " << nome << std::endl;
  //   std::cout << "CNPJ: " << cnpj << std::endl;
  // };

  virtual std::string getCpf() { return cpf; }
  virtual std::string getCnpj() { return cnpj; }

  virtual void registrar() {
    std::fstream file(FILE_PATH, std::ios::out | std::ios::in | std::ios::app);

    std::string delimiter = ";";
    std::string data = ID_P+delimiter+ID_PJ+delimiter+getNome()+delimiter+getEmail()+delimiter+cnpj;

    file << data << std::endl;
  }

protected:
  std::string cpf = "Sem CPF";
  std::string cnpj;
};

#endif