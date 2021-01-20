//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_profilu.h"
#include "ekran_ebazarek.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormActivate(TObject *Sender)
{
	if (Forma_ekran_bazarek->zalogowanie() == 1)
	{
		Edit_login->Text = (Forma_ekran_bazarek->MojKlient->podaj_nazwe_klienta()).c_str();
		Edit_email->Text = (Forma_ekran_bazarek->MojKlient->podaj_email()).c_str();
		//Edit_haslo->Text = (Forma_ekran_bazarek->MojKlient->podaj_haslo()).c_str();			   potrzebna funkcja
		Image_klient->Visible = true;
	}
	else if (Forma_ekran_bazarek->zalogowanie() == 2)
	{
		Edit_login->Text = (Forma_ekran_bazarek->MojaFirma->podaj_nazwe_firmy()).c_str();
		Edit_email->Text = (Forma_ekran_bazarek->MojaFirma->podaj_email()).c_str();
		//Edit_haslo->Text = (Forma_ekran_bazarek->MojaFirma->podaj_haslo()).c_str();                 potrzebna funkcja
		Image_firma->Visible = true;
	}
	else if (Forma_ekran_bazarek->zalogowanie() == 3)
	{
		Edit_login->Text = "admin";
		Edit_email->Text = "admin";
		Edit_haslo->Text = "1234";
		Image_admin->Visible = true;
		Btn_usun_konto->Visible = false;
		Btn_zmien_dane->Visible = false;
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image_okoClick(TObject *Sender)
{
	if(Edit_haslo->Password == true)
	{
		Edit_haslo->Password = false;
    }
	else
	{
		Edit_haslo->Password = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image_paskiClick(TObject *Sender)
{

	Edit_email->Enabled = false;
	Edit_login->Enabled = false;
	Edit_haslo->Enabled = false;
	Btn_usun_konto->Visible = true;
	Image_firma->Visible = false;
	Image_klient->Visible = false;
	Image_admin->Visible = false;
	Edit_haslo->Password = true;
	ModalResult = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_usun_kontoClick(TObject *Sender)
{
	if (Forma_ekran_bazarek->zalogowanie() == 1)
	{
		Forma_ekran_bazarek->ListaK->usun(Forma_ekran_bazarek->MojKlient->podaj_id());
	}
	else if (Forma_ekran_bazarek->zalogowanie() == 2)
	{
		Forma_ekran_bazarek->ListaF->usun(Forma_ekran_bazarek->MojaFirma->podaj_id());
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Btn_zmien_daneClick(TObject *Sender)
{
	Edit_email->Enabled = true;
	Edit_login->Enabled = true;
	Edit_haslo->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit_loginChange(TObject *Sender)
{

	if (Forma_ekran_bazarek->zalogowanie() == 1)
	{
		Forma_ekran_bazarek->MojKlient->ustaw_nazwe_klienta(AnsiString(Edit_login->Text).c_str());
	}
	else if (Forma_ekran_bazarek->zalogowanie() == 2)
	{
		Forma_ekran_bazarek->MojaFirma->ustaw_nazwe_firmy(AnsiString(Edit_login->Text).c_str());
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit_emailChange(TObject *Sender)
{
	if (Forma_ekran_bazarek->zalogowanie() == 1)
	{
		if(Forma_ekran_bazarek->ListaK->wyszukaj_klienta(AnsiString(Edit_email->Text).c_str()) == NULL)
		{
			Forma_ekran_bazarek->MojKlient->edytuj_dane(AnsiString(Edit_email->Text).c_str(),Forma_ekran_bazarek->MojKlient->podaj_haslo());
		}
	}
	else if (Forma_ekran_bazarek->zalogowanie() == 2)
	{
		if(Forma_ekran_bazarek->ListaF->wyszukaj_firme(AnsiString(Edit_email->Text).c_str()) == NULL)
		{
			Forma_ekran_bazarek->MojaFirma->edytuj_dane(AnsiString(Edit_email->Text).c_str(),Forma_ekran_bazarek->MojaFirma->podaj_haslo());
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit_hasloChange(TObject *Sender)
{
    if (Forma_ekran_bazarek->zalogowanie() == 1)
	{
		Forma_ekran_bazarek->MojKlient->edytuj_dane(Forma_ekran_bazarek->MojKlient->podaj_email(),AnsiString(Edit_login->Text).c_str());
	}
	else if (Forma_ekran_bazarek->zalogowanie() == 2)
	{
		Forma_ekran_bazarek->MojaFirma->edytuj_dane(Forma_ekran_bazarek->MojaFirma->podaj_email(),AnsiString(Edit_email->Text).c_str());
	}
}
//---------------------------------------------------------------------------
