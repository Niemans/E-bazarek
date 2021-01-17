//---------------------------------------------------------------------------

#ifndef ekran_startowyH
#define ekran_startowyH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Colors.hpp>
#include <FMX.Ani.hpp>
//---------------------------------------------------------------------------
class TForma_ekran_startowy : public TForm
{
__published:	// IDE-managed Components
	TText *Text_login;
	TEdit *Edit_haslo;
	TText *Text_haslo;
	TEdit *Edit_login;
	TCheckBox *CheckBox_robot;
	TButton *Btn_logowanie;
	TText *Text_blad;
	TText *Text_zap_haslo;
	TText *Text_kliknij;
	TButton *Btn_rejestracja;
	TText *Text_brak_konta;
	TColorAnimation *ColorAnimation1;
	TColorAnimation *ColorAnimation2;
	TImage *Image_EB;
	TButton *Btn_przegladaj;
	TColorAnimation *ColorAnimation3;
	void __fastcall Btn_logowanieClick(TObject *Sender);
	void __fastcall CheckBox_robotClick(TObject *Sender);
	void __fastcall Text_kliknijClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Btn_rejestracjaClick(TObject *Sender);
	void __fastcall Btn_przegladajClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForma_ekran_startowy(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForma_ekran_startowy *Forma_ekran_startowy;
//---------------------------------------------------------------------------
#endif
