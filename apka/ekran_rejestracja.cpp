﻿//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_rejestracja.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForma_rejestracja *Forma_rejestracja;
TADOConnection* ADOConnection;
//---------------------------------------------------------------------------
__fastcall TForma_rejestracja::TForma_rejestracja(TComponent* Owner, TADOConnection* a_ADOConnection)
	: TForm(Owner)
{
	ADOConnection = a_ADOConnection;
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
	ModalResult = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForma_rejestracja::FormClose(TObject *Sender, TCloseAction &Action)

{
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

void TForma_rejestracja::rejestracja(int typ)
{
	TADOQuery* Query = new TADOQuery(NULL);
	Query -> Connection = ADOConnection;

	Query -> SQL -> Clear();
	Query -> SQL -> Add("INSERT into dbo.uzytkownicy ");
	Query -> SQL -> Add("(login, haslo, email, typ) ");
	Query -> SQL -> Add("VALUES (trim(:login), trim(:haslo), trim(:email), :typ )");

	Query -> Parameters -> ParamByName("login") -> Value = Edit_login -> Text;
	Query -> Parameters -> ParamByName("haslo") -> Value = Edit_haslo -> Text;
	Query -> Parameters -> ParamByName("email") -> Value = Edit_email -> Text;
	Query -> Parameters -> ParamByName("typ") 	-> Value = typ;

    Query -> ExecSQL();

    delete Query;
}
//--------------------------------------------------------------------
bool TForma_rejestracja::sprawdzEmail()
{
	TADOQuery* Query = new TADOQuery(NULL);
    Query -> Connection = ADOConnection;

	Query -> SQL -> Clear();
	Query -> SQL -> Add("SELECT email from dbo.uzytkownicy where trim(email) = trim('"+Edit_email->Text+"');");

	Query -> Open();

	AnsiString x = Query -> FieldByName("email")->AsString;

	if (Query -> FieldByName("email")->AsString != "")
	{
		delete Query;
		return true;
	}else
	{
		delete Query;
		return false;
	}
}
//--------------------------------------------------------------------
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
	else if (sprawdzEmail())
	{
        Text_blad->Text = "podany email istenieje";
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
		rejestracja(1);
		ModalResult = 1;
	}
	//je�li to firma
	else if(ListBoxItem_Firma->IsChecked == true)
	{
		rejestracja(2);
		ModalResult = 1;
	}
}
//---------------------------------------------------------------------------



void __fastcall TForma_rejestracja::Edit_loginChange(TObject *Sender)
{
	if(Edit_login->Text != "")
	{
		CheckBox_login->IsChecked = true;
	}
	else
	{
		CheckBox_login->IsChecked = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForma_rejestracja::Edit_emailChange(TObject *Sender)
{
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

void __fastcall TForma_rejestracja::Edit_hasloChange(TObject *Sender)
{
	if(Edit_haslo->Text != "")
	{
		CheckBox_haslo->IsChecked = true;
		
		if (Edit_phaslo->Text != Edit_haslo->Text) 
		{
			CheckBox_phaslo->IsChecked = false;		
		}
	}
	else
	{
		CheckBox_haslo->IsChecked = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForma_rejestracja::Edit_phasloChange(TObject *Sender)
{
	if(Edit_phaslo->Text != "" && Edit_phaslo->Text == Edit_haslo->Text)
	{
		CheckBox_phaslo->IsChecked = true;
	}
	else
	{
		CheckBox_phaslo->IsChecked = false;
	}
}
//---------------------------------------------------------------------------


