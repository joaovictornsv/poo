#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>

class Pessoa
{
public:
  Pessoa(
    std::string _nome,
    std::string _endereco,
    std::string _email
  ): nome(_nome), endereco(_endereco), email(_email) {}


  virtual void exibirDados() = 0;
  virtual std::string getCpf() = 0;
  virtual std::string getCnpj() = 0;

  std::string getNome() { return this->nome; }

protected:
  std::string nome;
  std::string endereco;
  std::string email;
};

#endif