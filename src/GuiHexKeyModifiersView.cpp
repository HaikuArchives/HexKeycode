/*
	GuiHexKeyModifiersView.cpp
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYAPP_H
#include "GuiHexKeyApp.h"
#endif

#ifndef GUIHEXKEYMODIFIERSWINDOW_H
#include "GuiHexKeyModifiersWindow.h"
#endif

#ifndef GUIHEXKEYMODIFIERSVIEW_H
#include "GuiHexKeyModifiersView.h"
#endif

GuiHexKeyModifiersView::GuiHexKeyModifiersView(BRect rect, char *name, int KeyNum)
	: BView(rect, name, B_FOLLOW_ALL, B_WILL_DRAW)
{
	KeyIndex = KeyNum;
	
	aBoxRect = rect;
	aBoxRect.InsetBy(10, 10);
}

void GuiHexKeyModifiersView::AttachedToWindow() 
{
    BBox *aBox;
    //BRect aBoxRect;
	//aBoxRect.Set(10, 10, 390, 250);
    
    aBox = new BBox(aBoxRect, "Box1", B_FOLLOW_NONE);
    aBox->SetLabel(LABEL_MODIFIER_BOX_TITLE);
    AddChild(aBox);
    
    BRect rdbRect;
	
	rdbRect.Set(20, 20, 125, 35);
	
	notmod = new BRadioButton(rdbRect, "NotMod", LABEL_MODIFIER_NOT_MODIFIER, new BMessage(OPTION_NOTMODIFIER));
	aBox->AddChild(notmod);
	
	rdbRect.Set(20, 40, 125, 55);
	
	caps = new BRadioButton(rdbRect, "CapsLock", LABEL_MODIFIER_CAPS_LOCK, new BMessage(OPTION_CAPS));
	aBox->AddChild(caps);
	
	rdbRect.Set(20, 60, 125, 75);
	
	scroll = new BRadioButton(rdbRect, "ScrollLock", LABEL_MODIFIER_SCROLL_LOCK, new BMessage(OPTION_SCROLL));
	aBox->AddChild(scroll);
	
	rdbRect.Set(20, 80, 125, 95);
	
	num= new BRadioButton(rdbRect, "NumLock", LABEL_MODIFIER_NUM_LOCK, new BMessage(OPTION_NUM));
	aBox->AddChild(num);
	
	rdbRect.Set(20, 100, 125, 115);
	
	leftshift = new BRadioButton(rdbRect, "LeftShift", LABEL_MODIFIER_LEFT_SHIFT, new BMessage(OPTION_LEFT_SHIFT));
	aBox->AddChild(leftshift);
	
	rdbRect.Set(20, 120, 125, 135);
	
	rightshift = new BRadioButton(rdbRect, "RightShift", LABEL_MODIFIER_RIGHT_SHIFT, new BMessage(OPTION_RIGHT_SHIFT));
	aBox->AddChild(rightshift);
	
	rdbRect.Set(20, 140, 125, 155);
	
	leftcommand = new BRadioButton(rdbRect, "LeftCommand", LABEL_MODIFIER_LEFT_COMMAND, new BMessage(OPTION_LEFT_COMMAND));
	aBox->AddChild(leftcommand);
	
	rdbRect.Set(20, 160, 125, 175);
	
	rightcommand = new BRadioButton(rdbRect, "RightCommand", LABEL_MODIFIER_RIGHT_COMMAND, new BMessage(OPTION_RIGHT_COMMAND));
	aBox->AddChild(rightcommand);
	
	rdbRect.Set(20, 180, 125, 195);
	
	leftcontrol = new BRadioButton(rdbRect, "LeftControl", LABEL_MODIFIER_LEFT_CONTROL, new BMessage(OPTION_LEFT_CONTROL));
	aBox->AddChild(leftcontrol);
	
	rdbRect.Set(20, 200, 125, 215);
	
	rightcontrol = new BRadioButton(rdbRect, "RightControl", LABEL_MODIFIER_RIGHT_CONTROL, new BMessage(OPTION_RIGHT_CONTROL));
	aBox->AddChild(rightcontrol);
	
	rdbRect.Set(20, 220, 125, 235);
	
	leftoption = new BRadioButton(rdbRect, "LeftOption", LABEL_MODIFIER_LEFT_OPTION, new BMessage(OPTION_LEFT_OPTION));
	aBox->AddChild(leftoption);
	
	rdbRect.Set(20, 240, 125, 255);
	
	rightoption = new BRadioButton(rdbRect, "RightOption", LABEL_MODIFIER_RIGHT_OPTION, new BMessage(OPTION_RIGHT_OPTION));
	aBox->AddChild(rightoption);
	
	rdbRect.Set(20, 260, 125, 275);
	
	menu = new BRadioButton(rdbRect, "Menu", LABEL_MODIFIER_MENU, new BMessage(OPTION_MENU));
	aBox->AddChild(menu);
	
	BRect buttonRect;
	buttonRect.Set(20, 290, 65, 310);
	
	BButton * button = new BButton(buttonRect, NULL, LABEL_CANCEL, new BMessage(OPTION_CANCEL), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	aBox->AddChild(button);
	
	buttonRect.Set(75, 290, 120, 310);
	
	button = new BButton(buttonRect, NULL, LABEL_MODIFY, new BMessage(OPTION_MODIFY), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	aBox->AddChild(button);
	
	BKeymap  aKeymap;
	BWindow  *parentWindow;
	    int  modifier;
	
	parentWindow = this->Window();
	
	modifier = aKeymap.ModifierNum(KeyIndex);
	
	switch (modifier)
	{
		case 0:
		{
			notmod->SetValue(B_CONTROL_ON);
			parentWindow->PostMessage(new BMessage(OPTION_NOTMODIFIER));
		}
		break;
		
		case 1:
		{
			caps->SetValue(B_CONTROL_ON);
			parentWindow->PostMessage(new BMessage(OPTION_CAPS));
		}
		break;
		
		case 2:
		{
			scroll->SetValue(B_CONTROL_ON);
			parentWindow->PostMessage(new BMessage(OPTION_SCROLL));
		}
		break;
		
		case 3:
		{
			num->SetValue(B_CONTROL_ON);
			parentWindow->PostMessage(new BMessage(OPTION_NUM));
		}
		break;
		
		case 4:
		{
			leftshift->SetValue(B_CONTROL_ON);
			parentWindow->PostMessage(new BMessage(OPTION_LEFT_SHIFT));
		}
		break;
		
		case 5:
		{
			rightshift->SetValue(B_CONTROL_ON);
			parentWindow->PostMessage(new BMessage(OPTION_RIGHT_SHIFT));
		}
		break;
		
		case 6:
		{
			leftcommand->SetValue(B_CONTROL_ON);
			parentWindow->PostMessage(new BMessage(OPTION_LEFT_COMMAND));
		}
		break;
		
		case 7:
		{
			rightcommand->SetValue(B_CONTROL_ON);
			parentWindow->PostMessage(new BMessage(OPTION_RIGHT_COMMAND));
		}
		break;
		
		case 8:
		{
			leftcontrol->SetValue(B_CONTROL_ON);
			parentWindow->PostMessage(new BMessage(OPTION_LEFT_CONTROL));
		}
		break;
		
		case 9:
		{
			rightcontrol->SetValue(B_CONTROL_ON);
			parentWindow->PostMessage(new BMessage(OPTION_RIGHT_CONTROL));
		}
		break;
		
		case 10:
		{
			leftoption->SetValue(B_CONTROL_ON);
			parentWindow->PostMessage(new BMessage(OPTION_LEFT_OPTION));
		}
		break;
		
		case 11:
		{
			rightoption->SetValue(B_CONTROL_ON);
			parentWindow->PostMessage(new BMessage(OPTION_RIGHT_OPTION));
		}
		break;
		
		case 12:
		{
			menu->SetValue(B_CONTROL_ON);
			parentWindow->PostMessage(new BMessage(OPTION_MENU));
		}
		break;
	
	}
	
}

void GuiHexKeyModifiersView::Draw(BRect updateRect)
{
	
}
