//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class MT4 : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall MT4(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif