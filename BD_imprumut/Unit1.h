//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Buttons.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.ODBC.hpp>
#include <FireDAC.Phys.ODBCDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Stan.Param.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TTimer *Timer1;
	TLabel *Label10;
	TSpeedButton *SpeedButton1;
	TLabel *Label13;
	TSpeedButton *SpeedButton5;
	TFDConnection *FDConnection1;
	TFDQuery *FDQuery1;
	TDataSource *DataSource1;
	TFDQuery *QCLIENT;
	TDataSource *DSQCLIENT;
	TFDQuery *QPRODUS;
	TDataSource *DSPRODUS;
	TFDQuery *QINREG;
	TFDQuery *QEDIT;
	TLabel *Label26;
	TEdit *Edit11;
	TLabel *Label27;
	TEdit *Edit12;
	TEdit *Edit13;
	TEdit *Edit14;
	TFDQuery *QLIBER;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TPanel *Panel4;
	TImage *Image1;
	TLabel *Label9;
	TLabel *Label11;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TEdit *Edit1;
	TEdit *Edit2;
	TTabSheet *TabSheet2;
	TPanel *Panel5;
	TPanel *Panel10;
	TSpeedButton *SpeedButton9;
	TSpeedButton *SpeedButton10;
	TGroupBox *GroupBox1;
	TEdit *nume;
	TCheckBox *CheckBox1;
	TButton *Button6;
	TPanel *Panel11;
	TDBGrid *DBGrid2;
	TTabSheet *TabSheet3;
	TPanel *Panel6;
	TPanel *Panel8;
	TPageControl *PageControl2;
	TTabSheet *TabSheet6;
	TLabel *Label19;
	TSpeedButton *SpeedButton7;
	TLabel *Label20;
	TSpeedButton *SpeedButton8;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label18;
	TLabel *Label17;
	TDateTimePicker *DateTimePicker3;
	TDateTimePicker *DateTimePicker4;
	TEdit *Edit7;
	TEdit *Edit5;
	TEdit *Edit6;
	TButton *Button3;
	TButton *Button4;
	TEdit *Edit4;
	TTabSheet *TabSheet7;
	TButton *Button5;
	TTabSheet *TabSheet5;
	TLabel *Label15;
	TLabel *Label16;
	TSpeedButton *SpeedButton6;
	TLabel *Label14;
	TSpeedButton *SpeedButton4;
	TLabel *Label12;
	TLabel *Label23;
	TLabel *Label24;
	TButton *Button1;
	TButton *Button2;
	TDateTimePicker *DateTimePicker1;
	TDateTimePicker *DateTimePicker2;
	TEdit *Edit3;
	TEdit *Edit9;
	TEdit *Edit10;
	TEdit *Edit88;
	TPanel *Panel9;
	TDBGrid *DBGrid1;
	TTabSheet *TabSheet4;
	TPanel *Panel7;
	TPanel *Panel12;
	TSpeedButton *SpeedButton11;
	TSpeedButton *SpeedButton12;
	TPanel *Panel13;
	TDBGrid *DBGrid3;
	TTabSheet *TabSheet8;
	TPanel *Panel14;
	TPanel *Panel15;
	TPageControl *PageControl3;
	TTabSheet *TabSheet11;
	TButton *Button10;
	TButton *Button11;
	TDateTimePicker *DateTimePicker7;
	TDateTimePicker *DateTimePicker8;
	TEdit *Edit19;
	TEdit *Edit20;
	TEdit *Edit22;
	TPanel *Panel16;
	TDBGrid *DBGrid4;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TCheckBox *CheckBox5;
	TCheckBox *CheckBox6;
	TCheckBox *CheckBox7;
	TEdit *Edit15;
	TFDQuery *QCAUTA;
	TDataSource *DSQCAUTA;
	TFDQuery *QDELETE;
	TEdit *prenume;
	TEdit *strada;
	TEdit *telefon;
	TEdit *idnp;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton9Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall SpeedButton10Click(TObject *Sender);
	void __fastcall SpeedButton12Click(TObject *Sender);
	void __fastcall SpeedButton11Click(TObject *Sender);
	void __fastcall SpeedButton8Click(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall SpeedButton7Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall CheckBox6Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
