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

// 1.3. Importando biblioteca responsável por executar variações de modelagem em string para dados existentes em arquivos tabulares alheios as pastas locais do software
#include <string.h>

// 1.4. Importando biblioteca responsável por executar as variações do algoritmo de importação de dados em arquivos variados alheios as pastas locais do software
#include <algorithm>

// 1.5. Importando biblioteca responsável por importar as variações de leitura de 'string', não nativas do C++
#include <string>

//--//--//--//--//--//--//--//--//--//--//

// 2. Ancorando variação de namespace para que o mesmo use os rescursos do modelo interno standard
using namespace std;

//--//--//--//--//--//--//--//--//--//--//

// 3. Criando modelo de execução principal do software e seus demais elementos
int main() {

    // 3.1. Declarando o caminho da pasta da qual o arquivo tabular está localizado
    ifstream arquivo("C:\\Users\\Heitor\\OneDrive - Fundação Salvador Arena\\Quarto Semestre\\Estruturas de Dados\\N2.B1\\dados_pessoais.csv");

    // 3.2. Criando modelo de leitura dos itens presentes no arquivo para que seja possível determinar seu tamanho em linhas
    // 3.2.1. Criando variavel do tipo inteiro que irá receber o valor obtido caso o modelo de leitura do arquivo seja bem sucedido
    int numero_elementos_arquivo = count_if(

        // 3.2.2. Integrando todos os elementos do arquivo tabular lido anteriormente como string, essa integração é realizada em um vetor que tem sua obrigatoriedade de inserção de elementos em string
        istream_iterator<string>(arquivo),

        // 3.2.3. Integrando os elemntos no vetor
        istream_iterator<string>(),

        // 3.2.4. Criando modelo de conjugação de conteúdo presente na linha
        [](const string& linha) {

            return !linha.empty();

        }

    );

    // 3.3. Criando uma arranjo que tem seu tamanho determinado pela quantidade de elementos lidos com sucesso nos processamentos anteriores
    int* arranjo = new int[numero_elementos_arquivo];

    // 3.4. Declara uma variação de retorno de valores padrão do compilador
    return 0;

}