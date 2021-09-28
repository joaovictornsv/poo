#include <iostream>
#include "IntegerSet.h"

using std::cout;
using std::endl;

int main() {
  IntegerSet set1;
  set1 << 1;
  set1 << 2;
  set1 << 3;

  cout << "Set1: ";
  cout << set1;

  IntegerSet set2;
  set2 << 3;
  set2 << 4;
  set2 << 5;

  cout << "Set2: ";
  cout << set2;

  IntegerSet set1_union_set2 = set1 | set2;
  IntegerSet set1_intersection_set2 = set1 & set2;

  cout << "Set1 union Set2: ";
  cout << set1_union_set2;

  cout << "Set1 intersection Set2: ";
  cout << set1_intersection_set2;

  cout << endl << " > Removendo elemento 5 do Set 2" << endl;
  set2 >> 5;

  cout << "Set2: ";
  cout << set2;

  return 0;
}