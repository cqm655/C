//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Error.hpp>
//---------------------------------------------------------------------------

class TForm1 : public TForm
{
__published:	// IDE-managed Components
void __fastcall RAD(TObject *Sender);
void __fastcall X(TObject *Sender);

private: 	// User declarations
public:

TButton *B1;
TButton *B2;

TEdit *E1;
TEdit *E2;
TEdit *E3;

TLabel *L;
TLabel *L1;
TLabel *L2;	// User declarations
	__fastcall TForm1(TComponent* Owner);



};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif