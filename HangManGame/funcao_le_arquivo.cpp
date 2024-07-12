#include <iostream>
#include <map>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "cabecalho_le_arquivo.h"


using namespace std;

vector <string> LeArquivo() 
{

    ifstream arquivo;
    arquivo.open("palavras.txt");

    if (arquivo.is_open()) 
    {

        int quantidade_palavras;
        arquivo >> quantidade_palavras;


        vector <string> palavras_do_arquivo;

        for (int i = 0; i < quantidade_palavras; i++) 
        {

            string palavra_lida;
            arquivo >> palavra_lida;
            palavras_do_arquivo.push_back(palavra_lida);

        }

        arquivo.close();
        return palavras_do_arquivo;

    }
    else 
    {

        cout << "N�o foi poss�vel acessar o banco de palavras." << endl;
        exit(0);

    }

}