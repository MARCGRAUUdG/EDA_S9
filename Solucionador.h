#ifndef EDA_S9_SOLUCIONADOR_H
#define EDA_S9_SOLUCIONADOR_H


#include "Solucio.h"
#include "Candidats.h"
#include <iostream>

class Solucionador {

public:

    bool solucionar(Solucio & sol);
    // Pre: cert
    // Post: retorna si ha trobat o no la solucio (i la guarda si l’ha trobada)

    void trobarUnaSolucio();
    // Pre: Sol inicialitzada i ant valida
    // Post: No encertat o encertat ^ sol és completa

    Solucio getSolucio();
    // Pre: cal haver exacutat solucionar
    // Post: Retorna una copia de la solucio si s’ha trobat

private:

    bool _acabat;
    Solucio _Sol;

};


#endif //EDA_S9_SOLUCIONADOR_H
