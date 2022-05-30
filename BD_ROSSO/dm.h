//---------------------------------------------------------------------------

#ifndef dmH
#define dmH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <FireDAC.Phys.MSSQL.hpp>
#include <FireDAC.Phys.MSSQLDef.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Stan.Param.hpp>
//---------------------------------------------------------------------------
class Tdm1 : public TDataModule
{
__published:	// IDE-managed Components
	TFDConnection *FDConnection1;
	TFDQuery *qliber;
	TFDQuery *qshow;
	TDataSource *dsqshow;
	TFDQuery *qedit;
	TFDQuery *qtip;
	TDataSource *dsqtip;
	TDataSource *dsqculoare;
	TDataSource *dsqmaterial;
	TFDQuery *qmaterial;
	TFDQuery *qculoare;
	TFDQuery *qgol;
	TFDQuery *qshowiarna;
	TDataSource *dsqiarna;
	TDataSource *dsqgol;
	TFDQuery *qgol2;
	TFDQuery *qsp;
	TDataSource *DSSP;
	TFDQuery *qsi;
	TDataSource *DSSPiarna;
private:	// User declarations
public:		// User declarations
	__fastcall Tdm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tdm1 *dm1;
//---------------------------------------------------------------------------
#endif