#ifndef INTEGER_SET_H
#define INTEGER_SET_H

class IntegerSet
{
public:
  IntegerSet();
  IntegerSet(int _conjunto[], int tamanho);

  void insertElement(int elemento);
  void deleteElement(int elemento);

  void print();

  friend IntegerSet unionOfSets(IntegerSet set1, IntegerSet set2);
  friend IntegerSet intersectionOfSets(IntegerSet set1, IntegerSet set2);
  
  int conjunto[100];
};


#endif