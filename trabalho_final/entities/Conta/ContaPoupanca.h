#ifndef CONTA_POUPANCA_H
#define CONTA_POUPANCA_H
#include <iostream>
#include "../Pessoa/Pessoa.h"

#include "Conta.h"

#include "../../exceptions/SaldoInsuficiente.h"

class ContaPoupanca: public Conta
{
public:
  ContaPoupanca(Pessoa* _correntista, std::string _numeroConta, double _saldo, std::string _aniversarioConta)
  : Conta(_correntista, _numeroConta, _saldo) {
    aniversarioConta = _aniversarioConta;
  }

  // Deposito
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
    try {
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
    } catch(std::runtime_error &e) {
      std::cerr << e.what() << std::endl;
    }
    
  }

  // Transferencia
  virtual void transferir(double valor, Conta* conta) {
    try {
      if ((saldo - valor) < 0) throw SaldoInsuficiente();

      *conta << valor;
      *this >> valor;

      Transacao transacao;

      transacao.valor = valor;
      transacao.descricao = "Transferencia";
      transacao.contaDestino = conta->numeroConta;

      time_t now = time(0);
      std::string date_time = ctime(&now);

      transacao.data = date_time;
      listaDeTransacoes.push_back(transacao);

      std::cout << "Transferencia de R$" << valor << " realizado para a conta " << conta->numeroConta << std::endl;

    } catch(std::runtime_error &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  
  virtual void extrato() {
    std::cout << "============================================" << std::endl;
    std::cout << "Tipo de conta: Corrente com Limite" << std::endl;
    std::cout << "Numero da conta: " << numeroConta << std::endl;
    std::cout << "Nome do cliente: " << correntista->getNome() << std::endl;
    std::cout << "Saldo: " << saldo << std::endl;
    std::cout << "Aniversario da conta: " << aniversarioConta << std::endl;
    std::cout << "---------------- Transacoes ----------------" << std::endl;
    int limite = listaDeTransacoes.size() <= 30 ? listaDeTransacoes.size() : 30;
    for (int i = 0; i < limite; i++) {
      std::cout << "Num.Transacao: " << i << std::endl;
      std::cout << "Descricao: " << listaDeTransacoes[i].descricao << std::endl;
      std::cout << "Valor: " << listaDeTransacoes[i].valor << std::endl;
      std::cout << "Data: " << listaDeTransacoes[i].data;
      if (listaDeTransacoes[i].descricao == "Transferencia") {
        std::cout << "Conta destino: " << listaDeTransacoes[i].contaDestino;
      }
      std::cout << "--------------------------------------------" << std::endl;
    }

    std::cout << "============================================" << std::endl;
  };

private:
  std::string aniversarioConta;
};

#endif