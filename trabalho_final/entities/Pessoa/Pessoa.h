#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>

class Pessoa
{
public:
  Pessoa(
    std::string _nome
  ): nome(_nome) {}


  // virtual void exibirDados() = 0;
  virtual std::string getCpf() = 0;
  virtual std::string getCnpj() = 0;

  std::string getNome() { return this->nome; }

  std::string nome;
};

#endif