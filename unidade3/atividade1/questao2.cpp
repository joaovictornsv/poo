#include <iostream>

using std::cout;
using std::fixed;
using std::endl;

int main() {
  double num = 100.453627;

  cout << fixed;
  
  cout.precision(1);
  cout << num << endl;

  cout.precision(2);
  cout << num << endl;

  cout.precision(3);
  cout << num << endl;

  cout.precision(4);
  cout << num << endl;

  return 0;
}