#include "../entities/weapon.h"

class Factory {
  public:
    template <class Weapon>
    Weapon createIronWeapon() {
      return Weapon(Iron);
    };

    template <class Weapon>
    Weapon createGoldWeapon() {
      return Weapon(Gold);
    };

    template <class Weapon>
    Weapon createDiamondWeapon() {
      return Weapon(Diamond);
    };
};