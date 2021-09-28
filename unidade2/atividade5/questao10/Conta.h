#ifndef CONTA_H
#define CONTA_H
#include <iostream>
#include <ctime>

typedef struct {
  std::string data;
  double valor;
  std::string descricao;
} Transacao;

class Conta
{
public:
  Conta(std::string _nomeCorrentista, std::string _numeroConta, double _saldo) {
    nomeCorrentista = _nomeCorrentista;
    numeroConta = _numeroConta;
    saldo = _saldo;
  }

  virtual void deposito(double valor) = 0;
  virtual void retirada(double valor) = 0;
  
  virtual void extrato() = 0;

protected:
  std::string nomeCorrentista;
  std::string numeroConta;
  double saldo;
  Transacao listaDeTransacoes[10];
  int totalTransacoes = 0;
};

#endif