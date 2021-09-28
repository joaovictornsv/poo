#ifndef DATA_H
#define DATA_H

class Data
{
public:
  Data(int dia, int mes, int ano);

  void setDia(int _dia);
  void setMes(int _mes);
  void setAno(int _ano);

  int getDia();
  int getMes();
  int getAno();

  void mostrarData();

private:
  int dia;
  int mes;
  int ano;
};

#endif