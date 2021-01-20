#include <string>
#include <vector>
#include <iostream>
#include <fmx.h>


class Przedmiot{
protected:
	static unsigned int licznik;
	unsigned int ID;
	std::string nazwa;
	unsigned int ilosc;
	unsigned int IDWlasciciela;
	unsigned int cena;
	Przedmiot* next;
	std::string opis;

public:
	Przedmiot(std::string nazwaPrzedmiotu, unsigned int iloscPrzedmiotow, unsigned int id_wystawiajacego, unsigned int cenaPrzedmiotu, std::string opisPrzedmiotu);		//konstruktor			zrobione
	bool sprawdz_id_wlasciciela(unsigned int idOsoby);		//funkcja sprawdzajaca czy podane id zgadza sie z id wlasciciela				zrobione
	unsigned int wypisz_id_wlasciciela();					//funkcja zwracajaca id wlasciciela						zrobione
	bool czy_dostepny();									//funkcja sprawdzajaca czy produkt jest dostepny		zrobione
	unsigned int podaj_id();								//funkcja zwracajaca id przedmiotu						zrobione
	int usun_przedmioty(unsigned int ilosc);				//funkcja usuwajaca egzemplaze przedmiotu				zrobione, jezeli funkcja zwroci wartosc dodatnia - operacja zostala wykonana, jezeli ujemna - czynnosc nie zostala wykonana
	std::string podaj_nazwe();								//zwraca nazwe przedmiotu								zrobione
	Przedmiot* podaj_adres_nastepnego_przedmiotu();			//zwraca adres nastepnego przedmiotu					zrobione
	void ustaw_nastepny_przedmiot(Przedmiot* nastepnyPrzedmiot);	//ustawia adres nastepnego przedmiotu			zrobione
	unsigned int podaj_ilosc();								//zwraca ilosc produktow								zrobione
	unsigned int podaj_cene();								//zwraca cene produktu									zrobione
	std::string podaj_opis();								//zwraca opis produktu									zrobione
	void edytuj(std::string nowaNazwa, unsigned int nowaIlosc, unsigned int nowaCena, std::string nowyOpis);		//zrobione
};


class HistoriaLicytacji {				//pojemnik na dane, nie wymaga konstruktora
public:
	unsigned int cena;
	std::string nazwaUczestkina;
	HistoriaLicytacji* next;
};


class Licytacja : public Przedmiot {
private:
	unsigned int czasZakonczenia;
	Licytacja* next;
	HistoriaLicytacji* head;

public:
	Licytacja(std::string nazwaLicytacji, unsigned int iloscPrzedmiotow, unsigned int id_wystawiajacego, unsigned int cenaWywolawcza, std::string opisPrzedmiotu, unsigned int czas);		//zrobione
	Licytacja* podaj_adres_nastepnej_licytacji();		//zwraca next													zrobione
	void wygrana();										//metoda wkladajaca wygrany przedmiot do koszyka zwyciezcy		do zrobienia
	void dodaj_historie(HistoriaLicytacji* toAdd);		//metoda dodajaca historie (najnowsza cene) do historii			zrobione, w zasadzie bezuzyteczne bo mamy dodaj oferte
	int dodaj_oferte(unsigned int nowaCena, std::string nazwaUczestnika);			//funkcja dodajaca oferte			zrobione
	void ustaw_nastepna_licytacje(Licytacja* nastepnaLicytacja);					//ustawia next						zrobione
	HistoriaLicytacji* zwroc_historie_licytacji();									//zwraca head, slozy do wypisywania historii w okienku		zrobione
};


class Bazarek {
private:
	unsigned int liczbaPrzedmiotow;
	unsigned int liczbaLicytacji;				//dodane przeze mnie
	Przedmiot* listaPrzedmiotow;
	Licytacja* listaLicytacji;					//dodane przeze mnie

public:

	Bazarek();
	//obsluga wystawionych przedmiotow i licytacji				tutaj wszystko do zrobienia
	int dodaj_przedmiot(Przedmiot* toAdd);				//funkcja dodajaca przedmiot		zrobione
	int dodaj_licytacje(Licytacja* toAdd);				//funkcja dodajaca licytacje		zrobione
	int usun_przedmiot(unsigned int idPrzedmiotu);		//funkcja usuwajaca przedmiot		zrobione
	int usun_licytacje(unsigned int idLicytacji);		//funkcja usuwajaca licytacje		zrobione

	std::vector<unsigned int>* szukaj_przedmiotow_po_nazwie(std::string szukanaOferta);			//funkcja szukajaca przedmiotow po nazwie		zrobione
	std::vector<unsigned int>* szukaj_licytacji_po_nazwie(std::string szukanaLicytacja);		//funkcja szukajaca licytacji po nazwie			zrobione
	Przedmiot* szukaj_przedmiotu_po_id(unsigned int idPrzedmiotu);								//funkcja szukajaca przedmiotow po id			zrobione
	Licytacja* szukaj_licytacji_po_id(unsigned int idLicytacji);								//funkcja szukajaca licytacji po id				zrobione

		//funkcje wspolpracojace z okienkami						tutaj wszystko do zrobienia
	void wyswietl();
	void wyswietl_przedmioty();
	void wyswietl_licytacje();

	std::vector<unsigned int>* wyszukaj_przedmioty_osoby(unsigned int idOsoby);			//funkcja szukajaca wszystkich przedmiotow osoby		zrobione
	std::vector<unsigned int>* wyszukaj_licytacje_osoby(unsigned int idOsoby);			//funkcja szukajaca wszystkich licytacji osoby			zrobione
	void usun_wszystkie_przedmioty_i_licytacje_wlasciciela(unsigned int idWlasciciela);	//funkcja uzywana przy usuwaniu konta

	//funkcje do obslugi licytacji								i tu tez
	bool sprawdz_czas_licytacji(Licytacja* licytacjaDoSprawdzenia);
	void sprawdz_wszystkie_licytacje();

};


class Osoba {
protected:
	std::string mail;
	std::string haslo;
	unsigned int ID;
	static unsigned int licznik;

public:
	Osoba(std::string newMail = "brak_danych", std::string newHaslo = "brak_danych");	//konstruktor klasy Osoba					zrobione	
	bool sprawdz_dane(std::string compMail, std::string compHaslo);						//funkcja sprawdzajaca czy podane przez uzytkownika dane sa poprawne		zrobione
	void edytuj_dane(std::string newMail, std::string newHaslo);						//funkcja edytujaca dane					zrobione
	unsigned int podaj_id();															//nowododana, nie ma w diagramie klas		zrobione
	std::string podaj_email();															//nowododana, nie ma w diagramie klas		zrobione

			//obsluga wystawionych przedmiotow			wszystko zrobione
	void dodaj_przedmiot(Bazarek* adresBazarku, std::string nazwaPrzedmiotu, unsigned int iloscPrzedmiotow, unsigned int cenaPrzedmiotu, std::string opisPrzedmiotu);
	int usun_przedmiot(Bazarek* adresBazarku, unsigned int idPrzedmiotu);
	int edytuj_przedmiot(Bazarek* adresBazarku, unsigned int idPrzedmiotu, std::string nowaNazwa, unsigned int nowaIlosc, unsigned int nowaCena, std::string nowyOpis);

		//obsluga wystawionych licytacji			zrobione
	void dodaj_licytacje(Bazarek* adresBazarku, std::string nazwaLicytacji, unsigned int iloscPrzedmiotow, unsigned int cenaWywolawcza, std::string opisPrzedmiotu, unsigned int czasZakonczenia);
	int usun_licytacje(Bazarek* adresBazarku, unsigned int idLicytacji);

};


class Klient : public Osoba {					
private:
	std::string imieINazwisko;
	Klient* next;
	std::vector<unsigned int> koszyk;

public:

	Klient(std::string nazwaKlienta, Klient* nastepnyKlient, std::string mailKlienta, std::string hasloKlienta);		//kosntruktor klienta		zrobione

		//dodawanie przedmiotu do koszyka			zrobione
	void dodaj_do_koszyka(unsigned int id_przedmiotu, int ilosc);

		//zakup przedmiotow z koszyka				do zrobienia
	Przedmiot* kup();

		//funkcja zwracajaca koszyk
	std::vector<unsigned int>* zwroc_koszyk();		//zrobione
		
		//oproznia koszyk uzytkownika
	void oproznij_koszyk();							//zrobione

	//gettery										//po prostu zwracaja dane, zrobione
	std::string podaj_nazwe_klienta();
	Klient* podaj_wskaznik_next_klienta();

	//settery
	void ustaw_nazwe_klienta(std::string nazwa_do_ustawienia);			//po prostu zmieniaja dane, zrobione
	void ustaw_wskaznik_next_klienta(Klient* wskaznik_do_ustawienia);

};


class Firma : public Osoba {
private:
	std::string nazwa_firmy;
	Firma* next;

public:

	Firma(std::string nazwaFirmy, Firma* nastepnaFirma, std::string mailFirmy, std::string hasloFirmy);		//kosntruktor firmy		zrobione


		//gettery										//po prostu zwracaja dane, zrobione
	std::string podaj_nazwe_firmy();
	Firma* podaj_wskaznik_next_firmy();

		//settery
	void ustaw_nazwe_firmy(std::string nazwa_do_ustawienia);		//po prostu zmieniaja dane, zrobione
	void ustaw_wskaznik_next_firmy(Firma* wskaznik_do_ustawienia);

};


class ListaFirm {

private:
	Firma* head;

public:
	ListaFirm();														//konstruktor											zrobione
	void dodaj(Firma* toAdd);											//funkcja dodaje firme do listy							zrobione
	int sprawdz(std::string email_firmy, std::string nazwa_firmy);		//funkcja sprawdza czy podana firma juz istnieje		zrobione, mozliwy odutput: 0-nic nie zajete, 1-zajeta nazwa, 2-zajety email, 3 zajeta nazwa i email
	Firma* wyszukaj_firme(unsigned int id_firmy);						//funkcja wyszukuje firme po id							zrobione
	Firma* wyszukaj_firme(std::string nazwa_firmy);						//funkcja wyszukuje firme po nazwie						zrobione
	int usun(unsigned int idFirmyDoUsuniecia, Bazarek* sklep);			//funkcja usuwajaca firme o danym id z listy			zrobione
		
};


class ListaKlientow {
private:
	Klient* head;

public:
	ListaKlientow();														//konstruktor											zrobione
	void dodaj(Klient* toAdd);												//funkcja dodaje klienta do listy						zrobione
	int sprawdz(std::string email_klienta, std::string nazwa_klienta);		//funkcja sprawdza czy podany klient juz istnieje		zrobione, mozliwy odutput: 0-nic nie zajete, 1-zajeta nazwa, 2-zajety email, 3 zajeta nazwa i email
	Klient* wyszukaj_klienta(unsigned int id_klienta);						//funkcja wyszukuje klienta po id						zrobione
	Klient* wyszukaj_klienta(std::string nazwa_klienta);					//funkcja wyszukuje klienta po nazwie					zrobione
	int usun(unsigned int idKlientaDoUsuniecia, Bazarek* sklep);			//funkcja usuwajaca klienta o danym id z listy			zrobione

};


class ObslugaZamowien {
private:
	std::string imie;
	std::string nazwisko;
	std::string kraj;
	std::string miasto;
	std::string ulica;
	std::string nrDomu;
	unsigned int kodPocztowy;
	std::vector<unsigned int> koszyk;

public:
	ObslugaZamowien();																			//konstruktor klasy ObslugaZamowien						zrobione
	void podaj_dane_osobowe(std::string Im, std::string Naz);									//funkcja pobierajaca od uzytkownika dane osobowe		zrobione
	void podaj_dane_adresowe(std::string Kr, std::string Mi, std::string Ul, std::string Nr);	//funkcja pobierajaca od uzytkownika dane adresowe		zrobione
	int przekieruj_na_payu();				//wszystkie te opcje wymagaja okienek
	void wybierz_opcje_platnosci();
	void przekieruj_do_przelewu();
	void podaj_koszyk(std::vector<unsigned int> koszyk_do_podania);		//funkcja podajaca koszyk klienta		zrobione
};


class Admin : public Osoba {
public:
	Admin();
	int usun_przedmiot(Bazarek* adresBazarku, unsigned int id_przedmiotu);		//usuwa wybrany przedmiot		zrobione
	int usun_licytacje(Bazarek* adresBazarku, unsigned int id_licytacji);		//usuwa wybrana licytacje		zrobione
	int usun_uzytkownika(unsigned int id_uzytkownika, ListaKlientow* listaUzytkownikow, Bazarek* sklep);		//funkcja usuwajaca uzytkownika o zadanym id z listy uzytkownikow		zrobione
	int usun_firme(unsigned int id_firmy, ListaFirm* listaFirm, Bazarek* sklep);								//funkcja usuwajaca firme o zadanym id z listy firm						zrobione

};