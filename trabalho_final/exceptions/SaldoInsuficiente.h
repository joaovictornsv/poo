#ifndef SALDO_INSUFICIENTE_H
#define SALDO_INSUFICIENTE_H

#include <stdexcept>

class SaldoInsuficiente : public std::runtime_error
{
public:
  SaldoInsuficiente(const char *e="Operação inválida. Saldo insuficiente"): runtime_error(e) {}
};

#endif