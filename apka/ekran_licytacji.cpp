//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_licytacji.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForma_licytacji *Forma_licytacji;
//---------------------------------------------------------------------------
__fastcall TForma_licytacji::TForma_licytacji(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForma_licytacji::Edit_nowa_cenaChange(TObject *Sender)
{
	char pomoc;
	for(int i = 0; Edit_nowa_cena->Text[i] != '\0' ; i++)
	{
		pomoc = Edit_nowa_cena->Text[i];
		if (pomoc < '0' || pomoc > '9')
		{
			Edit_nowa_cena->Text[i] = '0';
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForma_licytacji::FormClose(TObject *Sender, TCloseAction &Action)

{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForma_licytacji::Image_paskiClick(TObject *Sender)
{
	ModalResult = 1;

}
//---------------------------------------------------------------------------

void __fastcall TForma_licytacji::Button_licytujClick(TObject *Sender)
{
	//if(Edit_nowa_cena->Text)
	//dodaje go na listê
	//podwy¿sza kowtê licytacji o podan¹ kwotê
}
//---------------------------------------------------------------------------

