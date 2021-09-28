#include <iostream>
#include <string>

using namespace std;

void temMaiuscula(const string &palavra) {
  
  bool tem = false;
  char z;

  for(int i = 0; i < palavra.length(); i++) {
    z = toupper(palavra[i]);
    if (palavra[i] == z) {
      tem = true;
      break;
    }
  }

  if (tem) cout << "A palavra CONTÉM letras maiúsculas" << endl;
  else cout << "A palavra NÃO contém letras maiúsculas" << endl;
  
}


int main() {
  string nomeSemMaiusculas = "nome";
  string nomeComMaiusculas = "NoMe";

  temMaiuscula(nomeSemMaiusculas);
  temMaiuscula(nomeComMaiusculas);

  return 0;
}