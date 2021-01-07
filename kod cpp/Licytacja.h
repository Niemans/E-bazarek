#ifndef LICYTACJA_H
#define LICYTACJA_H

class Licytacja : Przedmiot 
{
	//Pola
private:
	/**
	 * sekundy do zakonczenia licytacji od dnia 01.01.2020 godz. 00:00:00
	 */
	long long int czas_zakonczenia;
	std::vector <int> id_klient;

	//Metody
public:
	/**
	 * wywoluje funkcje dodaj do koszyka dla konkretnego klienta w bazie danych klientow.
	 */
	void wygrana();

	void dodaj_historie(Histora_licytacji* Root);

	void dodaj_oferte();
};

#endif
