#include <iostream>

using std::cout;
using std::endl;

#include "Imovel.h"
#include "ImovelNovo.h"
#include "ImovelVelho.h"

int main() {
  Imovel imovel(15000, "Rua São Bernando do Campo, 134");
  ImovelNovo imovelNovo(15000, "Rua José Silva Neto, 200", 3000);
  ImovelVelho imovelVelho(15000, "Av. Carvalho do Sul, 430", 2000);

  cout << "> Imovel" << endl;
  cout << "Endereco: " << imovel.getEndereco() << endl;
  cout << "Preco: " << imovel.getPreco() << endl;
  cout << "==============" << endl;


  cout << "> ImovelNovo" << endl;
  cout << "Endereco: " << imovelNovo.getEndereco() << endl;
  cout << "Preco: " << imovelNovo.getPreco() << endl;
  cout << "Adicional: " << imovelNovo.getAdicional() << endl;
  cout << "==============" << endl;


  cout << "> ImovelVelho" << endl;
  cout << "Endereco: " << imovelVelho.getEndereco() << endl;
  cout << "Preco: " << imovelVelho.getPreco() << endl;
  cout << "Desconto: " << imovelVelho.getDesconto() << endl;
  cout << "==============" << endl;

  return 0;
}