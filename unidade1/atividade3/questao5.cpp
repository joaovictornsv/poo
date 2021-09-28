#include <iostream>

using namespace std;

void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}


int main() {
  int n1 = 111;
  int n2 = 222;

  cout << "N1: " << n1 << endl;
  cout << "N2: " << n2 << endl;

  swap(n1, n2);
  cout << "=== Swap (usando referências) ===" << endl;

  cout << "N1: " << n1 << endl;
  cout << "N2: " << n2 << endl;


  return 0;
}