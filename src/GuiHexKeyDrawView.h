/*
	GuiHexKeyDrawView.h
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYDRAWVIEW_H
#define GUIHEXKEYDRAWVIEW_H
#endif

#ifndef _HEX_H
#include "hex.h"
#endif

class DrawView : public BView
{

public:
              DrawView(BRect frame, char *name); 
virtual	void  AttachedToWindow();
virtual	void  Draw(BRect updateRect);
        void  DrawKeys();
virtual void  MouseDown(BPoint point);
        void  KeyPressDetected();
        void  IndicizeKeysPressed(uint8 keystatus[16]);
//	BString   intToBStringOfBits(uint8 aByteValue);
	 BString  HexValueKeysPressed();
        void  HighlightKeyPressed(int intPressed);
        void  HighlightAllKeysPressed();

private:
	BRect			 arrTasti[128];
	bool			 arrPremuto[128];
//	HexKeyView 		*parentView;
	BStringView     *lbl1;
	BStringView     *lbl2;
	BStringView		*lbl3;
	
};
