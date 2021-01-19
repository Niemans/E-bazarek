//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_ebazarek.h"
#include "ekran_przedmiotu.h"
#include "ekran_startowy.h"
#include "ekran_boczne_menu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

TForma_ekran_bazarek * Forma_ekran_bazarek;
//---------------------------------------------------------------------------
__fastcall TForma_ekran_bazarek::TForma_ekran_bazarek(TComponent* Owner)
	: TForm(Owner)
{
    zalogowane = 0;
	TForma_ekran_startowy * form_ekran_startowy = new TForma_ekran_startowy(this);

	if (form_ekran_startowy->ShowModal()) {
		delete form_ekran_startowy;
		WczytajDane();
	}
	else
	{
		delete form_ekran_startowy;
		Free();
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
	for (int i=0; i < 5; i++) {
	Grid->Cells[0][i] = "cze��";
	Grid->Cells[1][i] = "50";
	}
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
	TForma_boczne_menu *Form_boczne_menu = new TForma_boczne_menu(this);
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
