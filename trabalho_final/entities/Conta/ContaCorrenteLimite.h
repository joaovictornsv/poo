#ifndef CONTA_CORRENTE_LIMITE_H
#define CONTA_CORRENTE_LIMITE_H
#include <iostream>

#include "Conta.h"
#include "../Pessoa/Pessoa.h"
#include "../../exceptions/ExcedeLimite.h"

class ContaCorrenteLimite: public Conta
{
public:
  ContaCorrenteLimite(Pessoa* _correntista, std::string _numeroConta, double _saldo, double _limite)
  : Conta(_correntista, _numeroConta, _saldo) {
    limite = _limite;
  }

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
    if ((saldo - valor) < (limite * -1)) throw ExcedeLimite();

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
    if ((saldo - valor) < (limite * -1)) throw ExcedeLimite();

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

  virtual std::string getTipoConta() {
    return "ContaCorrenteLimite";
  }

  void info() {
    std::cout << "============================================" << std::endl;
    std::cout << "Tipo de conta: Corrente com Limite" << std::endl;
    std::cout << "Numero da conta: " << numeroConta << std::endl;
    std::cout << "Nome do cliente: " << correntista->getNome() << std::endl;
    std::cout << "Saldo: " << saldo << std::endl;
    std::cout << "Limite: " << limite << std::endl;
    std::cout << "============================================" << std::endl;
  }

  void basicInfo() {
    std::cout << "Tipo de conta: Corrente com Limite" << std::endl;
    std::cout << "Numero da conta: " << numeroConta << std::endl;
    std::cout << "Nome do cliente: " << correntista->getNome() << std::endl;
  }

  virtual void extrato() {
    std::cout << "============================================" << std::endl;
    std::cout << "Tipo de conta: Corrente com Limite" << std::endl;
    std::cout << "Numero da conta: " << numeroConta << std::endl;
    std::cout << "Nome do cliente: " << correntista->getNome() << std::endl;
    std::cout << "Saldo: " << saldo << std::endl;
    std::cout << "Limite: " << limite << std::endl;
    std::cout << "---------------- Transacoes ----------------" << std::endl;
    int limite = listaDeTransacoes.size() <= 30 ? listaDeTransacoes.size() : 30;
    for (int i = 0; i < limite; i++) {
      std::cout << "Num.Transacao: " << i << std::endl;
      std::cout << "Descricao: " << listaDeTransacoes[i].descricao << std::endl;
      std::cout << "Valor: " << listaDeTransacoes[i].valor << std::endl;
      std::cout << "Data: " << listaDeTransacoes[i].data << std::endl;
      if (listaDeTransacoes[i].descricao == "Transferencia") {
        std::cout << "Conta destino: " << listaDeTransacoes[i].contaDestino << std::endl;
      }
      std::cout << "--------------------------------------------" << std::endl;
    }

    std::cout << "============================================" << std::endl;
  };

  virtual void registrar() {
    std::fstream file("./database/contas.txt", std::ios::out | std::ios::in | std::ios::app);

    std::string delimiter = ";";
    std::string data = ID_C+delimiter+ID_CCL+delimiter+getCorrentista()->getNome()+delimiter+getNumeroConta()+delimiter+std::to_string(getSaldo())+
    delimiter+std::to_string(limite);
    
    file << data << std::endl;
  }

private:
  double limite;
};

#endif