//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_startowy.h"
#include "zapomniane_haslo.h"
#include "../class_library/class_library.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

TForma_zapomniane_haslo *Forma_zapomniane_haslo;
//---------------------------------------------------------------------------
__fastcall TForma_zapomniane_haslo::TForma_zapomniane_haslo(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForma_zapomniane_haslo::Btn_wyslij_wiadomoscClick(TObject *Sender)
{
	if(Edit_email->Text == "")
	{
		Text_blad1->Visible = true;
		Text_blad1->Text = "Brak napisanego emaila";
	}
	else if (/*brak maila w spisie emaili*/false)
	{
		Text_blad1->Visible = true;
		Text_blad1->Text = "Brak konta pod podanym emailem";
	}
	else
	{
		Text_blad1->Visible = false;
		wygeneruj_kod();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForma_zapomniane_haslo::Btn_zmien_hasloClick(TObject *Sender)
{
	if(Edit_kod->Text == "")
	{
		Text_blad2->Visible = true;
		Text_blad2->Text = "Brak kodu";
	}
	else if(Edit_kod->Text != kod)
	{
		Text_blad2->Visible = true;
		Text_blad2->Text = "Bledny kod";
	}
	else if(edit_nhaslo->Text == "")
	{
		Text_blad2->Visible = true;
		Text_blad2->Text = "Brak napisania nowego hasla";
	}
	else if(Edit_pnhaslo->Text == "")
	{
		Text_blad2->Visible = true;
		Text_blad2->Text = "Brak ponownego napisania nowego hasla";
	}
	else if(Edit_email->Text == "")
	{
		Text_blad2->Visible = true;
		Text_blad2->Text = "Do zmiany hasla potrzebny jest email";
	}
	else
	{
		Text_blad2->Visible = false;
		//zmiana has�a do konta o podanym danego emaila
	}
}
//---------------------------------------------------------------------------



void __fastcall TForma_zapomniane_haslo::FormClose(TObject *Sender, TCloseAction &Action)
{
	Forma_ekran_startowy->Visible = true;
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForma_zapomniane_haslo::Btn_powrotClick(TObject *Sender)
{
 ModalResult = 1;
}
//---------------------------------------------------------------------------

void TForma_zapomniane_haslo::wygeneruj_kod()
{
	short int number = 0; //chwilowe przechowanie danych
	char znak;            //znak na podstawie losowo wybranego numeru
	for (int i = 0; i < 4; i++)
	{
		number = rand()%62;
		if(number <26)
		{
			znak = 'A' + number;
		}
		else if(number >= 26 && number < 52)
		{
			znak = 'a' + znak - 26;
		}
		else
		{
			znak = '0' + znak - 52;
		}

		this->kod += znak;
	}
}


void __fastcall TForma_zapomniane_haslo::ListBoxItem_KlientClick(TObject *Sender)

{
	ListBoxItem_Firma->IsChecked = false;
	ListBoxItem_Klient->IsChecked = true;
}
//---------------------------------------------------------------------------

void __fastcall TForma_zapomniane_haslo::ListBoxItem_FirmaClick(TObject *Sender)
{
	ListBoxItem_Firma->IsChecked = true;
	ListBoxItem_Klient->IsChecked = false;
}
//---------------------------------------------------------------------------

