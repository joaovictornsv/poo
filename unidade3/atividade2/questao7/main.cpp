#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "Fila.h"

int main() {
  // Int
  cout << ">> Tipo: int" << endl;
  Fila<int> fila1;
  fila1.mostrarFila();
  cout << "Tamanho da fila: " << fila1.getTamanhoDaFila() << endl;;
  fila1.enfileira(1);
  fila1.enfileira(2);
  fila1.enfileira(5);
  fila1.enfileira(8);
  fila1.mostrarFila();
  cout << "Tamanho da fila: " << fila1.getTamanhoDaFila() << endl;;
  fila1.desenfileira();
  fila1.desenfileira();
  fila1.desenfileira();
  fila1.mostrarFila();
  cout << "=======================================" << endl;

  cout << ">> Tipo: double" << endl;
  Fila<double> fila2;
  fila2.mostrarFila();
  cout << "Tamanho da fila: " << fila2.getTamanhoDaFila() << endl;;
  fila2.enfileira(1.1);
  fila2.enfileira(2.1);
  fila2.enfileira(5.1);
  fila2.enfileira(8.1);
  fila2.mostrarFila();
  cout << "Tamanho da fila: " << fila2.getTamanhoDaFila() << endl;;
  fila2.desenfileira();
  fila2.desenfileira();
  fila2.desenfileira();
  fila2.mostrarFila();
  cout << "=======================================" << endl;

  cout << ">> Tipo: char" << endl;
  Fila<char> fila3;
  fila3.mostrarFila();
  cout << "Tamanho da fila: " << fila3.getTamanhoDaFila() << endl;;
  fila3.enfileira('a');
  fila3.enfileira('b');
  fila3.enfileira('c');
  fila3.enfileira('d');
  fila3.mostrarFila();
  cout << "Tamanho da fila: " << fila3.getTamanhoDaFila() << endl;;
  fila3.desenfileira();
  fila3.desenfileira();
  fila3.desenfileira();
  fila3.mostrarFila();
  cout << "=======================================" << endl;


  return 0;
}