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

	do {

	startIndex = inhalt.find(start);
	startIndex += start.length();
	endIndex = inhalt.find(end, startIndex);
	strNew += inhalt.substr(startIndex, endIndex - startIndex);
	newStart = endIndex + end.length() ;
	inhalt = inhalt.substr(newStart);
	
	} while (inhalt.find("<FLASHBACK>") != std::string::npos);
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
		std::cout << it->first << " " << it->second << endl;
	}
	} 