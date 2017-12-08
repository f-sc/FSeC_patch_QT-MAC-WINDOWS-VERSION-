//---------------------------------------------------------------------------

#ifndef offs_calcH
#define offs_calcH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>

//---------------------------------------------------------------------------
#include <sstream>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TLabel *Label1;
	TButton *Button1;
	TLabel *Label2;
	TLabel *Label3;
	TButton *Button2;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------


int calculate(UnicodeString str)
{
int dec;
std::string hex(AnsiString(str).c_str());
std::istringstream stream(hex);
stream >> std::hex >> dec;
return dec;
}

std::string get_hex(int val)
{
	std::stringstream stream;
	stream << std::hex << val;
	std::string result(stream.str());
	return result;
}
#endif
