//CEFSA - Centro Educacional da Fundação Salvador Arena
//FESA - Faculdade Engenheiro Salvador Arena
//Heitor Santos Ferreira - RA: 081230042
//Engenharia de Computação - Quarto semestre - EC4
//Estruturas de Dados - Atividade N2.B1
//Professor: Israel Florentino

// 1. Realizando importação de bibliotecas que serão usadas ao longo da execução do programa
// 1.1. Importando biblioteca responsável pela execução de comandos de inserção e exibição de dados
#include <iostream>

// 1.2. Importando biblioteca responsável por realizar a leitura de arquivos localizados em pastas externas ao software
#include <fstream>

// 1.3. Importando biblioteca responsável por auxiliar na gravação e manipulação de conteúdos de arquivos localizados em pastas alheias ao software
#include <sstream>


#include <vector>
#include <string>
#include <chrono>

using namespace std;

void imprimeArranjo(const vector< string >& arranjo) {

    for (const auto& elemento : arranjo) {

        cout << elemento << " ";

    }

    cout << endl;

}

void funcaoBubbleSort(vector < string >& arranjo) {

    int n = arranjo.size();
    for (int i = 0; i < n - 1; ++i) {

        for (int j = 0; j < n - i - 1; ++j) {

            if (arranjo[j] > arranjo[j + 1]) {

                swap(arranjo[j], arranjo[j + 1]);

            }

        }

    }

}

void funcaoInsertSort(vector < string >& arranjo) {

    int n = arranjo.size();
    for (int i = 1; i < n; ++i) {

        string key = arranjo[i];
        int j = i - 1;
        while (j >= 0 && arranjo[j] > key)
        {

            arranjo[j + 1] = arranjo[j];
            j = j - 1;

        }

        arranjo[j + 1] = key;

    }

}

void funcaoSelectionSort(vector < string >& arranjo) {

    int n = arranjo.size();
    for (int i = 0; i < n - 1; ++i) {

        int posicaoMinima = 1;

        for (int j = i + 1; j < n; ++j) {

            if (arranjo[j] < arranjo[posicaoMinima]) {

                posicaoMinima = j;

            }

        }

    }

}

void funcaoMerge(vector < string >& arranjo, int esquerda, int meio, int direita) {

    int numero1 = meio - esquerda + 1;
    int numero2 = direita - meio;

    vector < string > L(numero1), R(numero2);

    for (int i = 0; i < numero1; ++i) {

        L[i] = arranjo[esquerda + i];

    }

    for (int j = 0; j < numero2; ++j) {

        R[j] = arranjo[meio + 1 + j];

    }

    int i = 0, j = 0, k = esquerda;

    while (i < numero1 && j < numero2)
    {

        if (L[i] <= R[j]) {

            arranjo[k] = L[i];
            ++i;

        }
        else {

            arranjo[k] = R[j];
            ++j;

        }

        ++k;

    }

    while (i < numero1)
    {

        arranjo[k] = L[i];
        ++i;
        ++k;

    }

    while (j < numero2)
    {
        arranjo[k] = R[j];
        ++j;
        ++k;
    }

}

void funcaoMergeSort(vector < string >& arranjo, int esquerda, int direita) {

    if (esquerda >= direita) {

        return;

    }

    int meio = esquerda + (direita - esquerda) / 2;
    funcaoMergeSort(arranjo, esquerda, meio);
    funcaoMergeSort(arranjo, meio + 1, direita);
    funcaoMerge(arranjo, esquerda, meio, direita);

}

int funcaoDeParticionamento(vector < string >& arranjo, int baixo, int alto) {

    string pivot = arranjo[alto];
    int i = baixo - 1;

    for (int j = baixo; j <= alto - 1; ++j) {

        if (arranjo[j] < pivot){

            ++i;
            swap(arranjo[i], arranjo[j]);

        }

    }

    swap(arranjo[i + 1], arranjo[alto]);
    return i + 1;

}

void funcaoQuickSort(vector < string >& arranjo, int baixo, int alto) {

    if (baixo < alto) {

        int pi = funcaoDeParticionamento(arranjo, baixo, alto);
        funcaoQuickSort(arranjo, baixo, pi - 1);
        funcaoQuickSort(arranjo, pi + 1, alto);

    }

}

int main()
{

    string caminhoParaArquivoCSV = "X:\\Alunos\\081230042\\dados_pessoais.csv";

    ifstream file(caminhoParaArquivoCSV);
    if (!file.is_open()) {

        cerr << "Erro ao abrir arquivo '.csv'..." << endl;
        return 1;

    }

    vector < string > arranjoDeDados;

    string linha;
    while (getline(file, linha))
    {
        arranjoDeDados.push_back(linha);

    }

    file.close();

    vector < string > arranjoBubbleSort = arranjoDeDados;
    vector < string > arranjoInsertionSort = arranjoDeDados;
    vector < string > arranjoSelectionSort = arranjoDeDados;
    vector < string > arranjoMergeSort = arranjoDeDados;
    vector < string > arranjoQuickSort = arranjoDeDados;

    auto inicioCronometroBubbleSort = chrono::steady_clock::now();
    funcaoBubbleSort(arranjoBubbleSort);
    auto fimCronometroBubbleSort = chrono::steady_clock::now();
    chrono::duration<double> elapsedTimeBubbleSort = fimCronometroBubbleSort - inicioCronometroBubbleSort;

    auto inicioCronometroInsertionSort = chrono::steady_clock::now();
    funcaoInsertSort(arranjoInsertionSort);
    auto fimCronometroInsertionSort = chrono::steady_clock::now();
    chrono::duration<double> elapsedTimeInsertionSort = fimCronometroInsertionSort - inicioCronometroInsertionSort;

    auto inicioCronometroSelectionSort = chrono::steady_clock::now();
    funcaoSelectionSort(arranjoSelectionSort);
    auto fimCronometroSelectionSort = chrono::steady_clock::now();
    chrono::duration<double> elapsedTimeSelectionSort = fimCronometroSelectionSort - inicioCronometroSelectionSort;

    auto inicioCronometroMergeSort = chrono::steady_clock::now();
    funcaoMergeSort(arranjoMergeSort, 0, arranjoMergeSort.size() - 1);
    auto fimCronometroMergeSort = chrono::steady_clock::now();
    chrono::duration<double> elapsedTimeMergeSort = fimCronometroMergeSort - inicioCronometroMergeSort;

    auto inicioCronometroQuickSort = chrono::steady_clock::now();
    funcaoMergeSort(arranjoMergeSort, 0, arranjoQuickSort.size() - 1);
    auto fimCronometroQuickSort = chrono::steady_clock::now();
    chrono::duration<double> elapsedTimeQuickSort = fimCronometroQuickSort - inicioCronometroQuickSort;

    cout << "Ordenação com BubbleSort";
    imprimeArranjo(arranjoBubbleSort);
    cout << "Tempo de execução do Bubble Sort: " << elapsedTimeBubbleSort.count() << "segundos" << endl;
    cout << " ";

    cout << "Ordenação com Insertion Sort";
    imprimeArranjo(arranjoInsertionSort);
    cout << "Tempo de execução do Insertion Sort: " << elapsedTimeInsertionSort.count() << "segundos" << endl;
    cout << " ";

    cout << "Ordenação com Selection Sort";
    imprimeArranjo(arranjoSelectionSort);
    cout << "Tempo de execução do Selection Sort" << elapsedTimeSelectionSort.count() << "segundos" << endl;
    cout << " ";

    cout << "Ordenação com Merge Sort";
    imprimeArranjo(arranjoMergeSort);
    cout << "Tempo de execução do Merge Sort: " << elapsedTimeMergeSort.count() << "segundos" << endl;
    cout << " ";

    cout << "Ordenação com Quick Sort";
    imprimeArranjo(arranjoQuickSort);
    cout << "Tempo de execução do Quick Sort: " << elapsedTimeQuickSort.count() << "segundos" << endl;
    cout << " ";

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
