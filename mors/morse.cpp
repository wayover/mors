#include "morse.h"


morse::morse()																							//konstruktor bezprametrowy przypisuj¹cy 1 dla ka¿dej zmiennej
{
	czestotliwosc = 1;
	pauza = 1;
	czaskropka = 1;
	czaskreska = 1;
	znakprzerwa = 1;
}


morse::morse(int m_czestotliwosc, int m_pauza, int m_czaskropka, int m_czaskreska, int m_znakprzerwa)	//konstruktor 
{
	czestotliwosc = m_czestotliwosc;
	pauza = m_pauza;
	czaskropka = m_czaskropka;
	czaskreska = m_czaskreska;
	znakprzerwa = m_znakprzerwa;
}

morse::morse(const morse &t)																			//konstruktor kopiuj¹cy 
{
	czestotliwosc = t.czestotliwosc;
	pauza = t.pauza;
	czaskropka = t.czaskropka;
	czaskreska = t.czaskreska;
	znakprzerwa = t.znakprzerwa;

}


morse::~morse()																							//pusty destruktor, poniewa¿ nie ma alokowanej pamieci;
{

}

void morse::setFrequency(int a_czestotliwosc)															//prypisanie czêstotliwoœci 
{
	if (a_czestotliwosc < 0)																			//w ka¿dej metodzie jest sprawdzenie czy liczba jest ujemna. Je¿eli jest ujemna zmieniam znak naprzeciwny 
	{
		a_czestotliwosc = a_czestotliwosc * (-1);
	}


	if (a_czestotliwosc == 0)
	{
		a_czestotliwosc = 100;																			//je¿eli czestotliwosc zosta³a przypisana jako 0 ustawiasiê automatycznie na 100
	}																									//w innych metodach z pauz¹ nie ma sprawdzenia, poniewa¿ czas pauz mo¿e byæ zerowy 
	czestotliwosc = a_czestotliwosc;
}


void morse::setPause(int a_pauza)																		//prypisanie pauzy
{
	if (a_pauza < 0)
	{
		a_pauza = a_pauza * (-1);
	}

	pauza = a_pauza;
}

void morse::setDotTime(int a_czaskropka)																//przypisanie czasu kropki
{
	if (a_czaskropka < 0)
	{
		a_czaskropka = a_czaskropka * (-1);																
	}

	if (a_czaskropka == 0)
	{
		a_czaskropka = 100;																				//jezeli czas przypisany by³ jako 0 ustawiam go automatycznie na 100
	}

	czaskropka = a_czaskropka;
}

void morse::setDashTime(int a_czaskreska)																//przypisanie czasu kreski
{
	if (a_czaskreska < 0)
	{
		a_czaskreska = a_czaskreska * (-1);
	}

	if (a_czaskreska == 0)
	{
		a_czaskreska = 100;																				//jezeli czas przypisany by³ jako 0 ustawiam go automatycznie na 100
	}
	czaskreska = a_czaskreska;
}

void morse::setCharPause(int a_znakprzerwa)																//przypisanie przerwy pomiêdzy znakami
{
	if (a_znakprzerwa < 0)
	{
		a_znakprzerwa = a_znakprzerwa * (-1);
	}
	znakprzerwa = a_znakprzerwa;
}


morse morse::operator=(const morse & t)																	//operator przypisania							
{
	this->czestotliwosc = t.czestotliwosc;
	this->pauza = t.pauza;
	this->czaskropka = t.czaskropka;
	this->czaskreska = t.czaskreska;
	this->znakprzerwa = t.znakprzerwa;

	return *this;
}


void operator<<(morse &t, const char *tab)																//operator przekszta³caj¹cy tekst na morsa
{

	int h = 0;
	while(tab[h] != '\0')										//zakoñczenie pêtli gdy tablica siê skoñczy 				
	{
		cout << tab[h] << " ";//usun¹c@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		std::string mor = "";									//tworzenie pustego stringa
		mor=morsee(tab[h]);										//przypisanie do stringa wartoœci zwróconej z funkcji morsee
			int dlugosc=0;
			dlugosc = mor.length();								//przypisanie d³ugoœci stringa do zmiennej dlugosc
			for (int x = 0; x < dlugosc; x++)					//pêtla która przechodzi pokolei po ka¿dym zwróconym znaku przez funkcjê 
			{
				
				if (mor[x] == '_')								//sprawdzanie czy zwrócona wartoœæ to kreska
				{
					Beep(t.czestotliwosc, t.czaskreska);		//pikanie kreski
					Sleep(t.pauza);								//pauza
					cout << "_";//usun¹c@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
				}
				else if (mor[x] == '.')							//sprawdzanie czy zwrócona wartoœæ to kropka
				{
					Beep(t.czestotliwosc, t.czaskropka);		//pikanie kropki
					Sleep(t.pauza);								//pauza
					cout << ".";//usun¹c@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
				}
				else											//je¿eli zwróconyznak nie by³ kropk¹ ani kresk¹
				{
					Sleep(t.znakprzerwa);						//pauza
					cout << "  "; //usun¹c@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
				}
			}
			Sleep(t.znakprzerwa);
			h++;												//zwiêkszenie h o 1 i przejœcie do kolejnej litery/liczby/odstêpu
	}
	
}



morse morse::operator<<(const long a) const																//operator przekszta³ta³caj¹cy longa na morsa
{
	std::string mor = std::to_string(a);						//przekszta³cenie longa na stringa
	int dlugosc = 0;
	dlugosc=mor.length();										//przypisanie d³ugoœci stringa do zmiennej dlugosc
	std::cout << dlugosc<<std::endl; //usun¹c@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@				
	char * tab = new char[dlugosc];								//tworzenie tablicy dynamicznej

	std::string mor2 = "";										//tworzenie pustego stringa
	
	for (int i = 0; i < dlugosc; i++)							//przypisanie stringa do chara
	{
		tab[i] = mor[i];
	}


	for (int x = 0; x < dlugosc; x++)							//to samo co w poprzednim operatorze 
	{															//bez else poniewa¿ liczba nie posiada odstêpów
		std::string mors = "";
		mors = morsee(tab[x]);
		int dlugoscmorsa = 0;
		dlugoscmorsa = mors.length();
	std:cout << tab[x];//usun¹c@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		for (int c = 0; c < dlugoscmorsa; c++)
		{
			if (mors[c] == '_')
			{
				Beep(czestotliwosc, czaskreska);
				Sleep(pauza);
				cout << "_";//usun¹c@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			}
			else if (mors[c] == '.')
			{
				Beep(czestotliwosc, czaskropka);
				Sleep(pauza);
				cout << ".";//usun¹c@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			}
			
		}
	}

	delete[] tab;												//usuniêcie tablicy
	return *this;
}

morse morse::operator<<(const double a) const															//operator przekszta³ta³caj¹cy double na morsa
{																//dla kropki przypisa³em to co w morsie znaczy kropka 
	std::string mor = std::to_string(a);						//wszystko tak jak w poprzednim operatorze
	int dlugosc = 0;											
	dlugosc = mor.length();
	std::cout << dlugosc << std::endl;//usun¹c@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	char * tab = new char[dlugosc];

	std::string mor2 = "";

	for (int i = 0; i < dlugosc; i++)
	{
		tab[i] = mor[i];
	}


	for (int x = 0; x < dlugosc; x++)
	{
		std::string mors = "";
		mors = morsee(tab[x]);
		int dlugoscmorsa = 0;
		dlugoscmorsa = mors.length();
	std:cout << tab[x];//usun¹c@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		for (int c = 0; c < dlugoscmorsa; c++)
		{
			if (mors[c] == '_')
			{
				Beep(czestotliwosc, czaskreska);
				Sleep(pauza);
				cout << "_";//usun¹c@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			}
			else if (mors[c] == '.')
			{
				Beep(czestotliwosc, czaskropka);
				Sleep(pauza);
				cout << ".";//usun¹c@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			}

		}
	}

	delete[] tab;
	return *this;

}



std::ostream &pause(ostream & t)																		//definicja manipulatora pause 
{
	return t;
}


morse & morse::operator<<(ostream& (*pf)(std::ostream &))												//operator << dla manipulatora pause
{
	Sleep(znakprzerwa);
	return *this;
}

std::string morsee(char znak)																			//funkcjaprzyjmuj¹ca char i zwracaj¹ca string
{
	switch (znak)
	{
	case 'a': case 'A':											//podwójny case, ¿eby nie by³o ró¿nicy pomiêdzy ma³ymi i wielkimi literami 
		return "._";
	case 'b': case 'B':
		return "_...";
	case 'c': case 'C':
		return "_._.";
	case 'd': case 'D':
		return "_..";
	case 'e': case 'E':
		return ".";
	case 'f': case 'F':
		return ".._.";
	case 'g': case 'G':
		return "__.";
	case 'h': case 'H':
		return "....";
	case 'i': case 'I':
		return "..";
	case 'j': case 'J':
		return ".___";
	case 'k': case 'K':
		return "_._";
	case 'l': case 'L':
		return "._..";
	case 'm': case 'M':
		return "__";
	case 'n': case 'N':
		return "_.";
	case 'o': case 'O':
		return "___";
	case 'p': case 'P':
		return ".__.";
	case 'q': case 'Q':
		return "__._";
	case 'r': case 'R':
		return "._.";
	case 's': case 'S':
		return "...";
	case 't': case 'T':
		return "_";
	case 'u': case 'U':
		return ".._";
	case 'v': case 'V':
		return "..._";
	case 'w': case 'W':
		return ".__";
	case 'x': case 'X':
		return "_.._";
	case 'y': case 'Y':
		return "_.__";
	case 'z': case 'Z':
		return "__..";
	case '1':
		return ".____";
	case '2':
		return "..___";
	case '3':
		return "...__";
	case '4':
		return "...._";
	case '5':
		return ".....";
	case '6':
		return "_....";
	case '7':
		return "__...";
	case '8':
		return "___..";
	case '9':
		return "____.";
	case '0':
		return "_____";
	case ' ':													
		return " ";
	case '.':
		return "._._._";
	case'-':
		return "_...._";										//w morsie nie ma przypisania dla minusa to da³em myœlnik
	}															//doda³em tylko litery i liczby, inne znaki specjalne wystarczy dodaæ kolejnym case'm
}
