#ifndef EXCEPTION_CATCH_H
#define EXCEPTION_CATCH_H

#include <iostream>
#include <stdexcept>

void ExceptionCatch(std::runtime_error &e) {
  std::cerr << "[ERROR]: " << e.what() << std::endl;
}

#endif
