#ifndef UNAUTHORIZED_H
#define UNAUTHORIZED_H

#include <stdexcept>

class Unauthorized : public std::runtime_error
{
public:
  Unauthorized(const char *e="Request return with code 401 (Unauthorized)"): runtime_error(e) {}
};

#endif