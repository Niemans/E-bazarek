//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_zakupu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForma_zakupu *Forma_zakupu;
//---------------------------------------------------------------------------
__fastcall TForma_zakupu::TForma_zakupu(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForma_zakupu::Image_arrowClick(TObject *Sender)
{
    ModalResult = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForma_zakupu::FormClose(TObject *Sender, TCloseAction &Action)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TForma_zakupu::Btn_finalizacjaClick(TObject *Sender)
{
	ShowMessage("Tu by siê przechodzi³o do osobnej strony, a osoby sprzedaj¹ce dosta³yby wiadomoœæ na maila");
}
//---------------------------------------------------------------------------

