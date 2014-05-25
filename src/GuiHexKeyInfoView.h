/*
	GuiHexKeyInfoView.h
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYINFOVIEW_H
#define GUIHEXKEYINFOVIEW_H
#endif

#ifndef _VIEW_H
#include <View.h>
#endif

#ifndef _BOX_H
#include <Box.h>
#endif

#ifndef _STRINGVIEW_H
#include <StringView.h>
#endif

#ifndef _BUTTON_H
#include <Button.h>
#endif

#ifndef _INTERFACEDEFS_H
#include <interface/InterfaceDefs.h>
#endif

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STRING_H
#include <String.h> 
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

#ifndef _HEX_H
#include "hex.h"
#endif

#ifndef _CHAR_H
#include "char.h"
#endif

#ifndef _KEYMAP_H
#include "keymap.h"
#endif

class HexKeyInfoView : public BView
{

public:
              HexKeyInfoView(BRect frame, char *name); 
virtual	void  AttachedToWindow();
virtual	void  Draw(BRect updateRect);
        void  SetIndex(int index);
	     int  GetIndex();
        void  SetSelectedKeymap(int index);
        void  SetSelectedChar(char arrChars[3], int count);
	 BString  RetrieveKeyFromKeymap(BChar aChar);
        void  UptadeLabels();
	 
private:
		int	  KeyMapIndex;
	  BRect   aBoxRect;
		int   SelectedKeyMapNum;
	   char   SelectedChar[3];
	    int   SelectedCharCount;
		
	BString	  NormalKey;
	BString	  ShiftKey;
	BString   CapsKey;
	BString   CapsShiftKey;
	BString   OptionKey;
	BString   OptionShiftKey;
	BString   OptionCapsKey;
	BString   OptionCapsShiftKey;
	BString   ControlKey;
BStringView   *lbl0;
BStringView   *lbl1;
BStringView   *lbl2;
BStringView   *lbl3;
BStringView   *lbl4;
BStringView   *lbl5;
BStringView   *lbl6;
BStringView   *lbl7;
BStringView   *lbl8;
BStringView   *lbl9;

};

