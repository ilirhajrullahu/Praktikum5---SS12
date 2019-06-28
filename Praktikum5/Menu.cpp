#include "pch.h"
#include "Menu.h"


Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::readData() {
	string line;
	ifstream file("Lost_Staffel_1.txt", ios::in);
	if (!file) {
		cerr << "File could not be opened." << endl;
		exit(1);

	} 
	getline(file, line); //ignore first line
	while (getline(file,line)) {
		stringstream linestream(line);
		string item1;
		string item2;
		string item3;
		string item4;
		string skip;

		std::getline(linestream, skip,' ');
		std::getline(linestream, item1);
		getline(file, line);
		stringstream linestream2(line);
		std::getline(linestream2, item2, '(');
		std::getline(linestream2, item3, ')');
		linestream2.clear();
		getline(file, line, '*');
		item4 = line;
		getline(file, line); //�berspringe "****"
		Episode episode(stod(item1), item2, item3,item4); //mit doubles kann es rundungsfehler geben 
		episodes.push_back(episode);
	
    }
	file.close();
}


int Menu::run() {
	char menu = 'o';
	while (menu != '9') {
		cout << "[1] Englische Episodentitel und Inhalt einer beliebigen Episode ausgeben" << endl;
		cout << "[2] Nur R�ckblicke einer beliebigen Episode ausgeben" << endl;
		cout << "[3] Die 15 h�ufigsten W�rter der R�ckblicke einer Episode ausgeben" << endl;
		cout << "[4] Hauptpersonen aller Episoden ausgeben" << endl;
		cout << "[9] Program beenden" << endl;

		cin >> menu;

		switch (menu) {
		case '1':
			for (unsigned int i = 0; i < episodes.size(); ++i) {
				episodes[i].showNrEng();
			}
			double w;
			cout << "Welchen Episodeninhalt m�chten Sie sehen? ";
			cin >> w;
			for (unsigned int i = 0; i < episodes.size(); ++i)
				if (episodes[i].getNumber() == w) {
					episodes[i].displayCompleteInfo();
				}
			break;
		case '2':
			double j;
			cout << "Von welcher Episode sollen die R�ckblicke ausgegeben werden: ";
			cin >> j;
			for (unsigned int i = 0; i < episodes.size(); ++i)
				if (episodes[i].getNumber() == j) {
					cout << episodes[i].getFlashback() << endl;
				}
			break;
		case '3':
			double k;
			cout << "Von welcher Episode sollen die 15 h�ufigsten W�rter ausgegeben werden: ";
			cin >> k;
			for (unsigned int i = 0; i < episodes.size(); ++i)
				if (episodes[i].getNumber() == k) {
					episodes[i].printVec();
				}
			break;
		case '4':
			cout << left << setw(10) << "Epsiode " << setw(25) << "Titel" << setw(15) << "Hauptperson(en)" << endl;
			for (unsigned int i = 0; i < episodes.size(); ++i) {
				cout << setw(35) << episodes[i].toString()  << episodes[i].printVec2() << endl;
			}
			break;
		case '9':
			return 0;
		}
	}
}
