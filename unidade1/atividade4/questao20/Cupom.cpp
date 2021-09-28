#include "Cupom.h"

Cupom::Cupom(string id, string descricao, int quantidade, float preco) {
  setId(id);
  setDescricao(descricao);

  if (quantidade < 0) setQuantidade(0);
  else setQuantidade(quantidade);

  if (preco < 0) setPreco(0);
  else setPreco(preco);
};


void Cupom::setId(string _id) {
  id = _id;
};

void Cupom::setDescricao(string _descricao) {
  descricao = _descricao;
};

void Cupom::setQuantidade(int _quantidade) {
  quantidade = _quantidade;
};

void Cupom::setPreco(float _preco) {
  preco = _preco;
};


string Cupom::getId() {
  return id;
};

string Cupom::getDescricao() {
  return descricao;
};

int Cupom::getQuantidade() {
  return quantidade;
};

float Cupom::getPreco() {
  return preco;
};


float Cupom::calculaCupom() {
  return getPreco() * getQuantidade();
};