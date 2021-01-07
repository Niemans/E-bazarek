#ifndef BAZAREK_H
#define BAZAREK_H

class bazarek 
{
	//Pola
private:
	int liczba_przed;
	Przedmiot* head;

	//Metody
public:
	void usun(int id);

	Przedmiot* szukaj(std::string nazwa);

	void wyswietl();

	void wyswietl_przedmiot();

	void wyswietl_licytacje();

	bool sprawdz_czas_licytacji();

	void sprawdz_wszystkie_licytacje();

	void sprawdz_wszystkie_licytacje2();

	bool sprawdz_czas_licytacji2();
};

#endif
