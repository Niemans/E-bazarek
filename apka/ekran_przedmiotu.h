//---------------------------------------------------------------------------

#ifndef ekran_przedmiotuH
#define ekran_przedmiotuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm_ekran_przedmiotu : public TForm
{
__published:	// IDE-managed Components
	TText *text_nazwa;
	TText *text_opis;
	TText *text_kwota;
	TButton *btn_doKoszyka;
	TButton *btn_kupTeraz;
	TButton *btn_licytuj;
	TImageControl *ImageControl1;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TForm_ekran_przedmiotu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_ekran_przedmiotu *Form_ekran_przedmiotu;
//---------------------------------------------------------------------------
#endif
