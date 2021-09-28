#include <iostream>
#include "Data.h"

using std::cout;
using std::endl;

int main() {
  
  cout << "===== Mostrando data ====" << endl;
  Data data1(27, 7, 2021);
  data1.mostrarData();

  cout << "===== Testando data com valor de mês invalido ====" << endl;
  Data data2(1, 15, 2001);
  data2.mostrarData();

  return 0;
}