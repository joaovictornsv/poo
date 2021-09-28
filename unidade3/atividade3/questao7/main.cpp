#include <iostream>

#include <stdexcept>
#include "BadRequest.h"
#include "NotFound.h"
#include "Forbidden.h"
#include "Unauthorized.h"

int main() {
  
  try {
    throw BadRequest();
  } catch(std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    throw NotFound();
  } catch(std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    throw Unauthorized();
  } catch(std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
  }


  try {
    throw Forbidden();
  } catch(std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}