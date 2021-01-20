//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_startowy.h"
#include "zapomniane_haslo.h"
#include "ekran_ebazarek.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

TForma_zapomniane_haslo *Forma_zapomniane_haslo;
//---------------------------------------------------------------------------
__fastcall TForma_zapomniane_haslo::TForma_zapomniane_haslo(TComponent* Owner)
	: TForm(Owner)
{
	this->k_f = 0;
}
//---------------------------------------------------------------------------


void __fastcall TForma_zapomniane_haslo::Btn_wyslij_wiadomoscClick(TObject *Sender)
{
	if(Forma_ekran_bazarek->ListaF->wyszukaj_firme(AnsiString(Edit_email->Text).c_str()) != NULL)
	{
		this->k_f = 1;
	}
	else if(Forma_ekran_bazarek->ListaK->wyszukaj_klienta(AnsiString(Edit_email->Text).c_str()) != NULL)
	{
		this->k_f = 2;
    }

	if(CheckBox_email->IsChecked == false)
	{
		Text_blad1->Visible = true;
		Text_blad1->Text = "Brak napisanego emaila";
	}
	else if (k_f != 1 && k_f != 2)
	{
		Text_blad1->Visible = true;
		Text_blad1->Text = "Brak konta pod podanym emailem";
	}
	else
	{
		Text_blad1->Visible = false;

		UnicodeString wiadomosc = "Tu by siê wysy³a³a wiadomoœæ na maila. Kod: " + kod;
		ShowMessage(wiadomosc);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForma_zapomniane_haslo::Btn_zmien_hasloClick(TObject *Sender)
{
	Klient* pomK;
	Firma* pomF;

	if(CheckBox_kod->IsChecked == false)
	{
		Text_blad2->Visible = true;
		Text_blad2->Text = "Brak kodu";
	}
	else if(Edit_kod->Text != kod)
	{
		Text_blad2->Visible = true;
		Text_blad2->Text = "Bledny kod";
	}
	else if(CheckBox_nhaslo->IsChecked == false)
	{
		Text_blad2->Visible = true;
		Text_blad2->Text = "Brak napisania nowego hasla";
	}
	else if(CheckBox_pnhaslo->IsChecked == false)
	{
		Text_blad2->Visible = true;
		Text_blad2->Text = "Brak ponownego napisania nowego hasla";
	}
	else if(CheckBox_email->IsChecked == false)
	{
		Text_blad2->Visible = true;
		Text_blad2->Text = "Do zmiany hasla potrzebny jest email";
	}
	else
	{
		switch(k_f)
		{
			case 1:
				Text_blad2->Visible = false;
				pomK = Forma_ekran_bazarek->ListaK->wyszukaj_klienta(AnsiString(Edit_email->Text).c_str());
				pomK->edytuj_haslo(AnsiString(Edit_nhaslo->Text).c_str());
				break;
			case 2:
				Text_blad2->Visible = false;
				pomF = Forma_ekran_bazarek->ListaF->wyszukaj_firme(AnsiString(Edit_email->Text).c_str());
				pomF->edytuj_haslo(AnsiString(Edit_nhaslo->Text).c_str());
				break;
			default:
				Text_blad2->Visible = true;
				Text_blad2->Text = "Nieoczekiwany blad";
				break;
		}
		//zmiana has³a do konta o podanym danego emaila
	}
}
//---------------------------------------------------------------------------



void __fastcall TForma_zapomniane_haslo::FormClose(TObject *Sender, TCloseAction &Action)
{
	this->k_f = 0;
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
	std::string kodzik;   //dzia³anie na stringu
	for (int i = 0; i < 4; i++)
	{
		number = rand()%62;
		if(number <26)
		{
			kodzik[i] = 'A' + number;
		}
		else if(number >= 26 && number < 52)
		{
			kodzik[i] = 'a' + number - 26;
		}
		else
		{
			kodzik[i] = '0' + number - 52;
		}
	}
	kod = kodzik.c_str();
}





void __fastcall TForma_zapomniane_haslo::Edit_emailChange(TObject *Sender)
{
    wygeneruj_kod();
	if(Edit_email->Text != "")
	{
		CheckBox_email->IsChecked = true;
	}
	else
	{
		CheckBox_email->IsChecked = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForma_zapomniane_haslo::Edit_kodChange(TObject *Sender)
{
	if(Edit_kod->Text != "")
	{
		CheckBox_kod->IsChecked = true;
	}
	else
	{
		CheckBox_kod->IsChecked = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForma_zapomniane_haslo::Edit_nhasloChange(TObject *Sender)
{
	if(Edit_nhaslo->Text != "")
	{
		CheckBox_nhaslo->IsChecked = true;

		if (Edit_pnhaslo->Text != Edit_nhaslo->Text)
		{
			CheckBox_pnhaslo->IsChecked = false;
		}
	}
	else
	{
		CheckBox_nhaslo->IsChecked = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForma_zapomniane_haslo::Edit_pnhasloChange(TObject *Sender)
{
	if(Edit_pnhaslo->Text != "" && Edit_pnhaslo->Text == Edit_nhaslo->Text)
	{
		CheckBox_pnhaslo->IsChecked = true;
	}
	else
	{
		CheckBox_pnhaslo->IsChecked = false;
	}
}
//---------------------------------------------------------------------------

