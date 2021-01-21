#include "pch.h"
#include "class_library.h"

			//testy metod klasy Przedmiot
				//metody nie pokryte - podaj_id ze wzgledu na zmiane znaczenia id w trakcie pisania programu

Przedmiot PrzedmiotTestowy("Stary opel", 5, 10, 10000, "Sprzedam opla");

	//pokrywa metody czy_dostepne i usun_przedmioty
TEST(TestPrzedmiotu, Test_czy_dostepny) {

	EXPECT_TRUE(PrzedmiotTestowy.czy_dostepny());
	EXPECT_EQ(PrzedmiotTestowy.usun_przedmioty(2), 3);
	EXPECT_TRUE(PrzedmiotTestowy.czy_dostepny());
	EXPECT_EQ(PrzedmiotTestowy.usun_przedmioty(3), 0);
	EXPECT_FALSE(PrzedmiotTestowy.czy_dostepny());
	EXPECT_EQ(PrzedmiotTestowy.usun_przedmioty(3), -3);
}						

	//pokrywa metody wypisz_id_wlasciciela i sprawdz_id_wlasciciela
TEST(TestPrzedmiotu, Test_sprawdz_id_wlasciciela) {

	EXPECT_EQ(10, PrzedmiotTestowy.wypisz_id_wlasciciela());
	EXPECT_TRUE(PrzedmiotTestowy.sprawdz_id_wlasciciela(10));

}

	//pokrywa metody edytuj, podaj_nazwe, podaj_ilosc, podaj_cene, podaj_opis
TEST(TestPrzedmiotu, Test_edytuj) {

	PrzedmiotTestowy.edytuj("Nowy Mercedes", 2, 50000, "Dobra jakosc prosto z Niemiec");
	EXPECT_EQ("Nowy Mercedes", PrzedmiotTestowy.podaj_nazwe());
	EXPECT_EQ(2, PrzedmiotTestowy.podaj_ilosc());
	EXPECT_EQ(50000, PrzedmiotTestowy.podaj_cene());
	EXPECT_EQ("Dobra jakosc prosto z Niemiec", PrzedmiotTestowy.podaj_opis());

}

	//pokrywa metody podaj_adres_nastepnego_przedmiotu i ustaw_nastepny_przedmiot
TEST(TestPrzedmiotu, Test_podaj_adres_nastepnego_przedmiotu) {

	Przedmiot p1("p1", 22, 10, 22, "opis1");
	Przedmiot p2("p2", 23, 13, 23, "opis2");
	Przedmiot p3("p3", 42, 40, 42, "opis3");

	p1.ustaw_nastepny_przedmiot(&p2);
	p2.ustaw_nastepny_przedmiot(&p3);

	EXPECT_EQ(p1.podaj_adres_nastepnego_przedmiotu(), &p2);
	EXPECT_EQ(p2.podaj_adres_nastepnego_przedmiotu(), &p3);
	EXPECT_EQ((p1.podaj_adres_nastepnego_przedmiotu())->podaj_adres_nastepnego_przedmiotu(), &p3);



}

		

			//testy klasy Licytacja
				//metody nie pokryte - wygrana, poniewaz nie jest zaimplementowana

Licytacja LicytacjaTestowa("Tona wegla", 10, 10, 500, "10 ton wegla, kto pierwszy ten lepszy", 24);

	//pokrywa metody dodaj_oferte, dodaj_historie i zwroc_historie_licytacji
TEST(TestLicytacji, Test_dodaj_oferte)
{
	LicytacjaTestowa.dodaj_oferte(510, "Zbigniew M.");
	HistoriaLicytacji* historiaTestowa = LicytacjaTestowa.zwroc_historie_licytacji();
	EXPECT_EQ(historiaTestowa->cena, 510);
	EXPECT_EQ(historiaTestowa->nazwaUczestkina, "Zbigniew M.");

	LicytacjaTestowa.dodaj_oferte(512, "Stanislaw M.");
	historiaTestowa = LicytacjaTestowa.zwroc_historie_licytacji();
	EXPECT_EQ(historiaTestowa->cena, 512);
	EXPECT_EQ(historiaTestowa->nazwaUczestkina, "Stanislaw M.");

	LicytacjaTestowa.dodaj_oferte(555, "Wilhelm C.");
	historiaTestowa = LicytacjaTestowa.zwroc_historie_licytacji();
	EXPECT_EQ(historiaTestowa->cena, 555);
	EXPECT_EQ(historiaTestowa->nazwaUczestkina, "Wilhelm C.");

	LicytacjaTestowa.dodaj_oferte(420, "<><><><><>");
	historiaTestowa = LicytacjaTestowa.zwroc_historie_licytacji();
	EXPECT_EQ(historiaTestowa->cena, 555);
	EXPECT_EQ(historiaTestowa->nazwaUczestkina, "Wilhelm C.");

	LicytacjaTestowa.dodaj_oferte(20, "Jaroslaw K.");
	historiaTestowa = LicytacjaTestowa.zwroc_historie_licytacji();
	EXPECT_EQ(historiaTestowa->cena, 555);
	EXPECT_EQ(historiaTestowa->nazwaUczestkina, "Wilhelm C.");

	LicytacjaTestowa.dodaj_oferte(600, "Jan Kowalski");
	historiaTestowa = LicytacjaTestowa.zwroc_historie_licytacji();
	EXPECT_EQ(historiaTestowa->cena, 600);
	EXPECT_EQ(historiaTestowa->nazwaUczestkina, "Jan Kowalski");

	HistoriaLicytacji historia1;
	historia1.cena = 700;
	historia1.nazwaUczestkina = "123456789";
	historia1.next = NULL;
	LicytacjaTestowa.dodaj_historie(&historia1);
	historiaTestowa = LicytacjaTestowa.zwroc_historie_licytacji();
	EXPECT_EQ(historiaTestowa->cena, 700);
	EXPECT_EQ(historiaTestowa->nazwaUczestkina, "123456789");

	HistoriaLicytacji historia2;
	historia2.cena = 20;
	historia2.nazwaUczestkina = "abcdefghijk";
	historia2.next = NULL;
	LicytacjaTestowa.dodaj_historie(&historia2);
	historiaTestowa = LicytacjaTestowa.zwroc_historie_licytacji();
	EXPECT_EQ(historiaTestowa->cena, 20);
	EXPECT_EQ(historiaTestowa->nazwaUczestkina, "abcdefghijk");

}

	//pokrywa metody ustaw_nastepna_licytacje oraz podaj_adres_nastepnej_licytacji
TEST(TestLicytacji, Test_ustaw_nastepna_licytacje)
{
	Licytacja L1("l1", 10, 10, 10, "l1", 10);
	Licytacja L2("l2", 150, 150, 150, "l2", 150);

	LicytacjaTestowa.ustaw_nastepna_licytacje(&L1);
	L1.ustaw_nastepna_licytacje(&L2);

	EXPECT_EQ(LicytacjaTestowa.podaj_adres_nastepnej_licytacji(), &L1);
	EXPECT_EQ(L1.podaj_adres_nastepnej_licytacji(), &L2);
	EXPECT_EQ(LicytacjaTestowa.podaj_adres_nastepnej_licytacji()->podaj_adres_nastepnej_licytacji(), &L2);

}



			//test klasy Bazarek

Bazarek Sklep;
	//pokrywa metody dodaj_przedmiot, podaj_adres_nastepnego_przedmiotu i szukaj_przedmiotow_po_nazwie

TEST(TestBazarku, Test_dodaj_przedmiot)
{
	Przedmiot p1("pp0", 1, 12, 23, "p1");
	Przedmiot p2("pp0", 2, 22, 23, "p2");
	Przedmiot p3("p3", 1, 12, 63, "p3");
	Przedmiot p4("p4", 5, 16, 23, "p4");
	Przedmiot p5("p5", 10, 12, 23, "p5");

	Sklep.dodaj_przedmiot(&p1);
	Sklep.dodaj_przedmiot(&p2);
	Sklep.dodaj_przedmiot(&p3);
	Sklep.dodaj_przedmiot(&p4);
	Sklep.dodaj_przedmiot(&p5);

	EXPECT_EQ(p1.podaj_adres_nastepnego_przedmiotu(), &p2);
	EXPECT_EQ(p2.podaj_adres_nastepnego_przedmiotu(), &p3);
	EXPECT_EQ(p3.podaj_adres_nastepnego_przedmiotu(), &p4);
	EXPECT_EQ(p4.podaj_adres_nastepnego_przedmiotu(), &p5);
	EXPECT_EQ(p5.podaj_adres_nastepnego_przedmiotu(), nullptr);


	std::vector<unsigned int>* wektorId = Sklep.wyszukaj_przedmioty_osoby(12);
	EXPECT_EQ(wektorId->size(), 3);
	wektorId = Sklep.wyszukaj_przedmioty_osoby(16);
	EXPECT_EQ(wektorId->size(), 1);
	wektorId = Sklep.wyszukaj_przedmioty_osoby(77);
	EXPECT_EQ(wektorId->size(), 0);

	wektorId = Sklep.szukaj_przedmiotow_po_nazwie("pp0");
	EXPECT_EQ(wektorId->size(), 2);
	wektorId = Sklep.szukaj_przedmiotow_po_nazwie("p3");
	EXPECT_EQ(wektorId->size(), 1);

}

	//pokrywa metody dodaj_licytacje, podaj_adres_nastepnej_licytacji i szukaj_licytacji_po_nazwie 
TEST(TestBazarku, Test_dodaj_licytacje)
{
	Licytacja p1("pp0", 1, 12, 23, "p1", 24);
	Licytacja p2("pp0", 2, 22, 23, "p2", 24);
	Licytacja p3("p3", 1, 12, 63, "p3", 48);
	Licytacja p4("p4", 5, 16, 23, "p4", 48);
	Licytacja p5("p5", 10, 12, 23, "p5", 72);

	Sklep.dodaj_licytacje(&p1);
	Sklep.dodaj_licytacje(&p2);
	Sklep.dodaj_licytacje(&p3);
	Sklep.dodaj_licytacje(&p4);
	Sklep.dodaj_licytacje(&p5);

	EXPECT_EQ(p1.podaj_adres_nastepnej_licytacji(), &p2);
	EXPECT_EQ(p2.podaj_adres_nastepnej_licytacji(), &p3);
	EXPECT_EQ(p3.podaj_adres_nastepnej_licytacji(), &p4);
	EXPECT_EQ(p4.podaj_adres_nastepnej_licytacji(), &p5);
	EXPECT_EQ(p5.podaj_adres_nastepnej_licytacji(), nullptr);


	std::vector<unsigned int>* wektorId = Sklep.wyszukaj_licytacje_osoby(12);
	EXPECT_EQ(wektorId->size(), 3);
	wektorId = Sklep.wyszukaj_licytacje_osoby(16);
	EXPECT_EQ(wektorId->size(), 1);
	wektorId = Sklep.wyszukaj_licytacje_osoby(77);
	EXPECT_EQ(wektorId->size(), 0);

	wektorId = Sklep.szukaj_licytacji_po_nazwie("pp0");
	EXPECT_EQ(wektorId->size(), 2);
	wektorId = Sklep.szukaj_licytacji_po_nazwie("p3");
	EXPECT_EQ(wektorId->size(), 1);

}



			//test klasy Osoba

Osoba osobaTestowa;

	//test pokrywa metody sprawdz_dane, edytuj_email, edytuj_haslo, edytuj_dane i podaj_email
TEST(TestOsoby, Test_sprawdz_dane)
{
	EXPECT_TRUE(osobaTestowa.sprawdz_dane("brak_danych", "brak_danych"));
	osobaTestowa.edytuj_dane("Tynkaz Glazura", "123");
	EXPECT_TRUE(osobaTestowa.sprawdz_dane("Tynkaz Glazura", "123"));
	osobaTestowa.edytuj_email("Grazyna Zarko");
	osobaTestowa.edytuj_haslo("abc");
	EXPECT_TRUE(osobaTestowa.sprawdz_dane("Grazyna Zarko", "abc"));

	EXPECT_EQ(osobaTestowa.podaj_email(), "Grazyna Zarko");

}

	

			//test klasy Klient

Klient klientTestowy("Buczyslaw", nullptr, "buczek@agh.edu.pl", "123");

	//test pokrywa metody zwroc_koszyk, dodaj_do_koszyka, oproznij_koszyk
TEST(TestKlienta, Test_dodaj_do_koszyka)
{
	Przedmiot arbuzy("Arbuzy", 15, 33, 3, "Pyszne tropikalne owoce");

	std::vector<unsigned int>* wektorId = klientTestowy.zwroc_koszyk();
	EXPECT_EQ(wektorId->size(), 0);

	klientTestowy.dodaj_do_koszyka(arbuzy.podaj_id(), 5);
	wektorId = klientTestowy.zwroc_koszyk();
	EXPECT_EQ(wektorId->size(), 5);

	klientTestowy.oproznij_koszyk();
	wektorId = klientTestowy.zwroc_koszyk();
	EXPECT_EQ(wektorId->size(), 0);

}

	//test pokrywa metody ustaw_wskaznik_next_klienta, podaj_wskaznik_next_klienta, ustaw_nazwe_klienta i podaj_nazwe_klienta
TEST(TestKlienta, Test_podaj_nazwe_klienta)
{
	Klient k1("k1", nullptr, "k1", "123");
	Klient k2("k2", nullptr, "k2", "333");

	klientTestowy.ustaw_wskaznik_next_klienta(&k1);
	k1.ustaw_wskaznik_next_klienta(&k2);

	EXPECT_EQ(klientTestowy.podaj_wskaznik_next_klienta(), &k1);
	EXPECT_EQ(k1.podaj_wskaznik_next_klienta(), &k2);
	EXPECT_EQ(k2.podaj_wskaznik_next_klienta(), nullptr);

	klientTestowy.ustaw_nazwe_klienta("Grzmislaw");
	EXPECT_EQ(klientTestowy.podaj_nazwe_klienta(), "Grzmislaw");
}

