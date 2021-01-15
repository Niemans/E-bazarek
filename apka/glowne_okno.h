//---------------------------------------------------------------------------

#ifndef glowne_oknoH
#define glowne_oknoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Colors.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForma_glowne_okno : public TForm
{
__published:	// IDE-managed Components
	TImage *lupa;
	TImage *paski;
	TColorBox *ColorBox1;
	TEdit *Jasiu1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall lupaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForma_glowne_okno(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForma_glowne_okno *Forma_glowne_okno;
//---------------------------------------------------------------------------
#endif
