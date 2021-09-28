#include <iostream>
using std::cout;
using std::endl;

#include "Complex.h"

Complex::Complex(float _parteReal, float _parteImaginaria) {
  setParteReal(_parteReal);
  setParteImaginaria(_parteImaginaria);
};

void Complex::setParteReal(float _parteReal) {
  parteReal = _parteReal;
};

void Complex::setParteImaginaria(float _parteImaginaria) {
  parteImaginaria = _parteImaginaria;
};

float Complex::getParteReal() {
  return parteReal;
};

float Complex::getParteImaginaria() {
  return parteImaginaria;
};

void Complex::print() {
  std::string operador = getParteImaginaria() > 0 ? "+" : "";

  cout << getParteReal() << operador << getParteImaginaria() << "i" << endl;
};

Complex Complex::operator+(Complex &complex2) {
  float _parteReal = this->getParteReal() + complex2.getParteReal();
  float _parteImaginaria = this->getParteImaginaria() + complex2.getParteImaginaria();

  Complex complex3(_parteReal, _parteImaginaria);

  return complex3;
};

void Complex::operator+=(Complex &complex2) {
  this->parteReal = this->getParteReal() + complex2.getParteReal();
  this->parteImaginaria = this->getParteImaginaria() + complex2.getParteImaginaria();
};

Complex Complex::operator-(Complex &complex2) {
  float _parteReal = this->getParteReal() - complex2.getParteReal();
  float _parteImaginaria = this->getParteImaginaria() - complex2.getParteImaginaria();

  Complex complex3(_parteReal, _parteImaginaria);

  return complex3;
};

void Complex::operator-=(Complex &complex2) {
  this->parteReal = this->getParteReal() - complex2.getParteReal();
  this->parteImaginaria = this->getParteImaginaria() - complex2.getParteImaginaria();
};

Complex& Complex::operator++() {
  setParteReal(getParteReal() + 1);
  return *this;
};

Complex Complex::operator++(int) {
  Complex actual = *this;
  setParteReal(getParteReal() + 1);
  return actual;
};

Complex& Complex::operator--() {
  setParteReal(getParteReal() - 1);
  return *this;
};

Complex Complex::operator--(int) {
  Complex actual = *this;
  setParteReal(getParteReal() - 1);
  return actual;
};
