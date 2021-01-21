//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_edycja_przedmiotu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForma_edycji *Forma_edycji;
//---------------------------------------------------------------------------
__fastcall TForma_edycji::TForma_edycji(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForma_edycji::Image_paskiClick(TObject *Sender)
{
     ModalResult = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForma_edycji::FormClose(TObject *Sender, TCloseAction &Action)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TForma_edycji::Btn_edytujClick(TObject *Sender)
{
	Edit_nazwa->ReadOnly = false;
	Edit_koszt->ReadOnly = false;
	Edit_liczba->ReadOnly = false;
    Memo_opis->ReadOnly = false;
}
//---------------------------------------------------------------------------
void __fastcall TForma_edycji::Edit_liczbaChange(TObject *Sender)
{
	char pomoc;
	for(int i = 0; Edit_liczba->Text[i] != '\0' ; i++)
	{
		pomoc = Edit_liczba->Text[i];
		if (pomoc < '0' || pomoc > '9')
		{
			Edit_liczba->Text[i] = '0';
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForma_edycji::Edit_kosztChange(TObject *Sender)
{
	char pomoc;
	for(int i = 0; Edit_koszt->Text[i] != '\0' ; i++)
	{
		pomoc = Edit_koszt->Text[i];
		if (pomoc < '0' || pomoc > '9')
		{
			Edit_koszt->Text[i] = '0';
		}
	}
}
//---------------------------------------------------------------------------

