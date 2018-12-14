//
// Created by Marc Grau on 09/12/2018.
//

#ifndef EDA_S9_CANDIDATS_H
#define EDA_S9_CANDIDATS_H


#include <vector>

class Candidats {

public:

    Candidats(int vertex, int total_vertex);
    // Pre: n>0
    // Post: S’ha inicialitzat el candidat amb la posicio anterior i el nombre de salts

    bool esFi() const;
    // Pre: --
    // Post: Retorna cert si ja no queden candidats

    int cActual() const;
    // Pre:-- (Error: no hi ha candidat)
    // Post: Actualitza el candidat actual, el guarda i el retorna

    void seguent();
    // Pre: -- (Error: no hi ha candidat)
    // Post: Passa al següent candidat


private:

    int _iCan;
    int _max;

};


#endif //EDA_S9_CANDIDATS_H
