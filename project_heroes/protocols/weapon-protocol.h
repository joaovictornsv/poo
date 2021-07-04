#include <string>
using std::string;


class WeaponProtocol {
  virtual int getTotalDamage()=0;
  virtual int getBaseDamage()=0;
  virtual string getMaterial()=0;
};