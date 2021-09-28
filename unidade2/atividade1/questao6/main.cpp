#include <iostream>
using std::cout;
using std::endl;

#include "Time.h"

int main() {
  Time t1(16, 40);
  Time t2(11, 50, 59);
  Time t3(11, 59, 59);
  Time t4(23, 59, 59);

  cout << "Tempo 1 (ANTES do tick): ";
  t1.printUniversal();
  cout << "Tempo 1 (DEPOIS do tick): ";
  t1.tick();
  t1.printUniversal();

  cout << endl;

  cout << "Tempo 2 (ANTES do tick): ";
  t2.printUniversal();
  cout << "Tempo 2 (DEPOIS do tick): ";
  t2.tick();
  t2.printUniversal();

  cout << endl;

  cout << "Tempo 3 (ANTES do tick): ";
  t3.printUniversal();
  cout << "Tempo 3 (DEPOIS do tick): ";
  t3.tick();
  t3.printUniversal();
  
  cout << endl;

  cout << "Tempo 4 (ANTES do tick): ";
  t4.printUniversal();
  cout << "Tempo 4 (DEPOIS do tick): ";
  t4.tick();
  t4.printUniversal();

  return 0;
}