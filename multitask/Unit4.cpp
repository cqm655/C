//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Unit4.h"
#include "Project1PCH1.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit5.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall MT4::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
 MT5 *ff;
__fastcall MT4::MT4(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall MT4::Execute()
{
	//---- Place thread code here ----
	ff=new MT5(true);

	for(int i=4000; i<90000; i++)
	{
		Form1->Memo3->Lines->Add(i);
		if(i>5000)
		{
			ff->Start();
            MT4::Terminate();
        }

    }
}
//---------------------------------------------------------------------------
