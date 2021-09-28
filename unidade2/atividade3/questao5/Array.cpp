#include <iostream>
using std::cerr;
using std::endl;

#include "Array.h"

ostream &operator<<(ostream &out , const Array & a)
{
  for (int i = 0 ; i < a.tam ; i++)
    out << a.arr[i] << " ";
  
  out << endl;

  return out;
}

istream &operator>>(istream &inp, Array & a)
{
  for (int i = 0 ; i < a.tam ; i++)
    inp >> a.arr[i];
  
  return inp;
}

Array::Array(int tam)
{
  this->tam = (tam > 0 ? tam : 10);

  arr = new int[this->tam];

  for (int i = 0 ; i < this->tam ; i++)
    arr[i] = 0;
}

Array::Array(const Array &obj) : tam(obj.tam)
{
  arr = new int[this->tam];

  for (int i = 0 ; i < this->tam ; i++)
    arr[i] = obj.arr[i];
}

Array::~Array()
{
  delete [] arr;
}

int Array::getSize() const
{
  return tam;
}

const Array &Array::operator=(const Array &obj)
{
  if (&obj != this) // evita auto-atribuição
  {
    if (this->tam != obj.tam)
    {
      delete [] this->arr;
      this->tam = obj.tam;
      this->arr = new int[this->tam];
    }

    for (int i = 0 ; i < this->tam ; i++)
      arr[i] = obj.arr[i];

  }

  return *this;
}

bool Array::operator==(const Array &obj) const
{
  if (this->tam != obj.tam)
    return false;

  for (int i = 0 ; i < this->tam ; i++)
    if (arr[i] != obj.arr[i])
      return false;
  
  return true;
}

int &Array::operator[](int i)
{
  if (i < 0 || i >= tam)
  {
    cerr << "Erro: Indice " << i << " fora de faixa." << endl;

    exit(1);
  }

  return arr[i];
}

int Array::operator[](int i) const
{
  if (i < 0 || i >= tam)
  {
    cerr << "Erro: Indice " << i << " fora de faixa." << endl;

    exit(1);
  }

  return arr[i];
}

const Array &Array::operator+(const Array &obj) {
  int tamanho_total = this->getSize() + obj.getSize();

  Array *novo_array = new Array(tamanho_total);
     
  for (int i = 0; i < this->getSize(); i++) {
    novo_array->arr[i] = this->arr[i];
  }

  for (int j = 0; j < obj.getSize(); j++) {
    novo_array->arr[j + this->getSize()] = obj.arr[j];
  }

  return *novo_array;
};


void Array::operator+=(const Array &obj) {
  int tamanho_total = this->getSize() + obj.getSize();

  Array aux = *this;

  delete [] this->arr;
  this->tam = tamanho_total;
  this->arr = new int[tamanho_total];

  for (int i = 0; i < aux.getSize(); i++) {
    this->arr[i] = aux.arr[i];
  }

  for (int j = 0; j < obj.getSize(); j++) {
    this->arr[j + aux.getSize()] = obj.arr[j];
  }

};