#ifndef CONTA_CORRENTE_H
#define CONTA_CORRENTE_H
#include <iostream>
#include "../Pessoa/Pessoa.h"

#include "Conta.h"

class ContaCorrente: public Conta
{
public:
  ContaCorrente(Pessoa* _correntista, std::string _numeroConta, double _saldo)
  : Conta(_correntista, _numeroConta, _saldo) {}

  // Depósito
  virtual void operator<<(double valor) {
    if (totalTransacoes == 10) {
      std::cout << "Impossível realizar operação. Limite de transacoes atingido" << std::endl;
    }
    else {
      saldo += valor;

      Transacao transacao;
      transacao.valor = valor;
      transacao.descricao = "Deposito";

      time_t now = time(0);

      std::string date_time = ctime(&now);

      transacao.data = date_time;
      listaDeTransacoes[totalTransacoes] = transacao;
      totalTransacoes += 1;

      std::cout << "Deposito de R$" << valor << " realizado." << std::endl;
    }
  }

  // Retirada
  virtual void operator>>(double valor) {
    if (totalTransacoes == 10) {
      std::cout << "Impossível realizar operação. Limite de transacoes atingido" << std::endl;
      return;
    }

    saldo -= valor;

    Transacao transacao;

    transacao.valor = valor;
    transacao.descricao = "Saque";

    time_t now = time(0);

    std::string date_time = ctime(&now);

    transacao.data = date_time;
    listaDeTransacoes[totalTransacoes] = transacao;
    totalTransacoes += 1;

    std::cout << "Saque de R$" << valor << " realizado." << std::endl;
  }

  virtual void extrato() {
    std::cout << "============================================" << std::endl;
    std::cout << "Tipo de conta: Corrente Comum" << std::endl;
    std::cout << "Numero da conta: " << numeroConta << std::endl;
    std::cout << "Nome do cliente: " << correntista->getNome() << std::endl;
    std::cout << "Saldo: " << saldo << std::endl;
    std::cout << "---------------- Transacoes ----------------" << std::endl;
    for (int i = 0; i < totalTransacoes; i++) {
      std::cout << "Num.Transacao: " << i << std::endl;
      std::cout << "Descricao: " << listaDeTransacoes[i].descricao << std::endl;
      std::cout << "Valor: " << listaDeTransacoes[i].valor << std::endl;
      std::cout << "Data: " << listaDeTransacoes[i].data;
      std::cout << "--------------------------------------------" << std::endl;
    }

    std::cout << "============================================" << std::endl;
  };
};

#endif