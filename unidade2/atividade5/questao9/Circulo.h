#ifndef CIRCULO_H
#define CIRCULO_H

#ifndef PI
#define PI 3.14
#endif

#include "FormaBidimensional.h"

#include <iostream>
using std::cout;
using std::endl;

class Circulo : public FormaBidimensional
{
public:
  Circulo(double _raio) : FormaBidimensional(99999), raio(_raio) {}

  virtual void desenhar() {
    cout << "  _ " << endl;
    cout << "/   \\" << endl;
    cout << "\\   /" << endl;
    cout << "  ~ " << endl;
  }

  virtual double calcularArea() {
    double area = PI * raio * raio;
    return area;
  }

  virtual double calcularPerimetro() {
    double perimetro = 2 * PI * raio;
    return perimetro;
  }

private:
  double raio;
};

#endif