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

unsigned int Osoba::podaj_id()
{
	return ID;
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

	//gettery parametrow imieINazwisko oraz next
std::string Klient::podaj_nazwe_klienta()
{
	return imieINazwisko;
}

Klient* Klient::podaj_wskaznik_next_klienta()
{
	return next;
}

	//settery parametrow imieINazwisko oraz next
void Klient::ustaw_nazwe_klienta(std::string nazwa_do_ustawienia)
{
	imieINazwisko = nazwa_do_ustawienia;
}

void Klient::ustaw_wskaznik_next_klienta(Klient* wskaznik_do_ustawienia)
{
	next = wskaznik_do_ustawienia;
}


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

	//gettery parametrow nazwa i next
std::string Firma::podaj_nazwe_firmy()
{
	return nazwa_firmy;
}

Firma* Firma::podaj_wskaznik_next_firmy()
{
	return next;
}

	//settery parametrow nazwa i next
void Firma::ustaw_nazwe_firmy(std::string nazwa_do_ustawienia)
{
	nazwa_firmy = nazwa_do_ustawienia;
}

void Firma::ustaw_wskaznik_next_firmy(Firma* wskaznik_do_ustawienia)
{
	next = wskaznik_do_ustawienia;
}


		//metody klasy Admin

	//funkcja usuwajaca nieodpowiedni przedmiot
void Admin::usun_przedmiot(unsigned int id_przedmiotu){}		//do zrobienia
	
	//funkcja usuwajaca uzytkownika
void Admin::usun_uzytkownika(unsigned int id_uzytkownika){}	//do zrobienia

		//metody klasy ListaFirm

	//funkcja dodaje firme do listy
void ListaFirm::dodaj(Firma* toAdd)
{
	if (head == NULL)		//jezeli nie ma jeszcze firm na liscie - firma zostaje pierwsza
	{
		head = toAdd;			
		return;
	}

	Firma* pom = head;		//wskaznik pomocniczy - ustawiamy najpierw na glowe

	while (pom->podaj_wskaznik_next_firmy() != NULL)	//jezeli sa juz jakies firmy na liscie to szukamy ogona
	{
		pom = pom->podaj_wskaznik_next_firmy();			//z kazda iteracja wskaznik przeskakuje w strone ogona
	}

	pom->ustaw_wskaznik_next_firmy(toAdd);				//dodana firma staje sie ogonem
}

	//funkcja sprawdza czy podana firma juz istnieje
bool ListaFirm::sprawdz(std::string email_firmy, std::string nazwa_firmy)		//mozna zmodyfikowac funkcje aby zwracala informacja czy to email sie duplikuje czy nazwa firmy
{
	//nalezy do klasy Firma dodac funkcje porownojaca dane firmy z wprowadzonymi przez uzytkownika
	return true;
}

	//funkcja wyszukuje firme po id
Firma* ListaFirm::wyszukaj_firme(unsigned int id_firmy)
{
	Firma* pom = head;		//wskaznik pomocniczy - ustawiamy najpierw na glowe

	while (pom != NULL && pom->podaj_id() != id_firmy)		
	{
		pom = pom->podaj_wskaznik_next_firmy();		//dopoki nie znajdziemy firmy o danym ID lub nie dotrzemy do konca listy - przechodzimy kolejne welzy
	}

	return pom;		//jezeli znajdziemy firme - zwroci jej adres, jezeli nie - NULL
}

	//funkcja wyszukuje firme po nazwie
Firma* ListaFirm::wyszukaj_firme(std::string nazwa_firmy)
{
	Firma* pom = head;		//wskaznik pomocniczy - ustawiamy najpierw na glowe

	while (pom != NULL && pom->podaj_nazwe_firmy() != nazwa_firmy)
	{
		pom = pom->podaj_wskaznik_next_firmy();		//dopoki nie znajdziemy firmy o danej nazwie lub nie dotrzemy do konca listy - przechodzimy kolejne welzy
	}

	return pom;		//jezeli znajdziemy firme - zwroci jej adres, jezeli nie - NULL
}


		//metody klasy ListaKlientow

	//funkcja dodaje klienta do listy
void ListaKlientow::dodaj(Klient* toAdd)
{
	if (head == NULL)		//jezeli nie ma jeszcze klientow na liscie - klient zostaje pierwszy
	{
		head = toAdd;
		return;
	}

	Klient* pom = head;		//wskaznik pomocniczy - ustawiamy najpierw na glowe

	while (pom->podaj_wskaznik_next_klienta() != NULL)	//jezeli sa juz jacys klienci na liscie to szukamy ogona
	{
		pom = pom->podaj_wskaznik_next_klienta();			//z kazda iteracja wskaznik przeskakuje w strone ogona
	}

	pom->ustaw_wskaznik_next_klienta(toAdd);				//dodany klient staje sie ogonem
}

//funkcja sprawdza czy podany klient juz istnieje
bool ListaKlientow::sprawdz(std::string email_klienta, std::string nazwa_klienta)		//mozna zmodyfikowac funkcje aby zwracala informacja czy to email sie duplikuje czy nazwa klienta
{
	//nalezy do klasy Klient dodac funkcje porownojaca dane klienta z wprowadzonymi przez uzytkownika
	return true;
}

//funkcja wyszukuje klienta po id
Klient* ListaKlientow::wyszukaj_klienta(unsigned int id_klienta)
{
	Klient* pom = head;		//wskaznik pomocniczy - ustawiamy najpierw na glowe

	while (pom != NULL && pom->podaj_id() != id_klienta)
	{
		pom = pom->podaj_wskaznik_next_klienta();	//dopoki nie znajdziemy klienta o danym ID lub nie dotrzemy do konca listy - przechodzimy kolejne welzy
	}

	return pom;		//jezeli znajdziemy klienta - zwroci jego adres, jezeli nie - NULL
}

//funkcja wyszukuje klienta po nazwie
Klient* ListaKlientow::wyszukaj_klienta(std::string nazwa_klienta)
{
	Klient* pom = head;		//wskaznik pomocniczy - ustawiamy najpierw na glowe

	while (pom != NULL && pom->podaj_nazwe_klienta() != nazwa_klienta)
	{
		pom = pom->podaj_wskaznik_next_klienta();		//dopoki nie znajdziemy klienta o danej nazwie lub nie dotrzemy do konca listy - przechodzimy kolejne welzy
	}

	return pom;		//jezeli znajdziemy klienta - zwroci jej adres, jezeli nie - NULL
}
