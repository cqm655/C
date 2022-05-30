//---------------------------------------------------------------------------

#include <vcl.h>
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

void __fastcall TForm2::open1Click(TObject *Sender)
{
	if(OpenDialog1->Execute())
	{
		Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
		Form2->Caption=OpenDialog1->FileName;
		a=True;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::saveas1Click(TObject *Sender)
{
if(SaveDialog1->Execute())
{

	Memo1->Lines->SaveToFile(SaveDialog1->FileName);
	

}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::New1Click(TObject *Sender)
{
Memo1->Lines->Clear();

Form2->Caption="Untitled.txt";

}
//---------------------------------------------------------------------------

void __fastcall TForm2::exit1Click(TObject *Sender)
{
 Application->Terminate();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::save1Click(TObject *Sender)
{
if(a)
{
 Memo1->Lines->SaveToFile(OpenDialog1->FileName);
}
else
{
 saveas1->OnClick(Sender);
}
}
//---------------------------------------------------------------------------

