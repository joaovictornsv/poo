#include <iostream>
using std::string;
using std::cout;
using std::endl;

#include "Funcionario.h"

Funcionario::Funcionario(): PessoaFisica() {
  setMatricula("Sem matricula");
  setSalarioBase(1);
  setCargaHorariaMensal(1);
  setQuantDeHorasTrabalhadas(1);
}


Funcionario::Funcionario(
  string _nome,
    string _cpf,
    string _matricula,
    float _salarioBase,
    float _cargaHorariaMensal,
    float _quantDeHorasTrabalhadas
  ): PessoaFisica(_nome, _cpf) {
    setMatricula(_matricula);
    setSalarioBase(_salarioBase);
    setCargaHorariaMensal(_cargaHorariaMensal);
    setQuantDeHorasTrabalhadas(_quantDeHorasTrabalhadas);
  }

float Funcionario::calculaSalarioBruto() {
  float salarioBruto = getSalarioBase() * ( getQuantDeHorasTrabalhadas() / getCargaHorariaMensal() );

  return salarioBruto;
};

string Funcionario::getMatricula() {
  return matricula;
};

float Funcionario::getSalarioBase() {
  return salarioBase;
};

float Funcionario::getCargaHorariaMensal() {
  return cargaHorariaMensal;
};

float Funcionario::getQuantDeHorasTrabalhadas() {
  return quantDeHorasTrabalhadas;
};

void Funcionario::setMatricula(string _matricula) {
  matricula = _matricula;
};

void Funcionario::setSalarioBase(float _salarioBase) {
  salarioBase = _salarioBase;
};

void Funcionario::setCargaHorariaMensal(float _cargaHorariaMensal) {
  cargaHorariaMensal = _cargaHorariaMensal;
};

void Funcionario::setQuantDeHorasTrabalhadas(float _quantDeHorasTrabalhadas) {
  if (_quantDeHorasTrabalhadas < 0 || _quantDeHorasTrabalhadas > cargaHorariaMensal) {
    quantDeHorasTrabalhadas = 1;
    cout << "Carga horária inválida, valor setado como 1" << endl;
  }

  else {
    quantDeHorasTrabalhadas = _quantDeHorasTrabalhadas;
  }
};

ostream &operator<<(ostream &out, Funcionario f) {
  out << "Nome: " << f.getNome() << endl;
  out << "CPF: " << f.getCPF() << endl;
  out << "Matricula: " << f.getMatricula() << endl;
  out << "Salario base: R$" << f.getSalarioBase() << endl;
  out << "Carga horaria mensal: " << f.getCargaHorariaMensal() << " horas" << endl;
  out << "Quant. de horas trabalhadas: " << f.getQuantDeHorasTrabalhadas() << " horas" << endl;

  return out;
};