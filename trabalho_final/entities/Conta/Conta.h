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
  Conta(Pessoa* _correntista, std::string _numeroConta, double _saldo, std::string _chavePix) {
    correntista = _correntista;
    numeroConta = _numeroConta;
    chavePix = _chavePix;
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
  virtual void deletar() = 0;
  virtual std::string getLineFormat() = 0;

  std::string getNumeroConta() { return numeroConta; };
  Pessoa* getCorrentista() { return correntista; };

  void setChavePix(std::string novaChave) { chavePix = novaChave; };
  std::string getChavePix() { return chavePix; };

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

  void registrarTransacoes(std::ofstream* file) {
    for (int i = 0; i < listaDeTransacoes.size(); i++) {

      Transacao transacao = listaDeTransacoes[i];
      std::string data = transacao.data;
      for (int c = 0; c < data.length(); c++) {
        if (data[c] == '\n') {
          data.replace(data.find("\n"), 1, "");
        }
      }
      double valor = transacao.valor;
      std::string descricao = transacao.descricao;
      std::string contaDestino;

      std::string registro;
      if (descricao == TRANSFERENCIA) {
        contaDestino = transacao.contaDestino;
        std::string delimiter = ";";
        registro = ID_T+delimiter+numeroConta+delimiter+data+delimiter+std::to_string(valor)+delimiter+descricao+delimiter+contaDestino;
      } else {
        std::string delimiter = ";";
        registro = ID_T+delimiter+numeroConta+delimiter+data+delimiter+std::to_string(valor)+delimiter+descricao;
      }
        
      (*file) << registro << std::endl;
    }
    // (*file).close();
  }

  void registrarTransacao(Transacao transacao) {
    std::fstream file(FILE_PATH, std::ios::out | std::ios::in | std::ios::app);

    std::string data = transacao.data;
    data.replace(data.find("\n"), 1, "");
    double valor = transacao.valor;
    std::string descricao = transacao.descricao;
    std::string contaDestino;

    std::string registro;
    if (descricao == TRANSFERENCIA) {
      contaDestino = transacao.contaDestino;
      std::string delimiter = ";";
      registro = ID_T+delimiter+numeroConta+delimiter+data+delimiter+std::to_string(valor)+delimiter+descricao+delimiter+contaDestino;
    } else {
      std::string delimiter = ";";
      registro = ID_T+delimiter+numeroConta+delimiter+data+delimiter+std::to_string(valor)+delimiter+descricao;
    }
        
    file << registro << std::endl;
    file.close();
  }

  vector<Transacao> getListaTransacoes() { return listaDeTransacoes; };
  
protected:
  double saldo;
  std::string numeroConta;
  std::string chavePix;
  Pessoa* correntista;
  vector<Transacao> listaDeTransacoes;
};

#endif