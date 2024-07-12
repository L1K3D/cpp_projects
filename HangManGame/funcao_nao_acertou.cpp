#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

extern string palavra_secreta;
extern map <char, bool> chutou;

bool NaoAcertou() 
{

    for (char letra : palavra_secreta) {
        if (!chutou[letra]) {
            return true;
        }
    }

    return false;

}