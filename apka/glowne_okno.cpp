//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "glowne_okno.h"
#include "ekran_startowy.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.LgXhdpiTb.fmx", _PLAT_ANDROID)
#pragma resource ("*.LgXhdpiPh.fmx", _PLAT_ANDROID)

TForma_glowne_okno *Forma_glowne_okno;
//---------------------------------------------------------------------------
__fastcall TForma_glowne_okno::TForma_glowne_okno(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForma_glowne_okno::FormClose(TObject *Sender, TCloseAction &Action)

{
    Jasiu1->Visible = false;
	Forma_ekran_startowy->Visible = true;
	Forma_glowne_okno->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForma_glowne_okno::lupaClick(TObject *Sender)
{
	if(Jasiu1->Visible == false)
		Jasiu1->Visible = true;


	if(Jasiu1->Text != "")
	{
		//szukanie przedmiotów z podanym ci¹giem znaków (bez znaczenia ich wielkoœæ!)
	}
}
//---------------------------------------------------------------------------
