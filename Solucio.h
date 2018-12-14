//
// Created by Marc Grau on 09/12/2018.
//

#ifndef EDA_S9_SOLUCIO_H
#define EDA_S9_SOLUCIO_H


#include <vector>
#include "Candidats.h"
#include <list>
#include <map>

typedef float etiqueta;
//typedef string etiqueta;
const float etiqNula = -1;
//const string etiqNula ="";

class Solucio {

public:

    Solucio();
    //Pre: --
    //Post: Inicialitza la mida i el nivell de la solucio a 0

    Solucio(const char *nomFitxer);
    //Pre:--
    //Post: Inicialitza la solucio amb les dades del fitxer de nom "nomFitxer"

    Candidats inicialitzarCandidats() const;
    // Pre: --
    // Post: Retorna els candidats del nivell actual

    bool Acceptable(Candidats & iCan) const;
    // Pre: --
    // Post: Retorna cert si el candidat es pot afegir a la solució

    void anotarCandidat(Candidats & iCan);
    // Pre: iCan és acceptable
    // Post: Afegeix iCan a la solucio

    void desAnotarCandidat(Candidats &iCan);
    // Pre: iCan és el darrer candidat anotat
    // Pos: Es treu iCan de la solucio (darrer candidat anotat)

    bool esCompleta();
    // Pre: --
    // Post: Retorna cert si la solució ja és completa

    void mostrarSolucio()const;
    //Pre: --
    //Post: Mostra la solucio per pantalla

    int nVertexs() const;
    bool esDirigit() const;
    void AfegirAresta(int v1, int v2, etiqueta e);
    bool ExisteixAresta(int v1, int v2) const;


private:
    int _mida;
    float _cost;
    int _midaGraf;

    std::vector<int> _agafats;
    std::vector< std::map<int, etiqueta> > _arestes;

    bool esValid(int v) const;

};

#endif //EDA_S9_SOLUCIO_H
