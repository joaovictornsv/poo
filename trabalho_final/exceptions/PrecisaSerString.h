#ifndef PRECISA_SER_STRING_H
#define PRECISA_SER_STRING_H

#include <stdexcept>

class PrecisaSerString : public std::runtime_error
{
public:
  PrecisaSerString(const char *e="Ester valor só permite letras."): runtime_error(e) {}
};

#endif