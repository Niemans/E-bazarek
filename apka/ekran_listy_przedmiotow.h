//---------------------------------------------------------------------------

#ifndef ekran_listy_przedmiotowH
#define ekran_listy_przedmiotowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Colors.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.ScrollBox.hpp>
#include <System.Rtti.hpp>
//---------------------------------------------------------------------------
class TForma_listy_przedmiotow : public TForm
{
__published:	// IDE-managed Components
	TColorBox *ColorBox1;
	TImage *Image_EB;
	TImage *Image_paski;
	TImage *Image_box;
	TStringGrid *Grid;
	TStringColumn *grid_colNazwa;
	TCurrencyColumn *grid_colKwota;
	TCurrencyColumn *grid_colEdycja;
	TText *Text_przedmiot;
	TText *Text_koszt;
	TText *Text_edycja;
	void __fastcall Image_paskiClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TForma_listy_przedmiotow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForma_listy_przedmiotow *Forma_listy_przedmiotow;
//---------------------------------------------------------------------------
#endif