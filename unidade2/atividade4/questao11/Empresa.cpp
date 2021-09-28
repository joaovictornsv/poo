#include <iostream>
using std::string;
using std::cout;
using std::endl;

#include "Empresa.h"

Empresa::Empresa() {
  qtdClientes = 0;
  qtdFuncionarios = 0;
};

void Empresa::adicionarFuncionario(Funcionario &f) {
  if (qtdFuncionarios == 10) {
    cout << "Impossivel adicionar funcionario. Lista cheia." << endl;
  }
  else {
    funcionarios[qtdFuncionarios] = f;
    qtdFuncionarios += 1;
  }
};
void Empresa::adicionarCliente(Cliente &c) {
  if (qtdClientes == 10) {
    cout << "Impossivel adicionar cliente. Lista cheia." << endl;
  }
  else {
    clientes[qtdClientes] = c;
    qtdClientes += 1;
  }
};

void Empresa::imprimirFuncionarios() {
  cout << " ===== Lista de funcionários =====" << endl;
  for (int i = 0; i < qtdFuncionarios; i++) {
    cout << funcionarios[i].getNome() << endl;
  }
  cout << " =================================" << endl;
};
void Empresa::imprimirClientes() {
  cout << " ======= Lista de clientes =======" << endl;
  for (int i = 0; i < qtdClientes; i++) {
    cout << clientes[i].getNome() << endl;
  }
  cout << " =================================" << endl;
};

float Empresa::calcularFolhaDePagamento() {
  float totalFolha = 0;
  for (int i = 0; i < qtdFuncionarios; i++) {
    totalFolha += funcionarios[i].calculaSalarioBruto();
  }

  return totalFolha;
};