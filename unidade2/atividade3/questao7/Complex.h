#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
  Complex(float _parteReal, float _parteImaginaria);

  void setParteReal(float _parteReal);
  void setParteImaginaria(float _parteImaginaria);

  float getParteReal();
  float getParteImaginaria();

  void print();

  Complex operator+(Complex &);
  void operator+=(Complex &);
  Complex operator-(Complex &);
  void operator-=(Complex &);
  Complex& operator++();
  Complex operator++(int);
  Complex& operator--();
  Complex operator--(int);

private:
  float parteReal;
  float parteImaginaria;
};

#endif