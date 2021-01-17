//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_rejestracja.h"
#include "ekran_startowy.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForma_rejestracja *Forma_rejestracja;
//---------------------------------------------------------------------------
__fastcall TForma_rejestracja::TForma_rejestracja(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForma_rejestracja::Btn_co_to_loginClick(TObject *Sender)
{
    Text_Btn_co_to_login->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForma_rejestracja::Btn_co_to_emailClick(TObject *Sender)
{
    Text_Btn_co_to_email->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForma_rejestracja::Btn_co_to_hasloClick(TObject *Sender)
{
    Text_Btn_co_to_haslo->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForma_rejestracja::Btn_powrotClick(TObject *Sender)
{
	 CloseModal();
}
//---------------------------------------------------------------------------
void __fastcall TForma_rejestracja::FormClose(TObject *Sender, TCloseAction &Action)

{
	Forma_ekran_startowy->Visible = true;
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TForma_rejestracja::ListBoxItem_KlientClick(TObject *Sender)
{
	CheckBox_KF->IsChecked = true;
	ListBoxItem_Klient->IsChecked = true;
	ListBoxItem_Firma->IsChecked = false;
	Text_Btn_co_to_login->Text = "Nazwa, pod kt�r� widz� ci� inni u�ytkownicy";
}
//---------------------------------------------------------------------------


void __fastcall TForma_rejestracja::ListBoxItem_FirmaClick(TObject *Sender)
{
	CheckBox_KF->IsChecked = true;
	ListBoxItem_Klient->IsChecked = false;
	ListBoxItem_Firma->IsChecked = true;
	Text_Btn_co_to_login->Text = "Obowiazujaca na terenie Polski nazwa firmy";
}
//---------------------------------------------------------------------------

void TForma_rejestracja::rejestracja_klient()
{
	//Klient_rejestracja = new Klient;
	//Klient_rejestracja->edytuj_dane(AnsiString(Edit_email->Text).c_str(),AnsiString(Edit_haslo->Text).c_str());
	//Klient_rejestracja->ustaw_nazwe_klienta(AnsiString(Edit_login->Text).c_str());
	//doda� do listy klient�w
}

void TForma_rejestracja::rejestracja_firma()
{
	//Firma_rejestracja = new Firma;
	//Firma_rejestracja->edytuj_dane(AnsiString(Edit_email->Text).c_str(),AnsiString(Edit_haslo->Text).c_str());
	//Firma_rejestracja->ustaw_nazwe_firmy(AnsiString(Edit_login->Text).c_str());
	//doda� do listy firm
}

void __fastcall TForma_rejestracja::Btn_rejestracjaClick(TObject *Sender)
{
	//niewybrany rodzaj
	if(CheckBox_KF->IsChecked == false)
	{
		Text_blad->Text = "brak zaznaczonego rodzaju konta";
	}
	//co� jest puste
	else if(CheckBox_login->IsChecked == false)
	{
		Text_blad->Text = "brak loginu";
	}
	//co� jest puste
	else if (CheckBox_email->IsChecked == false)
	{
		Text_blad->Text = "brak emaila";
	}
	else if (/*je�li email ju� by�*/false)
	{

	}
	//co� jest puste
	else if (CheckBox_haslo->IsChecked == false)
	{
		Text_blad->Text = "brak hasla";
	}
	//co� jest puste
	else if (CheckBox_phaslo->IsChecked == false)
	{
		Text_blad->Text = "potwierdz haslo powtarzajac je";
	}
	//je�li to klient
	else if(ListBoxItem_Klient->IsChecked == true)
	{
		rejestracja_klient();
	}
	//je�li to firma
	else if(ListBoxItem_Firma->IsChecked == true)
	{
		rejestracja_firma();
	}


}
//---------------------------------------------------------------------------

