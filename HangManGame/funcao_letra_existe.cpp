#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

extern string palavra_secreta;

bool LetraExiste(char chute) 
{

    for (char letra : palavra_secreta) {
        if (chute == letra) {
            return true;
        }
    }
    return false;

}