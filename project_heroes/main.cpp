#include <iostream>
#include "entities/weapon.h"
#include "entities/hero.h"
#include "utils/factory.h"

using namespace std;

int main() {
  Factory factory = Factory();
  Axe machadinho = factory.createIronWeapon<Axe>();
  Sword espadinha = factory.createDiamondWeapon<Sword>();


  Warrior bivar = Warrior("Bivar", machadinho);
  Mage vini = Mage("Vini", espadinha);

  bivar.info();
  vini.info();


  return 0;
}