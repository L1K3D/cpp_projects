//CEFSA - Centro Educacional da Fundação Salvador Arena
//FESA - Faculdade Engenheiro Salvador Arena
//Enzo Brito Alves de Oliveira - RA: 082220040
//Heitor Santos Ferreira - RA: 081230042
//Disciplina: Estrutura de dados
//Professor: Israel Florentino
// -----------------------------------
//Atividade: Desenvolvimento de ordenações e manipulações númericas - Exercicio 2
// 
//Implemente um arranjo de inteiros com 100 posições, contendo valores aleatórios entre 0 e 1000. Em
//seguida, imprima o conteúdo do arranjo não ordenado e, após ordene - o e imprima o seu conteúdo
//ordenado registrando as métricas de tempo de execução.

// 1. Realizando a importação de bibliotecas que serão utilizadas ao longo do programa
// 1.1. Importando biblioteca responsável por administrar tempos de processamento de maneira nativa no programa
#include <chrono>

// 1.2. Importando biblioteca responsável por gerenciar conceitos de entrada e saída de dados ao usuário
#include <iostream>

// 1.3. Importando biblioteca responsável por criar movimentações padrão de código, importando conceitos básicos da linguagem
#include <stdlib.h>

// 1.4. Importando biblioteca responsável por traduzir tempo em linguagem de máquina para linguagem natural
#include <ctime>
//-----------------------------------//

// 2. Importando e incorporando divisões de workspace para funcionamento correto do programa
// 2.1. Importando o ambiente de processamento do programa com as funções padrões do C++
using namespace std;

// 2.2. Importando o ambiente de processamento do progarama integrando as fuñções padrões do C++ com as configurações temporáis
using namespace std::chrono;
//-----------------------------------//

// 3. Criando função de ordenação por modelo Bubble Sort
// 3.1. Nomenado função dentro do sooftware e atribuindo suas variaveis de processamento e valores pré-definidos
void ordenacaoBubbleSort(int arranjo[], int tamanho)
{

    // 3.2. Criando modelo de laço de repetição e analise onde para cada número composto dentro de um arranjo definido, é categorizado seu tamanho em bytes
    for (int numero = 0; numero < tamanho - 1; numero++)
    {

        // 3.2.1. Criando modelo de laço de repetição e analise onde para cada tamanho é adicionado mais uma analise para ordenação perante aos já organizados 
        for (int posicao = 0; posicao < tamanho - 1; posicao++)
        {

            // 3.2.1.1. Criando modelo de laço de repetição e analise onde para é realizado a ordenação dos componentes do arranjo com base em sua posição de tamanho
            if (arranjo[posicao] > arranjo[posicao + 1])
            {

                // 3.2.1.1.1. Criando variavel temporária que guarda a posição do número de maneira temporária enquanto a avaliação de tamanho é feita nos demais
                int temp = arranjo[posicao];

                // 3.2.1.1.2. Definindo o arranjo como uma posição a mais caso ele seja maior que o próximo subjulgado pela função
                arranjo[posicao] = arranjo[posicao + 1];

                // 3.2.1.1.3. Guarda a nova posição do número na variavel de posição temporária citada anteriormente
                arranjo[posicao + 1] = temp;

            }

        }

    }

}
//-----------------------------------//

// 4. Criando função principal de execução do software
// 4.1. Definindo sua principalidade como padrão
int main()
{

    // 4.2. Definindo tamanho do arranjo que será conjulgado para comportar 100 números
    const int tamanho_arranjo = 100; // OBS. 4.2. -> Esse tamanho é citado no enunciado do exercicio

    // 4.3. Criando lista vazia chamada de 'numeros_aleatorios' e definindo que essa lista deverá comportar 100 itens com base no número declarado na variavel 'tamanho_arranjo'
    int numeros_aleatorios[tamanho_arranjo];

    // 4.4. Definindo nullalidade dõ tempo de geração dos números aleatorios
    srand(time(NULL));

    // 4.5. Criando laço de repetição de verificação onde para cada número existente na avaliação ele deve atender as condições dentro do laço e as quantidades de repetição não deve exceder a quantidade de posições declarados no tamanho do arranjo
    for (int numero = 0; numero < tamanho_arranjo; numero++)
    {

        // 4.5.1. Preenchendo a lista de números aleatórios com base nos números e tamanho do arranjo pré-definido. Os números devem ser compreendidos em um intervalo de 0 a 1000
        numeros_aleatorios[numero] = rand() % 101;

    }

    // 4.6. Realiza a declaração da exibição do arranjo original sem ordenação das aleatoriedades
    cout << "Arranjo original gerado a partir de aleatoriedades: ";

    // 4.7. Cria laço de repetição de verificação onde é configurada o modelo de exibição dos números gerados
    for (int numero = 0; numero < tamanho_arranjo; numero++)
    {

        // 4.7.1. Realiza a exibição dos números e um modelo de separação com um espaço vazio.
        cout << numeros_aleatorios[numero] << " ";

    }

    // 4.8. Realiza exibição de linhas vazias para visualmente o software não demonstrar os dois meios de saídas configurados juntos.
    cout << "\n";
    cout << endl;
    cout << "\n";

    // 4.9. Cria variavel de inicio com a tipagem de 'auto', sendo essa tipagem um modelo nativo de linguagem de máquina. A variavel logo em seguida recebe o valor de 'relógio de alta resolução' capturando o tempo de linguagem de máquina no momento de execução. Essa momento capturado na variavel é usado para se medir o tempo de execução da função.
    auto inicio = high_resolution_clock::now();

    // 4.10. Executa a variavel de 'ordenacaoBubbleSort' criada e referenciada anteriormente no código e define como seus valores os números aleatorios gerados e o tamanho do arranjo definidos anteriormente
    ordenacaoBubbleSort(numeros_aleatorios, tamanho_arranjo);

    // 4.11. Cria variavel de parada com a tipagem de 'auto', sendo essa tipagem um modelo nativo da linguagem de máquina. A variavel logo em seguida recebe o valor de 'relógio de alta resolução' capturando o tempo de linguagem de máquina no momento de execução. Essa momento capturado na variavel é usado para se medir o tempo de execução da função.                                                            
    auto parada = high_resolution_clock::now();

    // 4.12. É criada uma varivael de calculo de tempo entre o tempo de inicio da função e o de parada, convertendo o tempo de linguagem de máquina para microsegundos. É realizada a subtração entre o tempo de parada e o de inicio
    auto duracao = duration_cast<microseconds>(parada - inicio);

    // 4.13. Realiza a declaração de anuncio da apresentação do arranjo ordenado pelo modelo BubbleSort
    cout << "Arranjo ordenado por variação BubbleSort: ";

    // 4.14. Cria laço de repetição de verificação onde é configurada o modelo de exibição dos números ordenados
    for (int numero = 0; numero < tamanho_arranjo; numero++)
    {

        // 4.14.1. Realiza a exibição dos números e um modelo de separação com um espaço vazio.
        cout << numeros_aleatorios[numero] << " ";

    }

    // 4.15. Realiza exibição de linhas vazias para visualmente o software não demonstrar os números ordenados emm BubbleSort e o tempo de execução juntos
    cout << endl;
    cout << "\n";

    // 4.16. Exibe o tempo necessário para a realização da operação em BubbleSort
    cout << "Tempo necessário para realizar as operações: " << duracao.count() << " microsegundos" << endl;

    // 4.17. Retorna '0' para sinalizar fim do processamento do software
    return 0;

}