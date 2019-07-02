#include "pch.h"
#include "Menu.h"


Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::readData() {
	string line = "";
	ifstream file("Lost_Staffel_1.txt", ios::in);
	if (!file) {
		cerr << "File could not be opened." << endl;
		exit(1);

	} 
	getline(file, line); //ignore first line
	while (getline(file,line)) {
		stringstream linestream(line);
		string item1="";
		string item2="";
		string item3="";
		string item4="";
		string skip="";

		std::getline(linestream, skip,' ');   //lese bis leerzeichen
		std::getline(linestream, item1);   // lese ab lesezeichen in der gleichen zeile bis zur ende
		getline(file, line);   // neue zeile einlesen
		stringstream linestream2(line);    //in neuem stringstream die zeile bringen
		std::getline(linestream2, item2, '('); //lese bis klammer
		std::getline(linestream2, item3, ')');   // lese von klammer bis klammer zu
		linestream2.clear();       // lösche den inhalt von dem zweiten stringstream
		getline(file, line, '*'); //lese solange bis * auftaucht
		item4 = line;            // item4(inhalt) ist alles bis * kommt
		getline(file, line);     //überspringe "****" indem man liest und nichts damit macht
		Episode episode(stod(item1), item2, item3,item4); // Neues objekt erstellen mit der parameterliste !mit doubles kann es rundungsfehler geben lieber string machen 
		episodes.push_back(episode); //neues object in dem container einfügen
	
    }
	file.close();
}


int Menu::run() {
	readData();
	char menu = 'o';
	while (menu != '9') {
		cout << "[1] Englische Episodentitel und Inhalt einer beliebigen Episode ausgeben" << endl;
		cout << "[2] Nur Rückblicke einer beliebigen Episode ausgeben" << endl;
		cout << "[3] Die 15 häufigsten Wörter der Rückblicke einer Episode ausgeben" << endl;
		cout << "[4] Hauptpersonen aller Episoden ausgeben" << endl;
		cout << "[9] Program beenden" << endl;

		cin >> menu;

		switch (menu) {
		case '1': {
			for (unsigned int i = 0; i < episodes.size(); ++i) {
				episodes[i].showNrEng();
			}
			double w = 0;
			cout << "Welchen Episodeninhalt möchten Sie sehen? ";
			cin >> w;
			for (unsigned int i = 0; i < episodes.size(); ++i)
				if (episodes[i].getNumber() == w) {
					episodes[i].displayCompleteInfo();
				}
		}
		
			break;
		case '2': {
			double j = 0;
			cout << "Von welcher Episode sollen die Rückblicke ausgegeben werden: ";
			cin >> j;
			for (unsigned int i = 0; i < episodes.size(); ++i)
				if (episodes[i].getNumber() == j) {
					cout << episodes[i].getFlashback() << endl;
				}
		}
			
			break;
		case '3': {
			double k = 0;
			cout << "Von welcher Episode sollen die 15 häufigsten Wörter ausgegeben werden: ";
			cin >> k;
			for (unsigned int i = 0; i < episodes.size(); ++i)
				if (episodes[i].getNumber() == k) {
					episodes[i].printVec();
				}
		}
			
			break;
		case '4':
			cout << left << setw(10) << "Epsiode " << setw(25) << "Titel" << setw(15) << "Hauptperson(en)" << endl;
			for (unsigned int i = 0; i < episodes.size(); ++i) {
				cout << setw(35) << episodes[i].toString()  << episodes[i].printVec2() << endl;
			}
			break;
		case '9':
			return 0; // mit 9 das program beenden
		}
	}
}
