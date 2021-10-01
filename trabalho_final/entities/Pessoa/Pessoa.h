#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <fstream>

#include "../../constants/identificadores.h"
#include "../../constants/arquivos.h"


class Pessoa
{
public:
  Pessoa(
    std::string _nome,
    std::string _email
  ): nome(_nome), email(_email) {}


  // virtual void exibirDados() = 0;
  virtual std::string getCpf() = 0;
  virtual std::string getCnpj() = 0;

  std::string getNome() { return this->nome; }
  std::string getEmail() { return this->email; }
  void setEmail(std::string email) { this->email = email; }

  virtual void registrar() = 0;

protected:
  std::string nome;
  std::string email;
};

#endif