#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;
using std::setprecision;
using std::left;
using std::right;

#include <fstream>
#include <string.h>

typedef struct {
  int registro;
  char nome[24];
  int quantidade;
  float preco;
} IFerramenta;

int totalRegistros = 0;



void atualizarFerramenta(std::fstream &file, IFerramenta &f) {
  IFerramenta ferramenta;

  file.clear();
  file.seekg(0);

  int line = 0;
  while(true) {
    file.read(reinterpret_cast<char*>(&ferramenta), sizeof(IFerramenta));

    if (file.eof()) break;

    if (f.registro == ferramenta.registro) {
      break;
    };

    line += 1;
  }

  cout << line << endl;
  file.seekp(line * sizeof(IFerramenta));
  file.write(reinterpret_cast<char*>(&f), sizeof(IFerramenta));

  file.flush();
}

void cadastrarFerramenta(std::fstream &file, IFerramenta &f) {
  file.clear();


  file.seekp(totalRegistros * sizeof(IFerramenta));
  file.write(reinterpret_cast<char*>(&f), sizeof(IFerramenta));

  file.flush();

  totalRegistros += 1;

}

void registrosIniciais(std::fstream &file) {
  IFerramenta ferramentas[] = {
    {3, "Lixadeira", 7, 57.98},
    {17, "Martelo", 76, 11.99},
    {24, "Serra tico-tico", 21, 11.00},
    {39, "Cortador de grama", 3, 79.50},
    {56, "Serra eletrica", 18, 99.99},
    {68, "Chave de fenda", 106, 6.99},
    {77, "Marreta", 11, 21.50},
    {83, "Chave inglesa", 34, 7.50},
  };

  for (int i = 0; i < 8; i++) {
    cadastrarFerramenta(file, ferramentas[i]);
  }
}

void listarFerramentas(std::fstream &file) {
  IFerramenta f;

  file.clear();
  file.seekg(0);


  cout << endl << "----------------------------------------------------------------------" << endl;
  cout << "| " << setw(12) << left << "REGISTRO" << "| " << setw(24) << left << "NOME" << right << "| " << setw(12) << "QUANT" << right << " |" << setw(12) << "PRECO R$" << " |" << endl;
  cout << "----------------------------------------------------------------------" << endl;

  if (totalRegistros) {

    while(true) {
      file.read(reinterpret_cast<char*>(&f), sizeof(IFerramenta));

      if (file.eof()) break;

      if (f.registro != -1) {
        cout << "| " << setw(12) << left << f.registro << "| " << setw(24) << left << f.nome <<  right << "| " << setw(12) << f.quantidade << right << " |" << setw(12) << std::fixed << std::setprecision(2) << f.preco << " |" << endl;
      }

    }


  } else {
    cout << "                       Nao ha registros                               " << endl;
  }
    cout << "----------------------------------------------------------------------" << endl;


}

bool deletarFerramenta(std::fstream &file, int registro) {

  IFerramenta f;

  file.clear();
  file.seekg(0);

  int line = 0;

  bool ferramentaFoiDeletada = false;

  while(true) {
    file.read(reinterpret_cast<char*>(&f), sizeof(IFerramenta));

    if (file.eof()) break;

    if (f.registro == registro) {
      f.registro = -1;
      file.seekp(line * sizeof(IFerramenta));
      file.write(reinterpret_cast<char*>(&f), sizeof(IFerramenta));
      file.flush();

      ferramentaFoiDeletada = true;
      totalRegistros -= 1;
      break;
    };
    line += 1;
  }

  return ferramentaFoiDeletada;
}

bool ferramentaExiste(std::fstream &file, int registro) {
  IFerramenta f;

  file.clear();
  file.seekg(0);

  bool ferramentaFoiAchada = false;

  while(true) {
    file.read(reinterpret_cast<char*>(&f), sizeof(IFerramenta));

    if (file.eof()) break;

    if (f.registro == registro) {
      ferramentaFoiAchada = true;
      break;
    };
  }

  return ferramentaFoiAchada;
}

void mostrarMenu() {
   cout << "====================== Menu ======================" << endl;
   cout << "[0] Cadastrar ferramenta" << endl;
   cout << "[1] Listar ferramentas" << endl;
   cout << "[2] Deletar ferramenta" << endl;
   cout << "[3] Atualizar ferramenta" << endl;
   cout << "[4] Sair" << endl;
   cout << "==================================================" << endl;
}



int main() {
  std::fstream file("hardware.dat", std::ios::out | std::ios::in);

  if (!file) {
    cout << "Ocorreu um erro ao iniciar o arquivo!" << endl;
    return 0;
  }
  registrosIniciais(file);


  while(true) {
    mostrarMenu();
    int opcao;
    cout << "Opcao: ";
    cin >> opcao;

    switch(opcao) {
      case 0:
        IFerramenta f;
        cout << endl << "============= Cadastro de ferramenta =============" << endl;
        cout << "N do registro: ";
        cin >> f.registro;
        if (ferramentaExiste(file, f.registro)) {
          cout << "Ja existe uma ferramenta com esse registro!" << endl;
          break;
        }
        cin.clear();
        cout << "Nome (sem espacos): ";
        cin >> f.nome;
        cin.clear();
        cout << "Quantidade: ";
        cin >> f.quantidade;
        cin.clear();
        cout << "Preco (R$): ";
        cin >> f.preco;
        cin.clear();

        cadastrarFerramenta(file, f);
        cout << "Ferramenta cadastrada!" << endl;
        break;

      case 1:
        listarFerramentas(file);
        break;
      
      case 2:
        cout << endl << "============= Remocao de ferramenta =============" << endl;
        int registro;
        cout << "Registro da ferramenta: " << endl;
        cin >> registro;

        if (deletarFerramenta(file, registro))  cout << "Ferramenta removida!" << endl;
        else cout << "Ferramenta nao encontrada!" << endl;
        break;

      case 3:
        IFerramenta fe;
        cout << endl << "=========== Atualizacao de ferramenta ===========" << endl;
        cout << "N do registro: ";
        cin >> fe.registro;

        if (ferramentaExiste(file, fe.registro) == false) {
          cout << "Ferramenta não existe!" << endl;
          break;
        }
        cout << ">> Insira os novos dados:" << endl;
        cin.clear();
        cout << "Nome (sem espacos): ";
        cin >> fe.nome;
        cin.clear();
        cout << "Quantidade: ";
        cin >> fe.quantidade;
        cin.clear();
        cout << "Preco (R$): ";
        cin >> fe.preco;
        cin.clear();

        atualizarFerramenta(file, fe);
        cout << "Ferramenta atualizada!" << endl;
        break;

      case 4:
        file.close();
        cout << "Saindo do sistema..." << endl;
        return 0;

      default:
        cout << "Escolha uma opcao válida!" << endl;
    }
  }  

  return 0;
}