/*
	GuiHexKeyView.cpp
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

HexKeyView::HexKeyView(BRect rect, char *name)
    : BView(rect, name, B_FOLLOW_ALL, B_WILL_DRAW)
{
	
}

void HexKeyView::AttachedToWindow() 
{
    
    BBox *aBox;
    BRect aBoxRect;
	aBoxRect.Set(10, 10, 370, 270);
    
    aBox = new BBox(aBoxRect, "Box1", B_FOLLOW_NONE);
    aBox->SetLabel(LABEL_BOX_TITLE);
    AddChild(aBox);
    
    BRect drawRect;
	drawRect.Set(10, 10, 340, 240);
	
	DrawView *drawView;
	drawView = new DrawView(drawRect, "DrawView");
	drawView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	drawView->SetLowColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	aBox->AddChild(drawView);
	
}

void HexKeyView::Draw(BRect)
{
	
}
