#ifndef EMPRESA_H
#define EMPRESA_H

#include "lib/Cliente.h"
#include "lib/Funcionario.h"

class Empresa
{
public:
  Empresa();

  void adicionarFuncionario(Funcionario &);
  void adicionarCliente(Cliente &);

  void imprimirFuncionarios();
  void imprimirClientes();

  float calcularFolhaDePagamento();

private:
  Cliente clientes[10];
  Funcionario funcionarios[10];
  int qtdClientes;
  int qtdFuncionarios;
};

#endif