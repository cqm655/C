//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFcec : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TLabel *Label1;
	TDateTimePicker *DT1;
	TLabel *Label2;
	TDateTimePicker *DT2;
	TLabel *Label3;
	TLabel *Label4;
	TSpeedButton *Cauta;
	TPanel *Panel4;
	TPanel *Panel5;
	TDBGrid *DBGrid1;
	TDBGrid *DBGrid2;
	TSpeedButton *SpeedButton1;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TSpeedButton *SpeedButton2;
	void __fastcall CautaClick(TObject *Sender);
	void __fastcall DBGrid2CellClick(TColumn *Column);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFcec(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFcec *Fcec;
//---------------------------------------------------------------------------
#endif