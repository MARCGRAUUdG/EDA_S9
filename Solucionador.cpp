#include "Solucionador.h"
#include <iostream>

void Solucionador::trobarUnaSolucio() {

    Candidats iCan=_Sol.inicialitzarCandidats();
    while ( ! iCan.esFi() && !_acabat )
    {
        if(_Sol.Acceptable(iCan))
        {
            _Sol.anotarCandidat(iCan);
            if (! _Sol.esCompleta())
            {
                trobarUnaSolucio();
                if (! _acabat)
                {
                    _Sol.desAnotarCandidat(iCan);
                }
            }
            else
            {
                _acabat=true;
            }
        }
        iCan.seguent();
    }
}

bool Solucionador::solucionar(Solucio &sol) {

    _acabat=false;
    _Sol=sol;
    trobarUnaSolucio();

    return _acabat;
}

Solucio Solucionador::getSolucio() {

    return _Sol;

}


