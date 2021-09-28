#ifndef HUGE_INTEGER_H
#define HUGE_INTEGER_H

#include <iostream>
#include <string.h>
using std::string;
using std::ostream;


class HugeInteger
{
public:
  HugeInteger();

  void input(std::string value);
  void output();

  void add(const HugeInteger &h);

  bool isEqualTo(const HugeInteger &h);
  bool isNotEqualTo(const HugeInteger &h);
  bool isGreaterThan(const HugeInteger &h);
  bool isLessThan(const HugeInteger &h);
  bool isGreaterThanOrEqual(const HugeInteger &h);
  bool isLessThanOrEqual(const HugeInteger &h);

  HugeInteger &operator=(const string &);
  HugeInteger operator+(HugeInteger &);
  void operator+=(HugeInteger &);
  bool operator==(HugeInteger &);
  bool operator!=(HugeInteger &);
  bool operator>(HugeInteger &);
  bool operator>=(HugeInteger &);
  bool operator<(HugeInteger &);
  bool operator<=(HugeInteger &);

  friend ostream &operator<<(ostream &, HugeInteger &);

private:
  std::string num;
  int tamanho;

  bool numeroValido(std::string value);
};

#endif