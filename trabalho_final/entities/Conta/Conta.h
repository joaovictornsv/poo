#ifndef CONTA_H
#define CONTA_H
#include <iostream>
#include <ctime>
#include "../Pessoa/Pessoa.h"

typedef struct {
  std::string data;
  double valor;
  std::string descricao;
  std::string contaDestino;
} Transacao;

class Conta
{
public:
  Conta(Pessoa* _correntista, std::string _numeroConta, double _saldo) {
    correntista = _correntista;
    numeroConta = _numeroConta;
    saldo = _saldo;
  }

  // Sobrecarregar operador <<
  virtual void deposito(double valor) = 0;

  // Sobrecarregar operador >>
  virtual void retirada(double valor) = 0;
  
  virtual void extrato() = 0;

  // Transferência
  virtual void transferir() = 0;

protected:
  Pessoa* correntista;
  std::string numeroConta;
  double saldo;
  Transacao listaDeTransacoes[10];
  int totalTransacoes = 0;
};

#endif