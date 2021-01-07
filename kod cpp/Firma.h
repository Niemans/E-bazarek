#ifndef FIRMA_H
#define FIRMA_H

class Firma : Osoba 
{
	//Pola
private:
	std::string nazwa_firmy;
	Firma* next;

	//Metody
private:

	void dodaj_przedmiot();

	void usun_przedmiot();

	void dodaj_licytacje();

	void usun_licytacje();

	void edytuj_przedmiot();
};

#endif
