#include <iostream>

#include <string>
#include <cstring>
#include "Solucio.h"
#include "Solucionador.h"

int main() {

    std::cout << "Entra el nom del fitxer d'entrada:" << std::endl;
    string str;
    std::cin >> str;
    char * cstr = new char [str.size()+1];
    std::strcpy(cstr, str.c_str());

    Solucio s=Solucio(cstr);
    Posicio inici(1,1);
    Solucionador backtracking;
    backtracking.solucionar(s,inici);

    if (backtracking.solucionar(s,inici))
    {
        s=backtracking.getSolucio();
        s.mostrarSolucio();

    }
    else std::cout << "No te solucio" << std::endl;

    delete [] cstr;



    return 0;
}