#include <iostream>
#include "entities/weapon.h"
#include "entities/hero.h"
#include "utils/factory.h"

using namespace std;

int main() {
  Factory factory = Factory();
  Axe stormbreaker = factory.createIronWeapon<Axe>();
  Sword darkSword = factory.createDiamondWeapon<Sword>();


  Warrior thor = Warrior("Thor", stormbreaker);
  Knight batman = Knight("Bruce", darkSword);

  thor.info();
  cout << endl;
  batman.info();


  return 0;
}