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
	string strNew = "";
	string start = "<FLASHBACK>";
	string end = "</FLASHBACK>";
	string newString;
	int newStart;

while (inhalt.find("<FLASHBACK>") != std::string::npos) {

	int startIndex = inhalt.find(start);
	startIndex += start.length();
	int endIndex = inhalt.find(end, startIndex);
	strNew = inhalt.substr(startIndex, endIndex - startIndex);
	
	return strNew;
	/*newStart = endIndex += end.length();
	newString = inhalt.substr(newStart);
	inhalt = newString;*/
	
}
}
		
		
	