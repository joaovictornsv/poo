#ifndef CUPOM_H
#define CUPOM_H

#include <string>
using std::string;

class Cupom
{
public:
  Cupom(string id, string descricao, int quantidade, float preco);

  void setId(string _id);
  void setDescricao(string _descricao);
  void setQuantidade(int _quantidade);
  void setPreco(float _preco);

  string getId();
  string getDescricao();
  int getQuantidade();
  float getPreco();

  float calculaCupom();

private:
  string id;
  string descricao;
  int quantidade;
  float preco;
};

#endif