//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "hx.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------




void __fastcall TForm3::Button1Click(TObject *Sender)
{
backup(true, NULL);
add_item(Form3->Edit1->Text);
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Button2Click(TObject *Sender)
{
Form3->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormShow(TObject *Sender)
{
Edit1->Clear();

}
//---------------------------------------------------------------------------


