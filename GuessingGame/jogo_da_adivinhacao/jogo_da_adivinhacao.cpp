//Jogo da adivinhação
//Desenvolvedor: Heitor Santos Ferreira - L1K3D
//LinkedIn: https://www.linkedin.com/in/heitor-ferreira-15a244204/
//GitHub: https://github.com/L1K3D
//X (twitter): https://twitter.com/HeitorZA

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//

// 1. Preparando o ambiente para execução do software
// 1.1. Importando bibliotecas que serão usadas ao longo da execução do software
#include <iostream>
#include <random>

// 1.2. Importando instância do espaço de trabalho como o padrão de uso do C++
using namespace std;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*//

// 2. Inicializando função principal do software
int main()
{
    
    // 2.1. Exibindo titulo do jogo
    cout << "************************************" << endl;
    cout << "* Bem-vindo ao jogo da adivinhacao *" << endl;
    cout << "************************************" << endl;

    // 2.2. Criando 'check-point' para inicialização de novo ciclo de menu de seleção de dificuldades
    Inicializacao:

    //2.2.1. Exibindo opções de níveis de dificuldade
    cout << "Escolha o seu nível de dificuldade" << endl;
    cout << "Facil (F)" << endl;
    cout << "Medio (M)" << endl;
    cout << "Dificil (D)" << endl;
    cout << ">> ";

    // 2.2.2. Declarando variavel que irá receber o valor de resposta do nível de dificuldade selecionado pelo usuário
    char dificuldade;
    cin >> dificuldade;

    // 2.2.3. Declarando variavel que irá receber o valor do número de tentativas com base no nível de dificuldade selecionado pelo usuário anteriormente
    int numero_tentativas_escolhidas;

    // 2.2.4. Criando chaves de verificação para determinar o número de tentativas que o usuário terá com base em sua escolha de dificuldade
    // 2.2.4.1. Caso a dificuldade selecionada seja 'F', referencindo a dificuldade 'Fácil', é determinado que o usuário terá 15 tentativas
    if (dificuldade == 'F') {

        numero_tentativas_escolhidas = 15;

    }
    // 2.2.4.2. Caso a dificuldade selecionada seja 'M', referencindo a dificuldade 'Médio', é determinado que o usuário terá 10 tentativas
    else if (dificuldade == 'M') {

        numero_tentativas_escolhidas = 10;

    }
    // 2.2.4.3. Caso a dificuldade selecionada seja 'D', referencindo a dificuldade 'Díficl', é determinado que o usuário terá 5 tentativas
    else if (dificuldade == 'D') {

        numero_tentativas_escolhidas = 5;

    }
    // 2.2.4.4. Caso nenhuma das letras validas ('D', 'M', 'F') sejam digitadas, solicita que o usuário selecione uma opção valida, retornando ao 'chek-point' com o nome de 'Inicialização' referenciado anteriormente
    else
    {
        cout << "Por favor, digite um valor valido conforme as opções demonstradas anteriormente...";
        goto Inicializacao;

    }

    // 2.2.5. Exibindo mensagem na tela para usuário para referência de geração de novo número aleatório
    cout << "Gerando novo numero aleatorio..." << endl;
    cout << "" << endl;

    // 2.2.6. Importando funcionabilidade de aleatoriedade nativa do C++
    random_device rd;

    // 2.2.7. Importando variação de números inteiros de resolução 19937 para geração de números inteiros aleatórios 
    mt19937 gen(rd());

    // 2.2.8. Instanciando a importação de um número aleatório de 1 a 100
    uniform_int_distribution<> dis(1, 100);

    // 2.2.9. Atribuindo o número gerado a uma variavel de tipagem inteira
    int numero_secreto = dis(gen);

    // 2.2.10. Indica para o usuário que um novo número aleatório foi gerado com sucesso
    cout << "Novo numero aleatorio gerado..." << endl;
    cout << "" << endl;

    // 2.2.11. Instanciando variavel de tipagem inteira que armazena o número de tentativas do usuário
    int numero_tentativas = 0;

    // 2.2.12. Instanciando variavel de tipagem de dupla virgula que armazena a quantidade de pontos que o usuário, essa variavel inicia com o valor de 100 e vai sendo descontado conforme erros do usuário
    double pontuacao = 100.00;

    // 2.2.13. Instanciando variavel de tipagem de dupla virgula que armazena o valor da penalidade sofrida pelo usuário conforme seus erros
    double total_penalidade = 0.00;

    // 2.3. Criando check-point no código para acesso do mesmo nessa posição de execução. Esse check-point incializa uma nova tentativa de advinhação do número secreto
    TentarAdivinhaNumeroGerado:

    // 2.3.1. Instanciando variavel de tipagem inteira que armazena o número chutado pelo usuário em sua tentativa de acertar o número secreto
    int numero_chute;

    // 2.3.2. Exibe uma mensagem ao usuário e solicita que o mesmo digite um número apróximado
    cout << "Digite um numero aproximado: ";

    // 2.3.3. Realiza o armazenamento do número chutado pelo usuário em sua tentativa de acertar o número secreto na varivel já declarada anteriormente
    cin >> numero_chute;

    // 2.3.4. Instanciando variavel do tipo booleana que realiza a conjulgação de acerto de adivinhação do número secreto comparando o número secreto e o número chutado
    bool acertou = (numero_secreto == numero_chute);

    // 2.3.5. Instanciando variavel do tipo boolena que realiza a conjulgação da condição do número chutado ser menor que o número de chute
    bool numero_secreto_maior_chute = (numero_secreto > numero_chute);

    // 2.3.6. Adicina '1' a variavel que contabiliza o número total de tentativas
    numero_tentativas++;
    
    // 2.3.7. Criando laço de verificação de acerto e determinação de perda de tentativa do usuário por exceder a quantidade de tentativas ou por zerar seus pontos
    if (acertou) {

        // 2.3.7.1. Exibindo "Tela de Vitória" para o usuário caso o mesmo tenha acertado o número secreto, exibindo em tela informações sobre a rodada
        cout << "Parabens! Voce acertou o numero secreto!" << endl;
        cout << "O numero era: " << numero_secreto << endl;
        cout << "Numero de tentativas ate seu acerto: " << numero_tentativas << endl;
        cout << "Sua pontuacao eh de: " << pontuacao << endl;
        cout << "Total de pontos perdidos: " << total_penalidade << endl;
        cout << "" << endl;

        // 2.3.7.2. Criando 'check-point' que grava a posição no código para o incio de uma nova tentativa do usuário caso o mesmo tenha acertado o número 
        JogarNovamenteAcertou:

        // 2.3.7.2.1. Instancia uma variavel do tipo 'string' (texto generalizado) que irá armazenar o valor da resposta do usuário
        string jogar_novamente;

        // 2.3.7.2.2. Exibe uma mensagem ao usuário o questionando se o mesmo deseja jogar novamente, e aguarda uma resposta de um único dígito, sendo "S" para "Sim" e "N" para "Não"
        cout << "Voce deseja jogar novamente? Digite 'S' para 'Sim' e 'N' para 'Nao': ";
        
        // 2.3.7.2.3. Armazena a resposta do usuário na variavel instanciada anteriormente
        cin >> jogar_novamente;
        cout << "" << endl;

        // 2.3.7.2.4. Conjulga a resposta do usuário. Nesse caso, caso a reposta tenha sido "S" para "Sim", realiza as ações conjulgadas
        if (jogar_novamente == "S") {

            // 2.3.7.2.4.1. Exibe mensagem ao usuário, indicando que o jogo será reiniciado
            cout << "Que legal! Vamos jogar de novo entao..." << endl;
            cout << "" << endl;

            // 2.3.7.2.4.2. Aponta a execução do código para o 'check-point' com o nome de "Inicialização" instanciado anteriormente
            goto Inicializacao;

        }
        else if (jogar_novamente == "N") {

            cout << "Puxa... Que pena... Espero que voce tenha gostado, qualquer coisa, volte novamente para jogar!!" << endl;
            cout << "" << endl;

            return 0;

        }
        else
        {

            cout << "Por favor, digite uma condicao valida..." << endl;
            cout << "" << endl;
            goto JogarNovamenteAcertou;

        }

    }
    else if (numero_secreto_maior_chute) {

        cout << "Voce chutou um numero a baixo do numero secreto! Por favor, tente novamente..." << endl;
        cout << "" << endl;

        double valor_penalidade = abs(((numero_secreto - numero_chute) / 2.0));

        total_penalidade = total_penalidade + valor_penalidade;

        pontuacao = pontuacao - valor_penalidade;

        if ((pontuacao == 0.00) || (numero_tentativas_escolhidas == numero_tentativas)) {

            cout << "Desculpe, voce perdeu..." << endl;

            JogarNovamenteChuteBaixo:
            string jogar_novamente;

            cout << "Voce deseja jogar novamente? Digite 'S' para 'Sim' e 'N' para 'Nao': ";
            cin >> jogar_novamente;
            cout << "" << endl;

            if (jogar_novamente == "S") {

                cout << "Que legal! Vamos jogar de novo entao..." << endl;
                cout << "" << endl;
                goto Inicializacao;

            }
            else if (jogar_novamente == "N") {

                cout << "Puxa... Que pena... Espero que voce tenha gostado, qualquer coisa, volte novamente para jogar!!" << endl;
                cout << "" << endl;

                return 0;

            }
            else
            {

                cout << "Por favor, digite uma condicao valida..." << endl;
                cout << "" << endl;
                goto JogarNovamenteChuteBaixo;

            }


        }
        else
        {

            goto TentarAdivinhaNumeroGerado;

        }

    }
    else
    {

        cout << "Voce chutou um numero acima do numero secreto! Por favor, tente novamente..." << endl;
        cout << "" << endl;

        double valor_penalidade = abs(((numero_secreto - numero_chute) / 2.0));

        total_penalidade = total_penalidade + valor_penalidade;

        pontuacao = pontuacao - valor_penalidade;

        if ((pontuacao == 0.00) || (numero_tentativas_escolhidas == numero_tentativas)) {

            cout << "Desculpe, voce perdeu..." << endl;

            JogarNovamenteChuteAcima:
            string jogar_novamente;

            cout << "Voce deseja jogar novamente? Digite 'S' para 'Sim' e 'N' para 'Nao': ";
            cin >> jogar_novamente;
            cout << "" << endl;

            if (jogar_novamente == "S") {

                cout << "Que legal! Vamos jogar de novo entao..." << endl;
                cout << "" << endl;
                goto Inicializacao;

            }
            else if (jogar_novamente == "N") {

                cout << "Puxa... Que pena... Espero que voce tenha gostado, qualquer coisa, volte novamente para jogar!!" << endl;
                cout << "" << endl;

                return 0;

            }
            else
            {

                cout << "Por favor, digite uma condicao valida..." << endl;
                cout << "" << endl;
                goto JogarNovamenteChuteAcima;

            }

        }
        else
        {

            goto TentarAdivinhaNumeroGerado;

        }
            

    }

}