#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <iostream>

typedef struct {
  std::string data;
  double valor;
  std::string descricao;
  std::string contaDestino;
} Transacao;

#endif