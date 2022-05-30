//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Unit5.h"
#include "Project1PCH1.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall MT5::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall MT5::MT5(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall MT5::Execute()
{
	//---- Place thread code here ----
	for(int i=5000; i<9000; i++)
	{
		Form1->Memo4->Lines->Add(i);
        MT5::Terminate();
    }
}
//---------------------------------------------------------------------------