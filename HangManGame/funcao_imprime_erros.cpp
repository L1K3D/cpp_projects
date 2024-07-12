#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

extern vector<char> chutes_errados;

void ImprimeErros() 
{

    cout << "Chutes errados: ";

    for (char letra : chutes_errados) 
    {
        
        cout << letra << " ";
    
    }
    
    cout << endl;

}