#pragma once
#include "Log.h"
#include <vector>
#include <string>

using namespace std;

enum class Status{IzvanMreze, NaMrezi, Aktivan, Ugasen};

class Uredjaj {
private:
	unsigned int id;
	string naziv, opis;
	Status status;
	vector<Log>logovi;
	void upisiLog(string poruka, Tip tip);

public:
	Uredjaj();
	Uredjaj(unsigned int id);
	Uredjaj(unsigned int id, string naziv);
	Uredjaj(unsigned int id, string naziv, string opis);
	void promjeniStatusMreze(bool naMrezi);
	void ukljuciUredjaj();
	void iskljuciUredjaj();
	void setNaziv(string naziv);
	void setOpis(string opis);
	string getNaziv();
	string getOpis();
	unsigned int getId();
	vector<Log>& dajLogove();
	bool pretrazi(const char* upit);
	string dajStatus();
	void prikaziHistoriju();
	string dajInformacije();
	~Uredjaj() = default;


};