#include <iostream>
#include "Retangulo.h"

using std::cout;
using std::endl;

int main() {
  Retangulo ret1;
  Retangulo ret2(-1, 21);
  Retangulo ret3(5, 10);

  cout << "==== Retangulo com valores padrão: ====" << endl;
  cout << "Altura: " << ret1.getAltura() << endl;
  cout << "Largura: " << ret1.getLargura() << endl;
  cout << "Perimetro: " << ret1.calculaPerimetro() << endl;
  cout << "Area: " << ret1.calculaArea() << endl;

  cout << endl;

  cout << "==== Retangulo com valores inválidos: ====" << endl;
  cout << "Altura: " << ret2.getAltura() << endl;
  cout << "Largura: " << ret2.getLargura() << endl;
  cout << "Perimetro: " << ret2.calculaPerimetro() << endl;
  cout << "Area: " << ret2.calculaArea() << endl;

  cout << endl;

  cout << "==== Retangulo com valores corretos: ====" << endl;
  cout << "Altura: " << ret3.getAltura() << endl;
  cout << "Largura: " << ret3.getLargura() << endl;
  cout << "Perimetro: " << ret3.calculaPerimetro() << endl;
  cout << "Area: " << ret3.calculaArea() << endl;
  
  return 0;
}