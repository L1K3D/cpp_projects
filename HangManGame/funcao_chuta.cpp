#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "cabecalho_letra_existe.h"

using namespace std;

extern map <char, bool> chutou;
extern vector <char> chutes_errados;

void Chuta() 
{

    cout << "Seu chute: ";
    char chute;
    cin >> chute;

    chutou[chute] = true;

    if (LetraExiste(chute)) 
    {

        cout << "Voc� acertou! Seu chute est� na palavra." << endl;
    
    }
    else 
    {

        cout << "Voc� errou! Seu chute n�o est� na palavra." << endl;
        chutes_errados.push_back(chute);
    
    }

    cout << endl;

}