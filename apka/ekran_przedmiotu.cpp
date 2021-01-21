//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ekran_przedmiotu.h"
#include "ekran_ebazarek.h"
#include "ekran_licytacji.h"
#include "ekran_zakupu.h"
#include "ekran_kaszyka.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm_ekran_przedmiotu *Form_ekran_przedmiotu;
//---------------------------------------------------------------------------
__fastcall TForm_ekran_przedmiotu::TForm_ekran_przedmiotu(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_ekran_przedmiotu::FormClose(TObject *Sender, TCloseAction &Action)

{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_przedmiotu::Image_paskiClick(TObject *Sender)
{
     ModalResult = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_przedmiotu::Btn_licytujClick(TObject *Sender)
{
	TForma_licytacji *form_licytacja = new TForma_licytacji(this);
	form_licytacja->ShowModal();
	delete form_licytacja;
}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_przedmiotu::FormActivate(TObject *Sender)
{
	//Jeœli to licytacja, to:

	//Btn_licytuj->Visible = true;
	//Btn_kupTeraz->Visible = false;
	//Btn_doKoszyka->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_przedmiotu::Btn_kupTerazClick(TObject *Sender)
{
	TForma_zakupu *form_zakupu;
	if(Edit_kupowana_liczba->Text == "")
	{

	}
	else
	{
		form_zakupu= new TForma_zakupu(this);
		form_zakupu ->ShowModal();
		delete form_zakupu;
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_przedmiotu::Edit_kupowana_liczbaChange(TObject *Sender)
{
	char pomoc;
	for(int i = 0; Edit_kupowana_liczba->Text[i] != '\0' ; i++)
	{
		pomoc = Edit_kupowana_liczba->Text[i];
		if (pomoc < '0' || pomoc > '9')
		{
			Edit_kupowana_liczba->Text[i] = '0';
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_ekran_przedmiotu::Btn_doKoszykaClick(TObject *Sender)
{
	//przedmiot dodawany do koszyka!!!

	TForma_koszyka *form_koszyka = new TForma_koszyka(this);
	form_koszyka->ShowModal();
    delete form_koszyka;

}
//---------------------------------------------------------------------------

