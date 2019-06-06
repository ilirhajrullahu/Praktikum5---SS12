#pragma once
#include "Episode.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
class Menu
{
public:
	Menu();
	~Menu();
	void readData();
	void show();
	int run();
private:
	vector <Episode> episodes;

};

