//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Memo.Types.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TListBox *ListBox1;
	TButton *Button2;
	TMemo *Memo1;
	TMemo *Memo2;
	TButton *Button3;
	TLabel *Snippets;
	TEdit *Edit2;
	TButton *Button1;
	TEdit *Edit3;
	TButton *Button4;
	TListBox *ListBox2;
	TButton *Button5;
	TButton *Button6;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *key;
	TLabel *code;
	void __fastcall sinp(TObject *Sender);
	void __fastcall Find(TCustomListBox * const Sender, TListBoxItem * const Item);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Find2(TCustomListBox * const Sender, TListBoxItem * const Item);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
