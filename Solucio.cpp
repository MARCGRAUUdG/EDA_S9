#include <fstream>
#include "Solucio.h"
#include <iostream>
#include <algorithm>

using namespace std;

Solucio::Solucio() {

    _mida=0;
    _midaGraf = 0;
    _cost=0.0;
}

Solucio::Solucio(const char *nomFitxerTGF) {
    std::ifstream f_ent;
    std::string n;
    int v1, v2;
    etiqueta e;
    _midaGraf = 0;

    _cost = 0.0;
    f_ent.open(nomFitxerTGF, std::ifstream::in);
    if (!f_ent.is_open())
    {
        throw ("No s'ha obert el fitxer!");
    }
    f_ent >> n;
    while (n != "#")
    {
        _midaGraf++;
        std::getline(f_ent, n);
    }
    while (!f_ent.eof())
    {
        f_ent >> v1 >> v2 >> e;
        _arestes.resize(5);
        AfegirAresta(v1, v2, e);
    }
    _arestes.resize(_midaGraf);

    f_ent.close();

}

int Solucio::nVertexs() const {
    return _mida;
}

void Solucio::AfegirAresta(int v1, int v2, etiqueta e) {
    if (not esValid(v1) or not esValid(v2)) throw("No és vàlid!");
    else if (not ExisteixAresta(v1,v2)) {
        _arestes[v1][v2] = e;
        _arestes[v2][v1] = e;
    }
}

bool Solucio::ExisteixAresta(int v1, int v2) const {
    if (not esValid(v1) or not esValid(v2)) return false;
    else return (_arestes[v1].count(v2) == 1);
}
bool Solucio::esValid(int v) const {
    return v > _mida;
}


Candidats Solucio::inicialitzarCandidats() const{

    return Candidats(_mida, _arestes.size());
}

bool Solucio::Acceptable(Candidats &iCan) const{
    vector<int>:: const_iterator it = find(_agafats.begin(),_agafats.end(),iCan.cActual());
    if(it==_agafats.end()){
        return true;
    }
    return false;
}

void Solucio::anotarCandidat(Candidats &iCan) {

    if (!_agafats.empty()) _agafats[iCan.cActual()] = 1;
    _agafats.push_back(iCan.cActual());
    _mida++;
}

void Solucio::desAnotarCandidat(Candidats &iCan) {
    if (_agafats.size() > 2)
    {
        _cost -= _arestes[_mida][iCan.cActual()];
        _agafats.pop_back();
        _mida--;
    }


}

bool Solucio::esCompleta() {
    return int(_agafats.size()) == _mida;
}

void Solucio::mostrarSolucio()const {
    for(int i=0; i< int(_agafats.size()); i++){
        cout << _agafats[i] << " ";
    }
    cout << _agafats[0];
}