//---------------------------------------------------------------------------

#ifndef ekran_ebazarekH
#define ekran_ebazarekH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.ImgList.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <System.ImageList.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Gestures.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.ScrollBox.hpp>
#include <System.Rtti.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class TForma_ekran_bazarek : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TImageList *ImageList1;
	TEdit *edit_szukaj;
	TGestureManager *GestureManager1;
	TStringGrid *Grid;
	TStringColumn *grid_colNazwa;
	TCurrencyColumn *grid_colKwota;
	TImage *Image1;
	TImage *Image2;
	void __fastcall btn_szukajClick(TObject *Sender);
	void __fastcall grid_colNazwaTap(TObject *Sender, const TPointF &Point);
private:	// User declarations
    void __fastcall WczytajDane();
public:		// User declarations
	__fastcall TForma_ekran_bazarek(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForma_ekran_bazarek *Forma_ekran_bazarek;
//---------------------------------------------------------------------------
#endif