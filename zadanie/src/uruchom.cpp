/*
 * uruchom.cpp
 *
 *  Created on: 8 mar 2014
 *      Author: Ania
 */
#include "uruchom.hh"
#include <fstream>



using namespace std;

void zegar::algorytm()
{
	for (unsigned int i=0; i<dane_podstawowe.size(); i++)
	{dane_podstawowe[i]=dane_podstawowe[i]*2;}
}

LARGE_INTEGER zegar::wlaczStoper()
{
 LARGE_INTEGER start;
 DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
 QueryPerformanceCounter(&start);
 SetThreadAffinityMask(GetCurrentThread(), oldmask);
 return start;
}

LARGE_INTEGER zegar::wylaczStoper()
{
 LARGE_INTEGER stop;
 DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
 QueryPerformanceCounter(&stop);
 SetThreadAffinityMask(GetCurrentThread(), oldmask);
 return stop;
}

void zegar::wczytaj(string nazwa)
{
	ifstream plik(nazwa.c_str());
	int liczba_ele;
	if (!plik)
	{
		cerr << "Brak pliku!" << endl;
	}
	plik >> liczba_ele;
	int liczba;
	for(int i=1; plik >> liczba; i++)
	{
		stosik.push(liczba);
	}
	plik.close();
}
