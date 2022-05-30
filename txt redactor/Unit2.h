//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *file1;
	TMenuItem *open1;
	TMenuItem *saveas1;
	TMenuItem *exit1;
	TOpenDialog *OpenDialog1;
	TMemo *Memo1;
	TSaveDialog *SaveDialog1;
	TMenuItem *New1;
	TLabel *Label1;
	TMenuItem *save1;
	void __fastcall open1Click(TObject *Sender);
	void __fastcall saveas1Click(TObject *Sender);
	void __fastcall New1Click(TObject *Sender);
	void __fastcall exit1Click(TObject *Sender);
	void __fastcall save1Click(TObject *Sender);
private:	// User declarations
public:
bool a;		// User declarations
	__fastcall TForm2(TComponent* Owner);


};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
