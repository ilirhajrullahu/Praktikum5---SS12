#pragma once
#include <string>
#include <iostream>
using namespace std;
class Episode
{
public:
	Episode(double m_number,string m_deTitel, string m_engTitel,string m_inhalt);
	~Episode();
	void displayCompleteInfo();
	double getNumber() {
		return number;
	}
	string getInhalt() {
		return inhalt;
	}
	string getEngTitel() {
		return engTitel;
	}
	string getDeTitel() {
		return deTitel;
	}
	void showNrEng();

	string showFlashback();
private:
	double number;
	string engTitel;
	string deTitel;
	string inhalt;

};

