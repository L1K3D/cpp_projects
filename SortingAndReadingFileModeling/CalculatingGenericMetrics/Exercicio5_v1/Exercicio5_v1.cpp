//CEFSA - Centro Educacional da Fundação Salvador Arena
//FESA - Faculdade Engenheiro Salvador Arena
//Heitor Santos Ferreira - RA: 081230042
//Engenharia de Computação - Quarto semestre - EC4
//Estruturas de Dados - Atividade N2.B1
//Professor: Israel Florentino

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <math.h>
#include <cmath>

using namespace std;
using namespace std::chrono;

int calcularIdade(const string& dataNascimento) {
	//Extrair o dia, mês e ano da data de nascimento
	stringstream ss(dataNascimento);
	int dia, mes, ano;
	char delim;
	ss >> dia >> delim >> mes >> delim >> ano;

	//Obter a data atual
	time_t now;
	time(&now);
	tm localTime;
	localtime_s(&localTime, &now);
	int anoAtual = localTime.tm_year + 1900;
	int mesAtual = localTime.tm_mon + 1;
	int diaAtual = localTime.tm_mday;

	//Calcular a idade
	int idade = anoAtual - ano;
	if (mesAtual < mes || (mesAtual == mes && diaAtual < dia)) {
		idade--;
	}

	return idade;
}

template < typename T >
double calcularMedia(const vector < T > & vetor) {

	double soma = 0.0;

	for (const T& elemento : vetor) {

		soma += elemento;

	}

	return static_cast <double> (soma) / vetor.size();

}

template < typename T >
double calcularMediana(vector < T >& vetor) {

	size_t tamanho = vetor.size();
	sort(vetor.begin(), vetor.end());

	if (tamanho % 2 == 0) {

		return (static_cast <double> (vetor[tamanho / 2 - 1]) + vetor[tamanho / 2]) / 2.0;

	}
	else
	{

		return static_cast <double> (vetor[tamanho / 2]);

	}

}

template < typename T >
double calcularDesvioPadrao(const vector < T >& vetor) {

	double media = calcularMedia(vetor);

	double somaQuadradosDiferenciais = 0.0;
	for (const T& elemento : vetor) {

		double diferenca = elemento - media;
		somaQuadradosDiferenciais += diferenca * diferenca;

	}

	double variancia = somaQuadradosDiferenciais / vetor.size();

	return sqrt(variancia);

}

double stringParaDouble(const string& str) {

	stringstream ss(str);
	double valor;
	ss >> valor;
	return valor;

}

int main()
{
   
	string caminhoParaArquivoCSV = "X:\\Alunos\\081230042\\dados_pessoais.csv";

	ifstream file(caminhoParaArquivoCSV);
	if (!file.is_open()) {

		cerr << "Erro ao abrir arquivo '.csv'..." << endl;
		return 1;

	}

	vector < string > ArranjoDeDatasNascimentoString;
	vector < string > ArranjoIdadesString;
	vector < string > ArranjoPesosString;
	vector < string > ArranjoAlturasString;

	string linha;
	bool primeira_linha = true;
	while (getline(file, linha)) {

		if (primeira_linha) {

			primeira_linha = false;
			continue;

		}

		istringstream ss(linha);
		string token;

		getline(ss, token, ';'); // Descarta o valor da primeira coluna
		getline(ss, token, ';'); // Pega o valor da segunda coluna (data de nascimento)

		// Armazena a data de nascimento
		ArranjoDeDatasNascimentoString.push_back(token);

		// Calcula a idade com base na data de nascimento
		int idade = calcularIdade(token);
		ArranjoIdadesString.push_back(to_string(idade));

		getline(ss, token, ';');
		ArranjoPesosString.push_back(token);

		getline(ss, token, ';');
		ArranjoAlturasString.push_back(token);

	}

	file.close();

	cout << "#---Datas de nascimento presentes no campo 'Idade' do arquivo '.csv'---#" << endl;
	cout << " ";
	for (string data_de_nascimento : ArranjoDeDatasNascimentoString) {

		cout << data_de_nascimento << " ";

	}

	cout << endl;
	cout << " ";
	cout << endl;

	cout << "#---Idades calculadas a partir do da data de nascimento capturada no campo 'Idade' do arquivo '.csv'---#" << endl;
	cout << endl;
	for (string idade : ArranjoIdadesString) {

		cout << idade << " ";
	}

	cout << endl;
	cout << " ";
	cout << endl;

	cout << "#---Pesos obtidos a partir da coluna 'Peso' do arquivo '.csv'---#" << endl;
	cout << endl;
	for (string peso : ArranjoPesosString) {

		cout << peso << " ";
	}

	cout << endl;
	cout << " ";
	cout << endl;

	cout << "#---Alturas obtidas a partir da coluna 'Altura' do arquivo '.csv'---#" << endl;
	cout << endl;
	for (string altura : ArranjoAlturasString) {

		cout << altura << " ";

	}

	//////

	vector < double > ArranjoIdadesDouble;
	for (const string& valor : ArranjoIdadesString) {

		ArranjoIdadesDouble.push_back(stringParaDouble(valor));

	}

	vector < double > ArranjoPesosDouble;
	for (const string& valor : ArranjoPesosString) {

		ArranjoPesosDouble.push_back(stringParaDouble(valor));

	}

	vector < double > ArranjoAlturasDouble;
	for (const string& valor : ArranjoAlturasString) {

		ArranjoAlturasDouble.push_back(stringParaDouble(valor));

	}

	double mediaIdades = calcularMedia(ArranjoIdadesDouble);
	double mediaPesos = calcularMedia(ArranjoPesosDouble);
	double mediaAlturas = calcularMedia(ArranjoAlturasDouble);

	double medianaIdades = calcularMediana(ArranjoIdadesDouble);
	double medianaPesos = calcularMediana(ArranjoPesosDouble);
	double medianaAlturas = calcularMediana(ArranjoAlturasDouble);

	double desvioPadraoIdades = calcularDesvioPadrao(ArranjoIdadesDouble);
	double desvioPadraoPesos = calcularDesvioPadrao(ArranjoPesosDouble);
	double desvioPadraoAlturas = calcularDesvioPadrao(ArranjoAlturasDouble);

	cout << endl;
	cout << " ";
	cout << endl;

	cout << "#-----Dados para Altura-----#" << endl;
	cout << "Media: " << mediaIdades << endl;
	cout << "Mediana: " << medianaIdades << endl;
	cout << "Desvio Padrao: " << desvioPadraoIdades << endl;

	cout << endl;
	cout << " ";
	cout << endl;

	cout << "#-----Dados para Peso-----#" << endl;
	cout << "Media: " << mediaPesos << endl;
	cout << "Mediana: " << medianaPesos << endl;
	cout << "Desvio Padrao: " << desvioPadraoPesos << endl;

	cout << endl;
	cout << " ";
	cout << endl;

	cout << "#-----Dados para Altura-----#" << endl;
	cout << "Media: " << mediaAlturas << endl;
	cout << "Mediana: " << medianaAlturas << endl;
	cout << "Desvio Padrao: " << desvioPadraoAlturas << endl;

	return 0;

}


// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
