//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_przedmiotu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm_ekran_przedmiotu *Form_ekran_przedmiotu;
//---------------------------------------------------------------------------
__fastcall TForm_ekran_przedmiotu::TForm_ekran_przedmiotu(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_ekran_przedmiotu::FormClose(TObject *Sender, TCloseAction &Action)

{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm_ekran_przedmiotu::Image_paskiDblClick(TObject *Sender)
{
    ModalResult = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_przedmiotu::FormActivate(TObject *Sender)
{
	/*
	jeœli to licytacja, to:
	Text_napis_kwota->Text = "aktualna cena";
	btn_kupTeraz->Visible = false;
	btn_doKoszyka->Visible = false;
	btn_licytuj->Visible = true;
	*/


}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_przedmiotu::btn_kupTerazClick(TObject *Sender)
{
    //po³¹czenie z zakupieniem
}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_przedmiotu::btn_doKoszykaClick(TObject *Sender)
{
    //dodanie do koszyka i wyjœcie
}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_przedmiotu::btn_licytujClick(TObject *Sender)
{
    //przejœcie do licytacji
}
//---------------------------------------------------------------------------

