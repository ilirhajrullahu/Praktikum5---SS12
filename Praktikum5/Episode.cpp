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
	newStart = endIndex + end.length();
	inhalt = inhalt.substr(newStart);
	
	} while (inhalt.find("<FLASHBACK>") != std::string::npos);
	return strNew;
}
		
void Episode::fillWordTree() {
	string tmp;
	stringstream ss(getFlashback());
	vector<string> words;

	while (getline(ss, tmp, ' ')) {
		words.push_back(tmp);
	}
	for (unsigned int i = 0; i < words.size(); ++i) {
		wordTree.insertNode(words[i]);
	}
}

void Episode::showFrequencyOfWords() {
	fillWordTree();
	for (unsigned int i = 0; i < 15; ++i) {
		cout << wordTree.postOrderTraversal() << endl;
	}

}
	