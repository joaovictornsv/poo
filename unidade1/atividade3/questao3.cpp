#include <iostream>

using namespace std;

int nums() {
  static int x = 0;

  return x++;
}

int main()
{
  cout << nums() << endl;
  cout << nums() << endl;
  cout << nums() << endl;
  cout << nums() << endl;
  cout << nums() << endl;
  cout << nums() << endl;

 return 0;
}
