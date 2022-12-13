#include "Uredjaj.h"
#include <cstring>
#include <iostream>

Uredjaj::Uredjaj(unsigned int id, string naziv, string opis) {
	this->id = id;
	this->setNaziv(naziv);
	this->setOpis(opis);
	this->status = Status::IzvanMreze;
}

Uredjaj::Uredjaj() : Uredjaj (0, "Test_0", "Ovo je testni uredjaj"){}
Uredjaj::Uredjaj(unsigned int id) : Uredjaj(id, "Test_" + id, "Ovo je testni uredjaj"){}
Uredjaj::Uredjaj(unsigned int id, string naziv) : Uredjaj(id, naziv, "Ovo je testni uredjaj"){}

void Uredjaj::promjeniStatusMreze(bool naMrezi) {
	if (naMrezi) {
		this->status = Status::NaMrezi;
		this->upisiLog("Uredjaj je na mrezi", Tip::Informacija);
	}
	else {
		this->status = Status::IzvanMreze;
		this->upisiLog("Uredjaj je izvan mreze", Tip::Upozorenje);
	}
}

void Uredjaj::ukljuciUredjaj() {
	if (this->status == Status::IzvanMreze) {
		this->upisiLog("Nije moguce ukljuciti uredjaj, jer je izvan mreze", Tip::Greska);
		throw("Uredjaj je izvan mreze");
	}
	if (this->status == Status::Ugasen || this->status == Status::NaMrezi) {
		this->status = Status::Aktivan;
		this->upisiLog("Uredjaj je ukljucen", Tip::Informacija);
	}
}

void Uredjaj::iskljuciUredjaj() {
	if (this->status == Status::IzvanMreze) {
		this->upisiLog("Nije moguce iskljuciti uredjaj, jer je izvan mreze", Tip::Greska);
		throw("Uredjaj je izvan mreze");
	}

	if (this->status == Status::Aktivan) {
		this->status = Status::Ugasen;
		this->upisiLog("Uredjaj je ugasen", Tip::Informacija);
	}
}

void Uredjaj::setNaziv(string naziv) {
	this->naziv = naziv;
}

void Uredjaj::setOpis(string opis) {
	this->opis = opis;
}

string Uredjaj::getNaziv() {
	return this->naziv;
}

string Uredjaj::getOpis() {
	return this->opis;
}

unsigned int Uredjaj::getId() {
	return this->id;
}

vector<Log>& Uredjaj::dajLogove() {
	return this->logovi;
}

bool Uredjaj::pretrazi(const char* upit) {
	return strcmpi(this->getNaziv().c_str(), upit) == 0;
}

void Uredjaj::prikaziHistoriju() {
	int brojLogova = this->dajLogove().size();

	cout << "Logovi\n";
	for (int i = brojLogova; i > 0; i--) {
		Log log = this->dajLogove()[i];
		cout << log.prikazi() << endl;
	}
}

string Uredjaj::dajStatus() {
	switch (this->status) {
	case Status::NaMrezi:
		return "Na mrezi";
	case Status::IzvanMreze:
		return "Izvan mreze";
	case Status::Aktivan:
		return "Aktivan";
	case Status::Ugasen:
		return "Ugasen";
	default:
		return "Nepoznat status";
	}
}

string Uredjaj::dajInformacije() {
	return this->getId() + " - " + this->getNaziv() + " - " + this->dajStatus() + "\n" + this->getOpis() + "\n";
}

void Uredjaj::upisiLog(string poruka, Tip tip) {
	Log log;
	string info = this->getId() + " - " + this->getNaziv() + ": " + poruka;

	switch (tip) {
	case Tip::Informacija:
		log.upisiInformaciju(info.c_str());
		break;

	case Tip::Upozorenje:
		log.upisiUpozorenje(info.c_str());
		break;

	case Tip::Greska:
		log.upisiGresku(info.c_str());
		break;

	default:
		break;

	}
}