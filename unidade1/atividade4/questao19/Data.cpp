#include <iostream>
#include "Data.h"

using std::cout;
using std::endl;

Data::Data(int dia, int mes, int ano) {
  setDia(dia);
  if (mes < 1 || mes > 12) setMes(1);
  else setMes(mes);
  setAno(ano);
};


void Data::setDia(int _dia) {
  dia = _dia; 
};

void Data::setMes(int _mes) {
  mes = _mes;
};

void Data::setAno(int _ano) {
  ano = _ano;
};


int Data::getDia() {
  return dia;
};

int Data::getMes() {
  return mes;
};

int Data::getAno() {
  return ano;
};


void Data::mostrarData() {
  cout << getDia() << "/" << getMes() << "/" << getAno() << endl;
};