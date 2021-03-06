//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_boczne_menu.h"
#include "ekran_startowy.h"
#include "ekran_rejestracja.h"
#include "ekran_panelu_admina.h"
#include "ekran_ebazarek.h"
#include "ekran_profilu.h"
#include "ekran_kaszyka.h"
#include "ekran_listy_przedmiotow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForma_boczne_menu *Forma_boczne_menu;
TADOConnection * ADOConnection2;
//---------------------------------------------------------------------------
__fastcall TForma_boczne_menu::TForma_boczne_menu(TComponent* Owner, TADOConnection* a_ADOConnection)
	: TForm(Owner)
{
	ADOConnection2= a_ADOConnection;
}
//---------------------------------------------------------------------------


void __fastcall TForma_boczne_menu::Btn_logowanieClick(TObject *Sender)
{
	TForma_ekran_startowy * form_ekran_startowy = new TForma_ekran_startowy(this, ADOConnection2);

	form_ekran_startowy->ShowModal();

	delete form_ekran_startowy;
}
//---------------------------------------------------------------------------

void __fastcall TForma_boczne_menu::Btn_rejestracjaClick(TObject *Sender)
{
	TForma_rejestracja * forma_rejestracja = new TForma_rejestracja(this, ADOConnection2);

	forma_rejestracja->ShowModal();

	delete forma_rejestracja;

}
//---------------------------------------------------------------------------

void __fastcall TForma_boczne_menu::Btn_adminClick(TObject *Sender)
{
	TForm_ekran_panelu_admina * forma_ekran_panelu_admina = new TForm_ekran_panelu_admina(this,ADOConnection2);

	forma_ekran_panelu_admina->ShowModal();

	delete forma_ekran_panelu_admina;
}
//---------------------------------------------------------------------------

void __fastcall TForma_boczne_menu::Btn_wylogujClick(TObject *Sender)
{
	Forma_ekran_bazarek->zmien_zalogowane(0);
	TForma_ekran_startowy * form_ekran_startowy = new TForma_ekran_startowy(this,ADOConnection2);

	form_ekran_startowy->ShowModal();

	delete form_ekran_startowy;
	ModalResult = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForma_boczne_menu::FormClose(TObject *Sender, TCloseAction &Action)

{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForma_boczne_menu::Image_domClick(TObject *Sender)
{
    //reset ekranu e-bazarka
	ModalResult = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForma_boczne_menu::FormActivate(TObject *Sender)
{
	switch (Forma_ekran_bazarek->zalogowanie())
	{
	case 1: //klient
		Btn_logowanie->Visible 		= false;
		Btn_rejestracja->Visible 	= false;
		Btn_profil->Visible 		= true;
		Btn_koszyk->Visible 		= true;
		Btn_przedmioty->Visible 	= true;
		Btn_admin->Visible          = false;
		Btn_wyloguj->Visible        = true;
		break;
	case 2: //firma
		Btn_logowanie->Visible 		= false;
		Btn_rejestracja->Visible 	= false;
		Btn_profil->Visible 		= true;
		Btn_koszyk->Visible 		= false;
		Btn_przedmioty->Visible 	= true;
		Btn_admin->Visible          = false;
		Btn_wyloguj->Visible        = true;
		break;
	case 3: //admin
		Btn_logowanie->Visible 		= false;
		Btn_rejestracja->Visible 	= false;
		Btn_profil->Visible 		= true;
		Btn_koszyk->Visible 		= false;
		Btn_przedmioty->Visible 	= false;
		Btn_admin->Visible          = true;
		Btn_wyloguj->Visible        = true;
		break;
	default: //brak zalogowania
		Btn_logowanie->Visible 		= true;
		Btn_rejestracja->Visible 	= true;
		Btn_profil->Visible 		= false;
		Btn_koszyk->Visible 		= false;
		Btn_przedmioty->Visible 	= false;
		Btn_admin->Visible          = false;
		Btn_wyloguj-> Visible       = false;
		break;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForma_boczne_menu::Image_arrowClick(TObject *Sender)
{
	ModalResult = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForma_boczne_menu::Btn_profilClick(TObject *Sender)
{
	TForm_profil *form_profil = new TForm_profil (this, ADOConnection2);
	form_profil->ShowModal();
	delete form_profil;
}
//---------------------------------------------------------------------------

void __fastcall TForma_boczne_menu::Btn_przedmiotyClick(TObject *Sender)
{

	TForma_listy_przedmiotow *form_listyp = new TForma_listy_przedmiotow (this, ADOConnection2);
	form_listyp->ShowModal();
	delete form_listyp;
}
//---------------------------------------------------------------------------

void __fastcall TForma_boczne_menu::Btn_koszykClick(TObject *Sender)
{

	TForma_koszyka *form_koszyk = new TForma_koszyka(this, ADOConnection2);
	form_koszyk->ShowModal();
	delete form_koszyk;
}
//---------------------------------------------------------------------------

