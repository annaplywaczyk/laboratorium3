/*
 * uruchom.hh
 *
 *  Created on: 8 mar 2014
 *      Author: Ania
 */

#ifndef URUCHOM_HH_
#define URUCHOM_HH_

/*!
 * \file
 * \brief Definicja klasy zegar
 *
 * Plik zawiera definicje klasy zegar, ktora jest klasa glowna programu.
 * Klasa ta jest pochodna i specjalizacja klasy dane.
 */
#include "dane.hh"
#include <windows.h>
#include "stos.hh"

using namespace std;
/*!
 * \brief Klasa modeluje uruchomienia g³ownych wlasciowosci programu.
 * Atrybutem klasy sa stowrzone dwa elemnty klasy dane, na ktorych wykonywane sa dzialania.
 */

class zegar{
private:
	/*!
	 * \brief Element podsatwowy klasy dane.
	 * Dane_podstawowe sa elementem klasy dane, na ktorych wykonywany jest alagorytm
	 * oraz jest jakby glownym elementem programu.
	 */
	dane dane_podstawowe;
	/*!
	 * \brief Element sprawdzajacy klasy dane.
	 * Dane_sprawdzjace sa elementem klasy dane, wektor ten wykorzystywany jest do porownania
	 * wykannego algorytmu z denymi podstawowymi.
	 */
	dane dane_sprawdzajace;
	stos stosik;

public:
	zegar(){
		stos stos(2);
		stosik=stos;
	};
	/*!
	 * \brief Wczytanie danych podstawowych
	 * Funkcja wczytuje dane, na ktorych wykonywany jest algorytm.
	 * Dane te sa glowna funkcja programu.
	 * \param[in] nazwa_pliku_pod - jest to zmienna ktora jest ciagiem
	 * znakow (nazwa pliku), ktory ma zostac otwarty.
	 * \return (brak)
	 */
	void wczytaj_dane_pod(string nazwa_pliku_pod){
		dane_podstawowe.wczytaj(nazwa_pliku_pod);
	}
	/*!
	 * \brief Wczytanie danych sprawdzajacych
	 * Funkcja wczytuje dane, na ktore zostaja porwonane z danymi na ktorych
	 * zostal wykonany algorytm.
	 * \param[in] nazwa_pliku_spr - jest to zmienna ktora jest ciagiem
	 * znakow (nazwa pliku), ktory ma zostac otwarty, w celu porownania.
	 * \return (brak)
	 */
	void wczytaj_dane_spr(string nazwa_pliku_spr){
		dane_sprawdzajace.wczytaj(nazwa_pliku_spr);
	}
	/*!
	* \brief Funkcja wykonuj¹ca zadany algorytm na wektorze.
	* Funkcja wykonuje zadany algorytm na wektorze wejsciowym.
	* W naszym przypadku wektor pomno¿ony jest przez sta³¹ liczbê 2.
	* \return (brak)
	*/
	void algorytm();
	/*!
	* \brief Funkcja porównuj¹ca dwa wektory.
	* Funkcja porównuje dwa wektory, sprawdza czy wszystkie elemnty s¹ ze sob¹ równe.
	* \return Funkcja zwraca true jezeli wektory sa jednakowe w przeciwnym wypadku zostaje wzrocony false.
	*/
	bool porownaj(){
		return dane_podstawowe==dane_sprawdzajace;
	}
	/*!
	* \brief Funkcja zapamietuj¹ca czas poczatkowy.
	* Funkcja nale¿¹ca do biblioteki "windows.h",  stoper zostaje w³¹czony.
	* Funkcja nale¿¹ca do funkcji bool QueryPerformanceCounter(_out LARGE_INTEGER *IpPerformanceCount),
	* funkcja ta zwraca wartosc niezerowa je¿eli w³aczenie zakoñczy siê sukcesem, natomiast w przeciwnym wypadku
	* zostanie wyrzucony b³¹d i zwróci wartosc 0. Dla komputerów multiprocesorowych nie ma znaczenia, który jest u¿ywany,
	* mog¹ jedynie ró¿niæ siê minimalnie czasy.
	*/
	LARGE_INTEGER wlaczStoper();
	/*!
	* \brief Funkcja zapamietuj¹ca czas koñcowy.
	* Funkcja nale¿¹ca do biblioteki "windows.h",  stoper zostaje wy³¹czony, aby zosta³ zmierzony czas wykonania
	* algorytmu w programie, poprzez odjêcie czasu pocz¹tkowego od czasu koñcowego.
	* Funkcja nale¿¹ca do funkcji bool QueryPerformanceCounter(_out LARGE_INTEGER *IpPerformanceCount),
	* funkcja ta zwraca wartosc niezerowa je¿eli wy³aczenie zakoñczy siê sukcesem, natomiast w przeciwnym wypadku
	* zostanie wyrzucony b³¹d i zwróci wartosc 0. Dla komputerów multiprocesorowych nie ma znaczenia, który jest u¿ywany,
	* mog¹ jedynie ró¿niæ siê minimalnie czasy.
	*/
	LARGE_INTEGER wylaczStoper();
	/*!
	 * \brief Funkcja wczytuj¹ca dane do stosu.
	 * Funkcja otwiera plik zdefiniowany w glownej funkcji przez u¿ytkownika, sprawdza czy plik zosta³ otwarty,
	 * je¿eli zosta³ otwarty wczytana jest liczba elementow pliku, nastepnie wczytywane sa wszystkie
	 * liczby do tablicy.
	 * \param[in] nazwa - zmienna, która zostaje wprowadzona przez u¿ytkownika do programu
	 * \return (brak)
	 */

	void wczytaj(string nazwa);

};




#endif /* URUCHOM_HH_ */
