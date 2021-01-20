//---------------------------------------------------------------------------

#ifndef ekran_boczne_menuH
#define ekran_boczne_menuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Colors.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include "ekran_ebazarek.h"
//---------------------------------------------------------------------------
class TForma_boczne_menu : public TForm
{
__published:	// IDE-managed Components
	TColorBox *ColorBox_biel;
	TImage *Image_EB;
	TImage *Image_arrow;
	TImage *Image_dom;
	TButton *Btn_rejestracja;
	TButton *Btn_przedmioty;
	TButton *Btn_logowanie;
	TButton *Btn_wyloguj;
	TButton *Btn_admin;
	TButton *Btn_profil;
	TButton *Btn_koszyk;
	TColorBox *ColorBox4;
	void __fastcall Btn_logowanieClick(TObject *Sender);
	void __fastcall Btn_rejestracjaClick(TObject *Sender);
	void __fastcall Btn_adminClick(TObject *Sender);
	void __fastcall Btn_wylogujClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Image_domClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall Image_arrowClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForma_boczne_menu(TComponent* Owner, TADOConnection* a_ADOConnection);
};
//---------------------------------------------------------------------------
extern PACKAGE TForma_boczne_menu *Forma_boczne_menu;
//---------------------------------------------------------------------------
#endif
