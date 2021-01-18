#include "class_library.h"

		//metody klasy Przedmiot

	//konstruktor klasy Przedmiot
Przedmiot::Przedmiot(std::string nazwaPrzedmiotu, unsigned int iloscPrzedmiotow, unsigned int id_wystawiajacego, unsigned int cenaPrzedmiotu, Przedmiot* nastepnyPrzedmiot, std::string opisPrzedmiotu)
{
	licznik++;			//inkrementujemy licznik przedmiotow

	ID = licznik;
	nazwa = nazwaPrzedmiotu;
	ilosc = iloscPrzedmiotow;
	IDWlasciciela = id_wystawiajacego;
	cena = cenaPrzedmiotu;
	next = nastepnyPrzedmiot;
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

	//funkcja wypisujaca przedmiot w okienku - potrzebna wspolpraca z okienkiem
void Przedmiot::wypisz() {}		//do zrobienia, potrzebne okienko

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


		//metody klasy licytacja

Licytacja::Licytacja(std::string nazwaLicytacji, unsigned int iloscPrzedmiotow, unsigned int id_wystawiajacego, unsigned int cenaWywolawcza, Przedmiot* nastepnaLicytacja, std::string opisPrzedmiotu, unsigned int czas) :
	Przedmiot(nazwaLicytacji, iloscPrzedmiotow, id_wystawiajacego, cenaWywolawcza, nastepnaLicytacja, opisPrzedmiotu)
{
	czasZakonczenia = czas;
}


	//metoda wkladajaca wygrany przedmiot do koszyka zwyciezcy
void Licytacja::wygrana() {}		//do zrobienia

	//metoda dodajaca historie (najnowsza cene) do historii
void Licytacja::dodaj_historie(HistoriaLicytacji* toAdd)
{
	toAdd->next = head;		//ustawiamy wskaznik next nowej ceny jako glowe
	head = toAdd;			//ustawiamy glowe na nowa cene
}

	//nie wiadomo co funkcja robi
void Licytacja::dodaj_oferte(){}		//dowiedziec sie co funkcja robi


		//metody klasy Osoba

	//konstruktor klasy Osoba
Osoba::Osoba(std::string newMail, std::string newHaslo): mail(newMail), haslo(newHaslo)
{
	licznik++;
	ID = licznik;
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


		//metody klasy Klient

	//konstruktor klasy Klient
Klient::Klient(std::string nazwaKlienta, Klient* nastepnyKlient, std::string mailKlienta, std::string hasloKlienta): Osoba(mailKlienta, hasloKlienta)
{
	imieINazwisko = nazwaKlienta;
	next = nastepnyKlient;
}

	//funkcja dodajaca przedmiot na bazarek
void Klient::dodaj_przedmiot(){}		//do zrobienia

	//funkcja usuwajaca przedmiot z bazarku
void Klient::usun_przedmiot(){}			//do zrobienia

	//funkcja zmieniajaca dane wystawionego przedmiotu
void Klient::edytuj_przedmiot(){}		//do zrobienia

	//funkcja dodajaca licytacje na bazarek
void Klient::dodaj_licytacje(){}		//do zrobienia

	//funkcja usuwajaca licytacje z bazarku
void Klient::usun_licytacje(){}			//do zrobienia

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
Firma::Firma(std::string nazwaFirmy, Firma* nastepnaFirma, std::string mailFirmy, std::string hasloFirmy): Osoba(mailFirmy, hasloFirmy)
{
	nazwa_firmy = nazwaFirmy;
	next = nastepnaFirma;
}

	//funkcja dodajaca przedmiot na bazarek
void Firma::dodaj_przedmiot(){}		//do zrobienia

	//funkcja usuwajaca przedmiot z bazarku
void Firma::usun_przedmiot(){}			//do zrobienia

	//funkcja zmieniajaca dane wystawionego przedmiotu
void Firma::edytuj_przedmiot(){}		//do zrobienia

	//funkcja dodajaca licytacje na bazarek
void Firma::dodaj_licytacje(){}		//do zrobienia

	//funkcja usuwajaca licytacje z bazarku
void Firma::usun_licytacje(){}			//do zrobienia

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
	licznik--;
	ID = 0;
}

	//funkcja usuwajaca nieodpowiedni przedmiot
void Admin::usun_przedmiot(unsigned int id_przedmiotu){}		//do zrobienia
	
	//funkcja usuwajaca uzytkownika
void Admin::usun_uzytkownika(unsigned int id_uzytkownika){}	//do zrobienia

		//metody klasy ListaFirm

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
	Firma* pom = head;		//wskaznik pomocniczy - ustawiamy najpierw na glowe

	while (pom != NULL && pom->podaj_id() != id_firmy)		
	{
		pom = pom->podaj_wskaznik_next_firmy();		//dopoki nie znajdziemy firmy o danym ID lub nie dotrzemy do konca listy - przechodzimy kolejne welzy
	}

	return pom;		//jezeli znajdziemy firme - zwroci jej adres, jezeli nie - NULL
}

	//funkcja wyszukuje firme po nazwie
Firma* ListaFirm::wyszukaj_firme(std::string nazwa_firmy)
{
	Firma* pom = head;		//wskaznik pomocniczy - ustawiamy najpierw na glowe

	while (pom != NULL && pom->podaj_nazwe_firmy() != nazwa_firmy)
	{
		pom = pom->podaj_wskaznik_next_firmy();		//dopoki nie znajdziemy firmy o danej nazwie lub nie dotrzemy do konca listy - przechodzimy kolejne welzy
	}

	return pom;		//jezeli znajdziemy firme - zwroci jej adres, jezeli nie - NULL
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
	Klient* pom = head;		//wskaznik pomocniczy - ustawiamy najpierw na glowe

	while (pom != NULL && pom->podaj_id() != id_klienta)
	{
		pom = pom->podaj_wskaznik_next_klienta();	//dopoki nie znajdziemy klienta o danym ID lub nie dotrzemy do konca listy - przechodzimy kolejne welzy
	}

	return pom;		//jezeli znajdziemy klienta - zwroci jego adres, jezeli nie - NULL
}

//funkcja wyszukuje klienta po nazwie
Klient* ListaKlientow::wyszukaj_klienta(std::string nazwa_klienta)
{
	Klient* pom = head;		//wskaznik pomocniczy - ustawiamy najpierw na glowe

	while (pom != NULL && pom->podaj_nazwe_klienta() != nazwa_klienta)
	{
		pom = pom->podaj_wskaznik_next_klienta();		//dopoki nie znajdziemy klienta o danej nazwie lub nie dotrzemy do konca listy - przechodzimy kolejne welzy
	}

	return pom;		//jezeli znajdziemy klienta - zwroci jej adres, jezeli nie - NULL
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
void Bazarek::dodaj_przedmiot(){}		//do zrobienia

	//funkcja dodajaca licytacje
void Bazarek::dodaj_licytacje(){}		//do zrobienia
	
	//funkcja usuwajaca przedmiot
void Bazarek::usun_przedmiot(){}			//do zrobienia

	//funkcja usuwajaca licytacje
void Bazarek::usun_licytacje(){}			//do zrobienia

	//funkcja wyszukujaca przedmioty
std::vector<unsigned int> Bazarek::szukaj(std::string szukanaOferta)
{
	Przedmiot* pomPrzedmiot = listaPrzedmiotow;			//zmienna pomocnicze
	
	std::vector<unsigned int> returnVector;				//zmienna zwracana

	while (pomPrzedmiot != NULL)												//przeszukujemy liste przedmiotow w poszukiwaniu przedmiotu z zadana nazwa
	{
		if (pomPrzedmiot->podaj_nazwe() == szukanaOferta)
		{
			returnVector.push_back(pomPrzedmiot->podaj_id());					
		}

		pomPrzedmiot = pomPrzedmiot->podaj_adres_nastepnego_przedmiotu();
	}

	pomPrzedmiot = listaLicytacji;

	while (pomPrzedmiot != NULL)												//podobnie z listami
	{
		if (pomPrzedmiot->podaj_nazwe() == szukanaOferta)
		{
			returnVector.push_back(pomPrzedmiot->podaj_id());
		}

		pomPrzedmiot = pomPrzedmiot->podaj_adres_nastepnego_przedmiotu();
	}

	return returnVector;

}



//funkcje wspolpracojace z okienkami		wszystko do zrobienia!!!
void Bazarek::wyswietl(){}
void Bazarek::wyswietl_przedmioty(){}
void Bazarek::wyswietl_licytacje(){}

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