#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using std::ostream;
using std::istream;

template <class T>
class Array
{
  // cout << obj
  friend ostream &operator<<(ostream &out , const Array<T> & a)
  {
    for (int i = 0 ; i < a.tam ; i++)
      out << a.arr[i] << " ";
    
    out << std::endl;

    return out;
  }
  

  // cin >> obj
  friend istream &operator>>(istream &inp, Array<T> & a)
  {
    for (int i = 0 ; i < a.tam ; i++)
      inp >> a.arr[i];
    
    return inp;
  }
public:
  Array( int = 10 );    //construtor-padrão
  Array(const Array<T> &); //construtor de cópia
  ~Array();             //destrutor

  int getSize() const;

  
  const Array &operator=( const Array<T> & ); //operador atribuição. "const Array &" evita algo como (a = b) = c

  bool operator==( const Array & ) const; //operador de igualdade

  bool operator!=( const Array &dir) const
  {
    return !(*this == dir);
  }

  T &operator[](int); //permite modificar o elemento
  T operator[](int) const; //não permite modificar o elemento

private:
  int tam;
  T *arr;
};


template<class T>
Array<T>::Array(int tam)
{
  this->tam = (tam > 0 ? tam : 10);

  arr = new T[this->tam];

  for (int i = 0 ; i < this->tam ; i++)
    arr[i] = 0;
}
template<class T>
Array<T>::Array(const Array<T> &obj) : tam(obj.tam)
{
  arr = new T[this->tam];

  for (int i = 0 ; i < this->tam ; i++)
    arr[i] = obj.arr[i];
}
template<class T>
Array<T>::~Array<T>()
{
  delete [] arr;
}
template<class T>
int Array<T>::getSize() const
{
  return tam;
}
template<class T>
const Array<T> &Array<T>::operator=(const Array<T> &obj)
{
  if (&obj != this) // evita auto-atribuição
  {
    if (this->tam != obj.tam)
    {
      delete [] this->arr;
      this->tam = obj.tam;
      this->arr = new T[this->tam];
    }

    for (int i = 0 ; i < this->tam ; i++)
      arr[i] = obj.arr[i];

  }

  return *this;
}
template<class T>
bool Array<T>::operator==(const Array &obj) const
{
  if (this->tam != obj.tam)
    return false;

  for (int i = 0 ; i < this->tam ; i++)
    if (arr[i] != obj.arr[i])
      return false;
  
  return true;
}
template<class T>
T &Array<T>::operator[](int i)
{
  if (i < 0 || i >= tam)
  {
    std::cerr << "Erro: Indice " << i << " fora de faixa." << std::endl;

    exit(1);
  }

  return arr[i];
}
template<class T>
T Array<T>::operator[](int i) const
{
  if (i < 0 || i >= tam)
  {
    std::cerr << "Erro: Indice " << i << " fora de faixa." << std::endl;

    exit(1);
  }

  return arr[i];
};

#endif