#ifndef CONTA_JA_EXISTE_H
#define CONTA_JA_EXISTE_H

#include <stdexcept>

class ContaJaExiste : public std::runtime_error
{
public:
  ContaJaExiste(const char *e="Já existe uma conta com esse número"): runtime_error(e) {}
};

#endif