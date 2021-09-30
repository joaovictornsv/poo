#ifndef CONTA_CORRENTE_H
#define CONTA_CORRENTE_H
#include <iostream>
#include "../Pessoa/Pessoa.h"

#include "Conta.h"
#include "../../exceptions/SaldoInsuficiente.h"

class ContaCorrente: public Conta
{
public:
  ContaCorrente(Pessoa* _correntista, std::string _numeroConta, double _saldo)
  : Conta(_correntista, _numeroConta, _saldo) {}

  // Depósito
  virtual void operator<<(double valor) {
    saldo += valor;

    Transacao transacao;
    transacao.valor = valor;
    transacao.descricao = "Deposito";

    time_t now = time(0);

    std::string date_time = ctime(&now);

    transacao.data = date_time;
    listaDeTransacoes.push_back(transacao);

    std::cout << "Deposito de R$" << valor << " realizado." << std::endl;
  }

  // Retirada
  virtual void operator>>(double valor) {
    if ((saldo - valor) < 0) throw SaldoInsuficiente();

    saldo -= valor;

    Transacao transacao;

    transacao.valor = valor;
    transacao.descricao = "Saque";

    time_t now = time(0);

    std::string date_time = ctime(&now);

    transacao.data = date_time;
    listaDeTransacoes.push_back(transacao);

    std::cout << "Saque de R$" << valor << " realizado." << std::endl;
  }

  // Transferencia
  virtual void transferir(double valor, Conta* conta) {
    if ((saldo - valor) < 0) throw SaldoInsuficiente();

    *conta << valor;
    saldo -= valor;

    Transacao transacao;

    transacao.valor = valor;
    transacao.descricao = "Transferencia";
    transacao.contaDestino = conta->getNumeroConta();

    time_t now = time(0);
    std::string date_time = ctime(&now);

    transacao.data = date_time;
    listaDeTransacoes.push_back(transacao);

    std::cout << "Transferencia de R$" << valor << " realizado para a conta " << conta->getNumeroConta() << std::endl;
  }

  void info() {
    std::cout << "============================================" << std::endl;
    std::cout << "Tipo de conta: Corrente Comum" << std::endl;
    std::cout << "Numero da conta: " << numeroConta << std::endl;
    std::cout << "Nome do cliente: " << correntista->getNome() << std::endl;
    std::cout << "Saldo: " << saldo << std::endl;
    std::cout << "============================================" << std::endl;
  }

  void basicInfo() {
    std::cout << "Tipo de conta: Corrente Comum" << std::endl;
    std::cout << "Numero da conta: " << numeroConta << std::endl;
    std::cout << "Nome do cliente: " << correntista->getNome() << std::endl;
  }

  virtual std::string getTipoConta() {
    return "ContaCorrente";
  }

  virtual void extrato() {
    std::cout << "============================================" << std::endl;
    std::cout << "Tipo de conta: Corrente Comum" << std::endl;
    std::cout << "Numero da conta: " << numeroConta << std::endl;
    std::cout << "Nome do cliente: " << correntista->getNome() << std::endl;
    std::cout << "Saldo: " << saldo << std::endl;
    std::cout << "---------------- Transacoes ----------------" << std::endl;

    int limite = listaDeTransacoes.size() <= 30 ? listaDeTransacoes.size() : 30;
    for (int i = 0; i < limite; i++) {
      std::cout << "Num.Transacao: " << i << std::endl;
      std::cout << "Descricao: " << listaDeTransacoes[i].descricao << std::endl;
      std::cout << "Valor: " << listaDeTransacoes[i].valor << std::endl;
      std::cout << "Data: " << listaDeTransacoes[i].data;
      if (listaDeTransacoes[i].descricao == "Transferencia") {
        std::cout << "Conta destino: " << listaDeTransacoes[i].contaDestino << std::endl;
      }
      std::cout << "--------------------------------------------" << std::endl;
    }

    std::cout << "============================================" << std::endl;
  };
};

#endif