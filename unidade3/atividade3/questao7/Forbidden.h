#ifndef FORBIDDEN_H
#define FORBIDDEN_H

#include <stdexcept>

class Forbidden : public std::runtime_error
{
public:
  Forbidden(const char *e="Request return with code 403 (Forbidden)"): runtime_error(e) {}
};

#endif