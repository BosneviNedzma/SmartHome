#include <iostream>
#include <vector>
#include "Kuca.h"
#include "Soba.h"
#include "Uredjaj.h"

using namespace std;

Kuca kuca;
int glavniMeni() {
	cout << "1. Unesi ku?u\n";
	cout << "2. Dodaj sobu\n";
	cout << "3. Dodaj ure?aj\n";
	cout << "4. Pretraži sobe\n";
	cout << "5. Pretraži ure?aje\n";
	cout << "6. Upravljaj sobom\n";
	cout << "7. Upravljaj ure?ajem\n";
	cout << "8. Ispisi\n";
	cout << "9. Kraj\n";

	int izbor;
	do {
		cout << "Izbor: ";
		cin >> izbor;
	} while (izbor < 1 || izbor > 9);

	cin.ignore();
	return izbor;
}

void unesiKucu() {
	char naziv[50];
	cout << "Unesite naziv ku?e: \n";
	cin.getline(naziv, 50);
	kuca = Kuca(naziv);
}

void dodajSobu() {
	char naziv[50];
	cout << "Unesite naziv sobe: \n";
	cin.getline(naziv, 50);
	int brojSoba = kuca.dajSobe().size() + 1;
	Soba soba = Soba(brojSoba, naziv);
	kuca.dodajSobu(&soba);
}

void dodajUredjajKuca() {
	char naziv[50];
	cout << "Unesite naziv ure?aja: \n";
	cin.getline(naziv, 50);
	int brojUredjaja = kuca.dajSveUredjaje().size() + 1;
	Uredjaj uredjaj = Uredjaj(brojUredjaja, naziv);
	kuca.dodajUredjaj(&uredjaj);
}

void pretraziSobe() {
	char upit[50];
	cout << "Unesite naziv sobe: \n";
	cin.getline(upit, 50);
	vector<Soba>& sobe = kuca.pretraziSobe(upit);
	if (sobe.size() == 0) {
		cout << "Ne postoji soba za uneseni upit.\n";
	}
	else {
		cout << "Na?ene sobe: \n";
		for (int i = 0; i < sobe.size(); i++) {
			sobe[i].ispisi();
		}
	}
}

void pretraziUredjaje() {
	char upit[50];
	cout << "Unesite naziv ure?aja: \n";
	cin.getline(upit, 50);
	vector<Uredjaj>& uredjaji = kuca.pretraziUredjaje(upit);
	if (uredjaji.size() == 0) {
		cout << "Ne postoji ure?aj za uneseni upit.\n";
	}
	else {
		cout << "Na?eni ure?aji: \n";
		for (int i = 0; i < uredjaji.size(); i++) {
			uredjaji[i].dajInformacije();
		}
	}
}

int sobaMeni() {
	cout << "1. Unesi uredjaj\n";
	cout << "2. Pretraži ure?aje\n";
	cout << "3. Upravljaj ure?ajima\n";
	cout << "4. Ispisi\n";
	cout << "5. Kraj\n";

	int izbor;
	do {
		cout << "Izbor: ";
		cin >> izbor;
	} while (izbor < 1 || izbor > 5);

	cin.ignore();
	return izbor;
}

int uredjajMeni() {
	cout << "1. Promjeni status\n";
	cout << "2. Upali\n";
	cout << "3. Izgasi\n";
	cout << "4. Ispisi\n";
	cout << "5. Kraj\n";

	int izbor;
	do {
		cout << "Izbor: ";
		cin >> izbor;
	} while (izbor < 1 || izbor > 5);

	cin.ignore();
	return izbor;
}

void unesiUredjajSoba(Soba* soba) {
	char naziv[50];
	cout << "Unesite naziv ure?aja: \n";
	cin.getline(naziv, 50);
	int brojUredjaja = kuca.dajSveUredjaje().size() + 1;
	Uredjaj uredjaj = Uredjaj(brojUredjaja, naziv);
	soba->dodajUredjaj(&uredjaj);
}

void pretraziUredjajeSoba(Soba* soba) {
	char upit[50];
	cout << "Unesite naziv ure?aja: \n";
	cin.getline(upit, 50);
	vector<Uredjaj>& uredjaji = soba->pretraziUredjaje(upit);
	if (uredjaji.size() == 0) {
		cout << "Ne postoji ure?aj za uneseni upit.\n";
	}
	else {
		cout << "Na?eni ure?aji: \n";
		for (int i = 0; i < uredjaji.size(); i++) {
			uredjaji[i].dajInformacije();
		}
	}
}

void promjeniStatus(Uredjaj* uredjaj) {
	int broj;
	cout << "Da li je ure?aj na mreži? 0 ili bilo sta drugo 0 - nije na mreži \n";
	cin >> broj;
	uredjaj->promjeniStatusMreze(broj == 0);
}

void upali(Uredjaj* uredjaj) {
	uredjaj->ukljuciUredjaj();
	cout << "Ure?aj je uklju?en\n";
}

void izgasi(Uredjaj* uredjaj) {
	uredjaj->iskljuciUredjaj();
	cout << "Ure?aj je isklju?en\n";
}

void upravljajUredjajem(Soba* soba) {
	int id;
	cout << "Unesite id uredjaja: \n";
	cin >> id;

	Uredjaj* uredjaj;
	if (soba == NULL) {
		uredjaj = kuca.dajUredjaj(id);
	}
	else {
		uredjaj = soba->dajUredjaj(id);
	}

	if (uredjaj == NULL) {
		cout << "Ne postoji soba sa id-jem: " << id << "\n";
		return;
	}

	int izbor;
	do {
		izbor = uredjajMeni();
		switch (izbor)
		{
		case 1:
			promjeniStatus(uredjaj);
			break;
		case 2:
			upali(uredjaj);
			break;
		case 3:
			izgasi(uredjaj);
			break;
		case 4:
			uredjaj->dajInformacije();
			break;
		default:
			break;
		}
	} while (izbor != 5);
}

void upravljajSobom() {
	int id;
	cout << "Unesite id sobe: \n";
	cin >> id;

	Soba* soba = kuca.dajSobu(id);
	if (soba == NULL) {
		cout << "Ne postoji soba sa id-jem: " << id << "\n";
		return;
	}

	int izbor;
	do {
		izbor = sobaMeni();
		switch (izbor)
		{
		case 1:
			unesiUredjajSoba(soba);
			break;
		case 2:
			pretraziUredjajeSoba(soba);
			break;
		case 3:
			upravljajUredjajem(soba);
			break;
		case 4:
			soba->ispisi();
			break;
		default:
			break;
		}
	} while (izbor != 5);
}

int main()
{
	int izbor;
	do {
		izbor = glavniMeni();
		switch (izbor)
		{
		case 1:
			unesiKucu();
			break;
		case 2:
			dodajSobu();
			break;
		case 3:
			dodajUredjajKuca();
			break;
		case 4:
			pretraziSobe();
			break;
		case 5:
			pretraziUredjaje();
			break;
		case 6:
			upravljajSobom();
			break;
		case 7:
			upravljajUredjajem(NULL);
			break;
		case 8:
			kuca.ispisi();
			break;
		default:
			break;
		}
	} while (izbor != 9);
}