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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Memo1->Lines->Clear();
Button1->Enabled=0;
Button2->Enabled=1;

  ClientSocket1->Host=Edit1->Text;
  ClientSocket1->Port=Edit2->Text.ToInt();
  ClientSocket1->Active==1;
  Memo1->Lines->Add("Connected");




}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 Memo1->Lines->Clear();
Button1->Enabled=1;
Button2->Enabled=0;
ClientSocket1->Active=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket)

{
 Memo1->Lines->Add(Socket->ReceiveText());


}
//
//---------------------------------------------------------------------------


