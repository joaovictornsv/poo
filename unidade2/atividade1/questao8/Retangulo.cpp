#include "Retangulo.h"

Retangulo::Retangulo(double altura, double largura) {
  setAltura(altura);
  setLargura(largura);
};

void Retangulo::setAltura(double valor) {
  altura = (valor > 0.0 && valor < 20.0) ? valor : 1;
};
void Retangulo::setLargura(double valor) {
  largura = (valor > 0.0 && valor < 20.0) ? valor : 1;
};

double Retangulo::calculaPerimetro() {
  return (getAltura() * 2) + (getLargura() * 2);
};

double Retangulo::calculaArea() {
  return getAltura() * getLargura();
};
 