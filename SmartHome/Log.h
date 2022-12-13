#pragma once
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

enum class Tip {Informacija, Upozorenje, Greska};

class Log {
private:
	char info[1000];
	Tip tip;
	time_t vrijeme;
	string dajTip();

public:
	void upisiGresku(const char poruka[1000]);
	void upisiUpozorenje(const char poruka[1000]);
	void upisiInformaciju(const char poruka[1000]);
	string prikazi();
	~Log() = default;

};