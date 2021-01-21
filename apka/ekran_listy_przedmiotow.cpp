//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_listy_przedmiotow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForma_listy_przedmiotow *Forma_listy_przedmiotow;
//---------------------------------------------------------------------------
__fastcall TForma_listy_przedmiotow::TForma_listy_przedmiotow(TComponent* Owner)
	: TForm(Owner)
{
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
