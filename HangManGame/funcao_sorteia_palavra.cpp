#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "cabecalho_le_arquivo.h"

using namespace std;

extern string palavra_secreta;

void SorteiaPalavra() 
{

    vector <string> palavras = LeArquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];

}