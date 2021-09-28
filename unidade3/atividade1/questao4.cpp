#include <iostream>
using std::cout;
using std::endl;


#include <iomanip>
using std::setw;

int main() {
  cout << "|" << setw(11) << "Fahrenheit" << "|" << setw(11) << "Celsius" << "|" << endl;
  for(int i = 0; i <= 212; i++) {
    double celsius = 5.0 / 9.0 * (i - 32);
    cout.precision(3);
    cout << "|" << setw(10) << i << "F" << "|" << setw(10) << celsius << "C" << "|" << endl;
  }
  return 0;
}