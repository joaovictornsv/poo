#include <iostream>
#include "Cupom.h"

using std::cout;
using std::endl;
using std::ios;

int main() {
  cout.setf(ios::fixed);
  cout.precision(2);

  string id_1 = "cupom-27-07-2021-01";
  string descricao_1 = "Cupom-01 em 27/07/2021";
  Cupom cupom1(id_1, descricao_1, 5, 10.0);
  cout << "======== Cupom 1 ========" << endl;
  cout << "Id: " << cupom1.getId() << endl;
  cout << "Descricao: " << cupom1.getDescricao() << endl;
  cout << "Quantidade: " << cupom1.getQuantidade() << endl;
  cout << "Preco: R$" << cupom1.getPreco() << endl;
  cout << "_________________________" << endl;
  cout << "Total: R$" << cupom1.calculaCupom() << endl;
  cout << "=========================" << endl;

  cout << endl;

  string id_2 = "cupom-03-11-2019-20";
  string descricao_2 = "Cupom-20 em 03/11/2019";
  Cupom cupom2(id_2, descricao_2, -1, -10);
  cout << "======== Cupom 2 (com valores inválidos) ========" << endl;
  cout << "Id: " << cupom2.getId() << endl;
  cout << "Descricao: " << cupom2.getDescricao() << endl;
  cout << "Quantidade: " << cupom2.getQuantidade() << endl;
  cout << "Preco: R$" << cupom2.getPreco() << endl;
  cout << "_________________________________________________" << endl;
  cout << "Total: R$" << cupom2.calculaCupom() << endl;
  cout << "=================================================" << endl;
  return 0;
}