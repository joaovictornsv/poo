#include <iostream>
#include "HugeInteger.h"

#include <iomanip>

using std::cout;
using std::endl;

int main() {
  HugeInteger num1;
  HugeInteger num2;
  num1 = "999";
  num2 = "991";

  cout << "Somando 999 + 991... Resultado: ";
  HugeInteger num1_soma_num2;
  num1_soma_num2 = num1 + num2;
  cout << num1_soma_num2;

  HugeInteger a;
  HugeInteger b;
  a = "123";
  b = "5";

  cout << "Somando 123 + 5... Resultado: ";
  a += b;
  cout << a;

  HugeInteger num3;
  HugeInteger num4;
  HugeInteger num5;
  num3 = "123";
  num4 = "456";
  num5 = "456";
  cout << "456 == 456: " << (num4 == num5) << endl;
  cout << "456 != 456: " << (num4 != num5) << endl;
  cout << "456 <= 456: " << (num4 <= num5) << endl;
  cout << "456 > 456: " << (num4 > num5) << endl << endl;

  cout << "123 == 456: " << (num3 == num4) << endl;
  cout << "123 != 456: " << (num3 != num4) << endl;
  cout << "123 > 456: " << (num3 > num4) << endl;
  cout << "123 >= 456: " << (num3 >= num4) << endl;
  cout << "123 < 456: " << (num3 < num4) << endl;
  cout << "123 <= 456: " << (num3 <= num4) << endl;

  return 0;
}