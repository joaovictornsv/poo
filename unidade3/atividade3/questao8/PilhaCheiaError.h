#ifndef PILHA_CHEIA_ERROR_H
#define PILHA_CHEIA_ERROR_H

#include <stdexcept>

class pilha_cheia_error : public std::out_of_range
{
public:
  pilha_cheia_error(const char *e="Impossivel adicionar. Pilha cheia."): out_of_range(e) {}
};

#endif