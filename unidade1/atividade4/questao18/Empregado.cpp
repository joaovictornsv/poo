#include <iostream>
#include "Empregado.h"

Empregado::Empregado(string _nome, string _sobrenome, double valor) {
  setNome(_nome);
  setSobrenome(_sobrenome);
  if (valor < 0) setSalarioMensal(0);
  else setSalarioMensal(valor);
}

string Empregado::getNome() {
  return nome;
};
string Empregado::getSobrenome() {
  return sobrenome;
};
double Empregado::getSalarioMensal() {
  return salario_mensal;
};

void Empregado::setNome(string _nome) {
  nome = _nome;
}

void Empregado::setSobrenome(string _sobrenome) {
  sobrenome = _sobrenome;
};


void Empregado::setSalarioMensal(double valor) {
  salario_mensal = valor;
};
