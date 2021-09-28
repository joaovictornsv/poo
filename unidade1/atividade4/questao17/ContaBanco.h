#ifndef CONTA_BANCO_H
#define CONTA_BANCO_H

class ContaBanco
{

public:
  ContaBanco(double valor);

  void creditar(double valor);

  void debitar(double valor);

  double getSaldo();

private:
  double saldo;

  void setSaldo(double valor);
};

#endif