#include "Soba.h"

Soba::Soba() : Soba(0, "Soba_0") {}
Soba::Soba(string naziv) : Soba(0, naziv) {}
Soba::Soba(unsigned int id, string naziv) {
	this->id = id;
	this->setNaziv(naziv);
}

void Soba::setNaziv(string naziv) {
	this->naziv = naziv;
}

string Soba::getNaziv() {
	return this->naziv;
}

unsigned int Soba::getId() {
	return this->id;
}

vector<Uredjaj>& Soba::dajUredjaje() {
	return this->uredjaji;
}

Uredjaj* Soba::dajUredjaj(unsigned int id) {
	for (int i = 0; i < this->dajUredjaje().size(); i++) {
		if (this->dajUredjaje()[i].pretrazi(upit)) {
			soba->dajUredjaje().push_back(this->dajUredjaje()[i]);
		}
	}
	return soba.get()->dajUredjaje();
}

bool Soba::pratrazi(const char* upit) {
	return strcmpi(this->getNaziv().c_str(), upit) == 0;
}

void Soba::dajUredjaj(Uredjaj* uredjaj) {
	if (this->dajUredjaj(uredjaj->getId()) != NULL) {
		throw ("Uredjaj je vec dodan u sobu");
	}
	this->dajUredjaje().push_back(*uredjaj);
}

void Soba::ispisi() {
	cout << "Podaci o sobi\n";
	cout << "Id:\t" << this->getId() << endl;
	cout << "Naziv:\t" << this->getNaziv() << endl;
	cout << "Uredjaji:\n";
	for (int i = 0; i < this->dajUredjaje().size(); i++) {
		Uredjaj uredjaj = this->dajUredjaje()[i];
		uredjaj.dajInformacije();
	}
}