//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Project1PCH1.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfreceptie *freceptie;
int fac_id;
int pr_den_id, pr_cod_id;
bool a;
//---------------------------------------------------------------------------
__fastcall Tfreceptie::Tfreceptie(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfreceptie::FormShow(TObject *Sender)
{
TabSheet2->TabVisible=true	;
TabSheet3->TabVisible=false;

TabSheet1->TabVisible=true;

}
//---------------------------------------------------------------------------
void __fastcall Tfreceptie::Button3Click(TObject *Sender)
{
dm->QUM->Close();
dm->QUM->Open();
TabSheet1->TabVisible=false;
TabSheet3->TabVisible=true;

}
//---------------------------------------------------------------------------
void __fastcall Tfreceptie::Button7Click(TObject *Sender)
{
Edit4->Text=dm->QUM->FieldByName("Abreviere")->AsString;
TabSheet1->TabVisible=true;
TabSheet3->TabVisible=false;

}
//---------------------------------------------------------------------------


void __fastcall Tfreceptie::ecautareChange(TObject *Sender)
{

AnsiString s;
if(ecautare->Text!="")
{
s="SELECT * FROM PRODUSE where ";
if(rb1->Checked) //cautarrea dupa nume
{
s+=" denumire like '"+ecautare->Text+"%' ";
}
else
{

	s+="cod_produs like'"+ecautare->Text+"%' ";
}
s+=" order by denumire ";
dm->qprodus->Close();
dm->qprodus->SQL->Clear();
dm->qprodus->SQL->Add(s);
dm->qprodus->Open();
}
else
{
dm->qprodus->Close();
}
}
//---------------------------------------------------------------------------

void __fastcall Tfreceptie::rb1Click(TObject *Sender)
{
if(rb1->Checked)ecautare->NumbersOnly=false;
else ecautare->NumbersOnly=true;
}
//---------------------------------------------------------------------------

void __fastcall Tfreceptie::Button2Click(TObject *Sender)
{
TabSheet1->TabVisible=false;
TabSheet2->TabVisible=true;
}
//---------------------------------------------------------------------------

void __fastcall Tfreceptie::Button8Click(TObject *Sender)
{
Edit2->Text=dm->qprodus->FieldByName("denumire")->AsString;
TabSheet2->TabVisible=false;
TabSheet1->TabVisible=true;
}
//---------------------------------------------------------------------------


void __fastcall Tfreceptie::Button1Click(TObject *Sender)
{

 if((Edit1->Text!="") && (Edit3->Text!=""))
 {
  dm->qliber->Close();
  dm->qliber->SQL->Clear();
  dm->qliber->SQL->Add("select * from factura_rec where data_factura=:data_factura and nr_factura=:nr_factura");
  dm->qliber->ParamByName("data_Factura")->AsDate=DateTimePicker1->Date;
  dm->qliber->ParamByName("nr_factura")->AsString=Edit1->Text;
  dm->qliber->Open();

  if(dm->qliber->IsEmpty())
  {

  dm->FDStoredProc1->Close();
  dm->FDStoredProc1->Params->Items[1]->AsDate=DateTimePicker1->Date;
  dm->FDStoredProc1->Params->Items[2]->AsString=Edit1->Text;
  dm->FDStoredProc1->Params->Items[3]->AsString=Edit3->Text;
  dm->FDStoredProc1->ExecProc();
  fac_id=dm->FDStoredProc1->Params->Items[0]->AsInteger;
  Button1->Enabled=false;
  Panel13->Enabled=true;
   ShowMessage("Inregistrare cu succes!");
 }
     else
{
	ShowMessage("SE REPETA FACTURA");
}
 }
 else
 {
 ShowMessage("Nu sunt indeplinite toate campurile!");
 }

 }
 

//---------------------------------------------------------------------------

void __fastcall Tfreceptie::Button4Click(TObject *Sender)
{
Button1->Enabled=true;
Panel13->Enabled=false;
if(MessageDlg("doriti sa inchideti factura", mtConfirmation, TMsgDlgButtons()<<mbYes<<mbNo,0)==mrYes)
{
Edit5->Clear();
Edit6->Clear();
Edit2->Clear();
Edit4->Clear();
Edit7->Clear();
Edit1->Clear();
Edit3->Clear();
dm->qreceptie->Close();
}
}
//---------------------------------------------------------------------------

void __fastcall Tfreceptie::Button6Click(TObject *Sender)
{
if((Edit2->Text!="") && (Edit4->Text!="") && (Edit5->Text!="") && (Edit6->Text!="") && (Edit7->Text!=""))
{
AnsiString s;
s+="INSERT INTO RECEPTIE(PRODUSE_ID,UNIT_MASURA_ID,FACTURA_REC_ID, OPERATOR_ID,STOCK1,STOCK2,PRET_INTRARE,PRET_VANZARE)";
s+="VALUES (:PRODUSE_ID,:UNIT_MASURA_ID,:FACTURA_REC_ID,:OPERATOR_ID,:STOCK1,:STOCK2,:PRET_INTRARE,:PRET_VANZARE)";

dm->qliber->Close();
dm->qliber->SQL->Clear();
dm->qliber->SQL->Add(s);
dm->qliber->ParamByName("PRODUSE_ID")->AsInteger=dm->qprodus->FieldByName("PRODUSE_ID")->AsInteger;
dm->qliber->ParamByName("UNIT_MASURA_ID")->AsInteger=dm->QUM->FieldByName("UNIT_MASURA_ID")->AsInteger;
ShowMessage(fac_id);
dm->qliber->ParamByName("factura_rec_id")->AsInteger=fac_id;
dm->qliber->ParamByName("operator_id")->AsInteger=2;
dm->qliber->ParamByName("stock1")->AsInteger=Edit7->Text.ToInt();
dm->qliber->ParamByName("stock2")->AsInteger=Edit7->Text.ToInt();
dm->qliber->ParamByName("pret_intrare")->AsFloat=Edit5->Text.ToDouble();
dm->qliber->ParamByName("pret_vanzare")->AsFloat=Edit6->Text.ToDouble();
dm->qliber->ExecSQL();

dm->qreceptie->Close();
dm->qreceptie->ParamByName("factura_rec_id")->AsInteger=fac_id;
dm->qreceptie->Open();

ShowMessage("Executare cu succes");
Edit5->Clear();
Edit6->Clear();
Edit2->Clear();
Edit4->Clear();
Edit7->Clear();
Edit1->Clear();
Edit3->Clear();


}
else
{
    ShowMessage("Nu sunt indeplinite toate campurile");
}
}
//---------------------------------------------------------------------------


void __fastcall Tfreceptie::Button17Click(TObject *Sender)
{
AnsiString s;
s+="insert into PRODUSE(DENUMIRE,COD_PRODUS)";
s+="values(:DENUMIRE,:COD_PRODUS)";
dm->qliber->Close();
dm->qliber->SQL->Clear();
dm->qliber->SQL->Add(s);
if((Edit11->Text!="") && (Edit12->Text!=""))
{
dm->qliber->ParamByName("denumire")->AsString=Edit11->Text;
dm->qliber->ParamByName("cod_produs")->AsInteger=Edit12->Text.ToInt();
dm->qliber->ExecSQL();
ShowMessage("Executare cu succes");
Edit11->Clear();
Edit12->Clear();
dm->qprodus->Close();
dm->qprodus->Open();
}
else
{
ShowMessage("Sunt campuri goale");
}

}
//---------------------------------------------------------------------------

void __fastcall Tfreceptie::Button18Click(TObject *Sender)
{
Edit11->Clear();
Edit12->Clear();

}
//---------------------------------------------------------------------------

void __fastcall Tfreceptie::DBGrid2DblClick(TObject *Sender)
{

Edit10->Text=dm->qprodus->FieldByName("DENUMIRE")->AsString;
pr_den_id=dm->qprodus->FieldByName("produse_id")->AsInteger;
Edit13->Text=dm->qprodus->FieldByName("COD_PRODUS")->AsInteger;



}
//---------------------------------------------------------------------------

void __fastcall Tfreceptie::Button13Click(TObject *Sender)
{
dm->qprodus->Close();
dm->qprodus->Open();
}
//---------------------------------------------------------------------------

void __fastcall Tfreceptie::SpeedButton1Click(TObject *Sender)
{
dm->qprodus->Close();
dm->qprodus->Open();
}
//---------------------------------------------------------------------------

void __fastcall Tfreceptie::Button21Click(TObject *Sender)
{

dm->qedit->Close();
dm->qedit->ParamByName("denumire")->AsString=Edit10->Text;
dm->qedit->ParamByName("cod_produs")->AsInteger=Edit13->Text.ToInt();
dm->qedit->ParamByName("produse_id")->AsInteger=pr_den_id;
dm->qedit->ExecSQL();
dm->qprodus->Close();
dm->qprodus->Open();



}
//---------------------------------------------------------------------------

void __fastcall Tfreceptie::Button22Click(TObject *Sender)
{
Edit10->Clear();
Edit13->Clear();
}
//---------------------------------------------------------------------------



void __fastcall Tfreceptie::FormClose(TObject *Sender, TCloseAction &Action)
{
Edit5->Clear();
Edit6->Clear();
Edit2->Clear();
Edit4->Clear();
Edit7->Clear();
Edit1->Clear();
Edit3->Clear();
dm->qreceptie->Close();
}
//---------------------------------------------------------------------------


