//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_boczne_menu.h"
#include "ekran_startowy.h"
#include "ekran_rejestracja.h"
#include "ekran_panelu_admina.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForma_boczne_menu *Forma_boczne_menu;
//---------------------------------------------------------------------------
__fastcall TForma_boczne_menu::TForma_boczne_menu(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForma_boczne_menu::Btn_logowanieClick(TObject *Sender)
{
	TForma_ekran_startowy * form_ekran_startowy = new TForma_ekran_startowy(this);
	if (form_ekran_startowy->ShowModal())
	{
		delete form_ekran_startowy;
	}
	else
	{
		delete form_ekran_startowy;
		Free();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForma_boczne_menu::Btn_rejestracjaClick(TObject *Sender)
{
	TForma_rejestracja * forma_rejestracja = new TForma_rejestracja(this);
	if (forma_rejestracja->ShowModal())
	{
		delete forma_rejestracja;
	}
	else
	{
		delete forma_rejestracja;
		Free();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForma_boczne_menu::Btn_adminClick(TObject *Sender)
{
	TForm_ekran_panelu_admina * forma_ekran_panelu_admina = new TForm_ekran_panelu_admina(this);
	if (forma_ekran_panelu_admina->ShowModal())
	{
		delete forma_ekran_panelu_admina;
	}
	else
	{
		delete forma_ekran_panelu_admina;
		Free();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForma_boczne_menu::Btn_wylogujClick(TObject *Sender)
{
	//wylogowywanie potrzebne!!!
    TForma_ekran_startowy * form_ekran_startowy = new TForma_ekran_startowy(this);
	if (form_ekran_startowy->ShowModal())
	{
		delete form_ekran_startowy;
		ModalResult = 1;
	}
	else
	{
		delete form_ekran_startowy;
		Free();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForma_boczne_menu::FormClose(TObject *Sender, TCloseAction &Action)

{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForma_boczne_menu::Image_domClick(TObject *Sender)
{
    ModalResult = 1;
}
//---------------------------------------------------------------------------

