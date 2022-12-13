#pragma once
#include <string>
#include <vector>
#include "Soba.h"
#include "Uredjaj.h"

using namespace std;

class Kuca {
private:
    string naziv;
    vector<Soba> sobe;
    vector<Uredjaj> uredjaji;
public:
    Kuca();
    Kuca(string naziv);
    void setNaziv(string naziv);
    string getNaziv();
    vector<Soba>& dajSobe();
    vector<Uredjaj>& dajUredjaje();
    vector<Uredjaj>& dajSveUredjaje();
    vector<Soba>& pretraziSobe(const char* upit);
    vector<Uredjaj>& pretraziUredjaje(const char* upit);
    Soba* dajSobu(unsigned int id);
    Uredjaj* dajUredjaj(unsigned int id);
    void dodajSobu(Soba* soba);
    void dodajUredjaj(Uredjaj* uredjaj);
    void ispisi();
    ~Kuca() = default;
}; #pragma once
