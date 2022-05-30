//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class multitask2 : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall multitask2(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
