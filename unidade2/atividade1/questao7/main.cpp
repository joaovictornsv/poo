#include <iostream>
using std::cout;
using std::endl;

#include "Time.h"

int main() {
  Time t;

  cout << "Hora atual: ";
  t.printUniversal();

  return 0;
}