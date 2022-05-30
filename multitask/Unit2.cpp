//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Unit2.h"
#include "Project1PCH1.h"
#include "Unit1.h"
#include "Unit3.h"
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
//      void __fastcall multitask2::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
MT3 *f;
__fastcall multitask2::multitask2(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall multitask2::Execute()
{
	//---- Place thread code here ----

 f=new MT3(true);


for(int i=0; i<90000; i++)
{
	Form1->Memo1->Lines->Add(i);
	if(i>3000)
	{
		f->Start();
        multitask2::Terminate();
    }

}

}
//---------------------------------------------------------------------------
