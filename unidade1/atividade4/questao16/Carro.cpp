#include <iostream>
using std::cout;
using std::endl;

#include "Carro.h"

//Implementação

Carro::Carro(string nome, int ano)
{ //modificação 1
  setMarca(nome);
  setAno(ano);
}

void Carro::setMarca(string nome)
{ //modificação 2
  if (nome == "")
    marca = "\"Sem Marca\"";
  else if (nome.length() > 10)
    marca = nome.substr(0,10);
  else
    marca = nome;
}

void Carro::setAno(int _ano)
{
  ano = _ano;
}

string Carro::getMarca()
{
  return marca;
}

int Carro::getAno()
{
  return ano;
}

void Carro::displayMessage()
{
  std::cout << "Olá, eu sou um carro da marca " << getMarca() << endl;
  std::cout << "Fui fabricado no ano " << getAno() << endl;
}