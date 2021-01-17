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
	TEdit *edit_nhaslo;
	TText *Text_pnhaslo;
	TEdit *Edit_pnhaslo;
	TText *Text_ListBox_KF;
	TListBox *ListBox_KF;
	TListBoxItem *ListBoxItem_Klient;
	TListBoxItem *ListBoxItem_Firma;
	void __fastcall Btn_wyslij_wiadomoscClick(TObject *Sender);
	void __fastcall Btn_zmien_hasloClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Btn_powrotClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall ListBoxItem_KlientClick(TObject *Sender);
	void __fastcall ListBoxItem_FirmaClick(TObject *Sender);
private:	// User declarations
	UnicodeString kod;
	void wygeneruj_kod();    //generuje kod
public:		// User declarations
	__fastcall TForma_zapomniane_haslo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForma_zapomniane_haslo *Forma_zapomniane_haslo;
//---------------------------------------------------------------------------
#endif
