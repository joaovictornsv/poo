#ifndef PRECISA_SER_NUMERO_H
#define PRECISA_SER_NUMERO_H

#include <stdexcept>

class PrecisaSerNumero : public std::runtime_error
{
public:
  PrecisaSerNumero(const char *e="Ester valor só permite numeros."): runtime_error(e) {}
};

#endif