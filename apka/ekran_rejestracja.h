//---------------------------------------------------------------------------

#ifndef ekran_rejestracjaH
#define ekran_rejestracjaH
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
//---------------------------------------------------------------------------
class TForma_rejestracja : public TForm
{
__published:	// IDE-managed Components
	TImage *Image_EB;
	TText *Text_login;
	TEdit *Edit_login;
	TButton *Btn_co_to_login;
	TText *Text_email;
	TEdit *Edit_email;
	TButton *Btn_co_to_email;
	TText *Text_has³o;
	TEdit *Edit_haslo;
	TButton *Btn_co_to_haslo;
	TText *Text_powtorz_haslo;
	TEdit *Edit_powtorz_haslo;
	TButton *Btn_powrot;
	TColorAnimation *ColorAnimation2;
	TButton *Btn_rejestracja;
	TText *Text_Btn_co_to_login;
	TColorAnimation *ColorAnimation1;
	TText *Text_Btn_co_to_email;
	TText *Text_Btn_co_to_haslo;
	void __fastcall Btn_co_to_loginClick(TObject *Sender);
	void __fastcall Btn_co_to_emailClick(TObject *Sender);
	void __fastcall Btn_co_to_hasloClick(TObject *Sender);
	void __fastcall Btn_powrotClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TForma_rejestracja(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForma_rejestracja *Forma_rejestracja;
//---------------------------------------------------------------------------
#endif
