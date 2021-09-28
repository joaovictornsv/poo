#include <iostream>

using std::cout;
using std::endl;
using std::string;

template<class T>
bool saoIguais(T a, T b) {
  if (a == b) return true;
  return false;
};

int main() {
  // Int
  cout << "int" << endl;
  cout << ">> 1 == 1 : " << saoIguais<int>(1, 1) << endl;
  cout << ">> 1 == 2 : " << saoIguais<int>(1, 2) << endl;

  cout << "char" << endl;
  cout << ">> a == a : " << saoIguais<char>('a', 'a') << endl;
  cout << ">> a == b : " << saoIguais<char>('a', 'b') << endl;

  cout << "double" << endl;
  cout << ">> 1.1 == 1.1 : " << saoIguais<double>(1.1, 1.1) << endl;
  cout << ">> 1.1 == 2.1 : " << saoIguais<double>(1.1, 2.1) << endl;

  cout << "string" << endl;
  cout << ">> abc == abc : " << saoIguais<string>("abc", "abc") << endl;
  cout << ">> abc == def : " << saoIguais<string>("abc", "def") << endl;
  

  return 0;
}