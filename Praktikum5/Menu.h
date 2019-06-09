#pragma once
#include "Episode.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
class Menu
{
public:
	Menu();
	~Menu();
	void readData();
	int run();
private:
	vector <Episode> episodes;

};

