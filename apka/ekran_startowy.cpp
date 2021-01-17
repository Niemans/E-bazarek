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

void __fastcall TForma_ekran_startowy::Button1Click(TObject *Sender)
{
	if(Jasiu->Text == "")
	{
		Text3->Visible = true;
		Text3->Text = "Brak napisanego loginu";
	}
	else if(Jasiu2->Text == "")
	{
		Text3->Visible = true;
		Text3->Text = "Brak napisanego has�a";
	}
	else if (CheckBox1->IsChecked == false)
	{
		Text3->Visible = true;
		Text3->Text = "Jestes robotem";
	}
	else
	{

		Text3->Visible = false;
		if (/*email i has�o s� razem w bazie*/ true) {
			Jasiu->Text = "";
			Jasiu2->Text = "";
			CloseModal();
		}

	}
}
//---------------------------------------------------------------------------









//---------------------------------------------------------------------------

void __fastcall TForma_ekran_startowy::CheckBox1Click(TObject *Sender)
{

	  if(CheckBox1->IsChecked == true)
	  {
		CheckBox1->Text = "Czyli jestes jednak robotem?";
	  }
	  else
	  {
		CheckBox1->Text = "Dobrze, ze jednak nie.";
	  }

}
//---------------------------------------------------------------------------




void __fastcall TForma_ekran_startowy::Text5Click(TObject *Sender)
{
	Jasiu2->Text = "";
    srand(time(NULL)*time(NULL)-time(NULL));

	TForma_zapomniane_haslo * frm_zapomniane_haslo = new TForma_zapomniane_haslo(this);
	frm_zapomniane_haslo->ShowModal();
	delete frm_zapomniane_haslo;
}
//---------------------------------------------------------------------------


void __fastcall TForma_ekran_startowy::FormClose(TObject *Sender, TCloseAction &Action)
{
	Forma_ekran_bazarek->Visible = true;
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TForma_ekran_startowy::Button2Click(TObject *Sender)
{
	TForma_rejestracja * forma = new TForma_rejestracja (this);
	forma->ShowModal();
	delete forma;
}
//---------------------------------------------------------------------------

