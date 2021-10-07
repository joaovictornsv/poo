#ifndef EXCEDE_LIMITE_H
#define EXCEDE_LIMITE_H

#include <stdexcept>

class ExcedeLimite : public std::runtime_error
{
public:
  ExcedeLimite(const char *e="Limite da conta excedido"): runtime_error(e) {}
};

#endif