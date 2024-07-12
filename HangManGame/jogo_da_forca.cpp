// 1. Importando bibliotecas e funções
// 1.1. Importando bibliotecas
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

// 1.2. Importando funções/cabeçalhos
#include "cabecalho_nao_acertou.h"
#include "cabecalho_letra_existe.h"
#include "cabecalho_nao_enforcou.h"
#include "cabecalho_chuta.h"
#include "cabecalho_imprime_cabecalho_software.h"
#include "cabecalho_imprime_erros.h"
#include "cabecalho_imprime_palavra.h"
#include "cabecalho_le_arquivo.h"
#include "cabecalho_sorteia_palavra.h"
#include "cabecalho_adiciona_palavra.h"

using namespace std;

string palavra_secreta;
map < char, bool > chutou;
vector < char > chutes_errados;

int main() 
{

    ImprimeCabecalho();

    InicioPrograma:

    LeArquivo();
    SorteiaPalavra();

    while (NaoAcertou() && NaoEnforcou()) 
    {

        ImprimeErros();

        ImprimePalavra();

        Chuta();

    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;

    if (NaoAcertou()) 
    {

        cout << "Você perdeu! Tente novamente!" << endl;
        cout << endl;

        cout << "Deseja jogar novamente? (S/N)" << endl;
        char resposta_jogar_novamente;
        cin >> resposta_jogar_novamente;

        if (resposta_jogar_novamente == 'S') 
        {

            goto InicioPrograma;

        }

        else
        {

            return 0;

        }

    }

    else 
    {
        cout << "Parabéns! Você acertou a palavra secreta!" << endl;

        cout << "Você deseja adicionar uma nova palavra ao banco? (S/N) ";
        char resposta;
        cin >> resposta;

        if (resposta == 'S') 
        {

            AdicionaPalavra();

        }

    }

    cin.get();

}