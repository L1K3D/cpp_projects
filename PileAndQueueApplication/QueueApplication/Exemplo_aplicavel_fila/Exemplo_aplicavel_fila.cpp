// Exemplo_aplicavel_fila.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <queue>;

using namespace std;

int main()
{

    //Cria uma fila com itens do tipo string, essa lista se chama 'cartas'
    queue < string > cartas;

    //OBS -> O exemplo de cartas foi usado pois em um baralho, a última carta a ser inserida em um baralho de compras
    //vai parar ao final da pilha de cartas, e assim ela é a primeira a ser comprada

    //OBS2 -> Uma pilha contémn um conceito de armazenamento mais dinâmico do que um arranjo ou um vetor, tornando-se
    //desnecessário declararmos o tamnho que uma pilha vai ter

    //Nesse exemplo, são adicionadas quatro cartas, sendo o primeiro item de possível manipulação, a carta de nome "Mago Negro",.
    //pois a mesma foi a última carta a ser inserida
    cartas.push("Dragão Branco de Olhos Azuis");
    cartas.push("O sarcofago risonho");
    cartas.push("Braço do Ezôdia");
    cartas.push("Mago Negro");

    //Exibe o tamanho da pilha, ou seja, nos diz quanto ele ocupa na memória e exibe a quantidade dos itens presentes na pilha
    cout << "Tamanho da fila: " << cartas.size() << "\n";

    //Exibe a carta que está a frente da fila
    cout << "Carta que está na frente da fila: " << cartas.front() << "\n";

    //Exibe a carta que está no final da fila
    cout << "Carta que está no final da fila: " << cartas.back() << "\n";

    //Elimina o último item a ser adicionado na pilha, ou seja, o item que está no topo da pilha, nesse exemplo, a carta "Mago Negro"
    cartas.pop();

    //Exibe o tamanho da pilha, ou seja, nos diz quanto ele ocupa na memória e exibe a quantidade dos itens presentes na pilha
    cout << "Tamanho da fila: " << cartas.size() << "\n";

    //Exibe a carta que está a frente da fila
    cout << "Carta que está na frente da fila: " << cartas.front() << "\n";

    //Exibe a carta que está no final da fila
    cout << "Carta que está no final da fila: " << cartas.back() << "\n";
	
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
