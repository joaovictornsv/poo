#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
using std::string;

#include "lib/PessoaFisica.h"


class Funcionario: public PessoaFisica
{
public:
  Funcionario(
    string _nome,
    string _cpf,
    string _matricula,
    float _salarioBase,
    float _cargaHorariaMensal,
    float _quantDeHorasTrabalhadas
  );

  float calculaSalarioBruto();

  string getMatricula();
  float getSalarioBase();
  float getCargaHorariaMensal();
  float getQuantDeHorasTrabalhadas();

  void setMatricula(string _matricula);
  void setSalarioBase(float _salarioBase);
  void setCargaHorariaMensal(float _cargaHorariaMensal);
  void setQuantDeHorasTrabalhadas(float _quantDeHorasTrabalhadas);

  friend ostream &operator<<(ostream &, Funcionario f);
 
private:
  string matricula;
  float salarioBase;
  float cargaHorariaMensal;
  float quantDeHorasTrabalhadas;
};

#endif