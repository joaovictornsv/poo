#include <iostream>
#include "ContaBanco.h"

using std::cout;
using std::endl;
using std::ios;

int main() {
  cout.setf(ios::fixed);
  cout.precision(2);

  cout << "=========== Conta 1 ===========" << endl;
  ContaBanco conta1(0);
  cout << "Saldo inicial: R$ " << conta1.getSaldo() << endl;
  cout << "[+] Creditando R$ 10.00 na conta 1" << endl;
  conta1.creditar(10);
  cout << "[+] Creditando R$ 10.00 na conta 1" << endl;
  conta1.creditar(10);
  cout << "[-] Debitando R$ 5.00 na conta 1" << endl;
  conta1.debitar(5);

  cout << endl << "Saldo da conta1: R$" << conta1.getSaldo() << endl;

  cout << "=========== Conta 2 ===========" << endl;
  ContaBanco conta2(1000);
  cout << "Saldo inicial: R$ " << conta2.getSaldo() << endl;
  cout << "[+] Creditando R$ 1000.00 na conta 2" << endl;
  conta2.creditar(1000);
  cout << "[-] Debitando R$ 3000.00 na conta 2" << endl;
  conta2.debitar(3000);
  cout << "Saldo da conta2: R$" << conta2.getSaldo() << endl;

  return 0;
}