//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_profilu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm_profil *Form_profil;
TADOConnection * ADOConnection4;
UnicodeString email_stary;

//---------------------------------------------------------------------------
__fastcall TForm_profil::TForm_profil(TComponent* Owner, TADOConnection * a_ADOConnection)
	: TForm(Owner)
{
   ADOConnection4 = a_ADOConnection;
}
//---------------------------------------------------------------------------
void __fastcall TForm_profil::FormActivate(TObject *Sender)
{
	if (Forma_ekran_bazarek->zalogowanie() == 1)
	{
		Edit_login->Text = (Forma_ekran_bazarek->MojKlient->podaj_nazwe_klienta()).c_str();
		Edit_email->Text = (Forma_ekran_bazarek->MojKlient->podaj_email()).c_str();   //wywala b��d!
		email_stary		 = (Forma_ekran_bazarek->MojKlient->podaj_email()).c_str();
		Edit_haslo->Text = (Forma_ekran_bazarek->MojKlient->podaj_haslo()).c_str();
		Image_klient->Visible = true;
	}
	else if (Forma_ekran_bazarek->zalogowanie() == 2)
	{
		Edit_login->Text = (Forma_ekran_bazarek->MojaFirma->podaj_nazwe_firmy()).c_str();
		Edit_email->Text = (Forma_ekran_bazarek->MojaFirma->podaj_email()).c_str();   //wywala b��d!
		email_stary		 = (Forma_ekran_bazarek->MojKlient->podaj_email()).c_str();
		Edit_haslo->Text = (Forma_ekran_bazarek->MojaFirma->podaj_haslo()).c_str();
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
void __fastcall TForm_profil::Image_okoClick(TObject *Sender)
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

void __fastcall TForm_profil::Image_paskiClick(TObject *Sender)
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

void __fastcall TForm_profil::Btn_usun_kontoClick(TObject *Sender) //usu�
{
	if (Forma_ekran_bazarek->zalogowanie() == 1)
	{
		//Forma_ekran_bazarek->ListaK->usun(Forma_ekran_bazarek->MojKlient->podaj_id());
	}
	else if (Forma_ekran_bazarek->zalogowanie() == 2)
	{
	   //Forma_ekran_bazarek->ListaF->usun(Forma_ekran_bazarek->MojaFirma->podaj_id());
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm_profil::Btn_zmien_daneClick(TObject *Sender)
{
	Text_informacja-> Visible = true;
	btn_potwierdz  -> Visible = true;
	Edit_email	   ->ReadOnly = false;
	Edit_login	   ->ReadOnly = false;
	Edit_haslo	   ->ReadOnly = false;
}
//---------------------------------------------------------------------------    // zapis tego do bazy danych!!!!
    // zapis tego do bazy danych!!!!
   // zapis tego do bazy danych!!!!


void __fastcall TForm_profil::btn_potwierdzClick(TObject *Sender)
{
	TADOQuery * Query = new TADOQuery(NULL);
	Query -> Connection = ADOConnection4;

	Query -> SQL -> Clear();
	Query -> SQL -> Add("UPDATE uzytkownicy ");
	Query -> SQL -> Add("SET login=trim(:login), haslo=trim(:haslo), email=trim(:email)");
	Query -> SQL -> Add("WHERE email = trim(:email_stary)");

	Query -> Parameters -> ParamByName("email_stary") -> Value = email_stary;

	Query -> Parameters -> ParamByName("login") -> Value = Edit_login -> Text;
	Query -> Parameters -> ParamByName("email") -> Value = Edit_email -> Text;
	Query -> Parameters -> ParamByName("haslo") -> Value = Edit_haslo -> Text;

	Query -> ExecSQL();

	delete Query;

    ShowMessage("Dane zosta�y zmienione");
}
//---------------------------------------------------------------------------

