#include <iostream>

using namespace std;

int main() {
  cout << "Letra a)" << endl;
  for(int i = 1; i < 6; i++) {
    for(int k = 0; k < i; k++) {
      cout << "*";
    }
    cout << endl;
  }

  cout << endl;

  cout << "Letra b)" << endl;
  for(int i = 5; i > 0; i--) {
    int k = 5 - i;
    for(int j = 0; j < k; j++) {
      cout << " ";
    }
    for(int j = 0; j < i; j++) {
      cout << "*";
    }
    cout << endl;
  }

  return 0;
}