#include "Log.h"
#include <format>
#include <string>

using namespace std;

void Log::upisiGresku(const char poruka[1000]) {
	this->vrijeme = time(0);
	this->tip = Tip::Greska;
	strcpy(this->info, poruka);
}

void Log::upisiUpozorenje(const char poruka[1000]) {
	this->vrijeme = time(0);
	this->tip = Tip::Upozorenje;
	strcpy(this->info, poruka);
}

void Log::upisiInformaciju(const char poruka[1000]) {
	this->vrijeme = time(0);
	this->tip = Tip::Informacija;
	strcpy(this->info, poruka);
}

string Log::prikazi() {
	char vrijeme[26];
	ctime_s(vrijeme, 26, &this->vrijeme);
	string vrijemeLoga(vrijeme);
	return vrijemeLoga + " - " + this->dajTip() + " - " << this->info + "\n";
}

string Log::dajTip() {
	switch (this->tip) {
	case Tip::Informacija:
		return "Informacija";
	case Tip::Upozorenje:
		return "Upozorenje";
	case Tip::Greska:
		return "Greska";
	default:
		return "Nepoznat tip";
	}
}