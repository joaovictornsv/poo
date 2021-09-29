#ifndef CONTA_NAO_EXISTE_H
#define CONTA_NAO_EXISTE_H

#include <iostream>
#include <stdexcept>

void ExceptionCatch(std::runtime_error &e) {
  std::cerr << e.what() << std::endl;
}

#endif
