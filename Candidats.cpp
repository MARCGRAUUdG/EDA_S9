#include "Candidats.h"


bool Candidats::esFi()const {

    return _iCan > _max;
}

Candidats::Candidats(int vertex, int total_vertex) {

    _iCan=vertex;
    _max=total_vertex;

}

int Candidats::cActual() const{

    if (esFi()) throw("No hi ha més candidats");
    //_Cact=(_TDespl[_iCan]*_nSalts) + _CAnt;
    return _iCan;
}


void Candidats::seguent() {
    //buscar a la taula el seguent candidat i actualitzar l'anterior
    if (esFi()) throw("No hi ha més candidats");
    _iCan++;

}