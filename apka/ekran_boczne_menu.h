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
//---------------------------------------------------------------------------
class TForma_boczne_menu : public TForm
{
__published:	// IDE-managed Components
	TColorBox *ColorBox1;
	TImage *Image_EB;
	TImage *Image1;
	TImage *Image2;
private:	// User declarations
public:		// User declarations
	__fastcall TForma_boczne_menu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForma_boczne_menu *Forma_boczne_menu;
//---------------------------------------------------------------------------
#endif
