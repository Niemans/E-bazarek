//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_ebazarek.h"
#include "ekran_przedmiotu.h"
#include "ekran_startowy.h"
#include "ekran_boczne_menu.h"
#include "ekran_rejestracja.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

TForma_ekran_bazarek * Forma_ekran_bazarek;
UnicodeString szukaj = "";
//---------------------------------------------------------------------------
__fastcall TForma_ekran_bazarek::TForma_ekran_bazarek(TComponent* Owner)
	: TForm(Owner)
{
    zalogowane = 0;
	TForma_ekran_startowy * form_ekran_startowy = new TForma_ekran_startowy(this, ADOConnection);

    ADOConnection->Connected = true;
//    if()
//	{
//		ShowMessage("Brak połączenia z internetem");
//        Application->Terminate();
//	}
	if (form_ekran_startowy->ShowModal()) {
		delete form_ekran_startowy;
		WczytajDane();
	}
	else if (form_ekran_startowy->ShowModal()==0)
	{
		delete form_ekran_startowy;
		Application->Terminate();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForma_ekran_bazarek::btn_szukajClick(TObject *Sender)
{
	if (edit_szukaj->Visible == true)
		edit_szukaj->Visible = false;
	else
		edit_szukaj->Visible = true;
}
//---------------------------------------------------------------------------




void __fastcall TForma_ekran_bazarek::WczytajDane()
{
	int count = 0;


//----------Inicjowanie SQL i select
	TADOQuery * Query = new TADOQuery(NULL);
	Query -> Connection = ADOConnection;

	Query -> SQL -> Clear();
	Query -> SQL -> Add("SELECT trim(nazwa) as nazwa ,trim(opis) as opis,kwota,id,id_parent from dbo.dane");

	if (szukaj != "")
	Query -> SQL -> Add("where (upper(nazwa) like upper('"+szukaj+"%')) or (upper(nazwa) = trim(upper('"+szukaj+"')))");


	Query -> Open();

	Grid -> BeginUpdate();

    //----------Usuwanie wszystkich przedmiotów z tabeli by wczytać je od nowa
	if (Grid->RowCount > 0)
		Grid->RowCount = 0;

//---------Wczytywanie wszystkich danych do tabeli grid
	while (!Query->Eof)
	{
		Grid->RowCount = count + 1;
        count = Grid->RowCount;

		Grid->Cells[0][count - 1] =
			Query -> FieldByName("nazwa") -> AsString + "\n\nOpis:\n" + Query -> FieldByName("Opis")->AsString;
		Grid->Cells[1][count - 1] =
			Query -> FieldByName("kwota") -> AsFloat;

        Query -> Next();
	}
	Grid -> EndUpdate();
	delete Query;
}



void __fastcall TForma_ekran_bazarek::grid_colNazwaTap(TObject *Sender, const TPointF &Point)

{
	TForm_ekran_przedmiotu *Form_ekran_przedmiotu = new TForm_ekran_przedmiotu(this);
	Form_ekran_przedmiotu->ShowModal();
	delete Form_ekran_przedmiotu;
}
//---------------------------------------------------------------------------

void __fastcall TForma_ekran_bazarek::Image1Click(TObject *Sender)
{
	TForma_boczne_menu *Form_boczne_menu = new TForma_boczne_menu(this, ADOConnection);
	Form_boczne_menu->ShowModal();
	delete Form_boczne_menu;
}
//---------------------------------------------------------------------------

void TForma_ekran_bazarek::zmien_zalogowane(short int zmiana) //Klient = 1,	Firma = 2,	Admin = 3, bez = 0
{
	if(zmiana >=0 && zmiana <=3)
	{
		zalogowane = zmiana;
	}
	else
	{
		zalogowane = 0;
    }
}

//----------------------------------------------------------------------------
short int TForma_ekran_bazarek::zalogowanie()
{
	return zalogowane;
}

void __fastcall TForma_ekran_bazarek::FormClose(TObject *Sender, TCloseAction &Action)

{
	if(MojKlient != NULL) delete MojKlient;
	if(MojaFirma != NULL) delete MojaFirma;
}
//---------------------------------------------------------------------------

void __fastcall TForma_ekran_bazarek::edit_szukajChange(TObject *Sender)
{
	szukaj = edit_szukaj->Text;
	WczytajDane();
}
//---------------------------------------------------------------------------



