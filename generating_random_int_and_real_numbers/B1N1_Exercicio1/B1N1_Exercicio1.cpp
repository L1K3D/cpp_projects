//CEFSA - Centro Educacional da Fundação Salvador Arena
//FESA - Faculdade Engenheiro Salvador Arena
//Enzo Brito Alves de Oliveira - RA: 082220040
//Heitor Santos Ferreira - RA: 081230042
//Disciplina: Estrutura de dados
//Professor: Israel Florentino
// -----------------------------------
//Atividade: Desenvolvimento de ordenações e manipulações númericas - Exercicio 1
// 
//Gere dois números aleatórios entre 0 e 100, sendo um número inteiro e outro real na linguagem C++.

// 1. Realizando importação de bibliotecas que vão ser usadas ao longo da execução do software
// 1.1. Realizando importação e declaração da biblioteca responsável por gerenciar modelos e caminhos de entrada e saida dos componentes nas variaveis
#include <iostream>

// 1.2. Realizando importação e declaração da biblioteca responsável por gerar números randomicos
#include <random>

// 2. Declarando inicialização da função principal na qual o software será executado
int main() {

	// 2.1. Inicialização do gerador de números aleatórios
	// 2.1.1 Inicia variavel sistemica do tipo natural da linguagem de máquina a partir do dispositivo que está executando o software e incializa um gerador de modelos randomicos
	std::random_device rd;
	std::mt19937 gen(rd());

	// 2.1.2. Inicializa um distribuidor de números inteiros e declara um range de execução do mesmo, sendo nesse caso de 0 a 100
	std::uniform_int_distribution <> int_dist(0, 100);

	// 2.1.3. Inicializa um distribuidor de números reais e declara um range de execução do mesmo, sendo nesse caso de 0.00 a 100.00, podendo variar de maneira de dois digitos após a virgula
	std::uniform_real_distribution <> real_dist(0.0, 100.0);

	// 2.2. Geração de um número aleatório inteiro
	int numero_inteiro = int_dist(gen);

	// 2.3. Geração de um número aleatório real
	double numero_real = real_dist(gen);

	// 2.4. Exibição dos resultados
	std::cout << "Número aleatório inteiro: " << numero_inteiro << "\n" << std::endl;
	std::cout << "Número aleatório real: " << numero_real << "\n" << std::endl;

	// 2.5 Encerrando processamento do software
	return 0;
}
