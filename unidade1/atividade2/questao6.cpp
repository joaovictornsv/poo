#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using std::string;
using std::cin;
using std::cout;
using std::endl;


int main() {
  string str, str2 = "";

  cout << "Entrada: ";
  getline(cin, str);
  for(char c: str) {
    if (c != '.' && c != ',' && c != '!' && c != '?' && c != '-') {
      str2 += c;
    }
  };

  cout << "Saída: " << str2 << endl;
  return 0;
}