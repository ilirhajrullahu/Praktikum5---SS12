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

	} // end if
	getline(file, line); //ignore first line
	while (getline(file,line)) {
		stringstream linestream(line);
		string item1;
		string item2;
		string item3;
		string skip;

		std::getline(linestream, skip,' ');
		std::getline(linestream, item1);
		getline(file, line);
		stringstream linestream2(line);
		std::getline(linestream2, item2, ',');
		std::getline(linestream2,skip, '(');
		std::getline(linestream2, item3, ')');
		linestream2.clear();

		Episode episode(stod(item1), item2, item3);
	

	}
	file.close();
}

void Menu::show() {
	for (int i = 0; i < episodes.size(); ++i) {
		episodes[i].display();
	}
}