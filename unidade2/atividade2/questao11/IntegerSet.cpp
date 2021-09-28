#include "iostream"
#include "IntegerSet.h"
using std::cout;
using std::endl;

IntegerSet::IntegerSet() {
  for(int i=0; i < 100; i++) {
    conjunto[i] = 0;
  }
};

IntegerSet::IntegerSet(int array[], int tamanho) {
  for(int i=0; i < tamanho; i++) {
    conjunto[array[i]] = 1;
  }
};

void IntegerSet::insertElement(int elemento) {
  conjunto[elemento] = 1;
};
void IntegerSet::deleteElement(int elemento) {
  conjunto[elemento] = 0;

};

void IntegerSet::print() {
  for(int i=0; i < 100; i++) {
    if (conjunto[i] == 1) {
      cout << i << " ";
    }
  }
  cout << endl;
};

IntegerSet unionOfSets(IntegerSet set1, IntegerSet set2) {
  IntegerSet unionSet;

  for(int i=0; i < 100; i++) {
    if (set1.conjunto[i] == 1 || set2.conjunto[i] == 1) {
      unionSet.insertElement(i);
    }
  } 

  return unionSet;
};

IntegerSet intersectionOfSets(IntegerSet set1, IntegerSet set2) {
  IntegerSet intersectionSet;

  for(int i=0; i < 100; i++) {
    if (set1.conjunto[i] == 1 && set2.conjunto[i] == 1) {
      intersectionSet.insertElement(i);
    }
  } 

  return intersectionSet;
};