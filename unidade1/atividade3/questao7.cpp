#include <iostream>
#include <string>

using namespace std;

void paraMaiscula(string &palavra) {
  
  bool tem = false;
  char z;

  for(int i = 0; i < palavra.length(); i++) {
    palavra[i] = toupper(palavra[i]);
  }
  
}


int main() {
  string nomeSemMaiusculas = "nome sem maiusculas";

  paraMaiscula(nomeSemMaiusculas);

  cout << nomeSemMaiusculas << endl;

  return 0;
}