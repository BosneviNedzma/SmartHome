#include "Kuca.h"
#include <iostream>

Kuca::Kuca() : Kuca("Moja ku?a") {}

Kuca::Kuca(string naziv) {
	this->setNaziv(naziv);
}

void Kuca::setNaziv(string naziv) {
	this->naziv = naziv;
}

string Kuca::getNaziv() {
	return this->naziv;
}

void Kuca::dodajSobu(Soba* soba) {
	if (this->dajSobu(soba->getId()) != NULL) {
		throw ("Soba je ve? dodana");
	}

	this->dajSobe().push_back(*soba);
}

void Kuca::dodajUredjaj(Uredjaj* uredjaj) {
	if (this->dajUredjaj(uredjaj->getId()) != NULL) {
		throw ("Ure?aj je ve? dodan");
	}
}

vector<Soba>& Kuca::dajSobe() {
	return this->sobe;
}

vector<Uredjaj>& Kuca::dajUredjaje() {
	return this->uredjaji;
}

vector<Uredjaj>& Kuca::dajSveUredjaje() {
	shared_ptr<Kuca> kuca = make_shared<Kuca>();
	for (int i = 0; i < this->dajSobe().size(); i++) {
		Soba soba = this->dajSobe()[i];

		for (int j = 0; j < soba.dajUredjaje().size(); j++) {
			kuca->dajUredjaje().push_back(uredjaji[i]);
		}
	}

	for (int i = 0; i < this->dajUredjaje().size(); i++) {
		kuca->dajUredjaje().push_back(this->dajUredjaje()[i]);
	}

	return kuca.get()->dajUredjaje();
}

vector<Soba>& Kuca::pretraziSobe(const char* upit) {
	shared_ptr<Kuca> kuca = make_shared<Kuca>();
	for (int i = 0; i < this->dajSobe().size(); i++) {
		if (this->dajSobe()[i].pretrazi(upit)) {
			kuca->dajSobe().push_back(this->dajSobe()[i]);
		}
	}

	return kuca.get()->dajSobe();
}

vector<Uredjaj>& Kuca::pretraziUredjaje(const char* upit) {
	shared_ptr<Kuca> kuca = make_shared<Kuca>();
	for (int i = 0; i < this->dajSobe().size(); i++) {
		Soba soba = this->dajSobe()[i];
		vector<Uredjaj> uredjaji = soba.pretraziUredjaje(upit);

		for (int j = 0; j < uredjaji.size(); j++) {
			kuca->dajUredjaje().push_back(uredjaji[i]);
		}
	}

	for (int i = 0; i < this->dajUredjaje().size(); i++) {
		if (this->dajUredjaje()[i].pretrazi(upit)) {
			kuca->dajUredjaje().push_back(this->dajUredjaje()[i]);
		}
	}

	return kuca.get()->dajUredjaje();
}

Soba* Kuca::dajSobu(unsigned int id) {
	for (int i = 0; i < this->dajSobe().size(); i++) {
		Soba soba = this->dajSobe()[i];
		if (soba.getId() == id)
			return &(soba);
	}
	return NULL;
}
Uredjaj* Kuca::dajUredjaj(unsigned int id) {
	for (int i = 0; i < this->dajUredjaje().size(); i++) {
		Uredjaj uredjaj = this->dajUredjaje()[i];
		if (uredjaj.getId() == id)
			return &(uredjaj);
	}

	for (int i = 0; i < this->dajSobe().size(); i++) {
		Soba soba = this->dajSobe()[i];
		Uredjaj* uredjaj = soba.dajUredjaj(id);
		if (uredjaj != NULL) {
			return uredjaj;
		}
	}

	return NULL;
}

void Kuca::ispisi() {
	cout << "********** Informacije o kuci *************\n";
	cout << "Naziv: " << this->getNaziv() << "\n";
	cout << "Sobe: " << "\n";

	for (int i = 0; i < this->dajSobe().size(); i++) {
		this->dajSobe()[i].ispisi();
	}

	for (int i = 0; i < this->dajUredjaje().size(); i++) {
		this->dajUredjaje()[i].dajInformacije();
	}
}