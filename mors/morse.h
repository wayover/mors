#include <string>
#include <Windows.h>
#include <iostream>//usun�c@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;//usun�c@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#ifndef MORS_H_
#define MORS_H_												//ochrona przed wielokrotnym w��czeniem


class morse
{
private:
	int czestotliwosc;										//zmienne prywatne, poniewa� �adna klada nie dziedziczy z klasy morse
	int pauza;
	int czaskropka;
	int czaskreska;
	int znakprzerwa;
public:
	morse();												//konstruktor bezparametrowy 
	morse(int m_czestotliwosc, int m_pauza, int m_czaskropka, int m_czaskreska, int m_znakprzerwa);		//konstruktor
	morse(const morse &t);									//konstruktor kopiuj�cy
	~morse();												//destruktor nie wirtualny, poniewa� �adna klasa nie dziedziczy 
	void setFrequency(int a_czestotliwosc);					//metody pzyjmuj�ce warto�ci	
	void setPause(int a_pauza);
	void setDotTime(int a_czaskropka);
	void setDashTime(int a_czaskreska);
	void setCharPause(int a_znakprzerwa);			

	morse operator=(const morse & t);						//operator przypisania	
	friend void operator<<(morse &t, const char *tab);		//operator przekszta�caj�cy tekst na morsa
	morse operator<<(const long a) const;					//operator przekszta�ta�caj�cy longa na morsa
	morse operator<<(const double a) const;					//operator przekszta�ta�caj�cy double na morsa	
	morse &operator<<(ostream& (*pf)(std::ostream &));		//operator << do manipulatora

};


	ostream & pause(ostream & t);								//deficja manipulatora
	std::string morsee(char znak);								//funkcja morsee zmieniaj�ca znak na morsa

#endif // !MORS_H_