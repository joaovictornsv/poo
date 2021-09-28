#include <iostream>

#include "Agenda.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"

int main() {
  Agenda agenda(10);

  PessoaJuridica *pJuridica1 = new PessoaJuridica(
    "Enrico Sousa Silva",
    "Praça Padre Miguel 119",
    "treinamento@enricoeseverinograficame.com.br",
    "94.311.027/0001-49",
    "919.559.190.679",
    "Enrico e Severino Gráfica ME"
  );

  PessoaFisica *pFisica1 = new PessoaFisica(
    "Juliana Mariana Jaqueline Nunes",
    "Rua Aruanã 344",
    "jjulianamarianajaquelinenunes@fortlar.com.br",
    "047.570.963-21",
    "09/10/1945",
    "Casada"
  );

  PessoaJuridica *pJuridica2 =  new PessoaJuridica(
    "Felipe Pereira Nunes",
    "Rua Pedro Zangrande 570",
    "sac@filipeefranciscofinanceirame.com.br",
    "40.332.583/0001-72",
    "311.931.661.273",
    "Filipe e Francisco Financeira ME"
  );

  std::cout << "> Adicionando 'Enrico': ";
  agenda.adicionarContato(pJuridica1);
  std::cout << "> Adicionando 'Juliana': ";
  agenda.adicionarContato(pFisica1);
  std::cout << "> Adicionando 'Felipe': ";
  agenda.adicionarContato(pJuridica2);


  std::cout << std::endl;

  agenda.exibirAgendaCompacta();


  std::cout << std::endl;


  std::cout << "> Removendo 'Mario': ";
  agenda.removerContato("Mario");

  std::cout << "> Removendo '047.570.963-21': ";
  agenda.removerContato("047.570.963-21");

  std::cout << std::endl;

  
  agenda.exibirAgendaCompacta();

  std::cout << std::endl;

  std::cout << "> Buscando por 'Juliana Mariana Jaqueline Nunes': " << std::endl;
  agenda.pesquisarContato("Juliana Mariana Jaqueline Nunes");

  std::cout << "> Buscando por '94.311.027/0001-49': " << std::endl;
  agenda.pesquisarContato("94.311.027/0001-49");

  std::cout << std::endl;

  agenda.exibirAgendaCompacta();

  std::cout << std::endl;

  std::cout << "> Agenda final: " << std::endl;
  agenda.exibirAgendaExpandida();


  return 0;
}