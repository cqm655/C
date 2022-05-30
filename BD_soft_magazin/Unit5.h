//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TFautentificare : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TEdit *Edit1;
	TEdit *Edit2;
	TImage *Image1;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TComboBox *ComboBox1;
	TLabel *Label1;
	void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFautentificare(TComponent* Owner);
    int utilizator;
};
//---------------------------------------------------------------------------
extern PACKAGE TFautentificare *Fautentificare;
//---------------------------------------------------------------------------
#endif
