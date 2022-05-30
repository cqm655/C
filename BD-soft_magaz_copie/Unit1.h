//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Grids.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class Tfmain : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TImage *Image1;
	TLabel *Label2;
	TLabel *Label3;
	TImage *Image2;
	TImage *Image3;
	TImage *Image4;
	TImage *Image5;
	TImage *Image6;
	TPanel *Panel2;
	TEdit *Edit1;
	TImageList *ImageList1;
	TImageList *ImageList2;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TPanel *Panel3;
	TPanel *Panel4;
	TLabel *Label10;
	TLabel *Label9;
	TLabel *Label8;
	TPanel *Panel5;
	TImage *Image7;
	TLabel *Label11;
	TImage *Image8;
	TLabel *Label12;
	TImage *Image9;
	TLabel *Label13;
	TPanel *Panel6;
	TImage *Image10;
	TLabel *Label14;
	TLabel *Label15;
	TPanel *Panel7;
	TImage *Image11;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TPanel *Panel8;
	TLabel *Label19;
	TEdit *Edit2;
	TPanel *Panel9;
	TImage *Image12;
	TLabel *Label20;
	TLabel *Label21;
	TPanel *Panel10;
	TDBGrid *DBGrid1;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TTimer *Timer1;
	TPanel *Panel11;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	TEdit *Edit3;
	TButton *Button4;
	TButton *Button5;
	TCheckBox *CBclient;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton7;
	TSpeedButton *SpeedButton9;
	TImage *Image13;
	TImage *Image14;
	TImage *Image15;
	TSpeedButton *SpeedButton8;
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall CBclientClick(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall SpeedButton9Click(TObject *Sender);
	void __fastcall SpeedButton8Click(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall Tfmain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfmain *fmain;
//---------------------------------------------------------------------------
#endif
