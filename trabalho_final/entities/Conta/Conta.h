#ifndef CONTA_H
#define CONTA_H
#include <iostream>
#include <ctime>
#include "../Pessoa/Pessoa.h"

#include "../Transacao/Transacao.h"

#include <vector>
using std::vector;
#include <fstream>

#include "../../constants/identificadores.h"
#include "../../constants/arquivos.h"
#include "../../constants/descricao_transacoes.h"

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

  virtual void info() = 0;

  virtual void basicInfo() = 0;

  virtual void registrar() = 0;
  virtual std::string getLineFormat() = 0;

  std::string getNumeroConta() { return numeroConta; };
  Pessoa* getCorrentista() { return correntista; };

  void adicionarTransacao(
    std::string data,
    double valor,
    std::string descricao,
    std::string contaDestino
  ) {
      Transacao transacao;
      transacao.data = data;
      transacao.valor = valor;
      transacao.descricao = descricao;
      transacao.contaDestino = contaDestino;
      listaDeTransacoes.push_back(transacao);
  }
  
protected:
  double saldo;
  std::string numeroConta;
  Pessoa* correntista;
  vector<Transacao> listaDeTransacoes;
};

#endif