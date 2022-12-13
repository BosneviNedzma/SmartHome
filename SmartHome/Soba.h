#pragma once
#include <string>
#include <vector>
#include "Uredjaj.h"

using namespace std;

class Soba {
private:
	unsigned int id;
	string naziv;
	vector<Uredjaj>uredjaji;

public:
	Soba();
	Soba(string naziv);
	Soba(unsigned int id, string naziv);
	void setNaziv(string naziv);
	string getNaziv();
	unsigned int getId();
	vector<Uredjaji>& dajUredjaje();
	Uredjaj* dajUredjaj(unsigned int id);
	vector<Uredjaj>& pretraziUredjaje(const char* upit);
	bool pratrazi(const char* upit);
	void dodajUredjaj(Uredjaj* uredjaj);
	void ispisi();
	~Soba() = default;
};
