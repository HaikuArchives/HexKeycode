/*
	GuiHexKeyView.h
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYVIEW_H
#define GUIHEXKEYVIEW_H
#endif 

#ifndef _VIEW_H
#include <View.h>
#endif

#ifndef _TEXTCONTROL_H
#include <TextControl.h>
#endif

#ifndef _STRINGVIEW_H
#include <StringView.h>
#endif

#ifndef _BUTTON_H
#include <Button.h>
#endif

#ifndef _BOX_H
#include <Box.h>
#endif

#ifndef _STRING_H
#include <String.h>
#endif

#ifndef _CSTDLIB_H
#include <cstdlib>
#endif

#ifndef _CMATH_H
#include <cmath>
#endif

class HexKeyView : public BView
{

public:
              HexKeyView(BRect frame, char *name); 
virtual	void  AttachedToWindow();
virtual	void  Draw(BRect updateRect);

};


