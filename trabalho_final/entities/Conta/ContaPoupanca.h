#ifndef CONTA_POUPANCA_H
#define CONTA_POUPANCA_H
#include <iostream>
#include "../Pessoa/Pessoa.h"

#include "Conta.h"

#include "../../exceptions/SaldoInsuficiente.h"

class ContaPoupanca: public Conta
{
public:
  ContaPoupanca(Pessoa* _correntista, std::string _numeroConta, double _saldo, std::string _chavePix, std::string _aniversarioConta)
  : Conta(_correntista, _numeroConta, _saldo, _chavePix) {
    aniversarioConta = _aniversarioConta;
  }

  // Deposito
  virtual void operator<<(double valor) {
    deletar();
    saldo += valor;
    registrar();

    Transacao transacao;
    transacao.valor = valor;
    transacao.descricao = DEPOSITO;

    time_t now = time(0);

    std::string date_time = ctime(&now);

    transacao.data = date_time;
    listaDeTransacoes.push_back(transacao);
    registrarTransacao(transacao);
    std::cout << "Deposito de R$" << valor << " realizado." << std::endl;

  }

  // Retirada
  virtual void operator>>(double valor) {
    if ((saldo - valor) < 0) throw SaldoInsuficiente();

    deletar();
    saldo -= valor;
    registrar();

    Transacao transacao;

    transacao.valor = valor;
    transacao.descricao = SAQUE;

    time_t now = time(0);
    std::string date_time = ctime(&now);

    transacao.data = date_time;
    listaDeTransacoes.push_back(transacao);
    registrarTransacao(transacao);

    std::cout << "Saque de R$" << valor << " realizado." << std::endl;  
  }

  // Transferencia
  virtual void transferir(double valor, Conta* conta) {
    if ((saldo - valor) < 0) throw SaldoInsuficiente();
    deletar();
    *conta << valor;
    saldo -= valor;
    registrar();

    Transacao transacao;

    transacao.valor = valor;
    transacao.descricao = TRANSFERENCIA;
    transacao.contaDestino = conta->getNumeroConta();

    time_t now = time(0);
    std::string date_time = ctime(&now);

    transacao.data = date_time;
    listaDeTransacoes.push_back(transacao);
    registrarTransacao(transacao);

    std::cout << "Transferencia de R$" << valor << " realizado para a conta " << conta->getNumeroConta() << std::endl;
  }
 
  void info() {
    std::cout << "============================================" << std::endl;
    std::cout << "Tipo de conta: Poupanca" << std::endl;
    std::cout << "Numero da conta: " << numeroConta << std::endl;
    std::cout << "Nome do cliente: " << correntista->getNome() << std::endl;
    std::cout << "Saldo: " << saldo << std::endl;
    std::cout << "Chave PIX: " << chavePix << std::endl;
    std::cout << "Aniversario da conta: " << aniversarioConta << std::endl;
    std::cout << "============================================" << std::endl;
  }

  void basicInfo() {
    std::cout << "Tipo de conta: Poupanca" << std::endl;
    std::cout << "Numero da conta: " << numeroConta << std::endl;
    std::cout << "Nome do cliente: " << correntista->getNome() << std::endl;
    std::cout << "Chave PIX: " << chavePix << std::endl;
  }

  virtual void extrato() {
    std::cout << "============================================" << std::endl;
    std::cout << "Tipo de conta: Poupanca" << std::endl;
    std::cout << "Numero da conta: " << numeroConta << std::endl;
    std::cout << "Nome do cliente: " << correntista->getNome() << std::endl;
    std::cout << "Saldo: " << saldo << std::endl;
    std::cout << "Chave PIX: " << chavePix << std::endl;
    std::cout << "Aniversario da conta: " << aniversarioConta << std::endl;
    std::cout << "---------------- Transacoes ----------------" << std::endl;
    int limite = listaDeTransacoes.size() <= 30 ? listaDeTransacoes.size() : 30;
    for (int i = 0; i < limite; i++) {
      std::cout << "Num.Transacao: " << i << std::endl;
      std::cout << "Descricao: " << listaDeTransacoes[i].descricao << std::endl;
      std::cout << "Valor: " << listaDeTransacoes[i].valor << std::endl;
      std::cout << "Data: " << listaDeTransacoes[i].data << std::endl;
      if (listaDeTransacoes[i].descricao == TRANSFERENCIA) {
        std::cout << "Conta destino: " << listaDeTransacoes[i].contaDestino << std::endl;
      }
      std::cout << "--------------------------------------------" << std::endl;
    }

    std::cout << "============================================" << std::endl;
  };

  virtual void registrar() {
    std::fstream file(FILE_PATH, std::ios::out | std::ios::in | std::ios::app);

    std::string delimiter = ";";
    std::string data = ID_C+delimiter+ID_CCL+delimiter+getCorrentista()->getNome()+delimiter+getNumeroConta()+delimiter+std::to_string(getSaldo())+delimiter+chavePix+delimiter+aniversarioConta;

    file << data << std::endl;
  }

  virtual std::string getLineFormat() {
    std::string delimiter = ";";
    std::string data = ID_C+delimiter+ID_CCL+delimiter+getCorrentista()->getNome()+delimiter+getNumeroConta()+delimiter+std::to_string(getSaldo())+delimiter+chavePix+delimiter+aniversarioConta;
    return data;
  }

  virtual void deletar() {
    std::ifstream file(FILE_PATH);
    std::ofstream tempFile(TEMP_FILE_PATH);

    std::string output;
    while (std::getline (file, output)) {
      if (output != getLineFormat()) {
        tempFile << output << std::endl;
      }
    }

    file.close();
    tempFile.close();
    remove(FILE_PATH);
    rename(TEMP_FILE_PATH, FILE_PATH);
  }

private:
  std::string aniversarioConta;
};

#endif