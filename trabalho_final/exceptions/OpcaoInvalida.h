#ifndef OPCAO_INVALIDA_H
#define OPCAO_INVALIDA_H

#include <stdexcept>

class OpcaoInvalida : public std::runtime_error
{
public:
  OpcaoInvalida(const char *e="Opção Inválida, tente novamente."): runtime_error(e) {}
};

#endif