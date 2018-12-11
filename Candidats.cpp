#include "Candidats.h"


bool Candidats::esFi() {

    return _iCan == 1;
}

Candidats::Candidats(int ant) {

    _iCan=1;
    _CAnt=ant;

}

int Candidats::cActual() {

    if (esFi()) throw("No hi ha més candidats");
    //_Cact=(_TDespl[_iCan]*_nSalts) + _CAnt;
    return _iCan ;
}

void Candidats::seguent() {
    //buscar a la taula el seguent candidat i actualitzar l'anterior
    if (esFi()) throw("No hi ha més candidats");
    _iCan++;

}

Candidats::Candidats() {

    _iCan=1;
}

int Candidats::cAnterior() {
    if (esFi()) throw("No hi ha més candidats");
    //_Cact=(_TDespl[_iCan]*_nSalts) + _CAnt;
    return _CAnt ;
}

