#include <iostream>
using std::string;
using std::cout;
using std::endl;

#include "Cliente.h"

Cliente::Cliente(
    string _nome,
    string _cpf,
    string _telefone,
    string _endereco
  ): PessoaFisica(_nome, _cpf) {
    setTelefone(_telefone);
    setEndereco(_endereco);
  }

string Cliente::getTelefone() {
  return telefone;
};

string Cliente::getEndereco() {
  return endereco;
};


void Cliente::setTelefone(string _telefone) {
  telefone = _telefone;
};

void Cliente::setEndereco(string _endereco) {
  endereco = _endereco;
}

ostream &operator<<(ostream &out, Cliente f) {
  out << "Nome: " << f.getNome() << endl;
  out << "CPF: " << f.getCPF() << endl;
  out << "Telefone: " << f.getTelefone() << endl;
  out << "Endereco: " << f.getEndereco() << endl;

  return out;
};