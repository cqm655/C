//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Project1PCH1.h"
#include "dm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int p_id=1,p_idciz=1, m_id=1,m_idciz=1,c_id=1,c_idciz=1, tip_id=1, tip_idciz=1;
int pm_id=1, pm_idciz=1, mm_id=1,mm_idciz=1,cm_id=1,cm_idciz=1, tipm_id=1, tipm_idciz=1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm1::SplitView1MouseEnter(TObject *Sender)
{ if(SplitView1->Opened)SplitView1->Close();
else SplitView1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{

	TabSheet1->TabVisible=1;
	depozit->TabVisible=0;
	magazin->TabVisible=0;
	SplitView1->Open();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
	if(Edit1->Text!="" && Edit2->Text!="")
	{
	 dm1->qgol->Close();
	 dm1->qgol->SQL->Clear();
	 dm1->qgol->SQL->Add("select * from Autentificare where Username=:username and Password=:password ");
	 dm1->qgol->ParamByName("username")->AsString=Edit1->Text;
	 dm1->qgol->ParamByName("password")->AsString=Edit2->Text;
	 dm1->qgol->Open();

	   if(!dm1->qgol->IsEmpty())
	   {
		switch(dm1->qgol->FieldByName("Tip_Acces")->AsInteger)
			  {
				  case 1: //admin
				  {

                   	TabSheet1->TabVisible=0;
					depozit->TabVisible=1;
					magazin->TabVisible=1;
					SplitView1->Close();
					//////
					Pantofi->TabVisible=false;
Cizme->TabVisible=false;

MPantofi->TabVisible=false;
MCizme->TabVisible=false;

SplitView4->Visible=false;
SplitView5->Visible=false;
svadauga->Visible=false;

MTip->TabVisible=false;
MCuloare->TabVisible=false;
MMAterial->TabVisible=false;

MGPantof->TabVisible=false;
MGCizme->TabVisible=false;



DT->Date.CurrentDate();   //now
DT1->Date.CurrentDate();  //now



				  break;
				  }
				  case 2:  //depozitar
				  {
				  SplitView1->Close();
				  magazin->TabVisible=false;
				  depozit->TabVisible=true;
				  TabSheet1->TabVisible=false;
				  MTip->TabVisible=false;
				  MCuloare->TabVisible=false;
				  MMAterial->TabVisible=false;
				  Pantofi->TabVisible=false;
				  Cizme->TabVisible=false;

				  MPantofi->TabVisible=false;
				  MCizme->TabVisible=false;

SplitView4->Visible=false;
SplitView5->Visible=false;
svadauga->Visible=false;


MGPantof->TabVisible=false;
MGCizme->TabVisible=false;


				  break;
				  }
				  default:  // vanzator
				  {
				  SplitView1->Close();
				  magazin->TabVisible=true;
				  depozit->TabVisible=false;
				  TabSheet1->TabVisible=false;
				  MTip->TabVisible=false;
				  MCuloare->TabVisible=false;
				  MMAterial->TabVisible=false;
				  Pantofi->TabVisible=false;
				  Cizme->TabVisible=false;

				  MPantofi->TabVisible=false;
				  MCizme->TabVisible=false;

SplitView4->Visible=false;
SplitView5->Visible=false;
svadauga->Visible=false;


MGPantof->TabVisible=false;
MGCizme->TabVisible=false;
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






////////////////////////////////////////////////////////////////////////////////////////
/*



 /*
if(Edit1->Text=="1" && Edit2->Text=="1")
{
	TabSheet1->TabVisible=0;
	depozit->TabVisible=1;
	magazin->TabVisible=1;
	SplitView1->Close();


}
else
{
ShowMessage("Parola sau Username GRESITE!");

}
*/
}
//---------------------------------------------------------------------------





void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
if(!SplitView1->Opened)
SplitView1->Open();
else SplitView1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SBafiseazaClick(TObject *Sender)
{
SplitView4->Open();
SplitView4->Visible=true;

if(SplitView5->Opened)
{
SplitView5->Close();
}
MTip->TabVisible=false;
MCuloare->TabVisible=false;
MMAterial->TabVisible=false;



}
//---------------------------------------------------------------------------

void __fastcall TForm1::SBmodificaClick(TObject *Sender)
{
SplitView5->Open();
SplitView5->Visible=true;
svadauga->Close();

if(SplitView4->Opened)
{
SplitView4->Close();
}
MTip->TabVisible=false;
MCuloare->TabVisible=false;
MMAterial->TabVisible=false;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::SBadaugaClick(TObject *Sender)
{
SplitView4->Close();
SplitView5->Close();
svadauga->Open();
svadauga->Visible=true;
MTip->TabVisible=false;
MCuloare->TabVisible=false;
MMAterial->TabVisible=false;





}
//---------------------------------------------------------------------------






void __fastcall TForm1::SpeedButton12Click(TObject *Sender)
{

Cizme->TabVisible=true;
Pantofi->TabVisible=false;
MCizme->TabVisible=false;
MPantofi->TabVisible=false;



if(SplitView1->Opened==true)
{

 SplitView1->Close();
 SplitView4->Close();

}
else
{

SplitView4->Close();

}

dm1->qshowiarna->Close();
dm1->qshowiarna->Open();


AnsiString s;
s=" SELECT SUM(M39)+SUM(M40)+SUM(M41)+SUM(M42)+SUM(m43)+SUM(m44)+SUM(m45) AS SUMA FROM PANTOF p ";
s+=" inner join sezon s on s.sezon_id=p.sezon_id ";
s+=" where s.sezon='IARNA' and ACTIV=1 ";
dm1->qliber->Close();
dm1->qliber->SQL->Clear();
dm1->qliber->SQL->Add(s);
dm1->qliber->Open();
Ltotalafisciz->Caption=dm1->qliber->FieldByName("SUMA")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton13Click(TObject *Sender)
{


Cizme->TabVisible=false;
Pantofi->TabVisible=true;
MCizme->TabVisible=false;
MPantofi->TabVisible=false;



dm1->qshow->Close();
dm1->qshow->Open();



if(SplitView1->Opened==true)
{
 SplitView1->Close();
 SplitView4->Close();
}
else
{
SplitView4->Close();
}

AnsiString s;
s=" SELECT SUM(M39)+SUM(M40)+SUM(M41)+SUM(M42)+SUM(m43)+SUM(m44)+SUM(m45) AS SUMA FROM PANTOF p ";
s+=" inner join sezon s on s.sezon_id=p.sezon_id ";
s+=" where s.sezon='VARA' and ACTIV=1 ";
dm1->qliber->Close();
dm1->qliber->SQL->Clear();
dm1->qliber->SQL->Add(s);
dm1->qliber->Open();
Ltotalafis->Caption=dm1->qliber->FieldByName("SUMA")->AsString;



}
//---------------------------------------------------------------------------



void __fastcall TForm1::SpeedButton15Click(TObject *Sender)
{
Cizme->TabVisible=false;
Pantofi->TabVisible=false;
MCizme->TabVisible=false;
MPantofi->TabVisible=true;


SpeedButton21->Enabled=false;
SpeedButton16->Enabled=true;



dm1->qshow->Close();
dm1->qshow->Open();

SplitView5->Close();


GroupBox1->Visible=false;
GroupBox1->Caption="Modifica Pantofi";
Edit3->Clear();
Edit4->Clear();
Edit5->Clear();
Edit6->Clear();
Edit7->Clear();
Edit8->Clear();
Edit9->Clear();
Edit10->Clear();
Edit11->Clear();
Edit12->Clear();
Edit13->Clear();
Edit14->Clear();


}
//---------------------------------------------------------------------------

void __fastcall TForm1::DBGrid3DblClick(TObject *Sender)
{
GroupBox1->Visible=true;

p_id=dm1->qshow->FieldByName("pantof_id")->AsInteger;

Edit3->Text=dm1->qshow->FieldByName("tip")->AsString;
tip_id=dm1->qshow->FieldByName("indice_grupa_id")->AsInteger;

Edit4->Text=dm1->qshow->FieldByName("Model")->AsString;

Edit5->Text=dm1->qshow->FieldByName("Material")->AsString;
m_id=dm1->qshow->FieldByName("MATERIAL_ID")->AsInteger;

Edit6->Text=dm1->qshow->FieldByName("culoare")->AsString;
c_id=dm1->qshow->FieldByName("CULOARE_ID")->AsInteger;

Edit7->Text=dm1->qshow->FieldByName("39")->AsInteger;

Edit8->Text=dm1->qshow->FieldByName("40")->AsInteger;

Edit9->Text=dm1->qshow->FieldByName("41")->AsInteger;

Edit10->Text=dm1->qshow->FieldByName("42")->AsInteger;

Edit11->Text=dm1->qshow->FieldByName("43")->AsInteger;

Edit12->Text=dm1->qshow->FieldByName("44")->AsInteger;

Edit13->Text=dm1->qshow->FieldByName("45")->AsInteger;

Edit14->Text=dm1->qshow->FieldByName("Pret")->AsInteger;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton14Click(TObject *Sender)
{
Cizme->TabVisible=false;
Pantofi->TabVisible=false;
MCizme->TabVisible=true;
MPantofi->TabVisible=false;


SpeedButton22->Enabled=true;
SpeedButton25->Enabled=false;

SplitView5->Close();

dm1->qshowiarna->Close();
dm1->qshowiarna->Open();

GroupBox2->Visible=false;
GroupBox1->Caption="Modifica Cizme";

 Edit18->Clear();
 Edit19->Clear();
 Edit20->Clear();
 Edit21->Clear();
 Edit22->Clear();
 Edit23->Clear();
 Edit24->Clear();
 Edit25->Clear();
 Edit26->Clear();
 Edit15->Clear();
 Edit16->Clear();
 Edit17->Clear();


}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton17Click(TObject *Sender)
{

Edit50->Clear();
Edit39->Clear();
Edit40->Clear();
Edit41->Clear();
Edit42->Clear();
Edit43->Clear();
Edit44->Clear();
Edit45->Clear();
Edit46->Clear();
Edit47->Clear();
Edit48->Clear();
Edit49->Clear();


dm1->qsi->Close();
dm1->qsi->Open();


}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton16Click(TObject *Sender)
{

dm1->qedit->Close();
dm1->qedit->ParamByName("Model")->AsString=Edit4->Text;
dm1->qedit->ParamByName("INDICE_GRUPA_ID")->AsInteger=tip_id;
dm1->qedit->ParamByName("material_id")->AsInteger=m_id;
dm1->qedit->ParamByName("CULOARE_ID")->AsInteger=c_id;
dm1->qedit->ParamByName("m39")->AsInteger=Edit7->Text.ToInt();
dm1->qedit->ParamByName("m40")->AsInteger=Edit8->Text.ToInt();
dm1->qedit->ParamByName("m41")->AsInteger=Edit9->Text.ToInt();
dm1->qedit->ParamByName("m42")->AsInteger=Edit10->Text.ToInt();
dm1->qedit->ParamByName("m43")->AsInteger=Edit11->Text.ToInt();
dm1->qedit->ParamByName("m44")->AsInteger=Edit12->Text.ToInt();
dm1->qedit->ParamByName("m45")->AsInteger=Edit13->Text.ToInt();
dm1->qedit->ParamByName("pret")->AsInteger=Edit14->Text.ToInt();
dm1->qedit->ParamByName("pantof_id")->AsInteger=p_id;
dm1->qedit->ExecSQL();

ShowMessage("Modificare cu succes!");

dm1->qshow->Close();
dm1->qshow->Open();

GroupBox1->Visible=false;
Edit3->Clear();
Edit4->Clear();
Edit5->Clear();
Edit6->Clear();
Edit7->Clear();
Edit8->Clear();
Edit9->Clear();
Edit10->Clear();
Edit11->Clear();
Edit12->Clear();
Edit13->Clear();
Edit14->Clear();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Click(TObject *Sender)
{
Edit3->Clear();
Edit26->Clear();
MTip->TabVisible=true;
MPantofi->TabVisible=false;
MCizme->TabVisible=false;

dm1->qtip->Close();
dm1->qtip->Open();
a=1;

}
//---------------------------------------------------------------------------



void __fastcall TForm1::DBGrid5DblClick(TObject *Sender)
{

Edit3->Clear();
Edit26->Clear();
Edit38->Clear();
Edit50->Clear();

   if(dm1->qtip->FieldByName("INDICE_GRUPA_ID")->AsInteger==4 ||
	  dm1->qtip->FieldByName("INDICE_GRUPA_ID")->AsInteger==5)
   {
	tip_idciz=dm1->qtip->FieldByName("INDICE_GRUPA_ID")->AsInteger;
	Edit26->Text=dm1->qtip->FieldByName("INDICE_GRUPA")->AsString;
	tipm_idciz=dm1->qtip->FieldByName("INDICE_GRUPA_ID")->AsInteger;
	Edit50->Text=dm1->qtip->FieldByName("INDICE_GRUPA")->AsString;
   }
   else
   {
	tip_id=dm1->qtip->FieldByName("INDICE_GRUPA_ID")->AsInteger;
	Edit3->Text=dm1->qtip->FieldByName("INDICE_GRUPA")->AsString;
	tipm_id=dm1->qtip->FieldByName("INDICE_GRUPA_ID")->AsInteger;
	Edit38->Text=dm1->qtip->FieldByName("INDICE_GRUPA")->AsString;
   }

MMAterial->TabVisible=false;
MCizme->TabVisible=false;
MGCizme->TabVisible=false;
MGPantof->TabVisible=false;

switch(a)
{
	case 1:  MPantofi->TabVisible=true; break;
	case 2:  MCizme->TabVisible=true;  break;
	case 3:  MGPantof->TabVisible=true; magazin->TabVisible=true; depozit->TabVisible=false; break;
	case 4:  MGCizme->TabVisible=true; magazin->TabVisible=true; depozit->TabVisible=false; break;
}
MTip->TabVisible=false;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::DBGrid6DblClick(TObject *Sender)
{

Edit5->Clear();
Edit16->Clear();


Edit40->Clear();
Edit28->Clear();

m_id=dm1->qmaterial->FieldByName("Material_id")->AsInteger;
m_idciz=dm1->qmaterial->FieldByName("Material_id")->AsInteger;

Edit5->Text=dm1->qmaterial->FieldByName("Material")->AsString;
Edit16->Text=dm1->qmaterial->FieldByName("Material")->AsString;

mm_id=dm1->qmaterial->FieldByName("Material_id")->AsInteger;
mm_idciz=dm1->qmaterial->FieldByName("Material_id")->AsInteger;

Edit28->Text=dm1->qmaterial->FieldByName("Material")->AsString;
Edit40->Text=dm1->qmaterial->FieldByName("Material")->AsString;

MMAterial->TabVisible=false;
MCizme->TabVisible=false;
MGCizme->TabVisible=false;
MGPantof->TabVisible=false;
switch(a)
{
	case 1:  MPantofi->TabVisible=true; break;
	case 2:  MCizme->TabVisible=true;  break;
    case 3:  MGPantof->TabVisible=true; magazin->TabVisible=true; depozit->TabVisible=false; break;
	case 4:  MGCizme->TabVisible=true; magazin->TabVisible=true; depozit->TabVisible=false; break;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit5Click(TObject *Sender)
{
Edit5->Clear();

MPantofi->TabVisible=false;
MMAterial->TabVisible=true;
MCizme->TabVisible=false;

dm1->qmaterial->Close();
dm1->qmaterial->Open();
a=1;
}

//---------------------------------------------------------------------------



void __fastcall TForm1::DBGrid7DblClick(TObject *Sender)
{


Edit6->Clear();
Edit17->Clear();

Edit29->Clear();
Edit41->Clear();

c_id=dm1->qculoare->FieldByName("CULOARE_ID")->AsInteger;
c_idciz=dm1->qculoare->FieldByName("CULOARE_ID")->AsInteger;

cm_id=dm1->qculoare->FieldByName("CULOARE_ID")->AsInteger;
cm_idciz=dm1->qculoare->FieldByName("CULOARE_ID")->AsInteger;

Edit6->Text=dm1->qculoare->FieldByName("CULOARE")->AsString;
Edit17->Text=dm1->qculoare->FieldByName("CULOARE")->AsString;

Edit29->Text=dm1->qculoare->FieldByName("CULOARE")->AsString;
Edit41->Text=dm1->qculoare->FieldByName("CULOARE")->AsString;

MCuloare->TabVisible=false;
MPantofi->TabVisible=false;
MMAterial->TabVisible=false;
MCizme->TabVisible=false;
MGCizme->TabVisible=false;
MGPantof->TabVisible=false;

switch(a)
{
	case 1:  MPantofi->TabVisible=true; break;
	case 2:  MCizme->TabVisible=true;  break;
    case 3:  MGPantof->TabVisible=true; magazin->TabVisible=true; depozit->TabVisible=false; break;
	case 4:  MGCizme->TabVisible=true; magazin->TabVisible=true; depozit->TabVisible=false; break;
}
MCuloare->TabVisible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit6Click(TObject *Sender)
{
Edit6->Clear();
MCuloare->TabVisible=true;
MPantofi->TabVisible=false;

dm1->qculoare->Close();
dm1->qculoare->Open();
}
//---------------------------------------------------------------------------






void __fastcall TForm1::SpeedButton18Click(TObject *Sender)
{
AnsiString s;

s=" UPDATE  PANTOF SET ACTIV=0 WHERE PANTOF_ID=:PANTOF_ID ";

dm1->qgol->Close();
dm1->qgol->SQL->Clear();
dm1->qgol->SQL->Add(s);

dm1->qgol->ParamByName("PANTOF_ID")->AsInteger=p_id;

dm1->qgol->ExecSQL();

dm1->qshow->Close();
dm1->qshow->Open();

GroupBox2->Visible=false;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::SpeedButton19Click(TObject *Sender)
{
svadauga->Close();
MPantofi->TabVisible=true;
MCizme->TabVisible=false;
GroupBox1->Visible=true;
Pantofi->TabVisible=false;
Cizme->TabVisible=false;


SpeedButton16->Enabled=false;
SpeedButton16->Hint="Doar adaugare sau anulare";
SpeedButton18->Enabled=false;
SpeedButton18->Hint="Doar adaugare sau anulare";

dm1->qshow->Close();
dm1->qshow->Open();

GroupBox1->Caption="Adauga Pantofi";
Edit3->Clear();
Edit4->Clear();
Edit5->Clear();
Edit6->Clear();
Edit7->Clear();
Edit8->Clear();
Edit9->Clear();
Edit10->Clear();
Edit11->Clear();
Edit12->Clear();
Edit13->Clear();
Edit14->Clear();
a=1;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton20Click(TObject *Sender)
{

svadauga->Close();
MCizme->TabVisible=true;
MPantofi->TabVisible=false;
Pantofi->TabVisible=false;
Cizme->TabVisible=false;


GroupBox2->Visible=true;
SpeedButton22->Enabled=true;

SpeedButton22->Enabled=false;
SpeedButton22->Hint="Doar adaugare sau anulare";
SpeedButton24->Enabled=false;
SpeedButton24->Hint="Doar adaugare sau anulare";
SpeedButton25->Enabled=true;

dm1->qshowiarna->Close();
dm1->qshowiarna->Open();

GroupBox1->Caption="Modifica Cizme";
 Edit18->Clear();
 Edit19->Clear();
 Edit20->Clear();
 Edit21->Clear();
 Edit22->Clear();
 Edit23->Clear();
 Edit24->Clear();
 Edit25->Clear();
 Edit26->Clear();
 Edit15->Clear();
 Edit16->Clear();
 Edit17->Clear();


a=2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton21Click(TObject *Sender)
{
dm1->qsi->Close();
dm1->qsi->Open();
AnsiString s;

if(Edit50->Text!="" &&
Edit39->Text!="" &&
Edit40->Text!="" &&
Edit41->Text!="" &&
Edit42->Text!="")
{
s+="SELECT p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.model as Model,m.material_id, m.MATERIAL as Material, ";
s+="       c.culoare_id, c.CULOARE as culoare, ";
s+="      p.m39 as [39],p.m40 as [40], p.m41 as [41],p.m42 as [42], p.m43 as [43],p.m44 as [44],p.m45 as [45], ";
s+="	   p.PRET, id.Magazin  ";
s+="        FROM PANTOF P ";
s+="		INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDICE_GRUPA_ID ";
s+="	INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID ";
s+="	INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID ";
s+="	INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID ";
s+="    INNER JOIN Indice_Spatiu id on id.Indice_Spatiu_ID=p.indice_spatiu_ID  ";
s+="	WHERE S.SEZON='IARNA'  and p.activ=1  ";
s+="    and id.Indice_Spatiu_ID=:Indice_Spatiu_ID ";
s+="    and p.Model=:Model and ig.INDICE_GRUPA_ID=:INDICE_GRUPA_ID ";
s+="    and m.MATERIAL_ID=:MATERIAL_ID and c.CULOARE_ID=:CULOARE_ID ";



 dm1->qgol->Close();
 dm1->qgol->SQL->Clear();
 dm1->qgol->SQL->Add(s);

dm1->qgol->ParamByName("Indice_Spatiu_ID")->AsInteger=1;
dm1->qgol->ParamByName("Model")->AsString=Edit39->Text;
dm1->qgol->ParamByName("INDICE_GRUPA_ID")->AsInteger=tipm_idciz;
dm1->qgol->ParamByName("MATERIAL_ID")->AsInteger=mm_idciz;
dm1->qgol->ParamByName("CULOARE_ID")->AsInteger=cm_idciz;




///////VERIFICARE LA ACELEASI INREGISTRARI/////////////////////////////////////
s+=" SELECT p.*, c.*, ig.*, m.*, id.* ";
s+="        FROM PANTOF P ";
s+="		INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDICE_GRUPA_ID ";
s+="	INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID ";
s+="	INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID ";
s+="	INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID ";
s+="    INNER JOIN Indice_Spatiu id on id.Indice_Spatiu_ID=P.Indice_spatiu_ID ";
s+="	WHERE S.SEZON='Iarna' and p.activ=1 ";
s+="    and  p.model=:model and ";
s+="    id.Indice_Spatiu_ID=:Indice_Spatiu_ID and ";
s+="    ig.indice_grupa_id=:indice_grupa_id and ";
s+="    c.culoare_id=:culoare_id and m.material_id=:material_id ";

dm1->qgol2->Close();
dm1->qgol2->SQL->Clear();
dm1->qgol2->SQL->Add(s);
dm1->qgol2->ParamByName("Indice_Spatiu_ID")->AsInteger=1;
dm1->qgol2->ParamByName("Model")->AsString=Edit39->Text;
dm1->qgol2->ParamByName("indice_grupa_id")->AsInteger=tipm_idciz;
dm1->qgol2->ParamByName("material_id")->AsInteger=mm_idciz;
dm1->qgol2->ParamByName("culoare_id")->AsInteger=cm_idciz;
dm1->qgol2->Open();
if(dm1->qgol2->IsEmpty())
{
 s=" INSERT INTO PANTOF(Indice_Spatiu_ID,INDICE_GRUPA_ID,Model,MATERIAL_ID,CULOARE_ID,M39,M40,M41,M42,m43,m44,m45,PRET, SEZON_ID) ";
 s+=" VALUES(:Indice_Spatiu_ID,:INDICE_GRUPA_ID,:Model,:MATERIAL_ID,:CULOARE_ID,:M39,:M40,:M41,:M42,:m43,:m44,:m45,:PRET,:SEZON_ID)";

 dm1->qgol->Close();
 dm1->qgol->SQL->Clear();
 dm1->qgol->SQL->Add(s);
 dm1->qgol->ParamByName("Indice_Spatiu_ID")->AsInteger=1;
 dm1->qgol->ParamByName("SEZON_ID")->AsInteger=1;  ///sezon iarna
 dm1->qgol->ParamByName("Model")->AsString=Edit39->Text;
 dm1->qgol->ParamByName("INDICE_GRUPA_ID")->AsInteger=tipm_idciz;
 dm1->qgol->ParamByName("MATERIAL_ID")->AsInteger=mm_idciz;
 dm1->qgol->ParamByName("CULOARE_ID")->AsInteger=cm_idciz;
 dm1->qgol->ParamByName("M39")->AsInteger=Edit42->Text.ToInt();
 dm1->qgol->ParamByName("M40")->AsInteger=Edit43->Text.ToInt();
 dm1->qgol->ParamByName("M41")->AsInteger=Edit44->Text.ToInt();
 dm1->qgol->ParamByName("M42")->AsInteger=Edit45->Text.ToInt();
 dm1->qgol->ParamByName("m43")->AsInteger=Edit46->Text.ToInt();
 dm1->qgol->ParamByName("m44")->AsInteger=Edit47->Text.ToInt();
 dm1->qgol->ParamByName("m45")->AsInteger=Edit48->Text.ToInt();
 dm1->qgol->ParamByName("PRET")->AsInteger=Edit49->Text.ToInt();
}
else /////facem actualizare daca avem deja acest produs
{   if (MessageDlg("Asemenea produs exista, actualizati informatia?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)

	{
	s=" update pantof set M39=M39+ :M39,M40=M40+ :M40,M41=M41+ :M41,M42=M42+ :M42, ";
	s+=" m43=m43+ :m43,m44=m44+ :m44,m45=m45+ :m45,PRET=:PRET ";
	s+=" where pantof_id=:pantof_id ";

	dm1->qgol->Close();
	dm1->qgol->SQL->Clear();
	dm1->qgol->SQL->Add(s);
	dm1->qgol->ParamByName("pantof_id")->AsInteger=dm1->qgol2->FieldByName("pantof_id")->AsInteger;
 dm1->qgol->ParamByName("M39")->AsInteger=Edit42->Text.ToInt();
 dm1->qgol->ParamByName("M40")->AsInteger=Edit43->Text.ToInt();
 dm1->qgol->ParamByName("M41")->AsInteger=Edit44->Text.ToInt();
 dm1->qgol->ParamByName("M42")->AsInteger=Edit45->Text.ToInt();
 dm1->qgol->ParamByName("m43")->AsInteger=Edit46->Text.ToInt();
 dm1->qgol->ParamByName("m44")->AsInteger=Edit47->Text.ToInt();
 dm1->qgol->ParamByName("m45")->AsInteger=Edit48->Text.ToInt();
 dm1->qgol->ParamByName("PRET")->AsInteger=Edit49->Text.ToInt();
	}
	else
	{
Edit50->Clear();
Edit39->Clear();
Edit40->Clear();
Edit41->Clear();
Edit42->Clear();
Edit43->Clear();
Edit44->Clear();
Edit45->Clear();
Edit46->Clear();
Edit47->Clear();
Edit48->Clear();
Edit49->Clear();
    }

	}

dm1->qgol->ExecSQL();
ShowMessage("Adaugare cu Succes");
dm1->qsi->Close();
dm1->qsi->Open();


Edit50->Clear();
Edit39->Clear();
Edit40->Clear();
Edit41->Clear();
Edit42->Clear();
Edit43->Clear();
Edit44->Clear();
Edit45->Clear();
Edit46->Clear();
Edit47->Clear();
Edit48->Clear();
Edit49->Clear();
}
else
{
    ShowMessage("Nu ati completat campurile");
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DBGrid1DblClick(TObject *Sender)
{
dm1->qshow->Close();
dm1->qshow->Open();
}
//---------------------------------------------------------------------------







void __fastcall TForm1::Edit16Change(TObject *Sender)
{
a=2;

}
//---------------------------------------------------------------------------




void __fastcall TForm1::Edit26Click(TObject *Sender)
{
Edit3->Clear();

MTip->TabVisible=true;
MPantofi->TabVisible=false;
MCizme->TabVisible=false;

dm1->qtip->Close();
dm1->qtip->Open();
a=2;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Edit16Click(TObject *Sender)
{
Edit16->Clear();

MPantofi->TabVisible=false;
MMAterial->TabVisible=true;
MCizme->TabVisible=false;

dm1->qmaterial->Close();
dm1->qmaterial->Open();
a=2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit17Click(TObject *Sender)
{
Edit17->Clear();
MCuloare->TabVisible=true;
MPantofi->TabVisible=false;
MCizme->TabVisible=false;

dm1->qculoare->Close();
dm1->qculoare->Open();
a=2;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton25Click(TObject *Sender)
{
dm1->qshowiarna->Close();
dm1->qshowiarna->Open();
AnsiString s;

if(Edit26->Text!="" &&
Edit15->Text!="" &&
Edit16->Text!="" &&
Edit17->Text!="" )
{
s+="SELECT p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.model as Model,m.material_id, m.MATERIAL as Material, ";
s+="       c.culoare_id, c.CULOARE as culoare, ";
s+="      p.m39 as [39],p.m40 as [40], p.m41 as [41],p.m42 as [42], p.m43 as [43],p.m44 as [44],p.m45 as [45], ";
s+="	   p.PRET ";
s+="        FROM PANTOF P ";
s+="		INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDICE_GRUPA_ID ";
s+="	INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID ";
s+="	INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID ";
s+="	INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID ";
s+="	WHERE S.SEZON='iarna'  and p.activ=1 ";
s+="    and p.Model=:Model and ig.INDICE_GRUPA_ID=:INDICE_GRUPA_ID ";
s+="    and m.MATERIAL_ID=:MATERIAL_ID and c.CULOARE_ID=:CULOARE_ID ";

 dm1->qgol->Close();
 dm1->qgol->SQL->Clear();
 dm1->qgol->SQL->Add(s);

dm1->qgol->ParamByName("Model")->AsString=Edit4->Text;
dm1->qgol->ParamByName("INDICE_GRUPA_ID")->AsInteger=tip_idciz;
dm1->qgol->ParamByName("MATERIAL_ID")->AsInteger=m_idciz;
dm1->qgol->ParamByName("CULOARE_ID")->AsInteger=c_idciz;




///////VERIFICARE LA ACELEASI INREGISTRARI/////////////////////////////////////
s+=" SELECT p.*, c.*, ig.*, m.* ";
s+="        FROM PANTOF P ";
s+="		INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDICE_GRUPA_ID ";
s+="	INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID ";
s+="	INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID ";
s+="	INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID ";
s+="	WHERE S.SEZON='iarna' and p.activ=1 ";
s+="    and  p.model=:model and ";
s+="   ig.indice_grupa_id=:indice_grupa_id and ";
s+="    c.culoare_id=:culoare_id and m.material_id=:material_id ";

dm1->qgol2->Close();
dm1->qgol2->SQL->Clear();
dm1->qgol2->SQL->Add(s);
dm1->qgol2->ParamByName("Model")->AsString=Edit15->Text;
dm1->qgol2->ParamByName("indice_grupa_id")->AsInteger=tip_idciz;
dm1->qgol2->ParamByName("material_id")->AsInteger=m_idciz;
dm1->qgol2->ParamByName("culoare_id")->AsInteger=c_idciz;
dm1->qgol2->Open();
if(dm1->qgol2->IsEmpty())
{
 s=" INSERT INTO PANTOF(INDICE_GRUPA_ID,Model,MATERIAL_ID,CULOARE_ID,M39,M40,M41,M42,m43,m44,m45,PRET, SEZON_ID) ";
 s+=" VALUES(:INDICE_GRUPA_ID,:Model,:MATERIAL_ID,:CULOARE_ID,:M39,:M40,:M41,:M42,:m43,:m44,:m45,:PRET,:SEZON_ID)";

 dm1->qgol->Close();
 dm1->qgol->SQL->Clear();
 dm1->qgol->SQL->Add(s);
 dm1->qgol->ParamByName("SEZON_ID")->AsInteger=1;  ///sezon iarna
 dm1->qgol->ParamByName("Model")->AsString=Edit15->Text;
 dm1->qgol->ParamByName("INDICE_GRUPA_ID")->AsInteger=tip_idciz;
 dm1->qgol->ParamByName("MATERIAL_ID")->AsInteger=m_idciz;
 dm1->qgol->ParamByName("CULOARE_ID")->AsInteger=c_idciz;
 dm1->qgol->ParamByName("M39")->AsInteger=Edit18->Text.ToInt();
 dm1->qgol->ParamByName("M40")->AsInteger=Edit19->Text.ToInt();
 dm1->qgol->ParamByName("M41")->AsInteger=Edit20->Text.ToInt();
 dm1->qgol->ParamByName("M42")->AsInteger=Edit21->Text.ToInt();
 dm1->qgol->ParamByName("m43")->AsInteger=Edit22->Text.ToInt();
 dm1->qgol->ParamByName("m44")->AsInteger=Edit23->Text.ToInt();
 dm1->qgol->ParamByName("m45")->AsInteger=Edit24->Text.ToInt();
 dm1->qgol->ParamByName("PRET")->AsInteger=Edit25->Text.ToInt();

  Edit18->Clear();
 Edit19->Clear();
 Edit20->Clear();
 Edit21->Clear();
 Edit22->Clear();
 Edit23->Clear();
 Edit24->Clear();
 Edit25->Clear();
 Edit26->Clear();
 Edit15->Clear();
 Edit16->Clear();
 Edit17->Clear();
}
else
{
   if (MessageDlg("Asemenea produs exista, actualizati informatia?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)

	{
	s=" update pantof set M39=M39+ :M39,M40=M40+ :M40,M41=M41+ :M41,M42=M42+ :M42, ";
	s+=" m43=m43+ :m43,m44=m44+ :m44,m45=m45+ :m45,PRET=:PRET ";
	s+=" where pantof_id=:pantof_id ";
	dm1->qgol->Close();
	dm1->qgol->SQL->Clear();
	dm1->qgol->SQL->Add(s);
	dm1->qgol->ParamByName("pantof_id")->AsInteger=dm1->qgol2->FieldByName("pantof_id")->AsInteger;
 dm1->qgol->ParamByName("M39")->AsInteger=Edit18->Text.ToInt();
 dm1->qgol->ParamByName("M40")->AsInteger=Edit19->Text.ToInt();
 dm1->qgol->ParamByName("M41")->AsInteger=Edit20->Text.ToInt();
 dm1->qgol->ParamByName("M42")->AsInteger=Edit21->Text.ToInt();
 dm1->qgol->ParamByName("m43")->AsInteger=Edit22->Text.ToInt();
 dm1->qgol->ParamByName("m44")->AsInteger=Edit23->Text.ToInt();
 dm1->qgol->ParamByName("m45")->AsInteger=Edit24->Text.ToInt();
 dm1->qgol->ParamByName("PRET")->AsInteger=Edit25->Text.ToInt();
	}
	else
	{
      Edit18->Clear();
 Edit19->Clear();
 Edit20->Clear();
 Edit21->Clear();
 Edit22->Clear();
 Edit23->Clear();
 Edit24->Clear();
 Edit25->Clear();
 Edit26->Clear();
 Edit15->Clear();
 Edit16->Clear();
 Edit17->Clear();
    }

 Edit18->Clear();
 Edit19->Clear();
 Edit20->Clear();
 Edit21->Clear();
 Edit22->Clear();
 Edit23->Clear();
 Edit24->Clear();
 Edit25->Clear();
 Edit26->Clear();
 Edit15->Clear();
 Edit16->Clear();
 Edit17->Clear();
  dm1->qshowiarna->Close();
 dm1->qshowiarna->Open();
	}

dm1->qgol->ExecSQL();
 dm1->qshowiarna->Close();
 dm1->qshowiarna->Open();

ShowMessage("Adaugare cu Succes");
////////////////////////////////////
}
else
{
    ShowMessage("Nu ati completat campurile");
}


}
//---------------------------------------------------------------------------

void __fastcall TForm1::DBGrid4DblClick(TObject *Sender)
{
GroupBox2->Visible=true;

p_idciz=dm1->qshowiarna->FieldByName("pantof_id")->AsInteger;

Edit26->Text=dm1->qshowiarna->FieldByName("tip")->AsString;
tip_idciz=dm1->qshowiarna->FieldByName("indice_grupa_id")->AsInteger;

Edit15->Text=dm1->qshowiarna->FieldByName("model")->AsString;

Edit16->Text=dm1->qshowiarna->FieldByName("Material")->AsString;
m_idciz=dm1->qshowiarna->FieldByName("MATERIAL_ID")->AsInteger;

Edit17->Text=dm1->qshowiarna->FieldByName("culoare")->AsString;
c_idciz=dm1->qshowiarna->FieldByName("CULOARE_ID")->AsInteger;

Edit18->Text=dm1->qshowiarna->FieldByName("39")->AsInteger;

Edit19->Text=dm1->qshowiarna->FieldByName("40")->AsInteger;

Edit20->Text=dm1->qshowiarna->FieldByName("41")->AsInteger;

Edit21->Text=dm1->qshowiarna->FieldByName("42")->AsInteger;

Edit22->Text=dm1->qshowiarna->FieldByName("43")->AsInteger;

Edit23->Text=dm1->qshowiarna->FieldByName("44")->AsInteger;

Edit24->Text=dm1->qshowiarna->FieldByName("45")->AsInteger;

Edit25->Text=dm1->qshowiarna->FieldByName("Pret")->AsInteger;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton22Click(TObject *Sender)
{

dm1->qedit->Close();
dm1->qedit->ParamByName("Model")->AsString=Edit15->Text;
dm1->qedit->ParamByName("INDICE_GRUPA_ID")->AsInteger=tip_idciz;
dm1->qedit->ParamByName("material_id")->AsInteger=m_idciz;
dm1->qedit->ParamByName("CULOARE_ID")->AsInteger=c_idciz;
dm1->qedit->ParamByName("M39")->AsInteger=Edit18->Text.ToInt();
dm1->qedit->ParamByName("M40")->AsInteger=Edit19->Text.ToInt();
dm1->qedit->ParamByName("M41")->AsInteger=Edit20->Text.ToInt();
dm1->qedit->ParamByName("M42")->AsInteger=Edit21->Text.ToInt();
dm1->qedit->ParamByName("m43")->AsInteger=Edit22->Text.ToInt();
dm1->qedit->ParamByName("m44")->AsInteger=Edit23->Text.ToInt();
dm1->qedit->ParamByName("m45")->AsInteger=Edit24->Text.ToInt();
dm1->qedit->ParamByName("PRET")->AsInteger=Edit25->Text.ToInt();
dm1->qedit->ParamByName("pantof_id")->AsInteger=p_idciz;
dm1->qedit->ExecSQL();

ShowMessage("Modificare cu succes!");

dm1->qshowiarna->Close();
dm1->qshowiarna->Open();

GroupBox2->Visible=false;
Edit26->Clear();
Edit15->Clear();
Edit16->Clear();
Edit17->Clear();
Edit18->Clear();
Edit19->Clear();
Edit20->Clear();
Edit21->Clear();
Edit22->Clear();
Edit23->Clear();
Edit24->Clear();
Edit25->Clear();
}
//---------------------------------------------------------------------------











void __fastcall TForm1::ecautareChange(TObject *Sender)
{
dm1->qshowiarna->Close();
AnsiString s;
s+="SELECT p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.Model as Model,m.material_id, m.MATERIAL as Material, ";
s+="       c.culoare_id, c.CULOARE as culoare, ";
s+="      p.m39 as [39],p.m40 as [40], p.m41 as [41],p.m42 as [42], p.m43 as [43],p.m44 as [44],p.m45 as [45], ";
s+="	   p.PRET ";
s+="        FROM PANTOF P ";
s+="		INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDICE_GRUPA_ID ";
s+="	INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID ";
s+="	INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID ";
s+="	INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID ";
s+="	WHERE S.SEZON='iarna' and p.activ=1 ";
s+="    and p.Model like '"+ecautare->Text+"%' ";
s+="    order by p.model ";

dm1->qshowiarna->SQL->Clear();
dm1->qshowiarna->SQL->Add(s);
dm1->qshowiarna->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ecautarepantChange(TObject *Sender)
{
dm1->qshow->Close();
AnsiString s;
s+="SELECT p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.model as Model,m.material_id, m.MATERIAL as Material, ";
s+="       c.culoare_id, c.CULOARE as culoare, ";
s+="      p.m39 as [39],p.m40 as [40], p.m41 as [41],p.m42 as [42], p.m43 as [43],p.m44 as [44],p.m45 as [45], ";
s+="	   p.PRET ";
s+="        FROM PANTOF P ";
s+="		INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDICE_GRUPA_ID ";
s+="	INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID ";
s+="	INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID ";
s+="	INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID ";
s+="	WHERE S.SEZON='VARA'  and p.activ=1 ";
s+="    and p.model like '"+ecautarepant->Text+"%' ";
s+="    order by p.model ";

dm1->qshow->SQL->Clear();
dm1->qshow->SQL->Add(s);
dm1->qshow->Open();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::DTshow2Click(TObject *Sender)
{
AnsiString s;
s+="SELECT p.data,p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.model as Model,m.material_id, m.MATERIAL as Material, ";
s+="       c.culoare_id, c.CULOARE as culoare, ";
s+="      p.M39 as [39],p.M40 as [40], p.M41 as [41],p.m42 as [42], p.m43 as [43],p.m44 as [44],p.m45 as [45], ";
s+="	   p.PRET ";
s+="        FROM PANTOF P ";
s+="		INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDICE_GRUPA_ID ";
s+="	INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID ";
s+="	INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID ";
s+="	INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID ";
s+="	WHERE S.SEZON='iarna' and p.data=:data ";
if(CBintrariIarna->Checked)
s+="  and p.activ=1 ";
if(CBelimIarna->Checked)
s+="  and p.activ=0 ";

dm1->qshowiarna->Close();
dm1->qshowiarna->SQL->Clear();
dm1->qshowiarna->SQL->Add(s);
dm1->qshowiarna->ParamByName("data")->AsDate=DTshow2->Date;

dm1->qshowiarna->Open();


}
//---------------------------------------------------------------------------

void __fastcall TForm1::RBintrariClick(TObject *Sender)
{
DTshow->Enabled=true;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::RBeliminariClick(TObject *Sender)
{
DTshow->Enabled=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton24Click(TObject *Sender)
{
AnsiString s;

s=" UPDATE  PANTOF SET ACTIV=0 WHERE PANTOF_ID=:PANTOF_ID ";

dm1->qgol->Close();
dm1->qgol->SQL->Clear();
dm1->qgol->SQL->Add(s);

dm1->qgol->ParamByName("PANTOF_ID")->AsInteger=p_idciz;

dm1->qgol->ExecSQL();

dm1->qshowiarna->Close();
dm1->qshowiarna->Open();

GroupBox2->Visible=false;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Edit4Change(TObject *Sender)
{
dm1->qshow->Close();
AnsiString s;
s+="SELECT p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.model as Model,m.material_id, m.MATERIAL as Material, ";
s+="       c.culoare_id, c.CULOARE as culoare, ";
s+="      p.m39 as [39],p.m40 as [40], p.m41 as [41],p.m42 as [42], p.m43 as [43],p.m44 as [44],p.m45 as [45], ";
s+="	   p.PRET ";
s+="        FROM PANTOF P ";
s+="		INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDICE_GRUPA_ID ";
s+="	INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID ";
s+="	INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID ";
s+="	INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID ";
s+="	WHERE S.SEZON='VARA'  and p.activ=1 ";
s+="    and p.model like '"+Edit4->Text+"%' ";
s+="    order by p.model ";

dm1->qshow->SQL->Clear();
dm1->qshow->SQL->Add(s);
dm1->qshow->Open();
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Edit15Change(TObject *Sender)
{
dm1->qshowiarna->Close();
AnsiString s;
s+="SELECT p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.model as Model,m.material_id, m.MATERIAL as Material, ";
s+="       c.culoare_id, c.CULOARE as culoare, ";
s+="      p.m39 as [39],p.m40 as [40], p.m41 as [41],p.m42 as [42], p.m43 as [43],p.m44 as [44],p.m45 as [45], ";
s+="	   p.PRET ";
s+="        FROM PANTOF P ";
s+="		INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDICE_GRUPA_ID ";
s+="	INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID ";
s+="	INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID ";
s+="	INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID ";
s+="	WHERE S.SEZON='iarna'  and p.activ=1 ";
s+="    and p.model like '"+Edit15->Text+"%' ";
s+="    order by p.model ";

dm1->qshowiarna->SQL->Clear();
dm1->qshowiarna->SQL->Add(s);
dm1->qshowiarna->Open();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::SpeedButton23Click(TObject *Sender)
{
GroupBox2->Visible=false;
Edit26->Clear();
Edit15->Clear();
Edit16->Clear();
Edit17->Clear();
Edit18->Clear();
Edit19->Clear();
Edit20->Clear();
Edit21->Clear();
Edit22->Clear();
Edit22->Clear();
Edit23->Clear();
Edit24->Clear();
Edit25->Clear();

dm1->qshowiarna->Close();
dm1->qshowiarna->Open();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::CBintrariIarnaClick(TObject *Sender)
{
if(CBintrariIarna->Checked)
{
DTshow2->Enabled=true;
CBelimIarna->Checked=false;
}
else
{
DTshow2->Enabled=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CBelimIarnaClick(TObject *Sender)
{
if(CBelimIarna->Checked)
{
DTshow2->Enabled=true;
CBintrariIarna->Checked=false;
}
else
{
DTshow2->Enabled=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CBintrariClick(TObject *Sender)
{
if(CBintrari->Checked)
{
DTshow->Enabled=true;

CBelim->Checked=false;
}
else
{
DTshow->Enabled=false;
}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------







void __fastcall TForm1::RBPANTOFIClick(TObject *Sender)
{
if(RBPANTOFI->Checked)
{
Panel8->Visible=false;
Panel5->Visible=false;
RBCIZME->Checked=false;
MGPantof->TabVisible=true;
MGCizme->TabVisible=false;
GroupBox3->Visible=true;
GroupBox4->Visible=false;

SpeedButton26->Enabled=false;
SpeedButton9->Enabled=true;
SpeedButton11->Enabled=true;

Edit38->Clear();
Edit27->Clear();
Edit28->Clear();
Edit29->Clear();
Edit30->Clear();
Edit31->Clear();
Edit32->Clear();
Edit33->Clear();
Edit34->Clear();
Edit35->Clear();
Edit36->Clear();
Edit37->Clear();

Edit50->Clear();
Edit39->Clear();
Edit40->Clear();
Edit41->Clear();
Edit42->Clear();
Edit43->Clear();
Edit44->Clear();
Edit45->Clear();
Edit46->Clear();
Edit47->Clear();
Edit48->Clear();
Edit49->Clear();
dm1->qsp->Close();
dm1->qsp->Open();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RBCIZMEClick(TObject *Sender)
{
if(RBCIZME->Checked)
{
Panel8->Visible=false;
Panel5->Visible=false;
RBPANTOFI->Checked=false;
MGCizme->TabVisible=true;
MGPantof->TabVisible=false;
GroupBox3->Visible=false;
GroupBox4->Visible=true;

SpeedButton30->Enabled=false;
SpeedButton27->Enabled=true;
SpeedButton29->Enabled=true;

Edit38->Clear();
Edit27->Clear();
Edit28->Clear();
Edit29->Clear();
Edit30->Clear();
Edit31->Clear();
Edit32->Clear();
Edit33->Clear();
Edit34->Clear();
Edit35->Clear();
Edit36->Clear();
Edit37->Clear();

Edit50->Clear();
Edit39->Clear();
Edit40->Clear();
Edit41->Clear();
Edit42->Clear();
Edit43->Clear();
Edit44->Clear();
Edit45->Clear();
Edit46->Clear();
Edit47->Clear();
Edit48->Clear();
Edit49->Clear();
dm1->qsi->Close();
dm1->qsi->Open();
}
}
//---------------------------------------------------------------------------





void __fastcall TForm1::SpeedButton5Click(TObject *Sender)
{

MGCizme->TabVisible=false;
MGPantof->TabVisible=false;
GroupBox3->Visible=false;
GroupBox4->Visible=false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
MGPantof->TabVisible=true;
MGCizme->TabVisible=false;


RBPANTOFI->Checked=false;
RBAPANTOF->Checked=false;
RBCIZME->Checked=false;
RBACIZME->Checked=false;

GroupBox3->Visible=false;

Panel5->Visible=true;
Panel5->Top=3;
Panel5->Left=506;

AnsiString s;
s=" SELECT SUM(M39)+SUM(M40)+SUM(M41)+SUM(M42)+SUM(m43)+SUM(m44)+SUM(m45) AS SUMA FROM PANTOF p ";
s+=" inner join sezon s on s.sezon_id=p.sezon_id ";
s+=" INNER JOIN Indice_Spatiu ip on ip.Indice_Spatiu_ID=P.Indice_Spatiu_ID ";
s+=" where s.sezon='VARA' and ACTIV=1 ";
dm1->qliber->Close();
dm1->qliber->SQL->Clear();
dm1->qliber->SQL->Add(s);
dm1->qliber->Open();
Label61->Caption=dm1->qliber->FieldByName("SUMA")->AsString;

dm1->qsp->Close();
dm1->qsp->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
MGPantof->TabVisible=false;
MGCizme->TabVisible=true;

RBPANTOFI->Checked=false;
RBAPANTOF->Checked=false;
RBCIZME->Checked=false;
RBACIZME->Checked=false;

GroupBox4->Visible=false;

Panel8->Visible=true;
Panel8->Top=3;
Panel8->Left=510;

AnsiString s;
s=" SELECT SUM(M39)+SUM(M40)+SUM(M41)+SUM(M42)+SUM(m43)+SUM(m44)+SUM(m45) AS SUMA FROM PANTOF p ";
s+=" inner join sezon s on s.sezon_id=p.sezon_id ";
s+=" INNER JOIN Indice_Spatiu ip on ip.Indice_Spatiu_ID=P.Indice_Spatiu_ID ";
s+=" where s.sezon='IARNA' and ACTIV=1 ";
dm1->qliber->Close();
dm1->qliber->SQL->Clear();
dm1->qliber->SQL->Add(s);
dm1->qliber->Open();
Label64->Caption=dm1->qliber->FieldByName("SUMA")->AsString;

dm1->qsi->Close();
dm1->qsi->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RBAPANTOFClick(TObject *Sender)
{
if(RBAPANTOF->Checked)
{
Panel8->Visible=false;
RBACIZME->Checked=false;
RBPANTOFI->Checked=false;
MGPantof->TabVisible=true;
MGCizme->TabVisible=false;
GroupBox3->Visible=true;
GroupBox4->Visible=false;

SpeedButton9->Enabled=false;
SpeedButton26->Enabled=true;
SpeedButton11->Enabled=false;

Edit38->Clear();
Edit27->Clear();
Edit28->Clear();
Edit29->Clear();
Edit30->Clear();
Edit31->Clear();
Edit32->Clear();
Edit33->Clear();
Edit34->Clear();
Edit35->Clear();
Edit36->Clear();
Edit37->Clear();

Edit50->Clear();
Edit39->Clear();
Edit40->Clear();
Edit41->Clear();
Edit42->Clear();
Edit43->Clear();
Edit44->Clear();
Edit45->Clear();
Edit46->Clear();
Edit47->Clear();
Edit48->Clear();
Edit49->Clear();

Panel5->Visible=false;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::RBACIZMEClick(TObject *Sender)
{
if(RBACIZME->Checked)
{
Panel8->Visible=false;
Panel5->Visible=false;
RBAPANTOF->Checked=false;
RBCIZME->Checked=false;
MGPantof->TabVisible=false;
MGCizme->TabVisible=true;
GroupBox3->Visible=false;
GroupBox4->Visible=true;

SpeedButton27->Enabled=false;
SpeedButton30->Enabled=true;
SpeedButton29->Enabled=false;

Edit38->Clear();
Edit27->Clear();
Edit28->Clear();
Edit29->Clear();
Edit30->Clear();
Edit31->Clear();
Edit32->Clear();
Edit33->Clear();
Edit34->Clear();
Edit35->Clear();
Edit36->Clear();
Edit37->Clear();

Edit50->Clear();
Edit39->Clear();
Edit40->Clear();
Edit41->Clear();
Edit42->Clear();
Edit43->Clear();
Edit44->Clear();
Edit45->Clear();
Edit46->Clear();
Edit47->Clear();
Edit48->Clear();
Edit49->Clear();

}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::DBGrid10DblClick(TObject *Sender)
{
if(!dm1->qsp->IsEmpty())
{
pm_id=dm1->qsp->FieldByName("pantof_id")->AsInteger;
ShowMessage(pm_id);
Edit38->Text=dm1->qsp->FieldByName("tip")->AsString;
tipm_id=dm1->qsp->FieldByName("indice_grupa_id")->AsInteger;
Edit27->Text=dm1->qsp->FieldByName("Model")->AsString;
Edit28->Text=dm1->qsp->FieldByName("Material")->AsString;
mm_id=dm1->qsp->FieldByName("MATERIAL_ID")->AsInteger;
Edit29->Text=dm1->qsp->FieldByName("culoare")->AsString;
cm_id=dm1->qsp->FieldByName("CULOARE_ID")->AsInteger;
Edit30->Text=dm1->qsp->FieldByName("39")->AsInteger;
Edit31->Text=dm1->qsp->FieldByName("40")->AsInteger;
Edit32->Text=dm1->qsp->FieldByName("41")->AsInteger;
Edit33->Text=dm1->qsp->FieldByName("42")->AsInteger;
Edit34->Text=dm1->qsp->FieldByName("43")->AsInteger;
Edit35->Text=dm1->qsp->FieldByName("44")->AsInteger;
Edit36->Text=dm1->qsp->FieldByName("45")->AsInteger;
Edit37->Text=dm1->qsp->FieldByName("Pret")->AsInteger;
}
else
ShowMessage("nu sunt inregistrari");

}
//---------------------------------------------------------------------------

void __fastcall TForm1::DBGrid9DblClick(TObject *Sender)
{
if(!dm1->qsi->IsEmpty())
{
pm_idciz=dm1->qsi->FieldByName("pantof_id")->AsInteger;
Edit50->Text=dm1->qsi->FieldByName("tip")->AsString;
tipm_idciz=dm1->qsi->FieldByName("indice_grupa_id")->AsInteger;
Edit39->Text=dm1->qsi->FieldByName("Model")->AsString;
Edit40->Text=dm1->qsi->FieldByName("Material")->AsString;
mm_idciz=dm1->qsi->FieldByName("MATERIAL_ID")->AsInteger;
Edit41->Text=dm1->qsi->FieldByName("culoare")->AsString;
cm_idciz=dm1->qsi->FieldByName("CULOARE_ID")->AsInteger;
Edit42->Text=dm1->qsi->FieldByName("39")->AsInteger;
Edit43->Text=dm1->qsi->FieldByName("40")->AsInteger;
Edit44->Text=dm1->qsi->FieldByName("41")->AsInteger;
Edit45->Text=dm1->qsi->FieldByName("42")->AsInteger;
Edit46->Text=dm1->qsi->FieldByName("43")->AsInteger;
Edit47->Text=dm1->qsi->FieldByName("44")->AsInteger;
Edit48->Text=dm1->qsi->FieldByName("45")->AsInteger;
Edit49->Text=dm1->qsi->FieldByName("Pret")->AsInteger;
}
else
ShowMessage("nu sunt inregistrari");

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit38Click(TObject *Sender)
{
Edit38->Clear();
Edit50->Clear();

depozit->TabVisible=true;
magazin->TabVisible=false;
MTip->TabVisible=true;
MPantofi->TabVisible=false;
MCizme->TabVisible=false;

dm1->qtip->Close();
dm1->qtip->Open();
a=3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit50Click(TObject *Sender)
{
Edit38->Clear();
Edit50->Clear();
magazin->TabVisible=false;
depozit->TabVisible=true;
MTip->TabVisible=true;
MPantofi->TabVisible=false;
MCizme->TabVisible=false;

dm1->qtip->Close();
dm1->qtip->Open();
a=4;
}
//---------------------------------------------------------------------------







void __fastcall TForm1::Edit39Click(TObject *Sender)
{
dm1->qsi->Close();
AnsiString s;
s+="SELECT p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.model as Model,m.material_id, m.MATERIAL as Material, ";
s+="       c.culoare_id, c.CULOARE as culoare, ";
s+="      p.m39 as [39],p.m40 as [40], p.m41 as [41],p.m42 as [42], p.m43 as [43],p.m44 as [44],p.m45 as [45], ";
s+="	   p.PRET ";
s+="        FROM PANTOF P ";
s+="		INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDICE_GRUPA_ID ";
s+="	INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID ";
s+="	INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID ";
s+="	INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID ";
s+="    INNER JOIN Indice_Spatiu ip on ip.Indice_Spatiu_ID=P.Indice_Spatiu_ID ";
s+="	WHERE S.SEZON='IARNA'  and p.activ=1 ";
s+="    and p.model like '" + Edit39->Text + "%' ";
s+="    order by p.model ";

dm1->qsi->SQL->Clear();
dm1->qsi->SQL->Add(s);
dm1->qsi->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit28Click(TObject *Sender)
{
Edit28->Clear();

depozit->TabVisible=true;
MPantofi->TabVisible=false;
MMAterial->TabVisible=true;
magazin->TabVisible=false;
MTip->TabVisible=false;
MPantofi->TabVisible=false;
MCizme->TabVisible=false;

MCizme->TabVisible=false;

dm1->qmaterial->Close();
dm1->qmaterial->Open();
a=3;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit40Click(TObject *Sender)
{
Edit40->Clear();

MPantofi->TabVisible=false;
MMAterial->TabVisible=true;
magazin->TabVisible=false;
MTip->TabVisible=false;
MPantofi->TabVisible=false;
MCizme->TabVisible=false;
depozit->TabVisible=true;

MCizme->TabVisible=false;

dm1->qmaterial->Close();
dm1->qmaterial->Open();
a=4;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit29Click(TObject *Sender)
{
Edit29->Clear();
depozit->TabVisible=true;
MCuloare->TabVisible=true;
magazin->TabVisible=false;
depozit->TabVisible=true;
MPantofi->TabVisible=false;
MMAterial->TabVisible=false;
magazin->TabVisible=false;
MTip->TabVisible=false;
MCizme->TabVisible=false;


a=3;


dm1->qculoare->Close();
dm1->qculoare->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit41Click(TObject *Sender)
{
Edit41->Clear();

depozit->TabVisible=true;
MCuloare->TabVisible=true;
MPantofi->TabVisible=false;
magazin->TabVisible=false;

a=4;


dm1->qculoare->Close();
dm1->qculoare->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton26Click(TObject *Sender)
{
dm1->qsp->Close();
dm1->qsp->Open();
AnsiString s;

if(Edit38->Text!="" &&
Edit27->Text!="" &&
Edit28->Text!="" &&
Edit29->Text!="" &&
Edit37->Text!="")
{
s+="SELECT p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.model as Model,m.material_id, m.MATERIAL as Material, ";
s+="       c.culoare_id, c.CULOARE as culoare, ";
s+="      p.m39 as [39],p.m40 as [40], p.m41 as [41],p.m42 as [42], p.m43 as [43],p.m44 as [44],p.m45 as [45], ";
s+="	   p.PRET, id.Magazin  ";
s+="        FROM PANTOF P ";
s+="		INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDICE_GRUPA_ID ";
s+="	INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID ";
s+="	INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID ";
s+="	INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID ";
s+="    INNER JOIN Indice_Spatiu id on id.Indice_Spatiu_ID=p.indice_spatiu_ID  ";
s+="	WHERE S.SEZON='VARA'  and p.activ=1  ";
s+="    and id.Indice_Spatiu_ID=:Indice_Spatiu_ID ";
s+="    and p.Model=:Model and ig.INDICE_GRUPA_ID=:INDICE_GRUPA_ID ";
s+="    and m.MATERIAL_ID=:MATERIAL_ID and c.CULOARE_ID=:CULOARE_ID ";


 dm1->qgol->Close();
 dm1->qgol->SQL->Clear();
 dm1->qgol->SQL->Add(s);

dm1->qgol->ParamByName("Indice_Spatiu_ID")->AsInteger=1;
dm1->qgol->ParamByName("Model")->AsString=Edit27->Text;
dm1->qgol->ParamByName("INDICE_GRUPA_ID")->AsInteger=tipm_id;
dm1->qgol->ParamByName("MATERIAL_ID")->AsInteger=mm_id;
dm1->qgol->ParamByName("CULOARE_ID")->AsInteger=cm_id;




///////VERIFICARE LA ACELEASI INREGISTRARI/////////////////////////////////////
s+=" SELECT p.*, c.*, ig.*, m.*, id.* ";
s+="        FROM PANTOF P ";
s+="		INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDICE_GRUPA_ID ";
s+="	INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID ";
s+="	INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID ";
s+="	INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID ";
s+="    INNER JOIN Indice_Spatiu id on id.Indice_Spatiu_ID=P.Indice_spatiu_ID ";
s+="	WHERE S.SEZON='VARA' and p.activ=1 ";
s+="    and  p.model=:model and ";
s+="    id.Indice_Spatiu_ID=:Indice_Spatiu_ID and ";
s+="    ig.indice_grupa_id=:indice_grupa_id and ";
s+="    c.culoare_id=:culoare_id and m.material_id=:material_id ";

dm1->qgol2->Close();
dm1->qgol2->SQL->Clear();
dm1->qgol2->SQL->Add(s);
dm1->qgol2->ParamByName("Indice_Spatiu_ID")->AsInteger=1;
dm1->qgol2->ParamByName("Model")->AsString=Edit27->Text;
dm1->qgol2->ParamByName("indice_grupa_id")->AsInteger=tipm_id;
dm1->qgol2->ParamByName("material_id")->AsInteger=mm_id;
dm1->qgol2->ParamByName("culoare_id")->AsInteger=cm_id;
dm1->qgol2->Open();
if(dm1->qgol2->IsEmpty())
{
 s=" INSERT INTO PANTOF(Indice_Spatiu_ID,INDICE_GRUPA_ID,Model,MATERIAL_ID,CULOARE_ID,M39,M40,M41,M42,m43,m44,m45,PRET, SEZON_ID) ";
 s+=" VALUES(:Indice_Spatiu_ID,:INDICE_GRUPA_ID,:Model,:MATERIAL_ID,:CULOARE_ID,:M39,:M40,:M41,:M42,:m43,:m44,:m45,:PRET,:SEZON_ID)";

 dm1->qgol->Close();
 dm1->qgol->SQL->Clear();
 dm1->qgol->SQL->Add(s);
 dm1->qgol->ParamByName("Indice_Spatiu_ID")->AsInteger=1;
 dm1->qgol->ParamByName("SEZON_ID")->AsInteger=2;  ///sezon vara
 dm1->qgol->ParamByName("Model")->AsString=Edit27->Text;
 dm1->qgol->ParamByName("INDICE_GRUPA_ID")->AsInteger=tipm_id;
 dm1->qgol->ParamByName("MATERIAL_ID")->AsInteger=mm_id;
 dm1->qgol->ParamByName("CULOARE_ID")->AsInteger=cm_id;
 dm1->qgol->ParamByName("M39")->AsInteger=Edit30->Text.ToInt();
 dm1->qgol->ParamByName("M40")->AsInteger=Edit31->Text.ToInt();
 dm1->qgol->ParamByName("M41")->AsInteger=Edit32->Text.ToInt();
 dm1->qgol->ParamByName("M42")->AsInteger=Edit33->Text.ToInt();
 dm1->qgol->ParamByName("m43")->AsInteger=Edit34->Text.ToInt();
 dm1->qgol->ParamByName("m44")->AsInteger=Edit35->Text.ToInt();
 dm1->qgol->ParamByName("m45")->AsInteger=Edit36->Text.ToInt();
 dm1->qgol->ParamByName("PRET")->AsInteger=Edit37->Text.ToInt();
}
else /////facem actualizare daca avem deja acest produs
{   if (MessageDlg("Asemenea produs exista, actualizati informatia?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)

	{
	s=" update pantof set M39=M39+ :M39,M40=M40+ :M40,M41=M41+ :M41,M42=M42+ :M42, ";
	s+=" m43=m43+ :m43,m44=m44+ :m44,m45=m45+ :m45,PRET=:PRET ";
	s+=" where pantof_id=:pantof_id ";

	dm1->qgol->Close();
	dm1->qgol->SQL->Clear();
	dm1->qgol->SQL->Add(s);
	dm1->qgol->ParamByName("pantof_id")->AsInteger=dm1->qgol2->FieldByName("pantof_id")->AsInteger;
 dm1->qgol->ParamByName("M39")->AsInteger=Edit30->Text.ToInt();
 dm1->qgol->ParamByName("M40")->AsInteger=Edit31->Text.ToInt();
 dm1->qgol->ParamByName("M41")->AsInteger=Edit32->Text.ToInt();
 dm1->qgol->ParamByName("M42")->AsInteger=Edit33->Text.ToInt();
 dm1->qgol->ParamByName("m43")->AsInteger=Edit34->Text.ToInt();
 dm1->qgol->ParamByName("m44")->AsInteger=Edit35->Text.ToInt();
 dm1->qgol->ParamByName("m45")->AsInteger=Edit36->Text.ToInt();
 dm1->qgol->ParamByName("PRET")->AsInteger=Edit37->Text.ToInt();
	}
	else
	{
	 Edit38->Clear();
Edit27->Clear();
Edit28->Clear();
Edit29->Clear();
Edit30->Clear();
Edit31->Clear();
Edit32->Clear();
Edit33->Clear();
Edit34->Clear();
Edit35->Clear();
Edit36->Clear();
Edit37->Clear();
    }

	}

dm1->qgol->ExecSQL();
ShowMessage("Adaugare cu Succes");
dm1->qsp->Close();
dm1->qsp->Open();

Edit38->Clear();
Edit27->Clear();
Edit28->Clear();
Edit29->Clear();
Edit30->Clear();
Edit31->Clear();
Edit32->Clear();
Edit33->Clear();
Edit34->Clear();
Edit35->Clear();
Edit36->Clear();
Edit37->Clear();
}
else
{
    ShowMessage("Nu ati completat campurile");
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton9Click(TObject *Sender)
{

dm1->qedit->Close();
dm1->qedit->ParamByName("Model")->AsString=Edit27->Text;
dm1->qedit->ParamByName("INDICE_GRUPA_ID")->AsInteger=tipm_id;
dm1->qedit->ParamByName("material_id")->AsInteger=mm_id;
dm1->qedit->ParamByName("CULOARE_ID")->AsInteger=cm_id;
dm1->qedit->ParamByName("m39")->AsInteger=Edit30->Text.ToInt();
dm1->qedit->ParamByName("m40")->AsInteger=Edit31->Text.ToInt();
dm1->qedit->ParamByName("m41")->AsInteger=Edit32->Text.ToInt();
dm1->qedit->ParamByName("m42")->AsInteger=Edit33->Text.ToInt();
dm1->qedit->ParamByName("m43")->AsInteger=Edit34->Text.ToInt();
dm1->qedit->ParamByName("m44")->AsInteger=Edit35->Text.ToInt();
dm1->qedit->ParamByName("m45")->AsInteger=Edit36->Text.ToInt();
dm1->qedit->ParamByName("pret")->AsInteger=Edit37->Text.ToInt();
dm1->qedit->ParamByName("pantof_id")->AsInteger=pm_id;

dm1->qedit->ExecSQL();
dm1->qsp->Close();
dm1->qsp->Open();
ShowMessage("Modificare cu succes!");






Edit38->Clear();
Edit27->Clear();
Edit28->Clear();
Edit29->Clear();
Edit30->Clear();
Edit31->Clear();
Edit32->Clear();
Edit33->Clear();
Edit34->Clear();
Edit35->Clear();
Edit36->Clear();
Edit37->Clear();

Edit50->Clear();
Edit39->Clear();
Edit40->Clear();
Edit41->Clear();
Edit42->Clear();
Edit43->Clear();
Edit44->Clear();
Edit45->Clear();
Edit46->Clear();
Edit47->Clear();
Edit48->Clear();
Edit49->Clear();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit27Change(TObject *Sender)
{
dm1->qsp->Close();
AnsiString s;
s+="SELECT p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.model as Model,m.material_id, m.MATERIAL as Material, ";
s+="       c.culoare_id, c.CULOARE as culoare, ";
s+="      p.m39 as [39],p.m40 as [40], p.m41 as [41],p.m42 as [42], p.m43 as [43],p.m44 as [44],p.m45 as [45], ";
s+="	   p.PRET, ip.Magazin ";
s+="        FROM PANTOF P ";
s+="		INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDICE_GRUPA_ID ";
s+="	INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID ";
s+="	INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID ";
s+="	INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID ";
s+="    INNER JOIN Indice_Spatiu ip on ip.Indice_Spatiu_ID=P.Indice_Spatiu_ID ";
s+="	WHERE S.SEZON='VARA'  and p.activ=1 and ip.Indice_Spatiu_ID=1";
s+="    and p.model like '"+Edit27->Text+"%' ";
s+="    order by p.model ";

dm1->qsp->SQL->Clear();
dm1->qsp->SQL->Add(s);
dm1->qsp->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton27Click(TObject *Sender)
{

dm1->qedit->Close();
dm1->qedit->ParamByName("Model")->AsString=Edit39->Text;
dm1->qedit->ParamByName("INDICE_GRUPA_ID")->AsInteger=tipm_idciz;
dm1->qedit->ParamByName("material_id")->AsInteger=mm_idciz;
dm1->qedit->ParamByName("CULOARE_ID")->AsInteger=cm_idciz;
dm1->qedit->ParamByName("m39")->AsInteger=Edit42->Text.ToInt();
dm1->qedit->ParamByName("m40")->AsInteger=Edit43->Text.ToInt();
dm1->qedit->ParamByName("m41")->AsInteger=Edit44->Text.ToInt();
dm1->qedit->ParamByName("m42")->AsInteger=Edit45->Text.ToInt();
dm1->qedit->ParamByName("m43")->AsInteger=Edit46->Text.ToInt();
dm1->qedit->ParamByName("m44")->AsInteger=Edit47->Text.ToInt();
dm1->qedit->ParamByName("m45")->AsInteger=Edit48->Text.ToInt();
dm1->qedit->ParamByName("pret")->AsInteger=Edit49->Text.ToInt();
dm1->qedit->ParamByName("pantof_id")->AsInteger=pm_idciz;

dm1->qedit->ExecSQL();
dm1->qsi->Close();
dm1->qsi->Open();
ShowMessage("Modificare cu succes!");






Edit38->Clear();
Edit27->Clear();
Edit28->Clear();
Edit29->Clear();
Edit30->Clear();
Edit31->Clear();
Edit32->Clear();
Edit33->Clear();
Edit34->Clear();
Edit35->Clear();
Edit36->Clear();
Edit37->Clear();

Edit50->Clear();
Edit39->Clear();
Edit40->Clear();
Edit41->Clear();
Edit42->Clear();
Edit43->Clear();
Edit44->Clear();
Edit45->Clear();
Edit46->Clear();
Edit47->Clear();
Edit48->Clear();
Edit49->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton10Click(TObject *Sender)
{

Edit38->Clear();
Edit27->Clear();
Edit28->Clear();
Edit29->Clear();
Edit30->Clear();
Edit31->Clear();
Edit32->Clear();
Edit33->Clear();
Edit34->Clear();
Edit35->Clear();
Edit36->Clear();
Edit37->Clear();

dm1->qsp->Close();
dm1->qsp->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton28Click(TObject *Sender)
{

Edit50->Clear();
Edit39->Clear();
Edit40->Clear();
Edit41->Clear();
Edit42->Clear();
Edit43->Clear();
Edit44->Clear();
Edit45->Clear();
Edit46->Clear();
Edit47->Clear();
Edit48->Clear();
Edit49->Clear();
dm1->qsi->Close();
dm1->qsi->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton29Click(TObject *Sender)
{
AnsiString s;

s=" UPDATE  PANTOF SET ACTIV=0 WHERE PANTOF_ID=:PANTOF_ID ";

dm1->qgol->Close();
dm1->qgol->SQL->Clear();
dm1->qgol->SQL->Add(s);

dm1->qgol->ParamByName("PANTOF_ID")->AsInteger=pm_idciz;

dm1->qgol->ExecSQL();

dm1->qsi->Close();
dm1->qsi->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton11Click(TObject *Sender)
{
AnsiString s;

s=" UPDATE  PANTOF SET ACTIV=0 WHERE PANTOF_ID=:PANTOF_ID ";

dm1->qgol->Close();
dm1->qgol->SQL->Clear();
dm1->qgol->SQL->Add(s);

dm1->qgol->ParamByName("PANTOF_ID")->AsInteger=pm_id;

dm1->qgol->ExecSQL();

dm1->qsp->Close();
dm1->qsp->Open();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Edit52Change(TObject *Sender)
{
dm1->qsi->Close();
AnsiString s;
s+="SELECT p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.model as Model,m.material_id, m.MATERIAL as Material, ";
s+="       c.culoare_id, c.CULOARE as culoare, ";
s+="      p.m39 as [39],p.m40 as [40], p.m41 as [41],p.m42 as [42], p.m43 as [43],p.m44 as [44],p.m45 as [45], ";
s+="	   p.PRET ";
s+="        FROM PANTOF P ";
s+="		INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDICE_GRUPA_ID ";
s+="	INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID ";
s+="	INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID ";
s+="	INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID ";
s+="    INNER JOIN Indice_Spatiu ip on ip.Indice_Spatiu_ID=P.Indice_Spatiu_ID ";
s+="	WHERE S.SEZON='IARNA'  and p.activ=1 ";
s+="    and p.model like '" + Edit52->Text + "%' ";
s+="    order by p.model ";

dm1->qsi->SQL->Clear();
dm1->qsi->SQL->Add(s);
dm1->qsi->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit51Change(TObject *Sender)
{
dm1->qsp->Close();
AnsiString s;
s+="SELECT p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.model as Model,m.material_id, m.MATERIAL as Material, ";
s+="       c.culoare_id, c.CULOARE as culoare, ";
s+="      p.m39 as [39],p.m40 as [40], p.m41 as [41],p.m42 as [42], p.m43 as [43],p.m44 as [44],p.m45 as [45], ";
s+="	   p.PRET, ip.Magazin ";
s+="        FROM PANTOF P ";
s+="		INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDICE_GRUPA_ID ";
s+="	INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID ";
s+="	INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID ";
s+="	INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID ";
s+="    INNER JOIN Indice_Spatiu ip on ip.Indice_Spatiu_ID=P.Indice_Spatiu_ID ";
s+="	WHERE S.SEZON='VARA'  and p.activ=1 and ip.Indice_Spatiu_ID=1";
s+="    and p.model like '"+Edit51->Text+"%' ";
s+="    order by p.model ";

dm1->qsp->SQL->Clear();
dm1->qsp->SQL->Add(s);
dm1->qsp->Open();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
if(CheckBox1->Checked)
{
	CheckBox2->Checked=false;
    MC->Enabled=true;
}


}
//---------------------------------------------------------------------------

void __fastcall TForm1::MC1Click(TObject *Sender)
{
AnsiString s;
s+="SELECT p.data,p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.model as Model,m.material_id, m.MATERIAL as Material, ";
s+="       c.culoare_id, c.CULOARE as culoare, ";
s+="      p.M39 as [39],p.M40 as [40], p.M41 as [41],p.m42 as [42], p.m43 as [43],p.m44 as [44],p.m45 as [45], ";
s+="	   p.PRET ";
s+="        FROM PANTOF P ";
s+="		INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDICE_GRUPA_ID ";
s+="	INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID ";
s+="	INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID ";
s+="	INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID ";
s+="    INNER JOIN Indice_Spatiu ip on ip.Indice_Spatiu_ID=P.Indice_Spatiu_ID ";
s+="	WHERE S.SEZON='VARA' ";
s+="	  and p.data=:data ";
if(CheckBox3->Checked)
s+="  and p.activ=1 ";
if(CheckBox4->Checked)
s+="  and p.activ=0 ";

dm1->qsi->Close();
dm1->qsi->SQL->Clear();
dm1->qsi->SQL->Add(s);
dm1->qsi->ParamByName("data")->AsDate=MC1->Date;

dm1->qsi->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox3Click(TObject *Sender)
{
if(CheckBox3->Checked)
{
	CheckBox4->Checked=false;
	 MC1->Enabled=true;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox4Click(TObject *Sender)
{
if(CheckBox4->Checked)
{
	CheckBox3->Checked=false;
	 MC1->Enabled=true;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MCClick(TObject *Sender)
{
AnsiString s;
s+="SELECT p.data,p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.model as Model,m.material_id, m.MATERIAL as Material, ";
s+="       c.culoare_id, c.CULOARE as culoare, ";
s+="      p.M39 as [39],p.M40 as [40], p.M41 as [41],p.m42 as [42], p.m43 as [43],p.m44 as [44],p.m45 as [45], ";
s+="	   p.PRET ";
s+="        FROM PANTOF P ";
s+="		INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDICE_GRUPA_ID ";
s+="	INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID ";
s+="	INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID ";
s+="	INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID ";
s+="    INNER JOIN Indice_Spatiu ip on ip.Indice_Spatiu_ID=P.Indice_Spatiu_ID ";
s+="	WHERE S.SEZON='VARA' ";
s+="	  and p.data=:data ";
if(CheckBox1->Checked)
s+="  and p.activ=1 ";
if(CheckBox2->Checked)
s+="  and p.activ=0 ";

dm1->qsp->Close();
dm1->qsp->SQL->Clear();
dm1->qsp->SQL->Add(s);
dm1->qsp->ParamByName("data")->AsDate=MC->Date;

dm1->qsp->Open();
}
//---------------------------------------------------------------------------





void __fastcall TForm1::DTshowClick(TObject *Sender)
{
AnsiString s;
s+="SELECT p.data,p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.model as Model,m.material_id, m.MATERIAL as Material, ";
s+="       c.culoare_id, c.CULOARE as culoare, ";
s+="      p.M39 as [39],p.M40 as [40], p.M41 as [41],p.m42 as [42], p.m43 as [43],p.m44 as [44],p.m45 as [45], ";
s+="	   p.PRET ";
s+="        FROM PANTOF P ";
s+="		INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDICE_GRUPA_ID ";
s+="	INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID ";
s+="	INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID ";
s+="	INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID ";
s+="	WHERE S.SEZON='VARA' and p.data=:data ";
if(CBintrari->Checked)
s+="  and p.activ=1 ";
if(CBelim->Checked)
s+="  and p.activ=0 ";

dm1->qshow->Close();
dm1->qshow->SQL->Clear();
dm1->qshow->SQL->Add(s);
dm1->qshow->ParamByName("data")->AsDate=DTshow->Date;

dm1->qshow->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
if(CheckBox2->Checked)
{
CheckBox1->Checked=false;
MC->Enabled=true;
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
RadioButton1->Checked=false;
MGPantof->TabVisible=false;
MGCizme->TabVisible=true;

RBPANTOFI->Checked=false;
RBAPANTOF->Checked=false;
RBCIZME->Checked=false;
RBACIZME->Checked=false;

GroupBox4->Visible=false;

Panel8->Visible=true;
Panel8->Top=3;
Panel8->Left=510;

AnsiString s;
s=" SELECT SUM(M39)+SUM(M40)+SUM(M41)+SUM(M42)+SUM(m43)+SUM(m44)+SUM(m45) AS SUMA FROM PANTOF p ";
s+=" inner join sezon s on s.sezon_id=p.sezon_id ";
s+=" INNER JOIN Indice_Spatiu ip on ip.Indice_Spatiu_ID=P.Indice_Spatiu_ID ";
s+=" where s.sezon='IARNA' and ACTIV=1 ";
dm1->qliber->Close();
dm1->qliber->SQL->Clear();
dm1->qliber->SQL->Add(s);
dm1->qliber->Open();
Label64->Caption=dm1->qliber->FieldByName("SUMA")->AsString;

dm1->qsi->Close();
dm1->qsi->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
RadioButton2->Checked=false;
MGPantof->TabVisible=true;
MGCizme->TabVisible=false;


RBPANTOFI->Checked=false;
RBAPANTOF->Checked=false;
RBCIZME->Checked=false;
RBACIZME->Checked=false;

GroupBox3->Visible=false;

Panel5->Visible=true;
Panel5->Top=3;
Panel5->Left=506;

AnsiString s;
s=" SELECT SUM(M39)+SUM(M40)+SUM(M41)+SUM(M42)+SUM(m43)+SUM(m44)+SUM(m45) AS SUMA FROM PANTOF p ";
s+=" inner join sezon s on s.sezon_id=p.sezon_id ";
s+=" INNER JOIN Indice_Spatiu ip on ip.Indice_Spatiu_ID=P.Indice_Spatiu_ID ";
s+=" where s.sezon='VARA' and ACTIV=1 ";
dm1->qliber->Close();
dm1->qliber->SQL->Clear();
dm1->qliber->SQL->Add(s);
dm1->qliber->Open();
Label61->Caption=dm1->qliber->FieldByName("SUMA")->AsString;

dm1->qsp->Close();
dm1->qsp->Open();
}
//---------------------------------------------------------------------------

