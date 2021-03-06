//---------------------------------------------------------------------------

#ifndef ekran_licytacjiH
#define ekran_licytacjiH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Colors.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.Objects.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.Types.hpp>
#include <System.Rtti.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TForma_licytacji : public TForm
{
__published:	// IDE-managed Components
	TImage *Image_paski;
	TColorBox *ColorBox1;
	TImage *Image_licytacja;
	TImage *Image_EB;
	TText *Text_osoby;
	TStringGrid *Grid;
	TStringColumn *grid_colNazwa;
	TCurrencyColumn *grid_colKwota;
	TText *Text_historia_cen;
	TText *Text_nowa_cena;
	TEdit *Edit_nowa_cena;
	TText *Text1;
	TEdit *Edit_cala_cena;
	TButton *Button_licytuj;
	void __fastcall Edit_nowa_cenaChange(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Image_paskiClick(TObject *Sender);
	void __fastcall Button_licytujClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForma_licytacji(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForma_licytacji *Forma_licytacji;
//---------------------------------------------------------------------------
#endif
