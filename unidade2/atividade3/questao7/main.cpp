#include <iostream>

using std::cout;
using std::endl;

#include "Complex.h"

int main() {
  Complex complex1(5, 3);
  Complex complex2(2, 5);

  cout << "Complex1: ";
  complex1.print();

  cout << "Complex2: ";
  complex2.print();

  cout << endl;
  cout << "Complex3 = Complex1 + Complex2: " << endl;
  cout << "Complex3: ";
  Complex complex3 = complex1 + complex2;
  complex3.print();

  cout << endl;
  cout << "Complex4 = Complex1 - Complex2: " << endl;
  cout << "Complex4: ";
  Complex complex4 = complex1 - complex2;
  complex4.print();

  cout << endl;
  cout << "Complex3 += Complex1: " << endl;
  cout << "Complex3: ";
  complex3 += complex1;
  complex3.print();

  cout << endl;
  cout << "Complex4 -= Complex2: " << endl;
  cout << "Complex4: ";
  complex4 -= complex2;
  complex4.print();

  cout << endl;
  cout << "--Complex3: ";
  --complex3;
  complex3.print();

  cout << "Complex3--: ";
  complex3--;
  complex3.print();

  cout << "++Complex4: ";
  ++complex4;
  complex4.print();
  
  cout << "Complex4++: ";
  complex4++;
  complex4.print();

  return 0;
}