## Trabalho Final de POO
### Aluno: João Victor Negreiros da Silva
---

### 1. Para compilar o programa:
```
g++ -std=c++17 -static -O2 -lm main.cpp -o main.exe && ./main.exe
```
---
### 2. Dados existentes:
Correntistas:

- Alícia Antonella Louise Sales (Pessoa Física)
- Osvaldo e Diego Gráfica Ltda (Pessoa Jurídica)

Contas:
  - Alícia:
    - Conta Corrente            (N20211011114853)
    - Conta Corrente com Limite (N20211011114923)

  - Osvaldo e Diego:
    - Conta Corrente            (N20211011115124)
    - Conta Corrente com Limite (N202110111210)
    - Conta Poupanca            (N20211011115039)
---
### 3. Observações:
Na criação de conta:
  - Numero da conta gerado automaticamente
  - Saldo sempre iniciado com o valor zero

Na atualização de conta:
  - Apenas a chave pix pode ser atualizada