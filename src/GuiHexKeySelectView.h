/*
	GuiHexKeySelectView.h
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYSELECTVIEW_H
#define GUIHEXKEYSELECTVIEW_H
#endif

#ifndef _VIEW_H
#include <View.h>
#endif

#ifndef _BUTTON_H
#include <Button.h>
#endif

#ifndef _STRINGVIEW_H
#include <StringView.h>
#endif

#ifndef _TEXTLISTCONTROL_H
#include <TextListControl.h>
#endif

#ifndef _STRING_H
#include <String.h> 
#endif

#ifndef _CSTDLIB_H
#include <cstdlib>
#endif

#ifndef _CHAR_H
#include "char.h"
#endif

#ifndef _HEX_H
#include "hex.h"
#endif

#ifndef _KEYMAP_H
#include "keymap.h"
#endif

#ifndef _UNICODETABLE_H
#include "UnicodeTable.h"
#endif

class HexKeySelectView : public BView
{

public:
              HexKeySelectView(BRect frame, char *name, int numKeymap, int numKey);
        void  NextPage();
        void  PrevPage();
        void  TableChanged();
virtual	void  AttachedToWindow();
virtual void  MouseDown(BPoint point);
        void  ModifyRequested();
	 	bool  HasBeenSelected();
	    bool  CheckHasGlimphs(BChar aChar);
        void  SetColorByTableNum(int tablenum);
        void  FillRegion(int i, int j, int value);
virtual	void  Draw(BRect updateRect);
	 	
private:
		int	  PageIndex;
	 	bool  Selected;
	  BChar   SelectedChar;
	    int   KeymapNum;
	    int   KeyNum;
	   bool   HasGlymphs;
	    int   TablePages[104];
BStringView   *lbl1;
BStringView   *lbl2;
 BTextListControl  *textlist;
BStringChoiceList  *aChoiceList;

        void initChoiceList();
        void initTablesPages();

};

