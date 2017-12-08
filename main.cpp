//---------------------------------------------------------------------------

#include <vcl.h>
#include <Windows.h>
#include <stdio.h>
#include <vector>
#include <io.h>
#include <stack>
#include <string>
#include <algorithm>
#pragma hdrstop

#include "main.h"
#include "offs_calc.h"
#include "help.h"
#include "hx.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm16 *Form16;

typedef void(__cdecl *function)(char*, int,std::vector<int>, std::vector<int>);

String filename = NULL;
void load_file();

std::vector<std::string> value;
std::vector<UnicodeString> backup_it;


 int backup_iterats = 0;


char *filen;

int offs = 0;
int value_off_x=0;
int value_off_y=0;
int file_size_I=0;

template<class type> class patch
{
	std::vector<type> offset;
	std::vector<type> data;
  public:
	type set_offs_data(type offset, type data);
	void func_setup();
};



template<class type>
type patch<type>::set_offs_data(type offset, type data)
{
	this->offset.push_back(offset);
	this->data.push_back(data);
	//MessageBox(NULL, "Offset and data ready", "Alert!", 0);

	return 0;
}
String file_opn()
{
  if(Form16->OpenDialog1->Execute())
  {
  return (Form16->OpenDialog1->FileName);
  }
  return NULL;
}

/*HMODULE LoadModule()
{
	HMODULE hDLL = LoadLibrary(TEXT("patch.dll"));
	if(!hDLL)
	{
	MessageBox(NULL,"Error while loading DLL", "Error", 0);
	}
	else
	{
		MessageBox(NULL, "DLL LOADED", "ALL_OK", 0);
		return hDLL;
	}
	return NULL;
}          */
template<class type>
void  patch<type>::func_setup()
{

if(filename!=NULL)
{
mf(AnsiString(filename).c_str(), offset.size(), offset, data);
}
else
{
	Form16->Memo1->Lines->Add("No file chosen!");
}
/*HMODULE LOADED = LoadModule();
if(LOADED)
{
	function patch =(function)GetProcAddress(LOADED, "mf");
   if(patch)
	{

		patch("23.exe", offset.size(), offset, data);
	}
	else
	{
		MessageBox(NULL, L"Error", L"Error", 0);
	}
}   */
}
void mf(char* filename, int offs_count, std::vector<int> offset, std::vector<int>data)
{

	FILE *fp;
	char ex;
	char * buffer = new char[25];
	//int offset_to_use = offset[0];
	//int data_to_use = data[0];
	//int offset[1] = { 1689 };
	//char data[1] = { 117 };
	fopen_s(&fp, filename, "r+");
	if (!fp)
	{
		MessageBox(NULL, "Error while patching", "Error", 0);
		Form16->Memo1->Lines->Add("Error while opening the file... "+AnsiString(__TIME__));
	}
	else
	{
	Form16->Memo1->Lines->Add("Working with file at: "+AnsiString(__TIME__));
		for (int j = 0; j < offs_count; j++)
		{
			fseek(fp, offset[j], SEEK_SET);
			fprintf(fp, "%c", char(data[j]));
		}
		/*fseek(fp, 1281, SEEK_SET);
		fread(buffer,4,1, fp);    */
	   /*ShowMessage(buffer);
	   ShowMessage(int(buffer[0]));
	   ShowMessage(AnsiString(get_hex(77).c_str()));  */
		Form16->StatusBar1->Panels->Items[0]->Text="File patched";
		Form16->Memo1->Lines->Add("File successfully patched... "+AnsiString(__TIME__));
		fclose(fp);
	}
}

patch<int> path;

//---------------------------------------------------------------------------
__fastcall TForm16::TForm16(TComponent* Owner)
	: TForm(Owner)
{


}
//---------------------------------------------------------------------------
void add_item(AnsiString Data)
{
int offset, data;
offset = offs;
data =  calculate(Data);
Form16->ListBox2->AddItem(Data, 0);

//Form16->ListBox3->AddItem();
//Form16->StringGrid1->Cells[value_off_y, value_off_x]=Data;
//Form16->StringGrid1->Col[value_off_y]->Row[0]=Data;
Form16->StringGrid1->Cols[value_off_x]->Strings[value_off_y]=Data;
if(Form16->RadioButton2->Checked==true)
{
path.set_offs_data(Form16->Edit1->Text.ToInt(), data);
Form16->ListBox1->AddItem(Form16->Edit1->Text, 0);
}
else
{
 path.set_offs_data(offset,data);
 Form16->ListBox1->AddItem(offset+'('+offset+')', 0);
}
  Form16->StatusBar1->Panels->Items[0]->Text="Data loaded";
  Form16->Memo1->Lines->Add("Data loaded... "+AnsiString(__TIME__));
}
void __fastcall TForm16::Button1Click(TObject *Sender)
{
  add_item(Edit2->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm16::Open1Click(TObject *Sender)
{
 MessageBox(NULL, "We are going to open a file to work straightly with it. Maybe create a backup?", "Warning", MB_YESNO);
 filename = file_opn();
  load_file();
 StatusBar1->Panels->Items[0]->Text=filename;
}
//---------------------------------------------------------------------------

void __fastcall TForm16::About1Click(TObject *Sender)
{
MessageBox(NULL, "Coded by 2ima", "FSeC TEAM", 0);
}
//---------------------------------------------------------------------------


void __fastcall TForm16::OffsetsCalculation1Click(TObject *Sender)
{
Form1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm16::OpenFile1Click(TObject *Sender)
{
  OPEN_->Click();
}
//---------------------------------------------------------------------------



void __fastcall TForm16::Manual1Click(TObject *Sender)
{
Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm16::HEXClick(TObject *Sender)
{
RadioButton2->Checked=false;
Edit1->NumbersOnly=false;
Edit2->NumbersOnly=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm16::RadioButton2Click(TObject *Sender)
{
HEX->Checked=false;
Edit1->NumbersOnly=true;
Edit2->NumbersOnly=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm16::CheckBox1Click(TObject *Sender)
{
if(CheckBox1->Checked)
{
Form16->FormStyle=3;
}
else
{
Form16->FormStyle=4;
}
}
//---------------------------------------------------------------------------

int file_size(FILE *fp)
{
 /*	FILE *fp;
	fopen_s(filename, "rb+");    */
	fseek(fp, 00000, SEEK_END);
	return ftell(fp);
}

void load_file()
{
	FILE *fp;
	char ex;
	char * buffer = new char[30];
	int string =1;
	int col_str=0;
	//std::bitset<32> b;
	//int offset_to_use = offset[0];
	//int data_to_use = data[0];
	//int offset[1] = { 1689 };
	//char data[1] = { 117 };
	fopen_s(&fp, AnsiString(filename).c_str(), "r+");
	if (!fp)
	{
		//MessageBox(NULL, "Error while opening the file", "Error", 0);
		Form16->Memo1->Lines->Add("Error while opening the file... "+AnsiString(__TIME__));
	}
	else
	{
	Form16->Memo1->Lines->Add("File opening at: "+AnsiString(__TIME__));
	file_size_I=file_size(fp);
	Form16->StringGrid1->RowCount=file_size_I;
	Form16->FILE_LOAD_PROGRESS_->Max=file_size_I;
	for(int y=0; y<file_size_I; y+=16)
	{
	  col_str++;
	  Form16->FILE_LOAD_PROGRESS_->Position=y;
	 Form16->StringGrid1->Cols[0]->Strings[col_str]="00"+AnsiString((get_hex(y).c_str()));
	 fseek(fp, y, SEEK_SET);
	fread(buffer,16,1, fp);
	for(int i=0; i<16; i++)
	{
	Form16->StringGrid1->Cols[i+1]->Strings[0]=AnsiString(get_hex(i).c_str());
	  value.resize(i);
	  value.push_back(get_hex(int(buffer[i])));
	  Form16->StringGrid1->Cols[i+1]->Strings[string]=AnsiString(value[i].c_str());
	  if(i==15)
	  {
		string++;
	  }
	  }
	}
	fclose(fp);
	}

}

void __fastcall TForm16::Export1Click(TObject *Sender)
{
//Memo1->Lines->Add(ListBox1->Items->Strings);
}
//---------------------------------------------------------------------------

void __fastcall TForm16::StringGrid1SelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect)
{
//ShowMessage((ARow*16)-16);
//ShowMessage(value[ACol]+ARow);
/*ShowMessage(StringGrid1->Cols[ACol]->Strings[ARow]);
ShowMessage(calculate(StringGrid1->Cols[0]->Strings[ARow].ToInt())+calculate(StringGrid1->Cols[ACol]->Strings[0].ToInt()));  */
offs = calculate(StringGrid1->Cols[0]->Strings[ARow])+calculate(StringGrid1->Cols[ACol]->Strings[0]);
value_off_x=ACol;
value_off_y=ARow;
StatusBar1->Panels->Items[1]->Text = StringGrid1->Cols[ACol]->Strings[ARow];
//Form3->Show();
}
//---------------------------------------------------------------------------

char parse(UnicodeString Text)
 {
char last = NULL;
int null_c = 0;
char last_elem = NULL;
bool alles = false;
if(Text!=NULL)
{
AnsiString offset_A(Text);
char *str = new char[offset_A.Length()+1];
strcpy(str, offset_A.c_str());
  //00000000
for(int i=0; i<offset_A.Length(); i++)
{
	if(str[i]=='0'&&str[i-1]=='0')
	{
	  null_c++;
	}
}
int lenED=Text.Length()-null_c-1;
char *offset_I = new char[lenED];
int temp=null_c;
for(int len =0; len<lenED; len++)
{
temp++;

	offset_I[len]=str[temp];
	//ShowMessage(offset_I[len]);
}

last_elem = str[offset_A.Length()-1];
//str[offset_A.Length()-1] = '0';

return  last_elem;
//ShowMessage(calculate(char(offset_I[0])));
//ShowMessage(lenED);
delete [] str;
}
}




void __fastcall TForm16::StringGrid1MouseWheelDown(TObject *Sender, TShiftState Shift,
		  TPoint &MousePos, bool &Handled)
{
/*StringGrid1->Perform(WM_KEYDOWN, VK_NEXT, 0);
StringGrid1->Perform(WM_KEYUP, VK_NEXT, 0);  */
}
//---------------------------------------------------------------------------

void __fastcall TForm16::Button5Click(TObject *Sender)
{
add_item(StringGrid1->Cols[value_off_y]->Strings[value_off_x]);
}
//---------------------------------------------------------------------------


void __fastcall TForm16::StringGrid1DblClick(TObject *Sender)
{
Form3->Visible=true;
//add_item(StringGrid1->Cols[value_off_y]->Strings[value_off_x]);
Form3->Show();
}
//---------------------------------------------------------------------------
namespace hex
{
int stoi(std::string in)
{
	int val=0;
	std::istringstream newstr(in);
	newstr >> val;
	return val;
}
}
std::vector<UnicodeString> revers(std::vector<UnicodeString> vec)
{
 for(int i=vec.size(); i>=0; i--)
 {

 }
}
void backup(bool create, bool back)
{

	 if(create==true)
	 {
	 backup_Str =(Form16->StringGrid1->Cols[value_off_x]->Strings[value_off_y]+'@'+value_off_y+'@'+value_off_x+'@');
	 backup_it.push_back(AnsiString(backup_Str.c_str()));
	 }
	 else
	 {
	 std::reverse(backup_it.begin(), backup_it.end());
	 std::string parsed;
	 std::vector<std::string> all_vals;
	 if(backup_iterats<backup_it.size())
	 {
	 backup_Str=backup_it[backup_iterats];
	 for(int i=1; i<backup_Str.Length()+1; i++)
	 {
		 if(backup_Str[i]!='@')
		 {
	   //	 ShowMessage(backup_Str[i]);
			parsed+=backup_Str[i];

		 }
		 else
		 {
			 all_vals.push_back(parsed);
			 parsed="";
		 }
	 }
	 backup_iterats++;
	  ShowMessage(AnsiString(hex::stoi(all_vals[1])));
	  Form16->StringGrid1->Cols[hex::stoi(all_vals[2])]->Strings[hex::stoi(all_vals[1])]=AnsiString(all_vals[0].c_str());
	 }
	 else
	 {
	   /*	backup_Str="";
		 all_vals.clear();
		 backup_it.clear();
		 backup_iterats=0;     */
	 }
	 }

}



void __fastcall TForm16::OPEN_Click(TObject *Sender)
{
 filename = file_opn();
 load_file();
 StatusBar1->Panels->Items[0]->Text=filename;
}
//---------------------------------------------------------------------------

void __fastcall TForm16::SAVE_Click(TObject *Sender)
{
if(filename==NULL)
{
	if(Form16->SaveDialog1->Execute(NULL))
	{
	   filename = Form16->SaveDialog1->FileName;
	}
}
path.func_setup();
}
//---------------------------------------------------------------------------




void __fastcall TForm16::BACK_Click(TObject *Sender)
{
if(filename!=NULL)
{
backup(false, true);
}
}
//---------------------------------------------------------------------------



void __fastcall TForm16::BitBtn6Click(TObject *Sender)
{
AnsiString offset_INDEX(Edit4->Text.c_str());
int offset_X = calculate(parse(Edit4->Text));
offset_INDEX[offset_INDEX.Length()]='0';
for(int i=0; i<file_size_I; i++)
{
//ShowMessage(offset_X);

	if(StringGrid1->Cols[0]->Strings[i]==(offset_INDEX))
	{
	StringGrid1->Col = offset_X+1;
	StringGrid1->Row = i;
	StatusBar1->Panels->Items[1]->Text = Edit4->Text;
	}
}

}
//---------------------------------------------------------------------------




void __fastcall TForm16::FORWARD_Click(TObject *Sender)
{
backup(false, false);
}
//---------------------------------------------------------------------------



