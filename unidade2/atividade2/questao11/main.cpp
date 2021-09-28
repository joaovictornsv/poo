#include <iostream>
#include "IntegerSet.h"

using std::cout;
using std::endl;

int main() {
  IntegerSet set1;
  set1.insertElement(1);
  set1.insertElement(2);
  set1.insertElement(3);

  cout << "Set1: ";
  set1.print();

  IntegerSet set2;
  set2.insertElement(3);
  set2.insertElement(4);
  set2.insertElement(5);

  cout << "Set2: ";
  set2.print();

  IntegerSet set1_union_set2 = unionOfSets(set1, set2);
  IntegerSet set1_intersection_set2 = intersectionOfSets(set1, set2);

  cout << "Set1 union Set2: ";
  set1_union_set2.print();

  cout << "Set1 intersection Set2: ";
  set1_intersection_set2.print();

  cout << endl << " > Removendo elemento 5 do Set 2" << endl;
  set2.deleteElement(5);

  cout << "Set2: ";
  set2.print();

  return 0;
}