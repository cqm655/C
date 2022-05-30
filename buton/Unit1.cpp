//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
B1=new TButton(this);
B1->Parent=this;


B1->Width=80;
B1->Height=80;

B1->Caption="=";
B1->Font->Size=20;

B1->Top=50;
B1->Left=120;

L=new TLabel(this);
L->Parent=this;
L1=new TLabel(this);
L1->Parent=this;
L2=new TLabel(this);
L2->Parent=this;

L->Caption="+";
L1->Caption="-";
L->Top=25;
L->Left=115;
L1->Top=25;
L1->Left=L->Left+80;

E1=new TEdit(this);
E1->Parent=this;
E2=new TEdit(this);
E2->Parent=this;
E3=new TEdit(this);
E3->Parent=this;

E1->OnClick=X;

E1->MaxLength=4;
E2->MaxLength=4;
E3->MaxLength=4;




E1->Width=60;
E2->Width=60;
E3->Width=60;

E1->Top=20;
E2->Top=20;
E3->Top=20;

E1->Left=50;
E2->Left=E1->Left+80;
E3->Left=E2->Left+80;

E1->NumbersOnly=1;
E2->NumbersOnly=1;
E3->NumbersOnly=1;

E1->TextHint="Enter a";
E2->TextHint="Enter b";
E3->TextHint="Enter c";

Form1->Top=250;
Form1->Left=390;

void *nume_functie= this->MethodAddress("RAD");
TMethod eva;
eva.Data=this;
eva.Code=nume_functie;
/*
B1->OnClick=*(TNotifyEvent*)&eva;
  */
 B1->OnClick = RAD;

}
//---------------------------------------------------------------------------
 void __fastcall TForm1::RAD(TObject *Sender)
 {
   B1->Caption=IntToStr(E1->Text.ToInt()+E2->Text.ToInt());
 }


void __fastcall TForm1::X(TObject *Sender)
{
E1->Clear();
}
//---------------------------------------------------------------------------

