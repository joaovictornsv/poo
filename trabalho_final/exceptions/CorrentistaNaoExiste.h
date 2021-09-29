#ifndef CORRENTISTA_NAO_EXISTE_H
#define CORRENTISTA_NAO_EXISTE_H

#include <stdexcept>

class CorrentistaNaoExiste : public std::runtime_error
{
public:
  CorrentistaNaoExiste(const char *e="Operação inválida. Correntista não encontrado, tente cadastrar um novo"): runtime_error(e) {}
};

#endif