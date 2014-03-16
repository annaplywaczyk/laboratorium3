#include "uruchom.hh"
#include <sstream>
#include <fstream>

using namespace std;

/*!
 * \file
 * \brief Funkcja glowna ktorej glownym zalozeniem jest wczytanie plikow z rozna wielkoscia
 * elementow znajdujacych siê w pliku, obliczenie sredniej wartosci czasu, w jakim zostaje wykonany
 * algorytm (w naszym przypadku pomnozenie przez 2),nastepnie program porownuje poprawnosc wykoannia
 * mnozenia z plikiem sprawdzajacym.
 * Uzytkownik musi w programie zdefiniowac: liczbe powtorzen (zmienna j), ilosc plikow -
 * do ilu wykonywane jest mnozenie (zmienna i), nazwy plikow (string czesc_1, i, czesc_2 - wszystko opcjonalnie).
 * \return (brak)
 */


int main()
{

	ofstream plik("wnioski1.csv");
	zegar tablica;

	for (int i=10; i<100000; i=i*10)
	{
		// zdefiniowane zmienne oraz czesci nazw plikow, ktore sie zmieniac beda;
		string czesc_1 = "dane";
		int liczba=i;
		string czesc_2=".txt";
		string nazwa_pliku1;
		int j;
		int suma=0;

		// konwersja int na string aby nazwa programu mogla sie zmieniac samoczynnie;
		ostringstream numer;
		numer << liczba;
		string element=numer.str();

		//tworzone nazwy plikow
		nazwa_pliku1=czesc_1+element+czesc_2;


		//petla for w ktorej wykonywana jest liczba powtorzen danego algorytmu
		for(j=0;j<50;j++)
		{
			// stworzone zmienne, ktore uzyte sa wylacznie w funkcji
			LARGE_INTEGER start;
			LARGE_INTEGER end;
			double czas=0;

			//funkcje wywolujaca glowna czesc programu - obliczanie czasu wykonywania algorytmu
			start=tablica.wlaczStoper();
			tablica.wczytaj(nazwa_pliku1);
			end=tablica.wylaczStoper();
			czas = end.QuadPart - start.QuadPart;
			suma=suma+czas;
		}
		//stworzenie pliku i zapisanie do niego danych o testowanym pliku

		plik << i << "," << j <<"," <<suma/j << endl;
		plik.flush();
	}
	plik.close();


	return 0;
}


