#include "pch.h"
#include "Episode.h"


Episode::Episode(double m_number, string m_deTitel, string m_engTitel, string m_inhalt) :number(m_number), deTitel(m_deTitel), engTitel(m_engTitel), inhalt(m_inhalt) {

}
Episode::Episode(const Episode& orig):number(orig.number), deTitel(orig.deTitel),engTitel(orig.engTitel),inhalt(orig.inhalt)  {

}

Episode::~Episode()
{
}

void Episode::displayCompleteInfo() {
	cout << "Episode : " << number << " " << "Titel: " << engTitel << " " << "Titel auf Deutsch: " << deTitel << endl;
	cout << inhalt << endl;
}

void Episode::showNrEng() {
	cout << number << " " <<engTitel << endl;
	
}

string Episode::getFlashback() {
	string strNew = "";
	string start = "<FLASHBACK>";
	string end = "</FLASHBACK>";
	string newString = "";
	int newStart = 0;
	int startIndex = 0;
	int endIndex = 0;
	string temp = inhalt;
	do {
		
	startIndex = temp.find(start);
	startIndex += start.length();
	endIndex = temp.find(end, startIndex);
	strNew += temp.substr(startIndex, endIndex - startIndex);
	newStart = endIndex + end.length() ;
	temp = temp.substr(newStart);
	
	} while (temp.find("<FLASHBACK>") != std::string::npos);
	return strNew;
}
		
void Episode::fillMap() {

	string tmp;
	stringstream ss(getFlashback());
	while (getline(ss, tmp, ' '))
	{
		if (words.empty()) {
			words.insert({ tmp,1 });
		}
		else {
			for (auto& it : words)
			{
				if (it.first == tmp)
					{
						++it.second;
					}
				else {
					
					if (it.first != tmp)
					{
						words.insert({ tmp,1 });
						
					}
				}
			}
		}
	}
	copy(words.begin(),words.end(),back_inserter<vector<pair>>(vec));

	sort(vec.begin(), vec.end(),[](const pair& l, const pair& r) {
		if (l.second != r.second)
			return l.second > r.second;

		return l.first < r.first;
	});

}
		

void Episode::printVec() {
	fillMap();
	for(vector<pair>::iterator it = vec.begin();it!=vec.begin()+15;++it) {
		cout << it->first << " " << it->second << endl;
	}
	} 

void Episode::fillMap2() {

	ifstream File;
	string actor;
	File.open("Hauptpersonen.txt");
	while (File >> actor) {

		actors.insert({ actor, 0 });
	}
	File.close();

	string tmp;
	string pure = getFlashback();
	int position = pure.find(".");
	while (position != string::npos) {
		 pure.replace(position, 1, " ");
		 position = pure.find(".", position + 1);
		
	}
	int position2 = pure.find(",");
	while (position2 != string::npos) {
		pure.replace(position2, 1, " ");
		position2 = pure.find(".", position2 + 1);

	}


	stringstream ss(pure);

	while (getline(ss, tmp, ' '))
	{
		for (std::map <string, int>::iterator it = actors.begin(); it != actors.end(); ++it) {
			if (tmp == it->first) {
				it->second++;
			}
		}
	}

	copy(actors.begin(), actors.end(), back_inserter<vector<pair2>>(vec2));

	sort(vec2.begin(), vec2.end(), [](const pair2& l, const pair2& r) {
		if (l.second != r.second)
			return l.second > r.second;

		return l.first < r.first;
	});
}

string Episode::printVec2() {
	string hauptperson;
	fillMap2();
	for (auto it = vec2.begin(); it != vec2.end(); ++it) {
		if (it->second >= 5) {
			hauptperson += " ";
			hauptperson += it->first ;
		}
	}
	if (hauptperson.empty())
	{
		hauptperson = "keine spezielle ";
	}
		return hauptperson;
}

string Episode::toString() const {
	std::stringstream outStream;
	outStream << left << setw(10) << this->number << setw(7) << this->deTitel;
	return outStream.str();
}