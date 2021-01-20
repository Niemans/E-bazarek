//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("ekran_przedmiotu.cpp", Form_ekran_przedmiotu);
USEFORM("ekran_rejestracja.cpp", Forma_rejestracja);
USEFORM("ekran_startowy.cpp", Forma_ekran_startowy);
USEFORM("zapomniane_haslo.cpp", Forma_zapomniane_haslo);
USEFORM("ekran_boczne_menu.cpp", Forma_boczne_menu);
USEFORM("ekran_ebazarek.cpp", Forma_ekran_bazarek);
USEFORM("ekran_panelu_admina.cpp", Form_ekran_panelu_admina);
USEFORM("ekran_profilu.cpp", Form1);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TForma_ekran_bazarek), &Forma_ekran_bazarek);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
