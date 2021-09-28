#include <iostream>
#include "HugeInteger.h"

#include <iomanip>

using std::cout;
using std::endl;

int main() {
  HugeInteger num1;
  HugeInteger num2;
  num1.input("999");
  num2.input("991");

  cout << "Somando 999 + 991... Resultado: ";
  num1.add(num2);
  num1.output();

  HugeInteger a;
  HugeInteger b;
  a.input("123");
  b.input("5");

  cout << "Somando 123 + 5... Resultado: ";
  a.add(b);
  a.output();

  HugeInteger num3;
  HugeInteger num4;
  HugeInteger num5;
  num3.input("123");
  num4.input("456");
  num5.input("456");
  cout << "456 == 456: " << num4.isEqualTo(num5) << endl;
  cout << "456 != 456: " << num4.isNotEqualTo(num5) << endl;
  cout << "456 <= 456: " << num4.isLessThanOrEqual(num5) << endl;
  cout << "456 > 456: " << num4.isGreaterThan(num5) << endl << endl;

  cout << "123 == 456: " << num3.isEqualTo(num4) << endl;
  cout << "123 != 456: " << num3.isNotEqualTo(num4) << endl;
  cout << "123 > 456: " << num3.isGreaterThan(num4) << endl;
  cout << "123 >= 456: " << num3.isGreaterThanOrEqual(num4) << endl;
  cout << "123 < 456: " << num3.isLessThan(num4) << endl;
  cout << "123 <= 456: " << num3.isLessThanOrEqual(num4) << endl;

  return 0;
}