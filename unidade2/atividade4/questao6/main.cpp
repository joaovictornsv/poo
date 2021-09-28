#include <iostream>

using std::cout;
using std::endl;

#include "Animal.h"
#include "Cachorro.h"
#include "Gato.h"

int main() {
  Animal animal1;
  Animal animal2("Canguru");

  Cachorro c1;
  Cachorro c2("Caramelo");

  Gato g1;
  Gato g2("Garfield");

  cout << "> Objetos Animal" << endl;
  animal1.caminha();
  animal2.caminha();
  cout << "=====================" << endl;

  cout << "> Objetos Cachorro" << endl;
  c1.caminha();
  c1.late();
  c2.caminha();
  c2.late();
  cout << "=====================" << endl;

  cout << "> Objetos Gato" << endl;
  g1.caminha();
  g1.mia();
  g2.caminha();
  g2.mia();
  cout << "=====================" << endl;



  return 0;
}