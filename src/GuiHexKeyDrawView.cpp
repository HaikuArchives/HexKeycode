/*
	GuiHexKeyDrawView.cpp
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYAPP_H
#include "GuiHexKeyApp.h"
#endif

#ifndef GUIHEXKEYWINDOW_H
#include "GuiHexKeyWindow.h"
#endif

#ifndef GUIHEXKEYVIEW_H
#include "GuiHexKeyView.h"
#endif

#ifndef GUIHEXKEYDRAWVIEW_H
#include "GuiHexKeyDrawView.h"
#endif

#ifndef GUIHEXKEYINFOWINDOW_H
#include "GuiHexKeyInfoWindow.h"
#endif

DrawView::DrawView(BRect rect, char *name)
    : BView(rect, name, B_FOLLOW_ALL, B_WILL_DRAW)
{
		
	int xstart;
	int ystart;
	int larg_x;
	int larg_y;
	
	xstart = 15;
	ystart = 15;
	larg_x = 15;
	larg_y = 15;
	
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int x1;
			int y1;
			int x2;
			int y2;
			
			x1 = xstart + (larg_x + 4) * i;
			y1 = ystart + (larg_y + 4) * j;
			x2 = x1 + larg_x;
			y2 = y1 + larg_y;
			
			int arrIndex;
			
			arrIndex = i + j * 16; 
			
			arrTasti[arrIndex].Set(x1, y1, x2, y2);
				
		}
	
	}
	
}

void DrawView::AttachedToWindow() 
{
    
    BRect lbl1Rect;
	lbl1Rect.Set(10, 180, 340, 190);
	
	lbl1 = new BStringView(lbl1Rect, "lbl1", LABEL_TITLE_KEY_PRESSED, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	AddChild(lbl1);
	
	BRect lbl2Rect;
	lbl2Rect.Set(10, 200, 340, 210);
	
	lbl2 = new BStringView(lbl2Rect, "lbl2", LABEL_KEY_PRESSED, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	AddChild(lbl2);
	
	BRect lbl3Rect;
	lbl3Rect.Set(10, 220, 340, 230);
	
	lbl3 = new BStringView(lbl3Rect, "lbl3", LABEL_INSTRUCTIONS, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	AddChild(lbl3);
	
}

void DrawView::MouseDown(BPoint point)
{
	
	HexKeyInfoWindow	*aWindow;
    BRect 			 	 aRect;
	
	for (int i = 0; i < 128; i++)
	{
		if (arrTasti[i].Contains(point))
		{
			aRect.Set(150, 250, 610, 585);
    		aWindow = new HexKeyInfoWindow(aRect, i);
    		break;
    	}
    }

}

/*
BString DrawView::intToBStringOfBits(uint8 aByteValue)
{
	BString bitsString;
	BString	tmpString;
	
	bitsString.SetTo("");
	tmpString.SetTo("");
			
	while (aByteValue > 0)
	{
		tmpString << (int)(aByteValue % 2);
		aByteValue = aByteValue / 2;
	}
			
	for (int j = 8 - tmpString.CountChars(); j > 0 ; j--)
	{
		tmpString <<  "0";
	}
			
	for (int j = 8 - 1; j >= 0 ; j--)
	{
		bitsString << tmpString[j];
	}
	
	return(bitsString);
	
}
*/

void  DrawView::HighlightKeyPressed(int intPressed)
{
	SetHighColor(250, 210, 0);
	
	FillRect(arrTasti[intPressed], B_SOLID_HIGH);

}

void  DrawView::HighlightAllKeysPressed()
{
	SetHighColor(250, 210, 0);
	
	for (int i = 0; i < 128; i++)
	{
		if (arrPremuto[i])
		{
				FillRect(arrTasti[i], B_SOLID_HIGH);
		}
	}
	
}

void DrawView::IndicizeKeysPressed(uint8 keystatus[16])
{
	
	uint8	aByteValue;
	
	for (int i = 0; i < 128; i++)
	{
		arrPremuto[i] = false;
	}
	
	for (int i = 0; i < 16; i++)
	{
		aByteValue = keystatus[i];
		
		int pos;
		int decimal;
		
		pos = 1;
		decimal = 0;
		
		while (aByteValue > 0)
		{
			
			if ((aByteValue % 2) == 1)
			{
				decimal = (8 - (pos -1)) + i * 8 - 1;
				arrPremuto[decimal] = true;
			}
			
			aByteValue = aByteValue / 2;
			pos++;
		}
		
	}
		
}

BString DrawView::HexValueKeysPressed()
{
	BString  labelHex;
	   bool	 NotFirst;
	    Hex  hexConv;
	
	labelHex.SetTo("");
	NotFirst = false;
	
	for (uint8 i = 0; i < 128; i++)
	{
		if (arrPremuto[i])
		{
			if (NotFirst) labelHex << "; ";
			labelHex << (int)i << " - ";
			labelHex << "0x";
			hexConv.Set(i);
			labelHex << hexConv.GetString();
			NotFirst = true;
		}
		
	}
	
	return(labelHex);
	
}

void  DrawView::DrawKeys()
{
	
	SetHighColor(50, 150, 25);
	
	for (int i = 0; i < 128; i++)
	{
		FillRect(arrTasti[i], B_SOLID_HIGH);
	}
	
}

void DrawView::KeyPressDetected()
{
	key_info *newkeystatus = new key_info;
	
	uint8 	states[16];
	uint32	modifiers;
	bool	badDetection;
		
	get_key_info(newkeystatus);
	
	badDetection = true;
		
	for (int i = 0; i < 16; i++)
	{
		states[i] = newkeystatus->key_states[i];
		badDetection = badDetection && (states[i] == 0);
	}
	  		
	modifiers = newkeystatus->modifiers;
	  		
	if (!(badDetection))
	{
		BString strHexValue;
		
		IndicizeKeysPressed(states);
		
		strHexValue = HexValueKeysPressed();
		lbl2->SetText(strHexValue.String());
		
		DrawKeys();
		HighlightAllKeysPressed();
		
	}
	
}

void DrawView::Draw(BRect updateRect)
{
	DrawKeys();
	HighlightAllKeysPressed();
}
