//---------------------------------------------------------------------------

#include <vcl.h>
#include <IniFiles.hpp>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
 int q,r, R, CR;



void f()
{
 TIniFile *p= new TIniFile("d://test.ini");

 switch(q)
 {
	case 1:
	{
		   Form2->Label2->Caption=p->ReadString("1","a","Erroare");
		   Form2->RadioButton1->Caption=p->ReadString("1","b","Erroare");
		   Form2->RadioButton2->Caption=p->ReadString("1","c","Erroare");
		   Form2->RadioButton3->Caption=p->ReadString("1","d","Erroare");
		   Form2->RadioButton4->Caption=p->ReadString("1","e","Erroare");
		   r=p->ReadInteger("1","r",-1);
	};break;
	case 2:
	{
		   Form2->Label2->Caption=p->ReadString("2","a","Erroare");
		   Form2->RadioButton1->Caption=p->ReadString("2","b","Erroare");
		   Form2->RadioButton2->Caption=p->ReadString("2","c","Erroare");
		   Form2->RadioButton3->Caption=p->ReadString("2","d","Erroare");
		   Form2->RadioButton4->Caption=p->ReadString("2","e","Erroare");
		   r=p->ReadInteger("2","r",-1);
	};break;
	case 3:
	{
		   Form2->Label2->Caption=p->ReadString("3","a","Erroare");
		   Form2->RadioButton1->Caption=p->ReadString("3","b","Erroare");
		   Form2->RadioButton2->Caption=p->ReadString("3","c","Erroare");
		   Form2->RadioButton3->Caption=p->ReadString("3","d","Erroare");
		   Form2->RadioButton4->Caption=p->ReadString("3","e","Erroare");
		   r=p->ReadInteger("3","r",-1);
	};break;
 };




 delete p;
};


void __fastcall TForm2::RadioButton1Click(TObject *Sender)
{
R=1;
Button2->Enabled=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton2Click(TObject *Sender)
{
R=2;
Button2->Enabled=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton3Click(TObject *Sender)
{
R=3;
Button2->Enabled=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton4Click(TObject *Sender)
{
R=4;
Button2->Enabled=1;
}
//---------------------------------------------------------------------------
bool a=0;
void __fastcall TForm2::Button2Click(TObject *Sender)
{

 Label6->Caption=="4";  a==1;
if(R==r)CR++;
q++;
ProgressBar1->StepBy(33);

if(q==3)
{

 Form2->Button2->Caption="Ultimul!";


}
else if(q>3)
{
  Form2->Panel3->Visible=1;
  Form2->Panel2->Visible=0;
  Form2->Label4->Caption=CR;
}
f();
Form2->RadioButton1->Checked=0;
Form2->RadioButton2->Checked=0;
Form2->RadioButton3->Checked=0;
Form2->RadioButton4->Checked=0;
Form2->Button2->Enabled=0;



}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button1Click(TObject *Sender)
{
Panel1->Visible=0;
Panel2->Visible=1;
q=1;
R=0;
f();
Timer1->Enabled=1;

}
//---------------------------------------------------------------------------





void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
Form2->Label6->Caption=Label6->Caption.ToInt()-1;
if (a==1)
	{
	
		 }
if(Form2->Label6->Caption=="0" && a==0)
	{

	 Label6->Caption=Label6->Caption.ToInt()+4;

	 Form2->Timer1->Enabled=0;
	  q++;
	 f();
	  Form2->Timer1->Enabled=1;

	 if(q>3)
{
  Form2->Panel3->Visible=1;
  Form2->Panel2->Visible=0;
  Form2->Label4->Caption=CR;
}
	}



}
//---------------------------------------------------------------------------


