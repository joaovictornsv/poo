#ifndef CONTA_NAO_EXISTE_H
#define CONTA_NAO_EXISTE_H

#include <stdexcept>

class ContaNaoExiste : public std::runtime_error
{
public:
  ContaNaoExiste(const char *e="Operação inválida. Não existe uma conta com esse número"): runtime_error(e) {}
};

#endif