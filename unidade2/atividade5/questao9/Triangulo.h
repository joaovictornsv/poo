#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "FormaBidimensional.h"

#include <iostream>
using std::cout;
using std::endl;

class Triangulo : public FormaBidimensional
{
public:
  Triangulo(double _base, double _altura) : FormaBidimensional(3),
  base(_base), altura(_altura) {}

  virtual void desenhar() {
    cout << "  .   " << endl;
    cout << " / \\ " << endl;
    cout << "/   \\" << endl;
    cout << "~~~~~ " << endl;
  }

  virtual double calcularArea() {
    double area = (base * altura) / 2;
    return area;
  }

  virtual double calcularPerimetro() {
    double perimetro = 3 * base;
    return perimetro;
  }

private:
  double base;
  double altura;
};

#endif