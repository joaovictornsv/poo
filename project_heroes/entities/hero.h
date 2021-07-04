#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

#include <iostream>
#include <string>
#include "weapon.h"
#include "../protocols/hero-protocol.h"

using namespace std;

class Hero:HeroProtocol {
  protected:
    string name;
    Weapon weapon;
    string skill;

  public:
    Hero(string _name, Weapon _weapon) {
      name = _name;
      weapon = _weapon;
      skill = "No skill";
    }

    virtual void info() {
      cout << "Name: " << name << endl;
      cout << "Weapon total damage: " << weapon.getBaseDamage() << endl;
      cout << "Weapon base damage: " << weapon.getTotalDamage() << endl;
      cout << "Weapon material: " << weapon.getMaterial() << endl;
      cout << "Skill: " << skill << endl;
    }
};

class Warrior:public Hero {
  public:
    Warrior(string _name, Weapon _weapon):Hero(_name, _weapon) {
      skill = "Area damage";
    };
};

class Knight:public Hero {
  public:
    Knight(string _name, Weapon _weapon):Hero(_name, _weapon) {
      skill = "Blades";
    };
};

#endif