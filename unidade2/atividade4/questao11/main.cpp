#include <iostream>

using std::cout;
using std::endl;

#include "Empresa.h"
#include "./lib/Funcionario.h"
#include "./lib/Cliente.h"

int main() {
  Empresa empresa;

  Funcionario funcionario1("Delia Fogaça Veiga","084.245.480-27", "8185813", 1500, 160, 150);
  Funcionario funcionario2("Anael Fortes Vilanova","274.136.660-81", "1747687", 2400, 160, 154);
  Funcionario funcionario3("Valéria Gaspar Carmo","654.952.280-30", "5038361", 3920, 160, 152);
  Funcionario funcionario4("Lígia Flores Sabrosa","432.768.920-30", "1609128", 1230, 160, 160);
  Funcionario funcionario5("João Victor Negreiros","880.128.400-49", "3146870", 2300, 160, 144);

  Cliente cliente1("Débora Faia Barreira","084.245.480-27", "9216214534", "Rua Allana Barroqueiro 345");
  Cliente cliente2("Artyom Monforte Mourão","274.136.660-81", "9464703910", "Rua Adam Sobreira 21");
  Cliente cliente3("Henrique Viana Caldas","654.952.280-30", "5583424948", "Rua Nancy Caniça 45");
  Cliente cliente4("Chris Malheiro Cadaval","432.768.920-30", "3954426538", "Rua Arnaldo Guimarães 762");
  Cliente cliente5("Letízia Jobim Tomé","880.128.400-49", "6495846472", "Rua Valter Taveiros 524");

  empresa.adicionarFuncionario(funcionario1);
  empresa.adicionarFuncionario(funcionario2);
  empresa.adicionarFuncionario(funcionario3);
  empresa.adicionarFuncionario(funcionario4);
  empresa.adicionarFuncionario(funcionario5);

  empresa.adicionarCliente(cliente1);
  empresa.adicionarCliente(cliente2);
  empresa.adicionarCliente(cliente3);
  empresa.adicionarCliente(cliente4);
  empresa.adicionarCliente(cliente5);

  empresa.imprimirFuncionarios();
  empresa.imprimirClientes();

  cout << "Total a ser gasto com os funcionários: R$" << empresa.calcularFolhaDePagamento() << endl;

  return 0;
}