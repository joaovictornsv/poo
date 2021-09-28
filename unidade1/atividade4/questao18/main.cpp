#include <iostream>
#include "Empregado.h"

using std::cout;
using std::endl;
using std::ios;

int main() {
  cout.setf(ios::fixed);
  cout.precision(2);

  Empregado empregado1("João", "Silva", 1500);
  cout << "===== Empregado 1 =====" << endl;
  cout << "Nome: " << empregado1.getNome() << endl;
  cout << "Sobrenome: " << empregado1.getSobrenome() << endl;
  cout << "Salario Mensal: R$" << empregado1.getSalarioMensal() << endl;

  Empregado empregado2("Lucas", "Fonsêca", -100);
  cout << "===== Empregado 2 =====" << endl;
  cout << "Nome: " << empregado2.getNome() << endl;
  cout << "Sobrenome: " << empregado2.getSobrenome() << endl;
  cout << "Salario Mensal: R$" << empregado2.getSalarioMensal() << endl;

  cout << endl << "=> Alterando salario de Lucas para 500" << endl;
  empregado2.setSalarioMensal(500);

  cout << "=> Aplicando 10% de aumento no salário dos empregados" << endl << endl;
  empregado1.setSalarioMensal(empregado1.getSalarioMensal() + empregado1.getSalarioMensal()*0.1);
  empregado2.setSalarioMensal(empregado2.getSalarioMensal() + empregado2.getSalarioMensal()*0.1);

  cout << "===== Salarios atualizados =====" << endl;
  cout << "Empregado 1: R$" << empregado1.getSalarioMensal() << endl;
  cout << "Empregado 2: R$" << empregado2.getSalarioMensal() << endl;

  return 0;
}