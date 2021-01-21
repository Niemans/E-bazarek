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
	if(Edit_imie->Text != "" && Edit_nazwisko->Text != "" && Edit_kraj->Text != "" && Edit_miasto->Text != "" && Edit_ulica->Text != "" && Edit_nrdomu->Text != "" && Edit_kod_pocztowy->Text != "")
	{
		Text_blad->Visible = false;
		ShowMessage("Tu by siê przechodzi³o do osobnej strony, a osoby sprzedaj¹ce dosta³yby wiadomoœæ na maila");
		ModalResult = 1;
	}
	else
	{
		Text_blad->Visible = true;
    }

}
//---------------------------------------------------------------------------

