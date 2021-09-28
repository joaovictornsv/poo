#ifndef QUADRADO_H
#define QUADRADO_H

#include "FormaBidimensional.h"

#include <iostream>
using std::cout;
using std::endl;

class Quadrado : public FormaBidimensional
{
public:
  Quadrado(double _lado) : FormaBidimensional(4), lado(_lado) {}

  virtual void desenhar() {
    cout << "-----" << endl;
    cout << "|   |" << endl;
    cout << "-----" << endl;
  }

  virtual double calcularArea() {
    double area = lado * lado;
    return area;
  }

  virtual double calcularPerimetro() {
    double perimetro = 4 * lado;
    return perimetro;
  }

private:
  double lado;
};

#endif