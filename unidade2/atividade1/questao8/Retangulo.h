#ifndef RETANGULO_H
#define RETANGULO_H

class Retangulo
{
public:
  Retangulo(double altura = 1.0, double largura = 1.0);

  inline double getAltura() { return altura; }
  inline double getLargura() { return largura; }

  void setAltura(double valor);
  void setLargura(double valor);

  double calculaPerimetro();
  double calculaArea();

private:
  double altura;
  double largura;

};

#endif