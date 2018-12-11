#include <fstream>
#include "Solucio.h"
#include <iostream>

using namespace std;

Solucio::Solucio() {

    _mida=0;
    _nivell=0;
}

Solucio::Solucio(const char *nomFitxerTGF, bool dirigit) {


    std::ifstream f_ent;
    std::string n;
    int v1, v2;
    float e;

    _dirigit = dirigit;
    f_ent.open(nomFitxerTGF, std::ifstream::in);
    if (!f_ent.is_open())
    {
        std::cout << "ARRIBA" << std::endl;
        throw ("No s'ha obert el fitxer!");
    }
    f_ent >> n;
    while (n != "#")
    {
        _mida++;
        std::getline(f_ent, n);
    }
    while (!f_ent.eof())
    {
        f_ent >> v1 >> v2 >> e;
        AfegirAresta(v1, v2, e);
    }
    f_ent.close();


}

int Solucio::nVertexs() const {
    return _mida;
}

bool Solucio::esDirigit() const {
    return _dirigit;
}

void Solucio::AfegirAresta(int v1, int v2, etiqueta e) {
    if (not esValid(v1) or not esValid(v2)) throw("No és vàlid!");
    else if (not ExisteixAresta(v1,v2)) {
        _arestes[v1][v2] = e;
        if (not _dirigit) _arestes[v2][v1] = e;
    }
}

bool Solucio::ExisteixAresta(int v1, int v2) const {
    if (not esValid(v1) or not esValid(v2)) return false;
    else return (_arestes[v1].count(v2) == 1);
}
bool Solucio::esValid(int v) const {
    return v > _mida;
}


Candidats Solucio::inicialitzarCandidats(int ant) {

    return Candidats(ant);
}

bool Solucio::Acceptable(Candidats &iCan) {
    auto candidat = _arestes[_nivell][iCan.cActual()];

    return (candidat <= pesMax && _agafats[iCan.cActual()] == 0);

}

void Solucio::anotarCandidat(Candidats &iCan) {
    //actualitzar vertex
    _nivell = iCan.cActual();
    _agafats[iCan.cActual()] = 1;
    pesMax = 99999;

}

void Solucio::desAnotarCandidat(Candidats &iCan) {

    _nivell = iCan.cAnterior();
    _agafats[iCan.cActual()] = 0;

}

bool Solucio::esCompleta() {
    bool complet = true;
    for (auto &agafats : _agafats)
    {
        if (agafats == 0) {complet = false;}
    }
    return complet;
}

void Solucio::mostrarSolucio()const {


}