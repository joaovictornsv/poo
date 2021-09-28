#ifndef BAD_REQUEST_H
#define BAD_REQUEST_H

#include <stdexcept>

class BadRequest : public std::runtime_error
{
public:
  BadRequest(const char *e="Request return with code 400 (Bad Request)"): runtime_error(e) {}
};

#endif