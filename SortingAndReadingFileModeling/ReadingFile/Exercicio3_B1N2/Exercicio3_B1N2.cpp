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

// 1.4. Importando biblioteca responsável por permitir a criação e manipulação de vetores de dados e de sistema de maneira mais eficiente
#include <vector>

// 1.5. Importando biblioteca responsável por importar as variações de leitura de 'string', não nativas do C++
#include <string>

//--//--//--//--//--//--//--//--//--//--//

// 2. Ancorando variação de namespace para que o mesmo use os rescursos do modelo interno standard
using namespace std;

//--//--//--//--//--//--//--//--//--//--//

// 3. Criando modelo de execução principal do software e seus demais elementos
int main()
{

    // 3.1. Declarando o caminho da pasta da qual o arquivo tabular está localizado
    string caminhoArquivoCSV = "X:\\Alunos\\081230042\\dados_pessoais.csv";

    // 3.2. Realizando a leitura do arquivo em modelo de streaming de acesso aos dados e atribuindo mesmo a uma variavel
    fstream file(caminhoArquivoCSV);

    // 3.3. Criando sequencia de verificação responsável pela validação de existência do arquivo
    // 3.3.1. Inicializa a sequência de verificação através de uma tentativa de abertura e já captura dos elementos e dados sistêmicos supostamente presentes no arquivo declarado
    if (!file.is_open()) {

        // 3.3.2. Exibe uma mensagem de erro caso o acesso ao arquivo supostamente em caminho declarado seja negada ou caso o arquivo não exista ou sua localização devida seja impossível
        cerr << "Erro ao abrir o arquivo CSV." << endl;
        return 1;

    }

    // 3.4. Cria vetor que recebe apenas dados em modelo 'string' com o nome de 'arranjoComDados'
    vector < vector < string >>  arranjoComDados;

    // 3.5. Cria modelos repetição para obtenção dos dados presente no arquivo de maneira organizada a fim de manter a performance do software e fazer com que o mesmo seja capaz de atribuir os valores obtidos para o vetor declarado anteriormente
    // 3.5.1. Cria variavel com o nome de 'linha' e atribui o dado do tipo 'string' a mesma. Essa variavel será responsável por armazenar os valores contidos em cada linha durante a execução do loop
    string linha;

    //3.5.2. Cria laço while onde sua condição de encerramento é a nullalidade valores supostamente presentes no arquivo tabular lido, ou seja, quando alguma linha do arquivo tabular for lido, o loop é interrompido
    while (getline(file, linha))
    {

        // 3.5.2.1. Cria variavel do tipo stream de string, ou seja, conversão forçada dos valores para string, valores esses todos presentes na variavel linha
        istringstream iss(linha);

        // 3.5.2.2. Cria um novo vetor do tipo string que armazena o número da linha
        vector<string> row;

        // 3.5.2.3. Cria variavel com o nome de 'campo' e atribui o dado do tipo 'string' a mesma. Essa variavel será responsável por armazenar os nomes e valores segmentando pelos campo/colunas presentes no arquivo tabular lido anteriormente
        string campo;

        // 3.5.2.4. Cria laço while onde analisa cada campo com suas variações e separadores do arquivo tabular
        while (getline(iss, campo, ';'))
        {

            // 3.5.2.4.1. Atribui a lógica de execução onde para cada linha presente no arquivo tabular, o mesmo é atribuido para o último valor a preencher o vetor e lê o próximo
            row.push_back(campo);

        }

        // 3.5.2.5. Atribui todos os valores presentes na linha na variavel 'row' para o arranjo de nome 'arranjoComDados'
        arranjoComDados.push_back(row);

    }

    // 3.6. Fecha a conexão com o arquivo tabular, uma vez que os dados necessários já foram coletados e manipulados
    file.close();

    // 3.7. Cria uma constante de repetição, laço for, que conjulga e trabalha a execução de cada linha presente no arranjo
    for (const auto& row : arranjoComDados) {

        // 3.7.1. Cria uma segunda constante de repetição de laço for que conjulga cada campo presente na linha que populou o arranjo
        for (const auto& campo : row) {

            // 3.7.1.1. Exibe cada item presente em cada campo para cada linha
            cout << campo << "\t";

        }

        // 3.7.2. Evoca um separador de linha genêrico do C++ para melhor formatação da exibição do código
        cout << endl;

    }

    // 3.8. Declara uma variação de retorno de valores padrão do compilador
    return 0;

}