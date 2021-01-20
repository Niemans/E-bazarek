//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_kaszyka.h"
#include "ekran_zakupu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForma_koszyka *Forma_koszyka;
//---------------------------------------------------------------------------
__fastcall TForma_koszyka::TForma_koszyka(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForma_koszyka::Image_paskiDblClick(TObject *Sender)
{
	ModalResult = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForma_koszyka::Btn_kupClick(TObject *Sender)
{
	TForma_zakupu * form_zakup = new TForma_zakupu(this);
	form_zakup->ShowModal();
	delete form_zakup;
}
//---------------------------------------------------------------------------

void __fastcall TForma_koszyka::FormClose(TObject *Sender, TCloseAction &Action)
{
	Close();
}
//---------------------------------------------------------------------------
