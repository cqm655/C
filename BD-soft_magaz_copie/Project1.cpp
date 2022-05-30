//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("..\BD_soft_magazin\Unit3.cpp", dm); /* TDataModule: File Type */
USEFORM("..\BD_soft_magazin\Unit2.cpp", freceptie);
USEFORM("Unit1.cpp", fmain);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(Tfmain), &fmain);
		Application->CreateForm(__classid(Tfreceptie), &freceptie);
		Application->CreateForm(__classid(Tdm), &dm);
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
