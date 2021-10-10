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
  std::cout << "Sua opcao: ";
}

void lerLinha(std::string *s) {
  std::fflush(stdin);
  std::getline(std::cin, *s);
  std::getline(std::cin, *s);
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
  std::cout << "[5] Listar contas de cliente" << std::endl;
  std::cout << "[6] Voltar ao menu inicial" << std::endl;
  std::cout << "====================================" << std::endl;
  std::cout << "Sua opcao: ";
}

void menuEntrarComConta() {
  std::cout << "----------------------------------------------------" << std::endl;
  std::cout << "                      Cliente                       " << std::endl;
  std::cout << "----------------------------------------------------" << std::endl;
  std::cout << "Insira o numero da sua conta (-1 encerra): ";
}

void menuVisaoCliente() {
  std::cout << "====================================" << std::endl;
  std::cout << "              Cliente               " << std::endl;
  std::cout << "====================================" << std::endl;
  std::cout << "Escolha como deseja prosseguir:" << std::endl;
  std::cout << "[0] Deposito" << std::endl;
  std::cout << "[1] Saque" << std::endl;
  std::cout << "[2] Transferencia" << std::endl;
  std::cout << "[3] Extrato" << std::endl;
  std::cout << "[4] Saldo" << std::endl;
  std::cout << "[5] Voltar ao menu inicial" << std::endl;
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
  std::cout << "Escolha que tipo de cliente deseja ser:" << std::endl;
  std::cout << "[0] Pessoa Fisica" << std::endl;
  std::cout << "[1] Pessoa Juridica" << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "Sua opcao: ";
}

void menuTipoDeConta() {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "            Tipo de conta           " << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "Escolha que tipo de conta deseja abrir:" << std::endl;
  std::cout << "[0] Conta Corrente Comum" << std::endl;
  std::cout << "[1] Conta Corrente como Limite" << std::endl;
  std::cout << "[2] Conta Poupanca" << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "Sua opcao: ";
}

void menuUsarCliente() {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "       Usar cliente existente       " << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "Nome do cliente: ";
}

void menuDeposito() {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "             Deposito               " << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "Valor do deposito: ";
}

void menuSaque() {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "               Saque                " << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "Valor do saque: ";
}

void menuTransferencia() {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "           Transferencia            " << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "Numero da conta destino: ";
}

void menuExtrato() {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "              Extrato               " << std::endl;
  std::cout << "------------------------------------" << std::endl;
}

void menuSaldo() {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "              Saldo                 " << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "Seu saldo eh: R$";
}

void menuConsultarConta() {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "          Consultar conta           " << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "Insira o numero da conta: ";
}

void menuAtualizarConta() {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "          Atualizar conta           " << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "(Apenas a chave PIX pode ser atualizada)" << std::endl;
  std::cout << "Insira o numero da conta: ";
}

void menuFecharConta() {
  std::cout << "------------------------------------" << std::endl;
  std::cout << "           Fechar conta             " << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "Insira o numero da conta: ";
}

void menuListarContasCliente() {
  std::cout << "------------------------------------------" << std::endl;
  std::cout << "         Listar contas do cliente         " << std::endl;
  std::cout << "------------------------------------------" << std::endl;
  std::cout << "Nome do cliente: ";
}

void menuListarContas() {
  std::cout << "------------------------------------------" << std::endl;
  std::cout << "              Listar contas               " << std::endl;
  std::cout << "------------------------------------------" << std::endl;
}