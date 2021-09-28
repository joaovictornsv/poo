#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using std::string;

class Pessoa
{
public:
  Pessoa();

  Pessoa(string nome, int idade, float altura);

  void setNome(string _nome);
  void setIdade(int _idade);
  void setAltura(float _altura);

  string getNome() const { return nome; };
  int getIdade() const { return idade; }
  float getAltura() const { return altura; };

  void info() const;

private:
  string nome;
  int idade;
  float altura;
};

#endif