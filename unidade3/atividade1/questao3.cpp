#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

int main() {
  std::string str;

  cin >> str;

  cout << setw(str.size()*2) << str << endl;

  return 0;
}