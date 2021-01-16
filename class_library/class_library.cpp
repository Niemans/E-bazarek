#include "class_library.h"

		//metody klasy Przedmiot

	//funkcja zwracajaca id osoby wystawiajacej przedmiot
bool Przedmiot::sprawdz_id_wlasciciela(unsigned int idOsoby)
{
	if (IDWlasciciela == idOsoby)
	{
		return true;
	}
	else
	{
		return false;
	}
}

	//funkcja wypisujaca przedmiot w okienku - potrzebna wspolpraca z okienkiem
void wypisz() {}		//do zrobienia, potrzebne okienko

	//funkcja zwracajaca id wlasciciela
unsigned int Przedmiot::wypisz_id_wlasciciela()
{
	return IDWlasciciela;
}

	//funkcja sprawdzajaca czy produkt jest dostepny
bool Przedmiot::czy_dostepny()
{
	if (ilosc > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

	//funkcja zwracajaca id przedmiotu
unsigned int Przedmiot::podaj_id()
{
	return ID;
}

	//funkcja usuwajaca egzemplaze przedmiotu
void Przedmiot::usun_przedmioty(int ilosc_do_usuniecia)			//WAZNE!!! Trzeba zmienic aby dzialalo lepiej - teraz nie sprzawdza czy...
{																//...nie usuwamy wiecej przedmiotow niz jest, powinna zwracac int
	ilosc -= ilosc_do_usuniecia;
}

		//metody klasy licytacja
	//metoda wkladajaca wygrany przedmiot do koszyka zwyciezcy
void Licytacja::wygrana() {}		//do zrobienia

	//metoda dodajaca historie (najnowsza cene) do historii
void Licytacja::dodaj_historie(HistoriaLicytacji* toAdd)
{
	toAdd->next = head;		//ustawiamy wskaznik next nowej ceny jako glowe
	head = toAdd;			//ustawiamy glowe na nowa cene
}

	//nie wiadomo co funkcja robi
void Licytacja::dodaj_oferte(){}		//dowiedziec sie co funkcja robi


		//metody klasy Osoba

	//konstruktor klasy Osoba
Osoba::Osoba(std::string newMail, std::string newHaslo): mail(newMail), haslo(newHaslo)
{
	licznik++;
	ID = licznik;
}

	
	//funkcja sprawdzajaca czy podane przez uzytkownika dane sa poprawne
bool Osoba::sprawdz_dane(std::string compMail, std::string compHaslo)
{
	if (mail == compMail && haslo == compHaslo)
	{
		return true;
	}
	else
	{
		return false;
	}
}

	//funkcja edytujaca dane
void Osoba::edytuj_dane(std::string newMail, std::string newHaslo)
{
	mail = newMail;
	haslo = newHaslo;
}


		//metody klasy Klient

	//funkcja dodajaca przedmiot na bazarek
void Klient::dodaj_przedmiot(){}		//do zrobienia

	//funkcja usuwajaca przedmiot z bazarku
void Klient::usun_przedmiot(){}			//do zrobienia

	//funkcja zmieniajaca dane wystawionego przedmiotu
void Klient::edytuj_przedmiot(){}		//do zrobienia

	//funkcja dodajaca licytacje na bazarek
void Klient::dodaj_licytacje(){}		//do zrobienia

	//funkcja usuwajaca licytacje z bazarku
void Klient::usun_licytacje(){}			//do zrobienia

	//funkcja dodaje podany przedmiot do koszyka
void Klient::dodaj_do_koszyka(unsigned int id_przedmiotu, int ilosc){}		//do zrobienia

	//funkcja uruchamia procedurê zakupu przedmiotów z koszyka
Przedmiot* Klient::kup() { return NULL; }		//do zrobienia

	//nie wiadomo co funkcja robi
Przedmiot* Klient::zwroc_koszyk() { return NULL; }		//dowiedziec sie co funkcja ma robic

	//usuwa przedmioty z koszyka
void Klient::oproznij_koszyk(){}		//do zrobienia


		//metody klasy Firma
			//praktycznie takie same jak w Kliencie - mozna przeniesc do klasy Osoba

	//funkcja dodajaca przedmiot na bazarek
void Firma::dodaj_przedmiot(){}		//do zrobienia

	//funkcja usuwajaca przedmiot z bazarku
void Firma::usun_przedmiot(){}			//do zrobienia

	//funkcja zmieniajaca dane wystawionego przedmiotu
void Firma::edytuj_przedmiot(){}		//do zrobienia

	//funkcja dodajaca licytacje na bazarek
void Firma::dodaj_licytacje(){}		//do zrobienia

	//funkcja usuwajaca licytacje z bazarku
void Firma::usun_licytacje(){}			//do zrobienia


		//metody klasy Admin

	//funkcja usuwajaca nieodpowiedni przedmiot
void Admin::usun_przedmiot(unsigned int id_przedmiotu){}		//do zrobienia
	
	//funkcja usuwajaca uzytkownika
void Admin::usun_uzytkownika(unsigned int id_uzytkownika){}	//do zrobienia

