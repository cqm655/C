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
}
//---------------------------------------------------------------------------

   void __fastcall TForm1::egalClick(TObject *Sender)
{   char cc, cc1, cc2, cc3;
	AnsiString LOG;
double y=0, y1=0, y2=0, y3=0;

if(a->Text.IsEmpty() || b->Text.IsEmpty() ||c->Text.IsEmpty() ||
   d->Text.IsEmpty() || e->Text.IsEmpty())
   {ShowMessage("enter value");
   if(a->Text.IsEmpty())LOG+="a no value ";
   if(b->Text.IsEmpty())LOG+="b no value ";
   if(c->Text.IsEmpty())LOG+="c no value ";
   if(d->Text.IsEmpty())LOG+="d no value ";
   if(e->Text.IsEmpty())LOG+="e no value ";

   m->Lines->Add(LOG);

   }
else
{
	if(s->ItemIndex==0)      {cc='+'; y=a->Text.ToDouble()+b->Text.ToDouble();}
	else if(s->ItemIndex==1) {cc='-'; y=a->Text.ToDouble()-b->Text.ToDouble();}
	else if(s->ItemIndex==2) {cc='*'; y=a->Text.ToDouble()*b->Text.ToDouble();}
	else if(s->ItemIndex==3) {cc='/'; y=a->Text.ToDouble()/b->Text.ToDouble();}

	if(s1->ItemIndex==0)      {cc1='+'; y1=y+c->Text.ToDouble();}
	else if(s1->ItemIndex==1) {cc1='-'; y1=y-c->Text.ToDouble();}
	else if(s1->ItemIndex==2) {cc1='*'; y1=y*c->Text.ToDouble();}
	else if(s1->ItemIndex==3) {cc1='/'; y1=y/c->Text.ToDouble();}

	if(s2->ItemIndex==0)      {cc2='+'; y2=y1+d->Text.ToDouble();}
	else if(s2->ItemIndex==1) {cc2='-'; y2=y1-d->Text.ToDouble();}
	else if(s2->ItemIndex==2) {cc2='*'; y2=y1*d->Text.ToDouble();}
	else if(s2->ItemIndex==3) {cc2='/'; y2=y1/d->Text.ToDouble();}

	if(s3->ItemIndex==0)      {cc3='+'; y3=y2+e->Text.ToDouble();}
	else if(s3->ItemIndex==1) {cc3='-'; y3=y2-e->Text.ToDouble();}
	else if(s3->ItemIndex==2) {cc3='*'; y3=y2*e->Text.ToDouble();}
	else if(s3->ItemIndex==3) {cc3='/'; y3=y2/e->Text.ToDouble();}

	r->Text=y3;

	 LOG+=a->Text;
	 LOG+=cc;
	 LOG+=b->Text;
	 LOG+=cc1;
	 LOG+=c->Text;
	 LOG+=cc2;
	 LOG+=d->Text;
	 LOG+=cc3;
	 LOG+=e->Text;
	 LOG+=" = ";
	 LOG+=r->Text;


	 m->Lines->Add(LOG);

}
}

//---------------------------------------------------------------------------





void __fastcall TForm1::pChange(TObject *Sender)
{
if(p->Text.IsEmpty())
{

}
 else
 {
 aa->Text =a->Text.ToDouble();
 a->Text=pow(a->Text.ToDouble(),p->Text.ToInt());
 }


}
//---------------------------------------------------------------------------



void __fastcall TForm1::p1Change(TObject *Sender)
{
bb->Text =b->Text.ToDouble();
b->Text=pow(b->Text.ToDouble(),p1->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::p2Change(TObject *Sender)
{
ccc->Text =c->Text.ToDouble();
c->Text=pow(c->Text.ToDouble(),p2->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::p3Change(TObject *Sender)
{
dd->Text =d->Text.ToDouble();
d->Text=pow(d->Text.ToDouble(),p3->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::p4Change(TObject *Sender)
{
ee->Text =e->Text.ToDouble();
e->Text=pow(e->Text.ToDouble(),p4->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::aChange(TObject *Sender)
{
aa->Text =a->Text.ToDouble();
a->Text=pow(a->Text.ToDouble(),p->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::clearClick(TObject *Sender)
{
m->Text=NULL;
}
//---------------------------------------------------------------------------

