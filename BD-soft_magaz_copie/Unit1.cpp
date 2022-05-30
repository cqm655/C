//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Project1PCH1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfmain *fmain;
TDateTime DT;
int CEC, CLIENT=1, OPERATOR=1;
float discount=0; // dam la client cod 1 ca default



//---------------------------------------------------------------------------
__fastcall Tfmain::Tfmain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------




void __fastcall Tfmain::SpeedButton1Click(TObject *Sender)
{
freceptie->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tfmain::Button3Click(TObject *Sender)
{
if(Image14->Visible)
{
Image15->Visible=false;
}
else
{
Image14->Visible=true;
}

}
//---------------------------------------------------------------------------





void __fastcall Tfmain::Timer1Timer(TObject *Sender)
{
 Label20->Caption=DT.CurrentTime();
}
//---------------------------------------------------------------------------

void __fastcall Tfmain::FormShow(TObject *Sender)
{
Label21->Caption=DT.CurrentDate();
}
//---------------------------------------------------------------------------

void __fastcall Tfmain::Button1Click(TObject *Sender)
{
if(Edit1->Text!="")
{
	AnsiString s;

	if(CBclient->Checked==false)
	{
	  s+="select r.*, p.denumire as produse, p.cod_produs,um.abreviere ";
s+=" from receptie  r inner join unit_masura um on um.unit_masura_id=r.unit_masura_id ";
s+=" inner join produse p on p.produse_id=r.produse_id ";
s+=" where cod_produs=:cod_produs and stock1>0 ";
	}
	else
	{
		s="select * from client c inner join discount d on c.discount_id=d.discount_id ";
		s+=" and c.cod_client=:cod_produs";//cod_produs doar nume de unde vine info, da vine de la noi
    }



dm->qliber->Close();
dm->qliber->SQL->Clear();
dm->qliber->SQL->Add(s);
dm->qliber->ParamByName("cod_produs")->AsString=Edit1->Text;
dm->qliber->Open();

if(CBclient->Checked==false) //cat timp e produs
{

if(!dm->qliber->IsEmpty())
{
	Label6->Caption=dm->qliber->FieldByName("produse")->AsString + " cost: " +
					dm->qliber->FieldByName("pret_vanzare")->AsString + " lei/ " +
					dm->qliber->FieldByName("abreviere")->AsString;

	float suma=dm->qliber->FieldByName("pret_vanzare")->AsFloat;
	int REC=dm->qliber->FieldByName("receptie_id")->AsInteger;

	if((dm->qvanzare->Active==false ) || (dm->qvanzare->IsEmpty()))
	{
		//formam cecul
		 dm->FDStoredProc1->Close();
  dm->proccec->Params->Items[1]->AsInteger=OPERATOR;  //opera2tor
   dm->proccec->Params->Items[2]->AsInteger=CLIENT; //client
  dm->proccec->Params->Items[3]->AsInteger=1;   //firma
  dm->proccec->ExecProc();
  CEC=dm->proccec->Params->Items[0]->AsInteger;

 }
 s="insert into VANZARE(CEC_ID,RECEPETIE_ID,CANTITATEA,SUMA,SUMA_DISC,SUMA_TOTAL) ";
 s+=" values (:CEC_ID,:RECEPTIE_ID,:CANTITATEA,:SUMA,:SUMA_DISC,:SUMA_TOTAL) ";

 dm->qliber->Close();
dm->qliber->SQL->Clear();
dm->qliber->SQL->Add(s);
dm->qliber->ParamByName("cec_id")->AsInteger=CEC;
dm->qliber->ParamByName("receptie_id")->AsInteger=REC;
dm->qliber->ParamByName("cantitatea")->AsInteger=1;
dm->qliber->ParamByName("suma")->AsFloat=suma;
dm->qliber->ParamByName("suma_disc")->AsFloat=suma*(discount/100);
dm->qliber->ParamByName("suma_total")->AsFloat=suma-(suma*(discount/100));

dm->qliber->ExecSQL();
 }
 }
 else    //daca e client
 {

	 if(!dm->qliber->IsEmpty())
	{
	   Label7->Caption=dm->qliber->FieldByName("nume")->AsString + " " +
					dm->qliber->FieldByName("prenume")->AsString + " - discount " +
					dm->qliber->FieldByName("valoarea")->AsString
					+ "%";
		CLIENT=dm->qliber->FieldByName("client_id")->AsInteger;
		discount=dm->qliber->FieldByName("valoarea")->AsFloat;

		//daca avem deja vanzari facute atunci facem reclacul
			if((dm->qvanzare->Active==true ) || (!dm->qvanzare->IsEmpty()))
			{
            ShowMessage(discount);
		s="update vanzare set SUMA_DISC=suma*( :SUMA_DISC /cast(100 as float)),SUMA_TOTAL=suma-(suma*( :SUMA_DISC /cast(100 as float))) where ";
		s+=" cec_id=:cec_id ";

		dm->qliber->Close();
		dm->qliber->SQL->Clear();
		dm->qliber->SQL->Add(s);

		dm->qliber->ParamByName("cec_id")->AsInteger=CEC;
		dm->qliber->ParamByName("SUMA_DISC")->AsFloat=discount; //discount ca parametru ca si sus, putem da oricare alt nume

		dm->qliber->ExecSQL();
			 }
	}
	else
	{
		Label7->Caption="neidentificat";
	}

 }
   dm->qvanzare->Close();
   dm->qvanzare->ParamByName("cec_id")->AsInteger=CEC;
   dm->qvanzare->Open();

		dm->qliber->Close();
		dm->qliber->SQL->Clear();
		dm->qliber->SQL->Add("select sum(SUMA_TOTAL) as suma from vanzare where cec_id=:cec_id ");
		dm->qliber->ParamByName("cec_id")->AsInteger=CEC;

		dm->qliber->Open();
		Label9->Caption=dm->qliber->FieldByName("suma")->AsString;


    }

else
{
	Label6->Caption=" Neidentificat";
}
}

//---------------------------------------------------------------------------

void __fastcall Tfmain::CBclientClick(TObject *Sender)
{
Edit1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall Tfmain::SpeedButton5Click(TObject *Sender)
{

dm->qvanzare->Close();

dm->qliber->Close();
		dm->qliber->SQL->Clear();
		dm->qliber->SQL->Add(" update cec set suma_cec=:suma_cec, NR_CEC=(select ISNULL( max(NR_CEC),0)+1 from CEC) where CEC_ID=:CEC_ID ");
		dm->qliber->ParamByName("CEC_ID")->AsInteger=CEC;
		dm->qliber->ParamByName("suma_cec")->AsFloat=Label9->Caption.ToDouble();
		dm->qliber->ExecSQL();   //punem exesql ca avem update


 AnsiString s;
 s=" select sum(v.SUMA_TOTAL) as suma ";
 s+=" from vanzare v inner join cec on cec.cec_id=v.cec_id where";
 s+=" cast(data_cec as date)=cast(getdate() as date) ";
 s+=" and operator_id=:operator_id ";
        dm->qliber->Close();
		dm->qliber->SQL->Clear();
		dm->qliber->SQL->Add(s);

		dm->qliber->ParamByName("operator_id")->AsInteger=OPERATOR;

		dm->qliber->Open();
		Label9->Caption="0.00";
		Label17->Caption=dm->qliber->FieldByName("suma")->AsString;

CLIENT=1;
discount=0;
CEC=0;
	   Edit1->Clear();
	   CBclient->Checked=false;

}
//---------------------------------------------------------------------------

void __fastcall Tfmain::SpeedButton9Click(TObject *Sender)
{
	AnsiString s;
if(Edit1->Text!="")



	if(CBclient->Checked==false)
	{
s+="select r.*, p.denumire as produse, p.cod_produs,um.abreviere ";
s+=" from receptie  r inner join unit_masura um on um.unit_masura_id=r.unit_masura_id ";
s+=" inner join produse p on p.produse_id=r.produse_id ";
s+=" where cod_produs=:cod_produs and stock1>0 ";
	}
	else
	{
		s="select * from client c inner join discount d on c.discount_id=d.discount_id ";
		s+=" and c.cod_client=:cod_produs";//cod_produs doar nume de unde vine info, da vine de la noi
	}



dm->qliber->Close();
dm->qliber->SQL->Clear();
dm->qliber->SQL->Add(s);
dm->qliber->ParamByName("cod_produs")->AsString=Edit1->Text;


dm->qliber->Open();

if(CBclient->Checked==false) //cat timp e produs
{


if(!dm->qliber->IsEmpty())
{
	Label6->Caption=dm->qliber->FieldByName("produse")->AsString + " cost: " +
					dm->qliber->FieldByName("pret_vanzare")->AsString + " lei/ " +
					dm->qliber->FieldByName("abreviere")->AsString;

	float suma=dm->qliber->FieldByName("pret_vanzare")->AsFloat;
	int REC=dm->qliber->FieldByName("receptie_id")->AsInteger;
  dm->qvanzare->Close();
	  ShowMessage(dm->qvanzare->FieldByName("produs")->AsString);
  dm->qvanzare->Open();


	if((dm->qvanzare->Active==false ) || (dm->qvanzare->IsEmpty()))
	{
		//formam cecul
		 dm->FDStoredProc1->Close();
  dm->proccec->Params->Items[1]->AsInteger=1;  //opera2tor
   dm->proccec->Params->Items[2]->AsInteger=CLIENT; //client
  dm->proccec->Params->Items[3]->AsInteger=1;   //firma
  dm->proccec->ExecProc();
  CEC=dm->proccec->Params->Items[0]->AsInteger;

 }
 s="insert into VANZARE(CEC_ID,RECEPETIE_ID,CANTITATEA,SUMA,SUMA_DISC,SUMA_TOTAL) ";
 s+=" values (:CEC_ID,:RECEPTIE_ID,:CANTITATEA,:SUMA,:SUMA_DISC,:SUMA_TOTAL) ";

 dm->qliber->Close();
dm->qliber->SQL->Clear();
dm->qliber->SQL->Add(s);

dm->qliber->ParamByName("cec_id")->AsInteger=CEC;
dm->qliber->ParamByName("receptie_id")->AsInteger=REC;
dm->qliber->ParamByName("cantitatea")->AsInteger=1;
dm->qliber->ParamByName("suma")->AsFloat=suma;
dm->qliber->ParamByName("suma_disc")->AsFloat=suma*(discount/100);
dm->qliber->ParamByName("suma_total")->AsFloat=suma-(suma*(discount/100));

dm->qliber->ExecSQL();

////////////////////////////VERIFICAREA//////////////////////////////////////
/*if((dm->qvanzare->Active==true ) || (!dm->qvanzare->IsEmpty()))
			{

AnsiString s;


 float a=2;
 ++a;

float tot,cost;
cost=dm->qvanzare->FieldByName("suma")->AsFloat/dm->qvanzare->FieldByName("cantitatea")->AsFloat;


tot=cost*a;

 s=" update VANZARE set cantitatea=:cantitatea, suma=:suma, suma_disc=:suma_disc, suma_total=:suma_total ";
 s+=" where vanzare_id=:vanzare_id ";

 dm->qliber->Close();
dm->qliber->SQL->Clear();
dm->qliber->SQL->Add(s);
dm->qliber->ParamByName("vanzare_id")->AsInteger=dm->qvanzare->FieldByName("vanzare_id")->AsInteger;
dm->qliber->ParamByName("cantitatea")->AsFloat=a;
dm->qliber->ParamByName("suma")->AsFloat=tot;
dm->qliber->ParamByName("suma_disc")->AsFloat=tot*(discount/100);
dm->qliber->ParamByName("suma_total")->AsFloat=tot-(tot*(discount/100));

dm->qliber->ExecSQL();
 ////////////////////////////////////////////////////////////
dm->qvanzare->Close();
dm->qvanzare->ParamByName("cec_id")->AsInteger=CEC;
dm->qvanzare->Open();

dm->qliber->Close();
dm->qliber->SQL->Clear();
dm->qliber->SQL->Add("select sum(SUMA_TOTAL) as suma from vanzare where cec_id=:cec_id ");
dm->qliber->ParamByName("cec_id")->AsInteger=CEC;


dm->qliber->Open();
Label9->Caption=dm->qliber->FieldByName("suma")->AsString;
Edit1->Clear();


			 } */
///////////////////////////////////////////////////////////////////////////////////////
 }

 else    //daca e client
 {

	 if(!dm->qliber->IsEmpty())
	{
	   Label7->Caption=dm->qliber->FieldByName("nume")->AsString + " " +
					dm->qliber->FieldByName("prenume")->AsString + " - discount " +
					dm->qliber->FieldByName("valoarea")->AsString
					+ "%";
		CLIENT=dm->qliber->FieldByName("client_id")->AsInteger;
		discount=dm->qliber->FieldByName("valoarea")->AsFloat;

/////////daca avem deja vanzari facute atunci facem reclacul/////////////////////////
			if((dm->qvanzare->Active==true ) || (!dm->qvanzare->IsEmpty()))
			{

		s="update vanzare set SUMA_DISC=suma*( :SUMA_DISC /cast(100 as float)),SUMA_TOTAL=suma-(suma*( :SUMA_DISC /cast(100 as float))) where ";
		s+=" cec_id=:cec_id ";

		dm->qliber->Close();
		dm->qliber->SQL->Clear();
		dm->qliber->SQL->Add(s);

		dm->qliber->ParamByName("cec_id")->AsInteger=CEC;
		dm->qliber->ParamByName("SUMA_DISC")->AsFloat=discount; //discount ca parametru ca si sus, putem da oricare alt nume

		dm->qliber->ExecSQL();

         dm->qliber->Close();
dm->qliber->SQL->Clear();
dm->qliber->SQL->Add("update cec set CLIENT_ID=:CLIENT_ID where CEC_ID=:CEC_ID");
dm->qliber->ParamByName("CEC_ID")->AsInteger=CEC;
dm->qliber->ParamByName("CLIENT_ID")->AsInteger=CLIENT;
dm->qliber->ExecSQL();
			 }
	}
	else
	{
		Label7->Caption="neidentificat";
	}

 }
   dm->qvanzare->Close();
   dm->qvanzare->ParamByName("cec_id")->AsInteger=CEC;
   dm->qvanzare->Open();

		dm->qliber->Close();
		dm->qliber->SQL->Clear();
		dm->qliber->SQL->Add("select sum(SUMA_TOTAL) as suma from vanzare where cec_id=:cec_id ");
		dm->qliber->ParamByName("cec_id")->AsInteger=CEC;


		dm->qliber->Open();
		Label9->Caption=dm->qliber->FieldByName("suma")->AsString;

	   Edit1->Clear();
	   CBclient->Checked=false;




}


else
{
	Label6->Caption=" Neidentificat";
}
}
//---------------------------------------------------------------------------


void __fastcall Tfmain::SpeedButton8Click(TObject *Sender)
{

if(Image14->Visible)
{
	Image15->Visible=false;
}
else
{

}

}
//---------------------------------------------------------------------------


void __fastcall Tfmain::SpeedButton6Click(TObject *Sender)
{
Panel11->Visible=true;

Label23->Caption=dm->qvanzare->FieldByName("produs")->AsString;
Edit3->Clear();
Edit3->Focused();
}
//---------------------------------------------------------------------------

void __fastcall Tfmain::Button5Click(TObject *Sender)
{
Edit1->Focused();
Panel11->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall Tfmain::Button4Click(TObject *Sender)
{
AnsiString s;
float tot,cost;
cost=dm->qvanzare->FieldByName("suma")->AsFloat/dm->qvanzare->FieldByName("cantitatea")->AsFloat;


tot=cost*Edit3->Text.ToDouble();

 s=" update VANZARE set cantitatea=:cantitatea, suma=:suma, suma_disc=:suma_disc, suma_total=:suma_total ";
 s+=" where vanzare_id=:vanzare_id ";

 dm->qliber->Close();
dm->qliber->SQL->Clear();
dm->qliber->SQL->Add(s);
dm->qliber->ParamByName("vanzare_id")->AsInteger=dm->qvanzare->FieldByName("idd")->AsInteger;
dm->qliber->ParamByName("cantitatea")->AsFloat=Edit3->Text.ToDouble();
dm->qliber->ParamByName("suma")->AsFloat=tot;
dm->qliber->ParamByName("suma_disc")->AsFloat=tot*(discount/100);
dm->qliber->ParamByName("suma_total")->AsFloat=tot-(tot*(discount/100));

dm->qliber->ExecSQL();
 ////////////////////////////////////////////////////////////
dm->qvanzare->Close();
dm->qvanzare->ParamByName("cec_id")->AsInteger=CEC;
dm->qvanzare->Open();

dm->qliber->Close();
dm->qliber->SQL->Clear();
dm->qliber->SQL->Add("select sum(SUMA_TOTAL) as suma from vanzare where cec_id=:cec_id ");
dm->qliber->ParamByName("cec_id")->AsInteger=CEC;


dm->qliber->Open();
Label9->Caption=dm->qliber->FieldByName("suma")->AsString;
Edit1->Clear();
CBclient->Checked=false;
Panel11->Visible=false;
}
//---------------------------------------------------------------------------
