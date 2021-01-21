//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_listy_przedmiotow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForma_listy_przedmiotow *Forma_listy_przedmiotow;
TADOConnection* ADOConnection6;
//---------------------------------------------------------------------------
__fastcall TForma_listy_przedmiotow::TForma_listy_przedmiotow(TComponent* Owner, TADOConnection* a_ADOConnection)
	: TForm(Owner)
{
	ADOConnection6 = a_ADOConnection;
    WczytajDane();
}

//---------------------------------------------------------------------------

void __fastcall TForma_listy_przedmiotow::WczytajDane()
{
	int count = 0;


//----------Inicjowanie SQL i select
	TADOQuery * Query = new TADOQuery(NULL);
	Query -> Connection = ADOConnection6;

	Query -> SQL -> Clear();
	Query -> SQL -> Add("SELECT trim(nazwa) as nazwa ,trim(opis) as opis,kwota,id,id_parent from dbo.dane");
	Query -> SQL -> Add("where id_parent=:id");

//    int id = Forma_ekran_bazarek -> MojKlient -> podaj_id();

	Query -> Parameters -> ParamByName("id") -> Value = Forma_ekran_bazarek -> MojKlient -> podaj_id();

	Query -> Open();

	UnicodeString opis = Query -> FieldByName("opis") -> AsString;

	Grid -> BeginUpdate();

    //----------Usuwanie wszystkich przedmiot�w z tabeli by wczyta� je od nowa
	if (Grid->RowCount > 0)
		Grid->RowCount = 0;

//---------Wczytywanie wszystkich danych do tabeli grid
	while (!Query->Eof)
	{
		Grid->RowCount = count + 1;
		count = Grid->RowCount;

		Grid->Cells[grid_colNazwa->Index][count - 1] =
			Query -> FieldByName("nazwa") -> AsString;
		Grid->Cells[grid_colKwota->Index][count - 1] =
			Query -> FieldByName("kwota") -> AsFloat;
		Grid->Cells[grid_colId->Index][count - 1] =
			Query -> FieldByName("id") -> AsString;

        Query -> Next();
	}
	Grid -> EndUpdate();
	delete Query;
}
//---------------------------------------------------------------------------
void __fastcall TForma_listy_przedmiotow::Image_paskiClick(TObject *Sender)
{
    ModalResult = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForma_listy_przedmiotow::FormClose(TObject *Sender, TCloseAction &Action)

{
    Close();
}
//---------------------------------------------------------------------------
