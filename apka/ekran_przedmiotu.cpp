//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_przedmiotu.h"
#include "ekran_ebazarek.h"
#include "ekran_licytacji.h"
#include "ekran_zakupu.h"
#include "ekran_kaszyka.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm_ekran_przedmiotu *Form_ekran_przedmiotu;
TADOConnection * ADOConnection3;
float koszt_baza;
int licytacja;
//---------------------------------------------------------------------------
__fastcall TForm_ekran_przedmiotu::TForm_ekran_przedmiotu(TComponent* Owner, TADOConnection * a_ADOConnection, int a_id)
	: TForm(Owner)
{
	id 			   = a_id;
	ADOConnection3 = a_ADOConnection;

	TADOQuery * Query = new TADOQuery(NULL);
	Query -> Connection = ADOConnection3;

	Query -> SQL -> Clear();
	Query -> SQL -> Add("SELECT trim(nazwa) as nazwa ,trim(opis) as opis,kwota,id,id_parent,ilosc,licytacja from dbo.dane ");
	Query -> SQL -> Add("where id = :id");

	Query -> Parameters -> ParamByName("id") -> Value = id;

	Query -> Open();

	licytacja 		   = Query -> FieldByName("licytacja") -> Value;

	koszt_baza		   = Query -> FieldByName("kwota") -> AsFloat * Edit_kupowana_liczba->Text.ToInt();

	Text_nazwa -> Text = Query -> FieldByName("nazwa") -> AsString;
    Text_ilosc -> Text = Query -> FieldByName("ilosc") -> AsInteger;
	Text_opis  -> Text = Query -> FieldByName("opis")  -> AsString;
    Edit_koszt -> Text = koszt_baza;

	Query -> Close();

	delete Query;
}
//---------------------------------------------------------------------------
void __fastcall TForm_ekran_przedmiotu::FormClose(TObject *Sender, TCloseAction &Action)

{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_przedmiotu::Image_paskiClick(TObject *Sender)
{
     ModalResult = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_przedmiotu::Btn_licytujClick(TObject *Sender)
{
	TForma_licytacji *form_licytacja = new TForma_licytacji(this);
	form_licytacja->ShowModal();
	delete form_licytacja;
}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_przedmiotu::FormActivate(TObject *Sender)
{
	//Je�li to licytacja, to:
	if (licytacja) {
		Btn_licytuj->Visible = true;
		Btn_kupTeraz->Visible = false;
		Btn_doKoszyka->Visible = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_przedmiotu::Btn_kupTerazClick(TObject *Sender)
{
	TForma_zakupu *form_zakupu;
	if(Edit_kupowana_liczba->Text == "")
	{

	}
	else
	{
		form_zakupu= new TForma_zakupu(this);
		form_zakupu ->ShowModal();
		delete form_zakupu;
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_przedmiotu::Edit_kupowana_liczbaChange(TObject *Sender)
{
	if (Edit_kupowana_liczba -> Text.ToInt() > Text_ilosc -> Text.ToInt())
        ShowMessage("Nie ma tylu sztuk");
	else
	{
		if(Edit_koszt -> Text != NULL)
		Edit_koszt -> Text = (koszt_baza) * (Edit_kupowana_liczba -> Text.ToInt());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_przedmiotu::Btn_doKoszykaClick(TObject *Sender)
{
	//przedmiot dodawany do koszyka!!!

    Forma_ekran_bazarek -> MojKlient -> dodaj_do_koszyka(id,1);

//	TForma_koszyka *form_koszyka = new TForma_koszyka(this);
//	form_koszyka->ShowModal();
//    delete form_koszyka;

}
//---------------------------------------------------------------------------

