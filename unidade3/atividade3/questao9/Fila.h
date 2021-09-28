#ifndef FILA_H
#define FILA_H

#include <iostream>
using std::ostream;
using std::istream;

#include "FilaCheiaError.h"
#include "FilaVaziaError.h"

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
  try {
    if (tam == 0) {
      throw fila_vazia_error();
    }
    else {
      T aux = this->fila[0];
      for(int i = 0; i < tam-1; i++) {
        this->fila[i] = this->fila[i+1];
      }
      this->tam -= 1;

      std::cout << "Valor " << aux << " desenfileirado." << std::endl;
    }
  } catch(std::out_of_range &e) {
    std::cerr << "Impossivel remover. " << e.what() << std::endl;
  }
};

template<class T>
void Fila<T>::enfileira(T value) {
  try {
    if (tam == 3) {
      throw fila_cheia_error();
    }
    else {
      this->fila[tam] = value;
      this->tam += 1;

      std::cout << "Valor " << value << " enfileirado." << std::endl;
    }
  } catch(std::out_of_range &e) {
    std::cerr << e.what() << std::endl;
  }
};


template<class T>
void Fila<T>::mostrarFila() {
  try {
    if (tam == 0) {
      throw fila_vazia_error();
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
  } catch(std::out_of_range &e) {
    std::cerr << e.what() << std::endl;
  }
  
};

#endif