#ifndef LISTA_KLIENT_H
#define LISTA_KLIENT_H

class lista_klient 
{
	//Pola
private:
	Klient* head;

	//Metody
public:
	void dodaj(Klient* nowy);

	bool spradz();

	Klient* wyszukaj_klient(int id);

	Klient* wyszukaj_osobe();
};

#endif
