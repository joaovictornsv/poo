#ifndef NOT_FOUND_H
#define NOT_FOUND_H

#include <stdexcept>

class NotFound : public std::runtime_error
{
public:
  NotFound(const char *e="Request return with code 404 (Not Found)"): runtime_error(e) {}
};

#endif