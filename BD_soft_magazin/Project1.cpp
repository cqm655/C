//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Unit2.cpp", freceptie);
USEFORM("Unit3.cpp", dm); /* TDataModule: File Type */
USEFORM("Unit4.cpp", Fcec);
USEFORM("Unit1.cpp", fmain);
USEFORM("Unit5.cpp", Fautentificare);
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
		Application->CreateForm(__classid(TFcec), &Fcec);
		Application->CreateForm(__classid(TFautentificare), &Fautentificare);
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
