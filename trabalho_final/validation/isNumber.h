#include <iostream>

bool isNumber(std::string valor) {
  int nums[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

  bool allValid = true;
  for (int i = 0; i < valor.size(); i++) {
    bool valid = false;
    char c = valor[i];

    for (int j = 0; j < 10; j++) {
      if (c == nums[j]) {
        valid = true;
        break;
      }
    }

    if(!valid) {
      allValid = false;
      break;
    }
  }
  return allValid;
}