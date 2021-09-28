#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using std::string;

class Animal
{
public:
  Animal();
  Animal(string nome);

  void caminha();
  string getNome();
 
protected:
  string nome;
  string raca = "Sem raca";
};

#endif