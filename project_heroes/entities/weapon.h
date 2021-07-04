#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED
#include "../utils/material.h"
#include "../protocols/weapon-protocol.h"

using std::string;

class Weapon:WeaponProtocol {
  protected:
    int baseDamage;
    BaseMaterial material;
  
  public:
    Weapon() {
      baseDamage = 0;
      material.name = "No material";
      material.damageBoost = 0;
    }
    Weapon(BaseMaterial _material) {
      baseDamage = 0;
      material.name = _material.name;
      material.damageBoost = _material.damageBoost;
    };
    int getTotalDamage() { return baseDamage + material.damageBoost; }
    int getBaseDamage() { return baseDamage; }
    string getMaterial() { return material.name; }
};

class Axe:public Weapon {
  public:
    Axe(){
      baseDamage = 50;
    };
    Axe(BaseMaterial _material):Weapon(_material) {
      baseDamage = 50;
    };
};

class Sword:public Weapon {
  public:
    Sword(){
      baseDamage = 100;
    };
    Sword(BaseMaterial _material):Weapon(_material) {
      baseDamage = 100;
    }
};

#endif