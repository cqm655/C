//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class Tfreceptie : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TPanel *Panel2;
	TPanel *Panel3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit1;
	TEdit *Edit3;
	TButton *Button1;
	TDateTimePicker *DateTimePicker1;
	TPanel *Panel4;
	TDBGrid *DBGrid1;
	TPanel *Panel5;
	TPanel *Panel6;
	TPageControl *PageControl2;
	TTabSheet *TabSheet6;
	TTabSheet *TabSheet7;
	TTabSheet *TabSheet8;
	TDBGrid *DBGrid2;
	TPanel *Panel7;
	TPanel *Panel8;
	TDBGrid *DBGrid3;
	TButton *Button7;
	TPanel *Panel10;
	TPanel *Panel11;
	TRadioButton *rb1;
	TRadioButton *rb2;
	TEdit *ecautare;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TPanel *Panel12;
	TLabel *Label13;
	TEdit *Edit11;
	TLabel *Label14;
	TEdit *Edit12;
	TButton *Button17;
	TButton *Button18;
	TPanel *Panel13;
	TLabel *Label5;
	TEdit *Edit2;
	TButton *Button2;
	TLabel *Label6;
	TEdit *Edit4;
	TButton *Button3;
	TLabel *Label9;
	TEdit *Edit7;
	TLabel *Label10;
	TDateTimePicker *DateTimePicker2;
	TLabel *Label7;
	TEdit *Edit5;
	TEdit *Edit6;
	TButton *Button6;
	TButton *Button5;
	TButton *Button4;
	TLabel *Label8;
	TLabel *Label15;
	TEdit *Edit10;
	TLabel *Label16;
	TEdit *Edit13;
	TButton *Button21;
	TButton *Button22;
	TImage *Image1;
	TSpeedButton *SpeedButton1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall ecautareChange(TObject *Sender);
	void __fastcall rb1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button17Click(TObject *Sender);
	void __fastcall Button18Click(TObject *Sender);
	void __fastcall DBGrid2DblClick(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall Button21Click(TObject *Sender);
	void __fastcall Button22Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall Tfreceptie(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfreceptie *freceptie;
//---------------------------------------------------------------------------
#endif
