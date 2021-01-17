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
	if(Edit_login->Text == "")
	{
		Text_blad->Visible = true;
		Text_blad->Text = "Brak napisanego loginu";
	}
	else if(Edit_haslo->Text == "")
	{
		Text_blad->Visible = true;
		Text_blad->Text = "Brak napisanego has�a";
	}
	else if (CheckBox_robot->IsChecked == false)
	{
		Text_blad->Visible = true;
		Text_blad->Text = "Jestes robotem";
	}
	else
	{

		Text_blad->Visible = false;
        //trzeba zrobi� prawdziwe zalogowanie si� do czego�
		if (Edit_login->Text=="admin" && Edit_haslo->Text == "1234") {
			ModalResult = 1;
		}else
		{

			ModalResult = 0;
		}

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


