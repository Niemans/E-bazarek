//---------------------------------------------------------------------------

#ifndef ekran_zakupuH
#define ekran_zakupuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Colors.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
//---------------------------------------------------------------------------
class TForma_zakupu : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit_miasto;
	TEdit *Edit_ulica;
	TEdit *Edit_nrdomu;
	TEdit *Edit_kod_pocztowy;
	TEdit *Edit_imie;
	TEdit *Edit_nazwisko;
	TEdit *Edit_kraj;
	TText *Text_informacja;
	TImage *Image_arrow;
	TColorBox *ColorBox1;
	TImage *Image_EB;
	TImage *Image_monety;
	TText *Text_imie;
	TText *Text_nazwisko;
	TText *Text_kraj;
	TText *Text_miasto;
	TText *Text_ulica;
	TText *Text_nrdomu;
	TText *Text_kod_pocztowy;
	TButton *Btn_finalizacja;
	TText *Text_typ_platnosci;
	TListBox *ListBox_typ;
	TListBoxItem *ListBoxItem_PayU;
	TListBoxItem *ListBoxItem_Przelew;
	TText *Text_blad;
	void __fastcall Image_arrowClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Btn_finalizacjaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForma_zakupu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForma_zakupu *Forma_zakupu;
//---------------------------------------------------------------------------
#endif
