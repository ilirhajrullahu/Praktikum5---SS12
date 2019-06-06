#include "pch.h"
#include "Episode.h"


Episode::Episode(double m_number,string m_deTitel, string m_engTitel,string m_inhalt):number(m_number),deTitel(m_deTitel),engTitel(m_engTitel),inhalt(m_inhalt)
{
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

string Episode::showFlashback() {
	string strNew;
	string start = "<FLASHBACK>";
	string end = "</FLASHBACK>";
	size_t startIndex = inhalt.find(start);
	startIndex += start.length();
	std::string::size_type endIndex = inhalt.find(end, startIndex); 
	return inhalt.substr(startIndex, endIndex - startIndex);
}