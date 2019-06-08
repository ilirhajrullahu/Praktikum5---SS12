#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <sstream> 
#include <algorithm>
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
	void fillMap();
	void printVec();
private:
	double number;
	string engTitel;
	string deTitel;
	string inhalt;
	std::map <string, int> words;
	typedef pair<std::string, int> pair;
	std::vector<pair> vec;


};

