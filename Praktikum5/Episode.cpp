#include "pch.h"
#include "Episode.h"


Episode::Episode(double m_number,string m_engTitel, string m_deTitel):number(m_number),engTitel(m_engTitel),deTitel(m_deTitel)
{
}


Episode::~Episode()
{
}

void Episode::display() {
	cout << "Episode : " << number << " " << "Titel: " << engTitel << endl;
}