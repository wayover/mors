#include "morse.h"

using namespace std;


int main()
{                           //obiekt ma dzialac nawet bez jakiegos seta
	morse m;                    //trycatch
	m.setFrequency(1000);       //zabezpieczenie przed liczbami ujemnymi
	m.setPause(200);
	m.setDotTime(100);
	m.setDashTime(200);         //z internetu znak na ³añcuch tekstowy i w komentarzu z jakiej strony
	m.setCharPause(2000);

	m << "Ala ma kota";           //spacja=CharPause
	long i = 0x5A5A5A5A;          //long zawsze 32bity liczba hexy,
	double d = 1.23456789;        //kropke taz ma wypikac        tylko 5 liczb po przecinku, ale na + jezeli da rade wiecej
	m << i << pause << d;             //pause=CharPause
								//jezeli nie da razy pause to zakomentowac


	system("pause");


	return 0;

}


