//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_rejestracja.h"
#include "ekran_startowy.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForma_rejestracja *Forma_rejestracja;
//---------------------------------------------------------------------------
__fastcall TForma_rejestracja::TForma_rejestracja(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForma_rejestracja::Btn_co_to_loginClick(TObject *Sender)
{
    Text_Btn_co_to_login->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForma_rejestracja::Btn_co_to_emailClick(TObject *Sender)
{
    Text_Btn_co_to_email->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForma_rejestracja::Btn_co_to_hasloClick(TObject *Sender)
{
    Text_Btn_co_to_haslo->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForma_rejestracja::Btn_powrotClick(TObject *Sender)
{
	 CloseModal();
}
//---------------------------------------------------------------------------
void __fastcall TForma_rejestracja::FormClose(TObject *Sender, TCloseAction &Action)

{
	Forma_ekran_startowy->Visible = true;
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TForma_rejestracja::FormActivate(TObject *Sender)
{
    Forma_ekran_startowy->Visible = false;
}
//---------------------------------------------------------------------------

