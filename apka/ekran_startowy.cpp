//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_startowy.h"
#include "zapomniane_haslo.h"
#include "ekran_rejestracja.h"
#include "ekran_ebazarek.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

TForma_ekran_startowy * Forma_ekran_startowy;

//---------------------------------------------------------------------------
__fastcall TForma_ekran_startowy::TForma_ekran_startowy(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForma_ekran_startowy::Btn_logowanieClick(TObject *Sender)
{
	bool blad = 0;
	if(Edit_email->Text == "")
	{
		Text_blad->Visible = true;
		Text_blad->Text = "Brak napisanego emaila";
		blad = 1;
	}
	else if(Edit_haslo->Text == "")
	{
		Text_blad->Visible = true;
		Text_blad->Text = "Brak napisanego has�a";
		blad = 1;
	}
	else if(ListBoxItem_Klient->IsChecked == false && ListBoxItem_Firma->IsChecked == false)
	{
		Text_blad->Visible = true;
		Text_blad->Text = "Brak wybranego rodzaju konta";
		blad = 1;
	}
	else if (CheckBox_robot->IsChecked == false)
	{
		Text_blad->Visible = true;
		Text_blad->Text = "Jestes robotem";
		blad = 1;
	}
	else
	{
		Text_blad->Visible = false;
        blad = 0;
	}

	if((Edit_email->Text == "admin" && Edit_haslo->Text == "1234"))
	{
		Forma_ekran_bazarek->zmien_zalogowane(3);
		ModalResult = 1;
	}
	else if(blad == 0)
	{
		//trzeba zrobi� prawdziwe zalogowanie si� do czego�
		ModalResult = 0;
	}
}
//---------------------------------------------------------------------------









//---------------------------------------------------------------------------

void __fastcall TForma_ekran_startowy::CheckBox_robotClick(TObject *Sender)
{

	  if(CheckBox_robot->IsChecked == true)
	  {
		CheckBox_robot->Text = "Czyli jestes jednak robotem?";
	  }
	  else
	  {
		CheckBox_robot->Text = "Dobrze, ze jednak nie.";
	  }

}
//---------------------------------------------------------------------------




void __fastcall TForma_ekran_startowy::Text_kliknijClick(TObject *Sender)
{
	Edit_haslo->Text = "";
    srand(time(NULL)*time(NULL)-time(NULL));

	TForma_zapomniane_haslo * forma = new TForma_zapomniane_haslo(this);
		if (forma->ShowModal())
	{
		delete forma;
	}
	else
	{
		delete forma;
		Free();
	}
}
//---------------------------------------------------------------------------


void __fastcall TForma_ekran_startowy::FormClose(TObject *Sender, TCloseAction &Action)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TForma_ekran_startowy::Btn_rejestracjaClick(TObject *Sender)
{
	Edit_haslo->Text = "";

	TForma_rejestracja * forma = new TForma_rejestracja (this);
	if (forma->ShowModal())
	{
		delete forma;
	}
	else
	{
		delete forma;
		Free();
	}
}
//---------------------------------------------------------------------------


void __fastcall TForma_ekran_startowy::Btn_przegladajClick(TObject *Sender)
{
    ModalResult = 1;
}
//---------------------------------------------------------------------------


void __fastcall TForma_ekran_startowy::ListBoxItem_KlientClick(TObject *Sender)
{
	ListBoxItem_Klient->IsChecked = true;
	ListBoxItem_Firma->IsChecked = false;
}
//---------------------------------------------------------------------------

void __fastcall TForma_ekran_startowy::ListBoxItem_FirmaClick(TObject *Sender)
{
	ListBoxItem_Klient->IsChecked = false;
	ListBoxItem_Firma->IsChecked = true;
}
//---------------------------------------------------------------------------

