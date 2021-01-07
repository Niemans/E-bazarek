#ifndef OSOBA_H
#define OSOBA_H


class Osoba
{
	//Pola
protected:
	std::string mail;
	std::string haslo;
	std::string nr_konta;
	int id;
public:
	/**
	 * STATIC
	 */
	int licznik;


	//Metody
protected:
	/**
	 * licznik++;
	 */
	Osoba(std::string mailnew, std::string haslonew);

	/**
	 * WIRTUALNA
	 * Sprawdza czy istnieje u¿ytkownik z podanym mailem i czy haslo jest poprawne.
	 */
	bool sprawdz_dane();

	/*
	*zmiana maila, hasla
	*/
	void edytuj_dane();
};

#endif
