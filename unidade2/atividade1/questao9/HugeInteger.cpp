#include <iostream>
#include <string.h>
#include "HugeInteger.h"

using std::string;
using std::cout;
using std::endl;
using std::stoi;
using std::to_string;

HugeInteger::HugeInteger() {};

void HugeInteger::input(std::string value) {

  if (numeroValido(value) && value.length() <= 40) {
    num = value;
    tamanho = value.length();
  }

  else {
    cout << "Número inválido" << endl;
    num = "0";
    tamanho = 1;
  }
};

void HugeInteger::output() {
  for (int i = 0; i < tamanho; i++) {
    cout << num[i];
  };
  cout << endl;
};

void HugeInteger::add(const HugeInteger &h) {
  std::string tempHNum = h.num;
  std::string tempNum = num;
  
  if (tamanho > h.tamanho) {
    for (int i = 0; i < (tamanho-h.tamanho); i++) {
      tempHNum = "0" + tempHNum;
    }
  }
  if (tamanho < h.tamanho) {
    for (int i = 0; i < (tamanho-h.tamanho); i++) {
      tempNum = "0" + tempNum;
    }
  }
  std::string soma = "";
  char sobra = '0';
  int somaInt;
  for (int i = tamanho-1; i >= 0; i--) {

    somaInt = (tempNum[i] - '0') + (tempHNum[i] - '0') + (sobra - '0');
    if (somaInt > 9) {
      sobra = to_string(somaInt)[0];
      soma = to_string(somaInt)[1] + soma;
    } else {
      soma = to_string(somaInt) + soma;
      sobra = '0';
    }

    
    if (i == 0 && sobra != '0') {
      soma = sobra + soma;      
    }
  }

  num = soma;
  tamanho = soma.length();
};

bool HugeInteger::isEqualTo(const HugeInteger &h) {
  if (tamanho != h.tamanho) { return false; }

  for (int i = 0; i < tamanho; i++) {
    if (num[i] != h.num[i]) { return false; };
  }

  return true;

};

bool HugeInteger::isNotEqualTo(const HugeInteger &h) {
  if (tamanho != h.tamanho) { return true; }


  for (int i = 0; i < tamanho; i++) {
    if (num[i] != h.num[i]) { return true; };
  }

  return false;
};

bool HugeInteger::isGreaterThan(const HugeInteger &h) {
  if (tamanho > h.tamanho) { return true; }


  for (int i = 0; i < tamanho; i++) {
    if (num[i] > h.num[i]) { return true; };
    if (num[i] < h.num[i]) { return false; };
  }

  return false;

};

bool HugeInteger::isLessThan(const HugeInteger &h) {
  if (tamanho < h.tamanho) { return true; }


  for (int i = 0; i < tamanho; i++) {
    if (num[i] < h.num[i]) { return true; };
    if (num[i] > h.num[i]) { return false; };
  }

  return false;
};

bool HugeInteger::isGreaterThanOrEqual(const HugeInteger &h) {
  if (isEqualTo(h) || isGreaterThan(h)) return true;

  return false;
};

bool HugeInteger::isLessThanOrEqual(const HugeInteger &h) { 
  if (isEqualTo(h) || isLessThan(h)) return true;

  return false;
};

bool HugeInteger::numeroValido(std::string value) {
  std::string numeros = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

  bool ehNumero = false;
  for (int i = 0; i < value.length(); i++) {
    for (int j = 0; j < 10; j++) {
      if (value[i] == numeros[j]) ehNumero = true;
    }
    if (!ehNumero) return false;
  }

  return true;
};