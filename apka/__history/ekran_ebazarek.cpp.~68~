//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_ebazarek.h"
#include "ekran_przedmiotu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.XLgXhdpiTb.fmx", _PLAT_ANDROID)
#pragma resource ("*.LgXhdpiPh.fmx", _PLAT_ANDROID)
#pragma resource ("*.NmXhdpiPh.fmx", _PLAT_ANDROID)

TForma_ekran_bazarek * Forma_ekran_bazarek;
//---------------------------------------------------------------------------
__fastcall TForma_ekran_bazarek::TForma_ekran_bazarek(TComponent* Owner)
	: TForm(Owner)
{
	UnicodeString Connection = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" +
	ExtractFilePath(Application->GetNamePath()) + "Baza.xlsx" + ";Extended Properties=Excel 9.0";
	ADOConnection->ConnectionString = Connection;

//	TStringList *SL = new TStringList;
//	SL = new TStringList;
//    ADOConnection->GetTableNames(SL);

    WczytajDane();
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
	int i = 0;
	ADOQuery->SQL->Text = "select ID, ID_Parent, Nazwa, Opis, Cena from [EBazarek]";
    ADOQuery->Open();
	while(!ADOQuery->Eof) {
	Grid->Cells[0][i] = ADOQuery->FieldByName("Nazwa")->AsString;
	Grid->Cells[1][i] = "50";
    i++;
	ADOQuery->Next();
	}
	ADOQuery->Close();
    ADOQuery->Free();
}



void __fastcall TForma_ekran_bazarek::grid_colNazwaTap(TObject *Sender, const TPointF &Point)

{
	TForm_ekran_przedmiotu *Form_ekran_przedmiotu = new TForm_ekran_przedmiotu(this);
	Form_ekran_przedmiotu->ShowModal();
	delete Form_ekran_przedmiotu;
}
//---------------------------------------------------------------------------

