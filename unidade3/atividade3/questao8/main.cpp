#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "Pilha.h"

int main() {
  //Pilha de inteiros
  cout << ">> Pilha de inteiros" << endl;
  Pilha<int> pi(3);
  int popEli = 1;
  pi.pop(popEli);
  pi.push(10);
  pi.push(10);
  pi.push(10);
  pi.push(10);

  //Pilha de doubles
  cout << ">> Pilha de doubles" << endl;
  Pilha<double> pd(3);
  double popEld;
  pd.pop(popEld);
  pd.push(10.0);
  pd.push(10.0);
  pd.push(10.0);
  pd.push(10.0);

  //Pilha de string
  cout << ">> Pilha de string" << endl;
  Pilha<string> ps(3);
  string popEls;
  ps.pop(popEls);
  ps.push("str1");
  ps.push("str1");
  ps.push("str1");
  ps.push("str1");
  return 0;
}