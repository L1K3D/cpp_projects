#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

extern vector <char> chutes_errados;

bool NaoEnforcou() 
{

    return chutes_errados.size() < 5;

}