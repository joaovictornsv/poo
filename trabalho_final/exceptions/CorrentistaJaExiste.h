#ifndef CORRENTISTA_JA_EXISTE_H
#define CORRENTISTA_JA_EXISTE_H

#include <stdexcept>

class CorrentistaJaExiste : public std::runtime_error
{
public:
  CorrentistaJaExiste(const char *e="Correntista já cadastrado"): runtime_error(e) {}
};

#endif