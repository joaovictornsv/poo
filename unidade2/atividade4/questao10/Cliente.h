#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
using std::string;

#include "lib/PessoaFisica.h"


class Cliente: public PessoaFisica
{
public:
  Cliente(
    string _nome,
    string _cpf,
    string _telefone,
    string _endereco
  );

  string getTelefone();
  string getEndereco();

  void setTelefone(string _telefone);
  void setEndereco(string _endereco);

  friend ostream &operator<<(ostream &, Cliente f);
 
private:
  string telefone;
  string endereco;
};

#endif