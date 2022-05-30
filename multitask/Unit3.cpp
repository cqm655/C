//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Unit3.h"
#include "Project1PCH1.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit4.h"
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
//      void __fastcall MT3::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

MT4 *e;
__fastcall MT3::MT3(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall MT3::Execute()
{
	//---- Place thread code here ----
e=new MT4(true);





for(int i=3000; i<90000; i++)
{
	Form1->Memo2->Lines->Add(i);
	if(i>4000)
	{
		e->Start();
        MT3::Terminate();
    }


}

}
//---------------------------------------------------------------------------
