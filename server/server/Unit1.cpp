//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
void connect();
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
Memo1->Lines->Clear();
Button1->Enabled=true;
Button2->Enabled=false;

Form1->ServerSocket1->Port=Form1->Edit2->Text.ToInt();
   Form1->ServerSocket1->Active=true;
 Form1->Memo1->Lines->Add("Server Connected");


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
ServerSocket1->Active=false;
Memo1->Lines->Clear();
 Form1->Memo1->Lines->Add("Server Disconnected");
 Button2->Enabled=true;
Button1->Enabled=false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{


if(ServerSocket1->Socket->Connections[0]->SendText(Edit3->Text))
Memo1->Lines->Add("- Server" + Edit3->Text);
}
//---------------------------------------------------------------------------




void __fastcall TForm1::ServerSocket1ClientWrite(TObject *Sender, TCustomWinSocket *Socket)

{
Memo1->Lines->Add(Socket->ReceiveText());
}
//---------------------------------------------------------------------------
