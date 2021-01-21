//---------------------------------------------------------------------------

#ifndef ekran_panelu_adminaH
#define ekran_panelu_adminaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Colors.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>

#include "ekran_ebazarek.h"
//---------------------------------------------------------------------------
class TForm_ekran_panelu_admina : public TForm
{
__published:	// IDE-managed Components
	TImage *paski;
	TColorBox *ColorBox1;
	TText *Text_usun_przedmiot;
	TText *Text_usun_uzytkownika;
	TEdit *Edit_usun_przedmiot;
	TEdit *Edit_usun_uzytkownika;
	TText *Text_wyslany_komentarz;
	TMemo *Memo_komentarz;
	TButton *Btn_usun;
	TButton *Btn_anuluj;
	TText *Text_blad;
	TImage *Image_EB;
	void __fastcall Btn_anulujClick(TObject *Sender);
	void __fastcall Btn_usunClick(TObject *Sender);
	void __fastcall paskiClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TForm_ekran_panelu_admina(TComponent* Owner, TADOConnection* a_ADOConnection);
	bool sprawdzIDprzedm();
	bool sprawdzIDu();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_ekran_panelu_admina *Form_ekran_panelu_admina;
//---------------------------------------------------------------------------
#endif
