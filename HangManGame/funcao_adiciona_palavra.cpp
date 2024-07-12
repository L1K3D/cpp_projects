#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "cabecalho_salva_arquivo.h"
#include "cabecalho_le_arquivo.h"

using namespace std;

void AdicionaPalavra()
{

    cout << "Digite a nova palavra, usando letras maiúsculas." << endl;
    string nova_palavra;
    cin >> nova_palavra;

    vector<string> lista_palavras = LeArquivo();
    lista_palavras.push_back(nova_palavra);

    SalvaArquivo(lista_palavras);

}