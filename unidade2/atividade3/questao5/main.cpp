#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Array.h"

int main() {
  Array a1(2);
  Array a2(2);

  cout << "Preenchendo a1:" << endl;
  cin >> a1;
  cout << "> a1: ";
  cout << a1;

  cout << "Preenchendo a2:" << endl;
  cin >> a2;
  cout << "> a2: ";
  cout << a2;

  cout << endl << "Concatenando a1 e a2 para criar a3:" << endl;
  Array a3 = a1 + a2;

  cout << "> a3: ";
  cout << a3;

  cout << endl << "Concatenando a1 e a2 e alterando a1:" << endl;
  a1 += a2;

  cout << "> a1 (modificado): ";
  cout << a1;

  return 0;
}