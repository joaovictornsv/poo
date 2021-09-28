#ifndef FILA_VAZIA_ERROR_H
#define FILA_VAZIA_ERROR_H

#include <stdexcept>

class fila_vazia_error : public std::out_of_range
{
public:
  fila_vazia_error(const char *e="Fila vazia."): out_of_range(e) {}
};

#endif