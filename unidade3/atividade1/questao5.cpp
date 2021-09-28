#include <iostream>
using std::cout;
using std::endl;


#include <iomanip>
using std::setw;

int main() {
  for(int i = 33; i <= 126; i++) {
    char c = i;
    cout << "| " << setw(3) << i << " | " << setw(3) << c << " |" << endl;
  }
  return 0;
}