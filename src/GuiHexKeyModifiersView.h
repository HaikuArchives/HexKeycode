/*
	GuiHexKeyModifiersView.h
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYMODIFIERSVIEW_H
#define GUIHEXKEYMODIFIERSVIEW_H
#endif

#ifndef _VIEW_H
#include <View.h>
#endif

#ifndef _BOX_H
#include <Box.h>
#endif

#ifndef _RADIOBUTTON_H
#include <RadioButton.h>
#endif

#ifndef _BUTTON_H
#include <Button.h>
#endif

#ifndef _STRING_H
#include <String.h> 
#endif

#ifndef _KEYMAP_H
#include "keymap.h"
#endif

class GuiHexKeyModifiersView : public BView
{

public:
              GuiHexKeyModifiersView(BRect frame, char *name, int KeyNum);
virtual	void  AttachedToWindow();
virtual	void  Draw(BRect updateRect);
	 	
private:
		int   KeyIndex;
	   BRect  aBoxRect;
BRadioButton  *notmod;
BRadioButton  *caps;
BRadioButton  *scroll;
BRadioButton  *num;
BRadioButton  *leftshift;
BRadioButton  *rightshift;
BRadioButton  *leftcommand;
BRadioButton  *rightcommand;
BRadioButton  *leftcontrol;
BRadioButton  *rightcontrol;
BRadioButton  *leftoption;
BRadioButton  *rightoption;
BRadioButton  *menu;

};

