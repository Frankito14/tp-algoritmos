#include <iostream>
#include "menu.cpp"
#include "centro.h"
#include <string>
#include <sstream>
#include <fstream>
using namespace std;


int main()
{

    Menu *menu = new Menu();
    while (true)
        menu->mostrarMenuPrincipal();
    
    delete menu;
    return 0;
}
