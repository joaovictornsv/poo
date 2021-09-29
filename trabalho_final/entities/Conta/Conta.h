#ifndef CONTA_H
#define CONTA_H
#include <iostream>
#include <ctime>
#include "../Pessoa/Pessoa.h"

#include <vector>
using std::vector;

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

  // Depósito
  virtual void operator<<(double valor) = 0;

  // Retirada
  virtual void operator>>(double valor) = 0;
  
  virtual void extrato() = 0;

  // Transferência
  virtual void transferir(double valor, Conta* conta) = 0;

  double getSaldo() { return saldo; };

  std::string numeroConta;
  
protected:
  Pessoa* correntista;
  double saldo;
  vector<Transacao> listaDeTransacoes;
};

#endif