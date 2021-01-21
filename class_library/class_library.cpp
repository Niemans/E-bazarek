#include "class_library.h"

		//metody klasy Przedmiot

	//konstruktor klasy Przedmiot
Przedmiot::Przedmiot(std::string nazwaPrzedmiotu, unsigned int iloscPrzedmiotow, unsigned int id_wystawiajacego, unsigned int cenaPrzedmiotu, std::string opisPrzedmiotu)
{
	nazwa = nazwaPrzedmiotu;
	ilosc = iloscPrzedmiotow;
	IDWlasciciela = id_wystawiajacego;
	cena = cenaPrzedmiotu;
	next = NULL;
	opis = opisPrzedmiotu;
}

	//funkcja sprawdzajaca czy podane id zgadza sie z id wlasciciela
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
int Przedmiot::usun_przedmioty(unsigned int ilosc_do_usuniecia)			
{		
	if (ilosc >= ilosc_do_usuniecia)
	{
		ilosc -= ilosc_do_usuniecia;
	}

	return (ilosc - ilosc_do_usuniecia);		//funkcja zwraca roznice miedzy iloscia a usuwanymi przedmiotami. Jezeli ujemna - przedmioty nie zostana odjete
}

	//zwraca nazwe przedmiotu
std::string Przedmiot::podaj_nazwe()
{
	return nazwa;
}

	//zwraca adres nastepnego przedmiotu
Przedmiot* Przedmiot::podaj_adres_nastepnego_przedmiotu()
{
	return next;
}

	//ustawia wskaznik na nasteny przedmiot
void Przedmiot::ustaw_nastepny_przedmiot(Przedmiot* nastepnyPrzedmiot)
{
	next = nastepnyPrzedmiot;
}

	//zwraca ilosc przedmiotow
unsigned int Przedmiot::podaj_ilosc()
{
	return ilosc;
}
	
	//zwraca cene przedmiotu
unsigned int Przedmiot::podaj_cene()
{
	return cena;
}

	//zwraca opis przedmiotu
std::string Przedmiot::podaj_opis()
{
	return opis;
}

	//edytuje parametry przedmiotu
void Przedmiot::edytuj(std::string nowaNazwa, unsigned int nowaIlosc, unsigned int nowaCena, std::string nowyOpis)
{
	nazwa = nowaNazwa;
	ilosc = nowaIlosc;
	cena = nowaCena;
	opis = nowyOpis;
}

		//metody klasy licytacja

	//konstruktor klasy Licytacja
Licytacja::Licytacja(std::string nazwaLicytacji, unsigned int iloscPrzedmiotow, unsigned int id_wystawiajacego, unsigned int cenaWywolawcza, std::string opisPrzedmiotu, unsigned int czas) :
	Przedmiot(nazwaLicytacji, iloscPrzedmiotow, id_wystawiajacego, cenaWywolawcza, opisPrzedmiotu)
{
	czasZakonczenia = czas;
	head = NULL;
	next = NULL;
}

	//metoda zwracajaca next
Licytacja* Licytacja::podaj_adres_nastepnej_licytacji()
{
	return next;
}

	//metoda wkladajaca wygrany przedmiot do koszyka zwyciezcy
void Licytacja::wygrana() {}		//do zrobienia

	//metoda dodajaca historie (najnowsza cene) do historii
void Licytacja::dodaj_historie(HistoriaLicytacji* toAdd)
{
	toAdd->next = head;		//ustawiamy wskaznik next nowej ceny jako glowe
	head = toAdd;			//ustawiamy glowe na nowa cene
}

	//funkcja dodajaca oferte
int Licytacja::dodaj_oferte(unsigned int nowaCena, std::string nazwaUczestnika)
{
	if (nowaCena < cena)		//trzeba przebic dotychczasowa cene
	{
		return -1;
	}

	HistoriaLicytacji* toAdd = new HistoriaLicytacji;

	toAdd->cena = nowaCena;								//ustawiamy zmienne w nowej historii
	toAdd->nazwaUczestkina = nazwaUczestnika;

	toAdd->next = head;									//oferta wskakuje na poczatek listy
	head = toAdd;
}

	//ustawia next licytacji
void Licytacja::ustaw_nastepna_licytacje(Licytacja* nastepnaLicytacja)
{
	next = nastepnaLicytacja;
}

	//zwraca head, slozy do wypisywania historii w okienku
HistoriaLicytacji* Licytacja::zwroc_historie_licytacji()
{
	return head;
}


		//metody klasy Osoba

	//konstruktor klasy Osoba
Osoba::Osoba(std::string newMail, std::string newHaslo, unsigned int idOsoby): mail(newMail), haslo(newHaslo), ID(idOsoby)
{
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

void Osoba::edytuj_email(std::string newMail)
{
	mail = newMail;
}

void Osoba::edytuj_haslo(std::string newHaslo)
{
	haslo = newHaslo;
}

	
	//funkcja zwracajaca id
unsigned int Osoba::podaj_id()
{
	return ID;
}

	//funkcja zwracajaca email
std::string Osoba::podaj_email()
{
	return mail;
}
	 //funkcja zwracajaca haslo
std::string Osoba::podaj_haslo()
{
   return haslo;
}

	//funkcja dodajaca przedmiot na bazarek			//zrobione
void Osoba::dodaj_przedmiot(Bazarek* adresBazarku, std::string nazwaPrzedmiotu, unsigned int iloscPrzedmiotow, unsigned int cenaPrzedmiotu, std::string opisPrzedmiotu)
{
	unsigned int idOsoby = this->podaj_id();
	Przedmiot* przedmiotDoDodania = new Przedmiot(nazwaPrzedmiotu, iloscPrzedmiotow, idOsoby, cenaPrzedmiotu, opisPrzedmiotu);
	adresBazarku->dodaj_przedmiot(przedmiotDoDodania);

}

	//funkcja usuwajaca przedmiot z bazarku			//zrobione
int Osoba::usun_przedmiot(Bazarek* adresBazarku, unsigned int idPrzedmiotu)
{
	Przedmiot* przedmiotDoUsuniecia = adresBazarku->szukaj_przedmiotu_po_id(idPrzedmiotu);

	if (przedmiotDoUsuniecia == NULL)
	{
		return -1;					//kiedy przedmiot o podanym id nie istnieje
	}

	if (przedmiotDoUsuniecia->wypisz_id_wlasciciela() != ID)
	{
		return 0;					//kiedy osoba nie jest wlascicielem przedmiotu
	}
	else
	{
		adresBazarku->usun_przedmiot(idPrzedmiotu);		
		return idPrzedmiotu;		//w przypadku prawidlowego usuniecia zwracane jest id przedmiotu
	}

}

	//funkcja zmieniajaca dane wystawionego przedmiotu
int Osoba::edytuj_przedmiot(Bazarek* adresBazarku, unsigned int idPrzedmiotu, std::string nowaNazwa, unsigned int nowaIlosc, unsigned int nowaCena, std::string nowyOpis)
{
	Przedmiot* przedmiotDoEdycji = adresBazarku->szukaj_przedmiotu_po_id(idPrzedmiotu);

	if (przedmiotDoEdycji == NULL)
	{
		return -1;					//kiedy przedmiot o podanym id nie istnieje
	}

	if (przedmiotDoEdycji->wypisz_id_wlasciciela() != ID)
	{
		return 0;					//kiedy osoba nie jest wlascicielem przedmiotu
	}
	else
	{
		przedmiotDoEdycji->edytuj(nowaNazwa, nowaIlosc, nowaCena, nowyOpis);
	}

}

	//funkcja dodajaca licytacje na bazarek			//zrobione
void Osoba::dodaj_licytacje(Bazarek* adresBazarku, std::string nazwaLicytacji, unsigned int iloscPrzedmiotow, unsigned int cenaWywolawcza, std::string opisPrzedmiotu, unsigned int czasZakonczenia)
{
	unsigned int idOsoby = this->podaj_id();
	Licytacja* LicytacjaDoDodania = new Licytacja(nazwaLicytacji, iloscPrzedmiotow, idOsoby, cenaWywolawcza, opisPrzedmiotu, czasZakonczenia);
	adresBazarku->dodaj_przedmiot(LicytacjaDoDodania);
}

	//funkcja usuwajaca licytacje z bazarku			//zrobione
int Osoba::usun_licytacje(Bazarek* adresBazarku, unsigned int idLicytacji)
{
	Licytacja* licytacjaDoUsuniecia = adresBazarku->szukaj_licytacji_po_id(idLicytacji);

	if (licytacjaDoUsuniecia == NULL)
	{
		return -1;					//kiedy przedmiot o podanym id nie istnieje
	}

	if (licytacjaDoUsuniecia->wypisz_id_wlasciciela() != ID)
	{
		return 0;					//kiedy osoba nie jest wlascicielem przedmiotu
	}
	else
	{
		adresBazarku->usun_licytacje(idLicytacji);
		return idLicytacji;		//w przypadku prawidlowego usuniecia zwracane jest id przedmiotu
	}
}

		//metody klasy Klient

	//konstruktor klasy Klient
Klient::Klient(std::string nazwaKlienta, Klient* nastepnyKlient, std::string mailKlienta, std::string hasloKlienta,unsigned int idKlienta): Osoba(mailKlienta, hasloKlienta, idKlienta)
{
	imieINazwisko = nazwaKlienta;
	mail = mailKlienta;
	haslo = hasloKlienta;
    ID = idKlienta;
	next = nastepnyKlient;
}

	//funkcja dodaje podany przedmiot do koszyka
void Klient::dodaj_do_koszyka(unsigned int id_przedmiotu, int ilosc)
{
	for (int i = 0; i < ilosc; i++)
	{
		koszyk.push_back(id_przedmiotu);
	}
}

	//funkcja uruchamia procedurê zakupu przedmiotów z koszyka
Przedmiot* Klient::kup() { return NULL; }		//do zrobienia

	//funkcja zwracajaca koszyk
std::vector<unsigned int>* Klient::zwroc_koszyk()
{
	return &koszyk;
}

	//usuwa przedmioty z koszyka
void Klient::oproznij_koszyk()
{
	koszyk.clear();
}

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
	
	//konstruktor klasy Firma
Firma::Firma(std::string nazwaFirmy, Firma* nastepnaFirma, std::string mailFirmy, std::string hasloFirmy,unsigned int idFirmy): Osoba(mailFirmy, hasloFirmy, idFirmy)
{
	nazwa_firmy = nazwaFirmy;
	mail = mailFirmy;
    haslo = hasloFirmy;
	ID = idFirmy;
	next = nastepnaFirma;
}


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

	//konstruktor			istnieje tylko jeden admin, wiec definiujemy go poza lista klientow
Admin::Admin(): Osoba("AdminBazarku@gmail.pl", "admin123")
{
}

	//funkcja usuwajaca nieodpowiedni przedmiot
int Admin::usun_przedmiot(Bazarek* adresBazarku, unsigned int id_przedmiotu)
{
	return adresBazarku->usun_przedmiot(id_przedmiotu);
}

	//funkcja usuwajaca nieodpowiednie licytacje
int Admin::usun_licytacje(Bazarek* adresBazarku, unsigned int id_licytacji)
{
	return adresBazarku->usun_licytacje(id_licytacji);
}
	
	//funkcja usuwajaca uzytkownika
int Admin::usun_uzytkownika(unsigned int id_uzytkownika, ListaKlientow* listaUzytkownikow, Bazarek* sklep)
{
	return listaUzytkownikow->usun(id_uzytkownika, sklep);		//zwraca wynik funkcji usun
}

	//funkcja usuwajaca firme
int Admin::usun_firme(unsigned int id_firmy, ListaFirm* listaFirm, Bazarek* sklep)
{
	return listaFirm->usun(id_firmy, sklep);
}

		//metody klasy ListaFirm

int ListaFirm::usun(unsigned int idFirmyDoUsuniecia, Bazarek* sklep)
{
	Firma* pom = head;			//ustawiamy wskaznik pomocniczy na poczatek listy

	if (pom == NULL)
	{
		return -1;				//jezeli lista jest pusta zwracamy -1
	}

	if (pom->podaj_id() == idFirmyDoUsuniecia)				//jezeli szukana firma to head
	{
		head = pom->podaj_wskaznik_next_firmy();
		sklep->usun_wszystkie_przedmioty_i_licytacje_wlasciciela(idFirmyDoUsuniecia);		//usuwamy wszystkie przedmioty i licytacje tej firmy z bazarku
		delete pom;		//usuwamy firme o zadanym id
		return idFirmyDoUsuniecia;		//jako znak poprawnego usuniecia klienta zwracamy jej id

	}

	while (pom->podaj_wskaznik_next_firmy() != NULL)		//petla dziala dopoki nastepnik zmiennej pomocniczej istnieje
	{
		if ((pom->podaj_wskaznik_next_firmy())->podaj_id() == idFirmyDoUsuniecia)		//jezeli ten nastepnik istnieje i jego id jest rowne id firmy do usuniecia to usuwamy ten obiekt
		{
			Firma* FirmaDoUsuniecia = pom->podaj_wskaznik_next_firmy();							//ustawiamy kolejna zmienna pomocnicza na element do usuniecia
			pom->ustaw_wskaznik_next_firmy(FirmaDoUsuniecia->podaj_wskaznik_next_firmy());		//next pomocniczego ustawiany jest na next firmy do usuniecia

			sklep->usun_wszystkie_przedmioty_i_licytacje_wlasciciela(idFirmyDoUsuniecia);		//usuwamy wszystkie przedmioty i licytacje tej firmy z bazarku
			delete FirmaDoUsuniecia;		//usuwamy firme o zadanym id
			return idFirmyDoUsuniecia;		//jako znak poprawnego usuniecia klienta zwracamy jej id
		}

		pom = pom->podaj_wskaznik_next_firmy();			//na koncu petli wskaznik pomocniczy ustawiany jest na nastepny obiekt
	}

	return 0;		//jezeli nie znaleziono firmy o takim id to zwracane jest 0
}

	//konstruktor klasy ListaFirm
ListaFirm::ListaFirm()
{
	head = NULL;
}

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
int ListaFirm::sprawdz(std::string email_firmy, std::string nazwa_firmy)		
{
	int returnInt = 0;		//wartosc ktora bedziemy zwracac

	Firma* pom = head;		//wskaznik pomocniczy - ustawiamy najpierw na glowe

	while (pom != NULL)
	{
		pom = pom->podaj_wskaznik_next_firmy();		//dopoki nie dotrzemy do konca listy - przechodzimy kolejne welzy

		if (pom->podaj_email() == email_firmy)
		{
			returnInt += 2;
		}

		if (pom->podaj_nazwe_firmy() == nazwa_firmy)
		{
			returnInt += 1;
		}

	}

	return returnInt;		//jezeli nie ma takiej firmy - 0, jezeli jest firma o takiej nazwie - 1, jezeli jest firma zarejestrowana na podany email - 2, jezeli nazwa i email sa zajete - 3
}

	//funkcja wyszukuje firme po id
Firma* ListaFirm::wyszukaj_firme(unsigned int id_firmy)
{
//	Firma* pom = head;		//wskaznik pomocniczy - ustawiamy najpierw na glowe
//
//	while (pom != NULL && pom->podaj_id() != id_firmy)
//	{
//		pom = pom->podaj_wskaznik_next_firmy();		//dopoki nie znajdziemy firmy o danym ID lub nie dotrzemy do konca listy - przechodzimy kolejne welzy
//	}
//
//	return pom;		//jezeli znajdziemy firme - zwroci jej adres, jezeli nie - NULL
}

	//funkcja wyszukuje firme po nazwie
Firma* ListaFirm::wyszukaj_firme(std::string email_firmy)
{
//	Firma* pom = head;		//wskaznik pomocniczy - ustawiamy najpierw na glowe
//
//	while (pom != NULL && pom->podaj_email() != email_firmy)
//	{
//		pom = pom->podaj_wskaznik_next_firmy();		//dopoki nie znajdziemy firmy o danej nazwie lub nie dotrzemy do konca listy - przechodzimy kolejne welzy
//	}
//
//	return pom;		//jezeli znajdziemy firme - zwroci jej adres, jezeli nie - NULL
}


		//metody klasy ListaKlientow

	//konstruktor klasy ListaKlientow
ListaKlientow::ListaKlientow()
{
	head = NULL;
}

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

	//funkcja usuwa z listy klienta o zadanym ID
int ListaKlientow::usun(unsigned int idKlientaDoUsuniecia, Bazarek* sklep)
{
	Klient* pom = head;			//ustawiamy wskaznik pomocniczy na poczatek listy

	if (pom == NULL)
	{
		return -1;				//jezeli lista jest pusta zwracamy -1
	}

	if (pom->podaj_id() == idKlientaDoUsuniecia)
	{
		head = pom->podaj_wskaznik_next_klienta();
		sklep->usun_wszystkie_przedmioty_i_licytacje_wlasciciela(idKlientaDoUsuniecia);			//usuwamy wszystkie przedmioty i licytacje klienta z bazarku
		delete pom;																				//usuwamy klienta o zadanym id
		return idKlientaDoUsuniecia;															//jako znak poprawnego usuniecia klienta zwracamy jego id
	}

	while (pom->podaj_wskaznik_next_klienta() != NULL)		//petla dziala dopoki nastepnik zmiennej pomocniczej istnieje
	{
		if ((pom->podaj_wskaznik_next_klienta())->podaj_id() == idKlientaDoUsuniecia)				//jezeli ten nastepnik istnieje i jego id jest rowne id klienta do usuniecia to usuwamy ten obiekt
		{
			Klient* KlientDoUsuniecia = pom->podaj_wskaznik_next_klienta();							//ustawiamy kolejna zmienna pomocnicza na element do usuniecia
			pom->ustaw_wskaznik_next_klienta(KlientDoUsuniecia->podaj_wskaznik_next_klienta());		//next pomocniczego ustawiany jest na next klienta do usuniecia

			sklep->usun_wszystkie_przedmioty_i_licytacje_wlasciciela(idKlientaDoUsuniecia);			//usuwamy wszystkie przedmioty i licytacje klienta z bazarku
			delete KlientDoUsuniecia;																//usuwamy klienta o zadanym id
			return idKlientaDoUsuniecia;															//jako znak poprawnego usuniecia klienta zwracamy jego id
		}

		pom = pom->podaj_wskaznik_next_klienta();			//na koncu petli wskaznik pomocniczy ustawiany jest na nastepny obiekt
	}

	return 0;		//jezeli nie znaleziono klienta o takim id to zwracane jest 0
}

//funkcja sprawdza czy podany klient juz istnieje
int ListaKlientow::sprawdz(std::string email_klienta, std::string nazwa_klienta)		
{
	int returnInt = 0;		//wartosc ktora bedziemy zwracac

	Klient* pom = head;		//wskaznik pomocniczy - ustawiamy najpierw na glowe

	while (pom != NULL)
	{
		pom = pom->podaj_wskaznik_next_klienta();		//dopoki nie dotrzemy do konca listy - przechodzimy kolejne welzy

		if (pom->podaj_email() == email_klienta)
		{
			returnInt += 2;
		}

		if (pom->podaj_nazwe_klienta() == nazwa_klienta)
		{
			returnInt += 1;
		}

	}

	return returnInt;		//jezeli nie ma takiego klienta - 0, jezeli jest klient o takiej nazwie - 1, jezeli jest klient zarejestrowany na podany email - 2, jezeli nazwa i email sa zajete - 3
}

//funkcja wyszukuje klienta po id
Klient* ListaKlientow::wyszukaj_klienta(unsigned int id_klienta)
{
//	Klient* pom = head;		//wskaznik pomocniczy - ustawiamy najpierw na glowe
//
//	while (pom != NULL && pom->podaj_id() != id_klienta)
//	{
//		pom = pom->podaj_wskaznik_next_klienta();	//dopoki nie znajdziemy klienta o danym ID lub nie dotrzemy do konca listy - przechodzimy kolejne welzy
//	}
//
//	return pom;		//jezeli znajdziemy klienta - zwroci jego adres, jezeli nie - NULL
}

//funkcja wyszukuje klienta po nazwie
Klient* ListaKlientow::wyszukaj_klienta(std::string email_klienta)
{
//	Klient* pom = head;		//wskaznik pomocniczy - ustawiamy najpierw na glowe
//
//	while (pom != NULL && pom->podaj_email() != email_klienta)
//	{
//		pom = pom->podaj_wskaznik_next_klienta();		//dopoki nie znajdziemy klienta o danej nazwie lub nie dotrzemy do konca listy - przechodzimy kolejne welzy
//	}
//
//	return pom;		//jezeli znajdziemy klienta - zwroci jej adres, jezeli nie - NULL
}

			//metody klasy Bazarek

	//konstruktor klasy Bazarek
Bazarek::Bazarek()
{
	liczbaPrzedmiotow = 0;
	liczbaLicytacji = 0;
	listaPrzedmiotow = NULL;
	listaLicytacji = NULL;
}

		//obsluga wystawionych przedmiotow i licytacji
	//funkcja dodajaca przedmiot
int Bazarek::dodaj_przedmiot(Przedmiot* toAdd)
{
	if (toAdd == NULL)
	{
		return -1;
	}

	Przedmiot* pom = listaPrzedmiotow;

	if (pom == NULL)
	{
		listaPrzedmiotow = toAdd;		//jezeli glowa listy == NULL to pom staje sie pierwszym przedmiotem na liscie	
	}
	else
	{
		while (pom->podaj_adres_nastepnego_przedmiotu() != NULL)		//petla skacze po liscie az nie trafi na jej koniec
		{
			pom = pom->podaj_adres_nastepnego_przedmiotu();
		}

		listaPrzedmiotow = toAdd;		//po zakonczeniu petli przedmiot dopisywany jest na koniec listy
	}

	return toAdd->podaj_id();			//na znak poprawnego dodania przedmiotu zwracane jest jego id
	
}

	//funkcja dodajaca licytacje
int Bazarek::dodaj_licytacje(Licytacja* toAdd)
{
	if (toAdd == NULL)
	{
		return -1;
	}

	Licytacja* pom = listaLicytacji;

	if (pom == NULL)
	{
		listaLicytacji = toAdd;		//jezeli glowa listy == NULL to pom staje sie pierwszym przedmiotem na liscie	
	}
	else
	{
		while (pom->podaj_adres_nastepnej_licytacji() != NULL)		//petla skacze po liscie az nie trafi na jej koniec
		{
			pom = pom->podaj_adres_nastepnej_licytacji();
		}

		listaLicytacji = toAdd;		//po zakonczeniu petli przedmiot dopisywany jest na koniec listy
	}

	return toAdd->podaj_id();			//na znak poprawnego dodania przedmiotu zwracane jest jego id


}		//do zrobienia
	
	//funkcja usuwajaca przedmiot
int Bazarek::usun_przedmiot(unsigned int idPrzedmiotu)
{
	Przedmiot* pom = listaPrzedmiotow;

	if (listaPrzedmiotow == NULL)
	{
		return -1;																						//jezeli lista jest pusta zwracamy -1
	}

	if (pom->podaj_id() == idPrzedmiotu)																//jezeli glowa to szukany przedmiot to ja usuwamy
	{
		listaPrzedmiotow = pom->podaj_adres_nastepnego_przedmiotu();
		delete pom;
		return idPrzedmiotu;
	}

	while (pom->podaj_adres_nastepnego_przedmiotu() != NULL)											//petla dziala dopoki nie dojdzie do konca listy
	{
		if ((pom->podaj_adres_nastepnego_przedmiotu())->podaj_id() == idPrzedmiotu)						//jezeli nastepnik biezacego przedmiotu ma zadane id to go usuwamy
		{
			Przedmiot* przedmiotDoUsuniecia = pom->podaj_adres_nastepnego_przedmiotu();					//wskaznik nakierowany na nastepnik biezacego przedmiotu 
			pom->ustaw_nastepny_przedmiot(przedmiotDoUsuniecia->podaj_adres_nastepnego_przedmiotu());	//next biezacego przedmiotu ustawiony na next jego nastepnika

			delete przedmiotDoUsuniecia;																//usuwamy zadany przedmiot
			return idPrzedmiotu;																		//zwracamy id usunietego przedmiotu na znak prawidlowego wykonania funkcji
		}

		pom = pom->podaj_adres_nastepnego_przedmiotu();
	}

	return 0;																							//jezeli nie ma przedmiotu o podanym id to zwracamy 0
}

	//funkcja usuwajaca licytacje
int Bazarek::usun_licytacje(unsigned int idLicytacji)
{
	Licytacja* pom = listaLicytacji;

	if (listaLicytacji == NULL)
	{
		return -1;																						//jezeli lista jest pusta zwracamy -1
	}

	if (pom->podaj_id() == idLicytacji)																	//jezeli glowa to szukana licytacja to ja usuwamy
	{
		listaLicytacji = pom->podaj_adres_nastepnej_licytacji();
		delete pom;
		return idLicytacji;
	}

	while (pom->podaj_adres_nastepnej_licytacji() != NULL)												//petla dziala dopoki nie dojdzie do konca listy
	{
		if ((pom->podaj_adres_nastepnej_licytacji())->podaj_id() == idLicytacji)						//jezeli nastepnik biezacegj licytacji ma zadane id to go usuwamy
		{
			Licytacja* licytacjaDoUsuniecia = pom->podaj_adres_nastepnej_licytacji();					//wskaznik nakierowany na nastepnik biezacej licytacji
			pom->ustaw_nastepna_licytacje(licytacjaDoUsuniecia->podaj_adres_nastepnej_licytacji());		//next biezacej licytacji ustawiony na next jego nastepnika

			delete licytacjaDoUsuniecia;																//usuwamy zadana licytacje
			return idLicytacji;																			//zwracamy id usunietej licytacji na znak prawidlowego wykonania funkcji
		}

		pom = pom->podaj_adres_nastepnej_licytacji();
	}

	return 0;																							//jezeli nie ma licytacji o podanym id zwracamy 0
}

	//funkcja szukajaca przedmiotow po nazwie
std::vector<unsigned int>* Bazarek::szukaj_przedmiotow_po_nazwie(std::string szukanaOferta)
{
	Przedmiot* pom = listaPrzedmiotow;													//przedmiot pomocniczy - hlowa listy
	std::vector<unsigned int>* zwracanyWektor = new std::vector<unsigned int>;			//wektor ktory bedziemy zwracac

	while (pom != NULL)																	//przechodzimy cala liste
	{
		if (pom->podaj_nazwe() == szukanaOferta)										//jezeli nazwa przedmiotu rowna sie szukanej nazwie
		{
			zwracanyWektor->push_back(pom->podaj_id());									//wk³adamy id tego przedmiotu do wektora
		}

		pom = pom->podaj_adres_nastepnego_przedmiotu();									//przechodzimy dalej w liscie
	}

	return zwracanyWektor;																//zwracamy wektor

}

	//funkcja szukajaca licytacji po nazwie
std::vector<unsigned int>* Bazarek::szukaj_licytacji_po_nazwie(std::string szukanaLicytacja)
{
	Licytacja* pom = listaLicytacji;													//przedmiot pomocniczy - glowa listy
	std::vector<unsigned int>* zwracanyWektor = new std::vector<unsigned int>;			//wektor ktory bedziemy zwracac

	while (pom != NULL)																	//przechodzimy cala liste
	{
		if (pom->podaj_nazwe() == szukanaLicytacja)										//jezeli nazwa licytacji rowna sie szukanej nazwie
		{
			zwracanyWektor->push_back(pom->podaj_id());									//wk³adamy id tej licytacji do wektora
		}

		pom = pom->podaj_adres_nastepnej_licytacji();									//przechodzimy dalej w liscie
	}

	return zwracanyWektor;
}

	//funkcja szukajaca przedmiotu o danym id
Przedmiot* Bazarek::szukaj_przedmiotu_po_id(unsigned int idPrzedmiotu)
{
	Przedmiot* pom = listaPrzedmiotow;
	Przedmiot* zwracanyWskaznik = NULL;

	while (pom != NULL)
	{
		if (pom->podaj_id() == idPrzedmiotu)
		{
			zwracanyWskaznik = pom;
			break;
		}
	}

	return zwracanyWskaznik;
}

	//funkcja szukajaca licytacji o danym id
Licytacja* Bazarek::szukaj_licytacji_po_id(unsigned int idLicytacji)
{
	Licytacja* pom = listaLicytacji;
	Licytacja* zwracanyWskaznik = NULL;

	while (pom != NULL)
	{
		if (pom->podaj_id() == idLicytacji)
		{
			zwracanyWskaznik = pom;
			break;
		}
	}

	return zwracanyWskaznik;
}



//funkcje wspolpracojace z okienkami		wszystko do zrobienia!!!
void Bazarek::wyswietl(){}
void Bazarek::wyswietl_przedmioty(){}
void Bazarek::wyswietl_licytacje(){}

	//funkcja szukajaca wszystkich przedmiotow osoby
std::vector<unsigned int>* Bazarek::wyszukaj_przedmioty_osoby(unsigned int idOsoby)
{
	Przedmiot* pom = listaPrzedmiotow;
	std::vector<unsigned int>* wektorDoZwrocenia = new std::vector<unsigned int>;

	while (pom != NULL)
	{
		if (pom->sprawdz_id_wlasciciela(idOsoby))
		{
			wektorDoZwrocenia->push_back(pom->podaj_id());
		}

		pom = pom->podaj_adres_nastepnego_przedmiotu();
	}

	return wektorDoZwrocenia;
}

	//funkcja szukajaca wszystkich licytacji osoby
std::vector<unsigned int>* Bazarek::wyszukaj_licytacje_osoby(unsigned int idOsoby)
{
	Licytacja* pom = listaLicytacji;
	std::vector<unsigned int>* wektorDoZwrocenia = new std::vector<unsigned int>;

	while (pom != NULL)
	{
		if (pom->sprawdz_id_wlasciciela(idOsoby))
		{
			wektorDoZwrocenia->push_back(pom->podaj_id());
		}

		pom = pom->podaj_adres_nastepnej_licytacji();
	}

	return wektorDoZwrocenia;
}

	//funkcja uzywana przy usuwaniu konta
void Bazarek::usun_wszystkie_przedmioty_i_licytacje_wlasciciela(unsigned int idWlasciciela)
{
	Licytacja* licPom = listaLicytacji;		//zmienne pomocnicze
	Przedmiot* przedPom = listaPrzedmiotow;

	while (licPom != NULL)
	{
		if (licPom->sprawdz_id_wlasciciela(idWlasciciela))
		{
			usun_licytacje(licPom->podaj_id());
		}

		licPom = licPom->podaj_adres_nastepnej_licytacji();
	}

	while (przedPom!= NULL)
	{
		if (przedPom->sprawdz_id_wlasciciela(idWlasciciela))
		{
			usun_przedmiot(przedPom->podaj_id());
		}

		przedPom = przedPom->podaj_adres_nastepnego_przedmiotu();
	}
}

//funkcje do obslugi licytacji
bool Bazarek::sprawdz_czas_licytacji(Licytacja* licytacjaDoSprawdzenia) { return true; }
void Bazarek::sprawdz_wszystkie_licytacje(){}


		//metody klasy ObslogaZamowien

	//konstruktor klasy ObslogaZamowien
ObslugaZamowien::ObslugaZamowien()
{
	imie = "brak";
	nazwisko = "brak";
	kraj = "brak";
	miasto = "brak";
	ulica = "brak";
	nrDomu = "brak";
	kodPocztowy = 0;
}

	//funkcja pobierajaca od uzytkownika dane osobowe
void ObslugaZamowien::podaj_dane_osobowe(std::string Im, std::string Naz)
{
	imie = Im;
	nazwisko = Naz;
}

	//funkcja pobierajaca od uzytkownika dane adresowe
void ObslugaZamowien::podaj_dane_adresowe(std::string Kr, std::string Mi, std::string Ul, std::string Nr)
{
	kraj = Kr;
	miasto = Mi;
	ulica = Ul;
	nrDomu = Nr;
}

	//???
int ObslugaZamowien::przekieruj_na_payu(){}			//do zrobienia wszystkie
void ObslugaZamowien::wybierz_opcje_platnosci(){}
void ObslugaZamowien::przekieruj_do_przelewu(){}

	//funkcja podajaca koszyk klienta
void ObslugaZamowien::podaj_koszyk(std::vector<unsigned int> koszyk_do_podania)
{
	koszyk = koszyk_do_podania;
}