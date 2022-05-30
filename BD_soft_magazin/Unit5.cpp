//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Project1PCH1.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFautentificare *Fautentificare;
//---------------------------------------------------------------------------
__fastcall TFautentificare::TFautentificare(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFautentificare::SpeedButton1Click(TObject *Sender)
{
	if(Edit1->Text!="" && Edit2->Text!="")
	{
	 dm->qliber->Close();
	 dm->qliber->SQL->Clear();
	 dm->qliber->SQL->Add("select * from operator where username=:username and pass=:pass and firma_id=:firma_id ");
	 dm->qliber->ParamByName("username")->AsString=Edit1->Text;
	 dm->qliber->ParamByName("pass")->AsString=Edit2->Text;
	 dm->qliber->ParamByName("firma_id")->AsInteger=1;
	 dm->qliber->Open();

	   if(!dm->qliber->IsEmpty())
	   {
	   fmain->Label3->Caption=dm->qliber->FieldByName("functia")->AsString;
	   fmain->Label2->Caption=dm->qliber->FieldByName("nume")->AsString+" "+dm->qliber->FieldByName("prenume")->AsString;
	   utilizator=dm->qliber->FieldByName("operator_id")->AsInteger;

		switch(dm->qliber->FieldByName("tip_acces")->AsInteger)
			  {
				  case 1: //casier
				  {
				   Close();
                   ShowMessage("1");
				   fmain->AlphaBlend=false;
				   //fmain->AlphaBlendValue=255;

				  break;
				  }
				  case 2:  //depozitar
				  {
				  Close();
				  freceptie->ShowModal();

				  break;
				  }
				  default:  // admin
				  {

				  break;
                  }
              }
	   }
	   else
	   {
		ShowMessage("Autentificare esuata!");
		Edit2->Clear();
		Edit1->Clear();
       }
	}
	else
	{
		ShowMessage("Campuri goale");
	}
}
//---------------------------------------------------------------------------
