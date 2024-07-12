//CEFSA - Centro Educacional da Fundação Salvador Arena
//FESA - Faculdade Engenheiro Salvador Arena
//Heitor Santos Ferreira - RA: 081230042
//Engenharia de Computação - Quarto semestre - EC4
//Estruturas de Dados - Atividade N2.B1
//Professor: Israel Florentino

// 1. Realizando a importação de bibliotecas que serão usadas ao longo do código
// 1.1. Importando biblioteca de inserção e exibição de dados digitáveis
#include <iostream>

// 1.2. Importando biblioteca responsável por realizar a importação de linguagens de modelo de tempo e variações de contágem temporal
#include <ctime>

// 2. Criando modelagem de classe com o nome de "Pessoa"
// 2.1. Declara variação do termmo "Pessoa" como uma classe
class Pessoa{

    // 2.1.1. Criando atributo com modelagem de 'privado' como seu nível de privacidade
    private:

    // 2.1.1.1. Criando atributo que recebe o nome da pessoa em modelo de 'char' como linguagem de modelo de dados
    char nome_pessoa;

    // 2.1.2 Criando demais atributos com a modelagem de 'publicos' como seu nível de privacidade
    public:

    // 2.1.2.1. Criando tributo que recebe a data de nascimento de um individuo, tendo o modelo de 'tm' evocado como um outro atributo do modelo comum do C++.
    std::tm data_nascimento_pessoa;

    // 2.1.2.2. Criando atributo que recebe o peso de um individuo, tendo modelo de 'double' evocado como atributo de dados
    double peso_pessoa;

    // 2.1.2.3. Criando atributo que recebe a altura de um individuo, tendo modelo de 'double' evocado como atributo de dados
    double altura_pessoa;

};

// 3. Criando execução do código principal.
int main()
{
    
    // Execução de código...

}