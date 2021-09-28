#ifndef EMPREGADO_H
#define EMPREGADO_H

#include <string>
using std::string;

class Empregado
{
public:
  Empregado(string name, string sobrenome, double valor);

  string getNome();
  string getSobrenome();
  double getSalarioMensal();

  void setNome(string name);
  void setSobrenome(string sobrenome);
  void setSalarioMensal(double valor);

private:
  string nome;
  string sobrenome;
  double salario_mensal;
};

#endif