//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("zapomniane_haslo.cpp", Forma_zapomniane_haslo);
USEFORM("glowne_okno.cpp", Forma_glowne_okno);
USEFORM("ekran_startowy.cpp", Forma_ekran_startowy);
USEFORM("ekran_ebazarek.cpp", Forma_ekran_bazarek);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
//		Application->CreateForm(__classid(TForma_ekran_startowy), &Forma_ekran_startowy);
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
