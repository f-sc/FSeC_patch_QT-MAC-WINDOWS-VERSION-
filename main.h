//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Buttons.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.PlatformDefaultStyleActnCtrls.hpp>
//---------------------------------------------------------------------------
class TForm16 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *About1;
	TMenuItem *Help1;
	TListBox *ListBox1;
	TListBox *ListBox2;
	TRadioButton *RadioButton2;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label1;
	TLabel *Label2;
	TPanel *Panel2;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TMenuItem *InputMode1;
	TMenuItem *OffsetsCalculation1;
	TMenuItem *OpenFile1;
	TStatusBar *StatusBar1;
	TMenuItem *Manual1;
	TRadioButton *HEX;
	TCheckBox *CheckBox1;
	TStringGrid *StringGrid1;
	TMemo *Memo1;
	TEdit *Edit3;
	TButton *Button5;
	TEdit *Edit4;
	TProgressBar *FILE_LOAD_PROGRESS_;
	TBitBtn *SAVE_;
	TBitBtn *OPEN_;
	TLabel *Label3;
	TBitBtn *FORWARD_;
	TBitBtn *BACK_;
	TListBox *ListBox3;
	TBitBtn *BitBtn6;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Open1Click(TObject *Sender);
	void __fastcall About1Click(TObject *Sender);
	void __fastcall OffsetsCalculation1Click(TObject *Sender);
	void __fastcall OpenFile1Click(TObject *Sender);
	void __fastcall Manual1Click(TObject *Sender);
	void __fastcall HEXClick(TObject *Sender);
	void __fastcall RadioButton2Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall Export1Click(TObject *Sender);
	void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall StringGrid1MouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall StringGrid1DblClick(TObject *Sender);
	void __fastcall OPEN_Click(TObject *Sender);
	void __fastcall SAVE_Click(TObject *Sender);
	void __fastcall BACK_Click(TObject *Sender);
	void __fastcall BitBtn6Click(TObject *Sender);
	void __fastcall FORWARD_Click(TObject *Sender);






private:	// User declarations
public:		// User declarations
	__fastcall TForm16(TComponent* Owner);
};
void add_item(AnsiString Data);
void backup(bool create, bool back);
UnicodeString backup_Str = NULL;
//---------------------------------------------------------------------------
extern PACKAGE TForm16 *Form16;
//---------------------------------------------------------------------------
#endif
