//---------------------------------------------------------------------------

#ifndef zapomniane_hasloH
#define zapomniane_hasloH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Ani.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
//---------------------------------------------------------------------------
class TForma_zapomniane_haslo : public TForm
{
__published:	// IDE-managed Components
	TButton *Btn_wyslij_wiadomosc;
	TText *Text_blad1;
	TColorAnimation *ColorAnimation1;
	TButton *Btn_powrot;
	TImage *Image_EB;
	TColorAnimation *ColorAnimation2;
	TButton *Btn_zmien_haslo;
	TColorAnimation *ColorAnimation3;
	TText *Text_blad2;
	TText *Text_email;
	TEdit *Edit_email;
	TText *Text_kod;
	TText *Text_nhaslo;
	TEdit *Edit_kod;
	TEdit *Edit_nhaslo;
	TText *Text_pnhaslo;
	TEdit *Edit_pnhaslo;
	TCheckBox *CheckBox_kod;
	TCheckBox *CheckBox_email;
	TCheckBox *CheckBox_nhaslo;
	TCheckBox *CheckBox_pnhaslo;
	void __fastcall Btn_wyslij_wiadomoscClick(TObject *Sender);
	void __fastcall Btn_zmien_hasloClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Btn_powrotClick(TObject *Sender);
	void __fastcall Edit_emailChange(TObject *Sender);
	void __fastcall Edit_kodChange(TObject *Sender);
	void __fastcall Edit_nhasloChange(TObject *Sender);
	void __fastcall Edit_pnhasloChange(TObject *Sender);
private:	// User declarations
	UnicodeString kod;
	void wygeneruj_kod();    //generuje kod
    bool sprawdzEmail();
public:		// User declarations
	__fastcall TForma_zapomniane_haslo(TComponent* Owner, TADOConnection *a_ADOConnection);
};
//---------------------------------------------------------------------------
extern PACKAGE TForma_zapomniane_haslo *Forma_zapomniane_haslo;
//---------------------------------------------------------------------------
#endif
