//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Project1PCH1.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFcec *Fcec;
//---------------------------------------------------------------------------
__fastcall TFcec::TFcec(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFcec::CautaClick(TObject *Sender)
{
dm->qcec->Close();
dm->qcec->ParamByName("operator_id")->AsInteger=Fautentificare->utilizator;
dm->qcec->ParamByName("D1")->AsDate=DT1->Date;
dm->qcec->ParamByName("D2")->AsDate=DT2->Date;
dm->qcec->Open();

dm->qtotalcec->Close();
dm->qtotalcec->ParamByName("operator_id")->AsInteger=1;
dm->qtotalcec->ParamByName("D1")->AsDate=DT1->Date;
dm->qtotalcec->ParamByName("D2")->AsDate=DT2->Date;
dm->qtotalcec->Open();

Label6->Caption=dm->qtotalcec->FieldByName("total")->AsString;

}
//---------------------------------------------------------------------------
void __fastcall TFcec::DBGrid2CellClick(TColumn *Column)
{
   dm->qvanzare->Close();
   dm->qvanzare->ParamByName("cec_id")->AsInteger=dm->qcec->FieldByName("cec_id")->AsInteger;
   dm->qvanzare->Open();
}
//---------------------------------------------------------------------------
void __fastcall TFcec::FormClose(TObject *Sender, TCloseAction &Action)
{
dm->qvanzare->Close();

}
//---------------------------------------------------------------------------
void __fastcall TFcec::SpeedButton1Click(TObject *Sender)
{
if(!dm->qcec->IsEmpty())
{
	dm->R1->ShowReport(true);
}
else
{
    ShowMessage("DVS nu aveti date pentru a face raport");
}
}
//---------------------------------------------------------------------------

void __fastcall TFcec::SpeedButton2Click(TObject *Sender)
{
if(!dm->qvanzare->IsEmpty())
{
	dm->R2->ShowReport(true);
}
else
{
    ShowMessage("Dvs nu aveti informatie despre produse");
}
}
//---------------------------------------------------------------------------

