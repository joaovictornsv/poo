#ifndef FILA_H
#define FILA_H

#include <iostream>
using std::ostream;
using std::istream;

template <class T>
class Fila
{
public:
  Fila();
  ~Fila();

  int getTamanhoDaFila() const;

  void desenfileira();
  void enfileira(T value);

  void mostrarFila();


private:
  int tam;
  T *fila;
};


template<class T>
Fila<T>::Fila()
{
  this->tam = 0;

  this->fila = new T[10];
}

template<class T>
Fila<T>::~Fila<T>()
{
  delete [] fila;
}

template<class T>
int Fila<T>::getTamanhoDaFila() const
{
  return tam;
}

template<class T>
void Fila<T>::desenfileira() {
  if (tam == 0) {
    std::cout << "Impossivel desenfileirar, fila vazia!" << std::endl;
  }
  else {
    T aux = this->fila[0];
    for(int i = 0; i < tam-1; i++) {
      this->fila[i] = this->fila[i+1];
    }
    this->tam -= 1;

    std::cout << "Valor " << aux << " desenfileirado." << std::endl;
  }
};

template<class T>
void Fila<T>::enfileira(T value) {
  if (tam == 10) {
    std::cout << "Impossivel enfileirar, fila cheia!" << std::endl;
    return;
  }
  else {
    this->fila[tam] = value;
    this->tam += 1;

    std::cout << "Valor " << value << " enfileirado." << std::endl;
  }
};


template<class T>
void Fila<T>::mostrarFila() {
  if (tam == 0) {
    std::cout << "Fila vazia!" << std::endl;
    return;
  }
  else {
    std::cout << "Fila: [ ";
    for(int i = 0; i < tam; i++) {
      if (i == tam-1)
        std::cout << this->fila[i];
      else
        std::cout << this->fila[i] << " - ";

    }
    std::cout << " ]" << std::endl;
  }
};

#endif