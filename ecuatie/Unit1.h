//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *egal;
	TButton *clear;
	TEdit *a;
	TComboBox *s;
	TEdit *d;
	TEdit *c;
	TEdit *b;
	TEdit *e;
	TComboBox *s2;
	TComboBox *s1;
	TComboBox *s3;
	TEdit *r;
	TMemo *m;
	TEdit *aa;
	TEdit *p;
	TEdit *bb;
	TEdit *dd;
	TEdit *ccc;
	TEdit *ee;
	TEdit *p1;
	TEdit *p2;
	TEdit *p3;
	TEdit *p4;
	void __fastcall egalClick(TObject *Sender);
	void __fastcall pChange(TObject *Sender);
	void __fastcall p1Change(TObject *Sender);
	void __fastcall p2Change(TObject *Sender);
	void __fastcall p3Change(TObject *Sender);
	void __fastcall p4Change(TObject *Sender);
	void __fastcall aChange(TObject *Sender);
	void __fastcall clearClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
