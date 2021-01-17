//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_panelu_admina.h"
#include "../class_library/class_library.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm_ekran_panelu_admina *Form_ekran_panelu_admina;
//---------------------------------------------------------------------------
__fastcall TForm_ekran_panelu_admina::TForm_ekran_panelu_admina(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_ekran_panelu_admina::Btn_anulujClick(TObject *Sender)
{
	Edit_usun_przedmiot->Text = "";
	Edit_usun_uzytkownika->Text = "";
    Memo_komentarz->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm_ekran_panelu_admina::Btn_usunClick(TObject *Sender)
{


	if (Edit_usun_przedmiot->Text == "" && Edit_usun_uzytkownika->Text == "")
	{
		Text_blad->Text = "brak wpisanego ID";
	}

	//szukanie ID

	if(/*brak podaneo ID*/false)
	{
		Text_blad->Text = "brak takiego ID";
	}
	else if(Edit_usun_przedmiot->Text != "")
	{
	 //usuwanie przedmiotu
	}
	else if(Edit_usun_uzytkownika->Text != "")
	{
	 //usuwa użytkownika i jego przedmioty
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_panelu_admina::paskiClick(TObject *Sender)
{
    ModalResult = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_panelu_admina::FormClose(TObject *Sender, TCloseAction &Action)

{
    Close();
}
//---------------------------------------------------------------------------

