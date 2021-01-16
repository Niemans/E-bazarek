#include "class_library.h"

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
		return 1;
	}
	else
	{
		return 0;
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
Przedmiot* Klient::kup(){}		//do zrobienia

	//nie wiadomo co funkcja robi
Przedmiot* Klient::zwroc_koszyk(){}		//dowiedziec sie co funkcja ma robic

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

