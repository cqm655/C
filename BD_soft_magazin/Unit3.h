//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MSSQL.hpp>
#include <FireDAC.Phys.MSSQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include "Project1PCH1.h"
#include "Project1PCH1.h"
#include "Project1PCH1.h"
#include "Project1PCH1.h"
#include "Unit2.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit4.h"
#include "Unit2.h"
#include "Unit2.h"
#include "Unit1.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit4.h"
#include "Project1PCH1.h"
#include "Project1PCH1.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit4.h"
#include "Unit1.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit2.h"
#include "Project1PCH1.h"
#include "Project1PCH1.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit4.h"
#include "frxClass.hpp"
#include "frxDBSet.hpp"

//---------------------------------------------------------------------------
class Tdm : public TDataModule
{
__published:	// IDE-managed Components
	TFDConnection *FDConnection1;
	TFDQuery *QUM;
	TDataSource *DSQUM;
	TFDQuery *qprodus;
	TDataSource *dsqprodus;
	TFDStoredProc *FDStoredProc1;
	TFDQuery *qliber;
	TFDQuery *qedit;
	TFDQuery *qreceptie;
	TDataSource *dsqreceptie;
	TFDQuery *qvanzare;
	TDataSource *dsqvanzare;
	TFDStoredProc *proccec;
	TFDQuery *qliber2;
	TFDQuery *qcec;
	TDataSource *dsqcec;
	TfrxReport *R1;
	TfrxDBDataset *frxDBDataset1;
	TFDQuery *qtotalcec;
	TDataSource *DataSource1;
	TfrxDBDataset *frxDBDataset2;
	TfrxReport *R2;
	TfrxDBDataset *frxDBDataset3;
	TfrxReport *frxcec;
	TfrxDBDataset *frxDBDataset4;
private:	// User declarations
public:		// User declarations
	__fastcall Tdm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tdm *dm;
//---------------------------------------------------------------------------
#endif