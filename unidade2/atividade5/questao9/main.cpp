#include <iostream>

#include "FormaBidimensional.h"
#include "Quadrado.h"
#include "Circulo.h"
#include "Triangulo.h"

int main() {
  Quadrado quadrado(4);
  Circulo circulo(2.5);
  Triangulo triangulo(4, 3);

  std::cout << "=== Quadrado: ===" << std::endl;
  std::cout << "Area: " << quadrado.calcularArea() << std::endl;
  std::cout << "Perimetro: " << quadrado.calcularPerimetro() << std::endl;

  std::cout << "=== Circulo: ===" << std::endl;
  std::cout << "Area: " << circulo.calcularArea() << std::endl;
  std::cout << "Perimetro: " << circulo.calcularPerimetro() << std::endl;

  std::cout << "=== Triangulo: ===" << std::endl;
  std::cout << "Area: " << triangulo.calcularArea() << std::endl;
  std::cout << "Perimetro: " << triangulo.calcularPerimetro() << std::endl;


  return 0;
}