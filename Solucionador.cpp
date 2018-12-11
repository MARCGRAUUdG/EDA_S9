#include "Solucionador.h"

Solucionador::Solucionador() {

    _encertat=false;

}

void Solucionador::trobarUnaSolucio(Solucio & sol) {

    Candidats iCan=sol.inicialitzarCandidats();
    while ( ! iCan.esFi() )
    {
        if(sol.Acceptable(iCan))
        {

            sol.anotarCandidat(iCan);
            if (! sol.esCompleta())
            {
                trobarUnaSolucio(sol);
                if (! _encertat)
                {
                    sol.desAnotarCandidat(iCan);
                }

            }
            else
            {
                _encertat=true;

            }
        }
        iCan.seguent();

    }
}



bool Solucionador::solucionar(Solucio &sol) {

    _encertat=false;
    _S=sol;
    trobarUnaSolucio(_S);

    return _encertat;
}

Solucio Solucionador::getSolucio() {

    return _S;

}


