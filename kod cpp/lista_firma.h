#ifndef LISTA_FIRMA_H
#define LISTA_FIRMA_H

class lista_firma 
{
	//Pola
private:
	Firma* head;

	//Metody
public:
	void dodaj(Firma* nowy);

	bool sprawdz();

	Firma* wyszukaj_firme(int id);

	Firma* wyszukaj_firme();
};

#endif
