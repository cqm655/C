//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TDateTime DT;
int CL,PR;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
Label3->Caption=DT.CurrentDate();

TabSheet2->TabVisible=0;
TabSheet3->TabVisible=0;
TabSheet4->TabVisible=0;
TabSheet8->TabVisible=0;


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
Label5->Caption=DT.CurrentTime();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{

if((Edit1->Text!="") && (!Edit2->Text.IsEmpty()))
{
   if((Edit1->Text=="1")&&(Edit1->Text=="1"))
   {

     FDQuery1->Close();
	 FDQuery1->Open();
	 TabSheet1->TabVisible=0;
	 TabSheet3->TabVisible=1;
     TabSheet8->TabVisible=1;
	 Label7->Caption="Admin";
     Label8->Caption="Admin";
   }
   else
   {
	   ShowMessage("Autentificare Esuata");
       Edit2->Clear();
   }
}
else
{
	ShowMessage("Dvs nu ati completat campurile pentru autentificare");
}
}
//---------------------------------------------------------------------------




void __fastcall TForm1::SpeedButton9Click(TObject *Sender)
{
TabSheet3->Visible=1;
TabSheet2->Visible=0;

Edit3->Text=QCLIENT->FieldByName("npp")->AsString;
Edit4->Text=QCLIENT->FieldByName("npp")->AsString;

CL=QCLIENT->FieldByName("CLIENT_ID")->AsInteger;

}

//---------------------------------------------------------------------------







void __fastcall TForm1::Button1Click(TObject *Sender)
{
if((Edit3->Text!="")&&(Edit88->Text!="")&&(Edit9->Text!="")&&(Edit10->Text!=""))
{
 QINREG->Close();
 QINREG->ParamByName("OPERATOR_ID")->AsInteger=1;
 QINREG->ParamByName("PRODUS_ID")->AsInteger=QPRODUS->FieldByName("PRODUS_ID")->AsInteger;
  QINREG->ParamByName("CLIENT_ID")->AsInteger=QCLIENT->FieldByName("CLIENT_ID")->AsInteger;
   QINREG->ParamByName("DATA_ELIBERARII")->AsDate=DateTimePicker1->Date;
	QINREG->ParamByName("DATA_RAMBURSARII")->AsDate=DateTimePicker2->Date;
	 QINREG->ParamByName("GAJ")->AsFloat=StrToFloat(Edit10->Text);
	  QINREG->ParamByName("SUMA_ACHITARE")->AsFloat=StrToFloat(Edit9->Text);
	  QINREG->ExecSQL();
	  ShowMessage("Inregistrare cu succes!");
	  Edit3->Clear();
	  Edit88->Clear();
	  Edit9->Clear();
	  Edit10->Clear();
	  FDQuery1->Close();
      FDQuery1->Open();
}
else
{
	ShowMessage("NU ATI COMPLETAT CAMPURILE");
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 	  Edit3->Clear();
	  Edit88->Clear();
	  Edit9->Clear();
	  Edit10->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DBGrid1DblClick(TObject *Sender)
{
Edit7->Text=FDQuery1->FieldByName("NUME_PRODUS")->AsString;
PR=FDQuery1->FieldByName("PRODUS_ID")->AsInteger;

Edit4->Text=FDQuery1->FieldByName("CLIENT")->AsString;
CL=FDQuery1->FieldByName("CLIENT_ID")->AsInteger;

DateTimePicker3->Date=FDQuery1->FieldByName("DATA_ELIBERARII")->AsString;
DateTimePicker4->Date=FDQuery1->FieldByName("DATA_RAMBURSARII")->AsString;

Edit5->Text=FDQuery1->FieldByName("SUMA_ACHITARE")->AsString;
Edit6->Text=FDQuery1->FieldByName("GAJ")->AsString;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
if((Edit4->Text!="")&&(Edit5->Text!="")&&(Edit6->Text!="")&&(Edit7->Text!=""))
{
 QEDIT->Close();
 QEDIT->ParamByName("OPERATOR_ID")->AsInteger=1;
 QEDIT->ParamByName("PRODUS_ID")->AsInteger=PR;
  QEDIT->ParamByName("CLIENT_ID")->AsInteger=CL;
   QEDIT->ParamByName("DATA_ELIBERARII")->AsDate=DateTimePicker3->Date;
	QEDIT->ParamByName("DATA_RAMBURSARII")->AsDate=DateTimePicker4->Date;
	 QEDIT->ParamByName("GAJ")->AsFloat=StrToFloat(Edit6->Text);
	  QEDIT->ParamByName("SUMA_ACHITARE")->AsFloat=StrToFloat(Edit5->Text);
QEDIT->ParamByName("IMPRUMUT_ID")->AsInteger=FDQuery1->FieldByName("IMPRUMUT_ID")->AsInteger;
	  QEDIT->ExecSQL();
	  ShowMessage("Inregistrare cu succes!");

	  FDQuery1->Close();
	  FDQuery1->Open();
      	  Edit4->Clear();
	  Edit5->Clear();
	  Edit6->Clear();
	  Edit7->Clear();
}
else
{
	ShowMessage("NU ATI COMPLETAT CAMPURILE");
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	  Edit4->Clear();
	  Edit5->Clear();
	  Edit6->Clear();
	  Edit7->Clear();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::SpeedButton10Click(TObject *Sender)
{
TabSheet2->Visible=0;
TabSheet3->Visible=1;

	nume->Visible=0;
	prenume->Visible=0;
	strada->Visible=0;
	idnp->Visible=0;
	telefon->Visible=0;
	Button6->Enabled=1;
	SpeedButton9->Enabled=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton12Click(TObject *Sender)
{
TabSheet4->Visible=0;
TabSheet3->Visible=1;
}
//---------------------------------------------------------------------------






void __fastcall TForm1::SpeedButton11Click(TObject *Sender)
{
TabSheet4->Visible=0;
TabSheet3->Visible=1;
Edit7->Text=QPRODUS->FieldByName("NUME_PRODUS")->AsString;
Edit88->Text=QPRODUS->FieldByName("NUME_PRODUS")->AsString;
PR=QPRODUS->FieldByName("PRODUS_ID")->AsInteger;



}
//---------------------------------------------------------------------------




void __fastcall TForm1::SpeedButton8Click(TObject *Sender)
{
QPRODUS->Close();
QPRODUS->Open();
TabSheet3->Visible=0;
TabSheet4->Visible=1;



}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton6Click(TObject *Sender)
{
QPRODUS->Close();
QPRODUS->Open();
TabSheet3->Visible=0;
TabSheet4->Visible=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton7Click(TObject *Sender)
{
QCLIENT->Close();
QCLIENT->Open();
TabSheet3->Visible=0;
TabSheet2->Visible=1;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
QCLIENT->Close();
QCLIENT->Open();
TabSheet3->Visible=0;
TabSheet2->Visible=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
if(CheckBox1->Checked)
{
	nume->Visible=1;
	prenume->Visible=1;
	strada->Visible=1;
	idnp->Visible=1;
    telefon->Visible=1;
	SpeedButton9->Enabled=0;
    Button6->Visible=1;

}
else
{
	nume->Visible=0;
	prenume->Visible=0;
	strada->Visible=0;
	idnp->Visible=0;
	telefon->Visible=0;
    Button6->Visible=0;
	SpeedButton9->Enabled=1;
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button6Click(TObject *Sender)
{
if((nume->Text!="")&&(prenume->Text!="")&&(telefon->Text!="")&&(idnp->Text!="")&&
	(strada->Text!=""))
	{
	 QLIBER->Close();
	 QLIBER->SQL->Clear();
	 QLIBER->SQL->Add("INSERT INTO CLIENT(NUME,PRENUME,ADRESA,TELEFON,IDNP) VALUES(:NUME,:PRENUME,:ADRESA,:TELEFON,:IDNP)");
	 QLIBER->ParamByName("NUME")->AsString=nume->Text;
	 QLIBER->ParamByName("PRENUME")->AsString=prenume->Text;
	 QLIBER->ParamByName("ADRESA")->AsString=strada->Text;
	 QLIBER->ParamByName("TELEFON")->AsString=telefon->Text;
	 QLIBER->ParamByName("IDNP")->AsString=idnp->Text;

	 QLIBER->ExecSQL();

	  QCLIENT->Close();
	  QCLIENT->Open();

	 ShowMessage("Inregistrare Cu Succes!");

     CheckBox1->Checked=false;
	 nume->Clear();
	 prenume->Clear();
	 strada->Clear();
	 telefon->Clear();
	 idnp->Clear();
	 SpeedButton10->Click();
	}
else
{

}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button10Click(TObject *Sender)
{
AnsiString s;

s="SELECT CL.NUME+' '+CL.PRENUME AS CLIENT,";
s+="       c.nume_categorie,";
s+="	   OP.NUME+' '+OP.PRENUME AS OPERATOR,";
s+="	   SUMA_ACHITARE-GAJ AS RAMAS,";
s+="	   P.NUME_PRODUS, I.*, CL.*, C.*, P.* ";
s+="          FROM CLIENT CL INNER JOIN IMPRUMUT I ON CL.CLIENT_ID=I.CLIENT_ID";
s+="                INNER JOIN OPERATOR OP ON OP.OPERATOR_ID=I.OPERATOR_ID";
s+="               INNER JOIN PRODUS P ON P.PRODUS_ID=I.PRODUS_ID ";
s+="               INNER JOIN CATEGORIE C ON C.CATEGORIE_ID=P.CATEGORIE_ID ";
s+="            WHERE I.ACTIV=1";
if(CheckBox2->Checked)
{
	s+=" and CL.nume like '"+Edit19->Text+"%' ";
}
if(CheckBox7->Checked)
{
	s+=" and CL.prenume like '"+Edit15->Text+"%' ";
}
if(CheckBox3->Checked)
{
	s+=" and p.nume_produs like '"+Edit22->Text+"%' ";
}
if(CheckBox4->Checked)
{
	s+=" and DATA_ELIBERARII =:DATA_ELIBERARII";
}
if(CheckBox5->Checked)
{
	s+=" and DATA_RETURNARII =:DATA_RETURNARII ";
}
s+="             ORDER BY I.DATA_ELIBERARII ";

 QCAUTA->Close();
 QCAUTA->SQL->Clear();
 QCAUTA->SQL->Add(s);
 if(CheckBox4->Checked)
{
	QCAUTA->ParamByName("DATA_ELIBERARII")->AsDate=DateTimePicker7->Date;
}
 if(CheckBox5->Checked)
{
	QCAUTA->ParamByName("DATA_RETURNARII")->AsDate=DateTimePicker8->Date;
}




QCAUTA->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{

if (MessageDlg("Doriti sa stergeti inregistrarea?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)

            {

              QDELETE->Close();
QDELETE->ParamByName("IMPRUMUT_ID")->AsInteger=FDQuery1->FieldByName("IMPRUMUT_ID")->AsInteger;

QDELETE->ExecSQL();

FDQuery1->Close();
FDQuery1->Open();
MessageDlg("Eliminare cu succes!",mtInformation, TMsgDlgButtons()<<mbOK,0);
            }
}
//---------------------------------------------------------------------------







void __fastcall TForm1::CheckBox6Click(TObject *Sender)
{
if(CheckBox6->Checked) //afiseaza doar datorinicii
{
	AnsiString s;
    s="SELECT CL.NUME+' '+CL.PRENUME AS CLIENT,";
s+="       c.nume_categorie,";
s+="	   OP.NUME+' '+OP.PRENUME AS OPERATOR,";
s+="	   SUMA_ACHITARE-GAJ AS RAMAS,";
s+="	   P.NUME_PRODUS, I.*, CL.*, C.*, P.* ";
s+="          FROM CLIENT CL INNER JOIN IMPRUMUT I ON CL.CLIENT_ID=I.CLIENT_ID";
s+="                INNER JOIN OPERATOR OP ON OP.OPERATOR_ID=I.OPERATOR_ID";
s+="               INNER JOIN PRODUS P ON P.PRODUS_ID=I.PRODUS_ID ";
s+="               INNER JOIN CATEGORIE C ON C.CATEGORIE_ID=P.CATEGORIE_ID ";
s+="          WHERE (SUMA_ACHITARE-GAJ)>0";

	 QCAUTA->Close();
 QCAUTA->SQL->Clear();
 QCAUTA->SQL->Add(s);
 QCAUTA->Open();
 FDQuery1->Close();
FDQuery1->Open();

}
}
//---------------------------------------------------------------------------


