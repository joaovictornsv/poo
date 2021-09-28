#include <iostream>
#include "ContaBanco.h"

using std::cerr;
using std::endl;

ContaBanco::ContaBanco(double valor) {
  if (valor < 0) setSaldo(0);
  else setSaldo(valor);
};


void ContaBanco::setSaldo(double valor) {
  saldo = valor;
}

void ContaBanco::creditar(double valor) {
  setSaldo(getSaldo() + valor);
};

void ContaBanco::debitar(double valor) {
  if (valor > getSaldo())
    cerr << "[ERRO] Saldo insuficiente para esta operação" << endl;

  else setSaldo(getSaldo() - valor);
}

double ContaBanco::getSaldo() {
  return saldo;
}