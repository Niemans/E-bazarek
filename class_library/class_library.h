#include <string>
#include <iostream>

//do zrobienia: mozna przeniesc obsloge wystawionych przedmiotow do osoby

class Przedmiot
{
	
};

class Osoba {
private:
	std::string mail;
	std::string haslo;
	unsigned int ID;
	static unsigned int licznik;

public:
	Osoba(std::string newMail = "brak_danych", std::string newHaslo = "brak_danych");
	bool sprawdz_dane(std::string compMail, std::string compHaslo);
	void edytuj_dane(std::string newMail, std::string newHaslo);

};


class Klient: public Osoba {
private:
	std::string imieINazwisko;
	Klient* nextKlient;
	Przedmiot* koszyk;

public:
		//obsluga wystawionych przedmiotow
	void dodaj_przedmiot();
	void usun_przedmiot();
	void edytuj_przedmiot();

		//obsluga wystawionych licytacji
	void dodaj_licytacje();
	void usun_licytacje();

		//dodawanie przedmiotu do koszyka
	void dodaj_do_koszyka(unsigned int id_przedmiotu, int ilosc);

		//zakup przedmiotow z koszyka
	Przedmiot* kup();

		//???
	Przedmiot* zwroc_koszyk();
		
		//oproznia koszyk uzytkownika
	void oproznij_koszyk();

};


class Firma : public Osoba {
private:
	std::string nazwa_firmy;
	Firma* next;

public:
		//obsluga wystawionych przedmiotow
	void dodaj_przedmiot();
	void usun_przedmiot();
	void edytuj_przedmiot();

		//obsluga wystawionych licytacji
	void dodaj_licytacje();
	void usun_licytacje();

};

class Admin : public Osoba {
public:
	void usun_przedmiot(unsigned int id_przedmiotu);
	void usun_uzytkownika(unsigned int id_uzytkownika);
};

