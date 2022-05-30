//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Project1PCH1.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
multitask2 *x;



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 Memo1->Clear();
 Button1->Enabled=0;
 Button2->Enabled=1;
 Button3->Enabled=1;
 x=new multitask2(true);


 x->Priority= tpTimeCritical;
 x->Start();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{

  x->Terminate();

Button1->Enabled=1;
Button2->Enabled=0;









}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
if(!x->Suspended)
{
	x->Suspended=1;


	Button3->Caption="Play";
}

else
{
x->Suspended=0;

Button3->Caption="Pause";
}


}
//---------------------------------------------------------------------------

