//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_startowy.h"
#include "zapomniane_haslo.h"
#include "ekran_rejestracja.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

TForma_ekran_startowy * Forma_ekran_startowy;
TADOConnection * ADOConnection1;
bool bez_konta = false;

//---------------------------------------------------------------------------
__fastcall TForma_ekran_startowy::TForma_ekran_startowy(TComponent* Owner, TADOConnection *a_ADOConnection)
	: TForm(Owner)
{
   ADOConnection1 = a_ADOConnection;
}
//---------------------------------------------------------------------------

void __fastcall TForma_ekran_startowy::Btn_logowanieClick(TObject *Sender)
{
	bool blad = 0;
	if(Edit_email->Text == "")
	{
		Text_blad->Visible = true;
		Text_blad->Text = "Brak napisanego emaila";
		blad = 1;
	}
	else if(Edit_haslo->Text == "")
	{
		Text_blad->Visible = true;
		Text_blad->Text = "Brak napisanego has³a";
		blad = 1;
	}
	else if(ListBoxItem_Klient->IsChecked == false && ListBoxItem_Firma->IsChecked == false)
	{
		Text_blad->Visible = true;
		Text_blad->Text = "Brak wybranego rodzaju konta";
		blad = 1;
	}
	else if (CheckBox_robot->IsChecked == false)
	{
		Text_blad->Visible = true;
		Text_blad->Text = "Jestes robotem";
		blad = 1;
	}
	else
	{
		Text_blad->Visible = false;
        blad = 0;
	}

	if(blad == 0)
	{
	TADOQuery * Query = new TADOQuery(NULL);
	Query -> Connection = ADOConnection1;
	Query -> SQL -> Clear();
	Query -> SQL -> Text = "select trim(login) as login, trim(haslo) as haslo, email, id, typ from dbo.uzytkownicy where email = trim('"+Edit_email->Text+"')";

	Query -> Open();

	if(Query -> FieldByName("haslo")->AsString == Edit_haslo->Text)
	{

		int typ = Query -> FieldByName("typ")->AsInteger;

		AnsiString login = Query -> FieldByName("login")->AsString;
		AnsiString haslo = Query -> FieldByName("haslo")->AsString;
		AnsiString email = Query -> FieldByName("email")->AsString;
		int 	   id    = Query -> FieldByName("id")->AsInteger;

		Forma_ekran_bazarek->zmien_zalogowane(typ);

        if(typ == 1) Forma_ekran_bazarek -> MojKlient = new Klient(login.c_str(), NULL, email.c_str(), haslo.c_str(), id);
		else if (typ == 2) Forma_ekran_bazarek -> MojKlient = new Klient(login.c_str(), NULL, email.c_str(), haslo.c_str(), id);

		delete Query;

		bez_konta = true;
		ModalResult = 1;
	}else
	{
		ShowMessage("B³êdne dane");
        delete Query;
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
	}
}
//---------------------------------------------------------------------------


void __fastcall TForma_ekran_startowy::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (!bez_konta) {
		Application -> Terminate();
	}else
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForma_ekran_startowy::Btn_rejestracjaClick(TObject *Sender)
{
	Edit_haslo->Text = "";

	TForma_rejestracja * forma = new TForma_rejestracja (this, ADOConnection1);
	if (forma->ShowModal())
	{
		delete forma;
	}
	else
	{
		delete forma;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForma_ekran_startowy::Btn_przegladajClick(TObject *Sender)
{
	bez_konta = true;
    ModalResult = 1;
}
//---------------------------------------------------------------------------


void __fastcall TForma_ekran_startowy::ListBoxItem_KlientClick(TObject *Sender)
{
	ListBoxItem_Klient->IsChecked = true;
	ListBoxItem_Firma->IsChecked = false;
}
//---------------------------------------------------------------------------

void __fastcall TForma_ekran_startowy::ListBoxItem_FirmaClick(TObject *Sender)
{
	ListBoxItem_Klient->IsChecked = false;
	ListBoxItem_Firma->IsChecked = true;
}
//---------------------------------------------------------------------------

