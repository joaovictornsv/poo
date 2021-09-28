#ifndef FILA_CHEIA_ERROR_H
#define FILA_CHEIA_ERROR_H

#include <stdexcept>

class fila_cheia_error : public std::out_of_range
{
public:
  fila_cheia_error(const char *e="Impossivel adicionar. Fila cheia."): out_of_range(e) {}
};

#endif