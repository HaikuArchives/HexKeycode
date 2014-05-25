/*
	GuiHexKeyTablesView.cpp
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYAPP_H
#include "GuiHexKeyApp.h"
#endif

#ifndef GUIHEXKEYTABLESWINDOW_H
#include "GuiHexKeyTablesWindow.h"
#endif

#ifndef GUIHEXKEYTABLESVIEW_H
#include "GuiHexKeyTablesView.h"
#endif

HexKeyTablesView::HexKeyTablesView(BRect rect, char *name)
	: BView(rect, name, B_FOLLOW_ALL, B_WILL_DRAW)
{	
	
}

void HexKeyTablesView::AttachedToWindow() 
{
	BRect listRect;
	
	listRect.Set(10, 10, 205, 310);
	
	list = new BListView(listRect, "Utf8Tables");
	
	BString      aString;
	UnicodeTable aTable;
	
	for (int i = 0; i < aTable.GetNum(); i++)
	{
		aString = aTable.GetTableNameByTableNum(i);
		list->AddItem(new BStringItem(aString.String()));
	}
	
	AddChild(new BScrollView("scroll_tables", list, B_FOLLOW_LEFT | B_FOLLOW_TOP, 0, false, true));
	
	BRect buttonRect;
	buttonRect.Set(15, 320, 105, 340);
	
	BButton * button = new BButton(buttonRect, NULL, LABEL_CANCEL, new BMessage(COMMAND_TABLE_CANCEL), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	AddChild(button);
	
	buttonRect.Set(125, 320, 215, 340);
	
	button = new BButton(buttonRect, NULL, LABEL_SELECT, new BMessage(COMMAND_TABLE_MODIFY), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	AddChild(button);
	
}

int32 HexKeyTablesView::GetSelectedIndex()
{
	int32 selected;
	
	selected = list->CurrentSelection(0);
	
	return (selected);
	
}

void HexKeyTablesView::Draw(BRect updateRect)
{
	
}
