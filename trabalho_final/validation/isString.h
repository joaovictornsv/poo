#include <iostream>

bool isString(std::string valor) {
  int nums[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

  bool valid = true;
  for (int i = 0; i < valor.size(); i++) {
    char c = valor[i];

    for (int j = 0; j < 10; j++) {
      if (c == nums[j]) {
        valid = false;
        break;
      }
    }

    if (!valid) {
      break;
    }
  }
  return valid;
}