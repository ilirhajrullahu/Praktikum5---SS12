#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <iterator>
#include <sstream> 
#include <algorithm>
#include <vector>
#include <fstream>
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
	void fillMap2();
	string printVec2();
	string toString() const;
private:
	double number;
	string engTitel;
	string deTitel;
	string inhalt;
	std::map <string, int> words; //nach string sortiert da string das key ist und int der wert zu dem key
	typedef pair<string, int> pair ;  //definition eines pairs aus string und int
	std::vector<pair> vec; //vector für häufigste wörter, der pair speichert (siehe eine zeile oben)
	std::map <string, int> actors;
	typedef std::pair <string, int> pair2;
	std::vector<pair2> vec2; //vector für hauptpersonen

};

