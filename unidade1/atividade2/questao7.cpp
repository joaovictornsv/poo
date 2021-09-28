#include <iostream>

using namespace std;

int main() {
  int cont = 0;
  double km, kmTotal = 0, litros, litrosTotal = 0;
  while(1) {
    cont += 1;
    cout << "Digite a kilometragem do tanque " << cont << ": ";
    cin >> km;
    if (km < 0) {
      cout << endl << "Calculando total..." << endl << endl;
      break;
    }
    kmTotal += km;

    cout << "Digite o consumo de gasolina em litros do tanque " << cont << ": ";
    cin >> litros;
    litrosTotal += litros;
  }

  if (litrosTotal == 0 || kmTotal == 0) {
    cout << "Valores insuficientes para realizar o cálculo!" << endl;
    return 0;
  }

  double media = kmTotal / litrosTotal;

  cout << "Total de kilomêtros percorridos: " << kmTotal << "km" << endl;
  cout << "Total de litros de gasolina consumidos: " << litrosTotal << "L" << endl;
  cout.precision(3);
  cout << "Média de consumo dos tanques: " << media << "km/L" << endl;

  return 0;
}