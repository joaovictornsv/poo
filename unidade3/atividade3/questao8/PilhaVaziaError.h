#ifndef PILHA_VAZIA_ERROR_H
#define PILHA_VAZIA_ERROR_H

#include <stdexcept>

class pilha_vazia_error : public std::out_of_range
{
public:
  pilha_vazia_error(const char *e="Impossivel remover. Pilha vazia."): out_of_range(e) {}
};

#endif