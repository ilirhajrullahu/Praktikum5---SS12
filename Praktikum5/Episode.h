#pragma once
#include <string>
#include <iostream>
#include "Tree.h"
#include "Tree.cpp"
#include <vector>
using namespace std;
class Episode
{
public:
	Episode(double m_number,string m_deTitel, string m_engTitel,string m_inhalt);
	Episode(const Episode& orig);
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

	string getFlashback();
	void fillWordTree();
	void showFrequencyOfWords();
private:
	double number;
	string engTitel;
	string deTitel;
	string inhalt;
	Tree <string> wordTree;


};

