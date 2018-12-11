//
// Created by Marc Grau on 09/12/2018.
//

#ifndef EDA_S9_CANDIDATS_H
#define EDA_S9_CANDIDATS_H


#include <vector>

using namespace std;

class Candidats {

public:

    Candidats();
    // Pre:--
    // Post: Inicialitza per defecte

    Candidats(int ant);
    // Pre: n>0
    // Post: S’ha inicialitzat el candidat amb la posicio anterior i el nombre de salts

    bool esFi();
    // Pre: --
    // Post: Retorna cert si ja no queden candidats

    int cActual();
    // Pre:-- (Error: no hi ha candidat)
    // Post: Actualitza el candidat actual, el guarda i el retorna

    int cAnterior();

    void seguent();
    // Pre: -- (Error: no hi ha candidat)
    // Post: Passa al següent candidat


private:

    int _iCan;
    int _nSalts;
    int _CAnt;
    int _Cact;

};


#endif //EDA_S9_CANDIDATS_H
