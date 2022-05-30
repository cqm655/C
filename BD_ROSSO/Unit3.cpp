//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Project1PCH1.h"
#include "Unit1.h"
#include "dm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::SpeedButton12Click(TObject *Sender)
{
if(RadioButton1->Checked)
{
Form1->Pantofi->TabVisible=true;
Form1->Cizme->TabVisible=false;
GroupBox1->Visible=false;



}
else if (RadioButton2->Checked)
{
 Form1->Pantofi->TabVisible=false;
Form1->Cizme->TabVisible=true;

	 }
	 else
	 {
       Form1->Pantofi->TabVisible=false;
Form1->Cizme->TabVisible=false;

	 }
Form3->Close();
RadioButton1->Checked=false;
RadioButton2->Checked=false;



}
//---------------------------------------------------------------------------
void __fastcall TForm3::SpeedButton13Click(TObject *Sender)
{
Form3->Close();
RadioButton1->Checked=false;
RadioButton2->Checked=false;

}
//---------------------------------------------------------------------------

