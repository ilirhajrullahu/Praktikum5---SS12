#pragma once
#include <string>
#include <iostream>
using namespace std;
class Episode
{
public:
	Episode(double m_number,string m_engTitel, string m_deTitel);
	~Episode();
	void display();
private:
	double number;
	string engTitel;
	string deTitel;

};

