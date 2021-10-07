#include <iostream>


void menuVisaoInicial() {
  std::cout << "====================================" << std::endl;
  std::cout << "         Bem vindo ao JVBank        " << std::endl;
  std::cout << "====================================" << std::endl;
  std::cout << "Escolha como deseja prosseguir:" << std::endl;
  std::cout << "[0] Gerente" << std::endl;
  std::cout << "[1] Cliente" << std::endl;
  std::cout << "[2] Sair do programa" << std::endl;
  std::cout << "====================================" << std::endl;
}


void menuVisaoGerente() {
  std::cout << "====================================" << std::endl;
  std::cout << "              Gerente               " << std::endl;
  std::cout << "====================================" << std::endl;
  std::cout << "Escolha como deseja prosseguir:" << std::endl;
  std::cout << "[0] Cadastrar nova conta" << std::endl;
  std::cout << "[1] Consultar conta" << std::endl;
  std::cout << "[2] Atualizar conta" << std::endl;
  std::cout << "[3] Fechar conta" << std::endl;
  std::cout << "[4] Listar contas" << std::endl;
  std::cout << "[4] Listar contas de cliente" << std::endl;
  std::cout << "====================================" << std::endl;
  std::cout << "Sua opcao: ";
}

void menuCadastrarConta() {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "            Abrir conta             " << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "Escolha como deseja prosseguir:" << std::endl;
  std::cout << "[0] Criar novo cliente" << std::endl;
  std::cout << "[1] Usar cliente registrado" << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "Sua opcao: ";
}

void menuCriarCliente() {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "       Cadastrar novo cliente       " << std::endl;
  std::cout << "------------------------------------" << std::endl;
}

void menuUsarCliente() {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "       Usar cliente existente       " << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "Nome do cliente: ";
}

void menuConsultarConta() {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "          Consultar conta           " << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "Insira o numero da conta :";
}

void menuAtualizarConta() {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "          Atualizar conta           " << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "(Apenas a chave PIX pode ser atualizada)" << std::endl;
  std::cout << "Insira o numero da conta :";
}

void menuFecharConta() {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "           Fechar conta             " << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "Insira o numero da conta :";
}

void menuListarContasCliente() {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "      Listar contas do cliente      " << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "Nome do cliente: ";
}

void menuListarContas() {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "             Listar contas          " << std::endl;
  std::cout << "------------------------------------" << std::endl;
}