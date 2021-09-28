#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "Array.h"

int main() {
  // Int
  cout << ">> Tipo:  int" << endl;
  Array<int> a1(5);
  cout << "lendo array: ";
  cin >> a1; 
  cout << "escrevendo array: ";
  cout << a1;  

  a1[3] = 100; 

  cout << "a1[3] == " << a1[3] << endl;
  cout << "escrevendo array: ";
  cout << a1;  
  cout << "=======================================" << endl;

  cout << ">> Tipo:  double" << endl;
  Array<double> a2(5);
  cout << "lendo array: ";
  cin >> a2; 
  cout << "escrevendo array: ";
  cout << a2;  

  a2[3] = 10.1; 

  cout << "a2[3] == " << a2[3] << endl;
  cout << "escrevendo array: ";
  cout << a2;  
  cout << "=======================================" << endl;

  cout << ">> Tipo:  char" << endl;
  Array<char> a3(5);
  cout << "lendo array: ";
  cin >> a3; 
  cout << "escrevendo array: ";
  cout << a3;  

  a3[3] = 'a'; 

  cout << "a3[3] == " << a3[3] << endl;
  cout << "escrevendo array: ";
  cout << a3;  
  cout << "=======================================" << endl;

 
  return 0;
}