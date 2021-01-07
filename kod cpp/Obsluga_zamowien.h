#ifndef OBSLUGA_ZAMOWIEN_H
#define OBSLUGA_ZAMOWIEN_H

class Obsluga_zamowien 
{
	//Pola
private:
	std::string imie;
	std::string nazwisko;
	std::string kraj;
	std::string misto;
	std::string ulica;
	std::string nr_domu;
	int kod_pocztowy;
	przedmiot koszyk[];

	//Metody
public:
	void podaj_dane_osobowe(int i, std::string n);

	void podaj_dane_adresowe(int k, int m, int u, std::string n, int kod);

	int przekieruj_na_payu();

	int wybierz_opcje_platnosci();

	int przekieruj_do_przelewu();

	void podaj_koszyk();
};

#endif
