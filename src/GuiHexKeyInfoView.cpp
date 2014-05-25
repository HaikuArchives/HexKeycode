/*
	GuiHexKeyInfoView.cpp
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYAPP_H
#include "GuiHexKeyApp.h"
#endif

#ifndef GUIHEXKEYINFOWINDOW_H
#include "GuiHexKeyInfoWindow.h"
#endif

#ifndef GUIHEXKEYINFOVIEW_H
#include "GuiHexKeyInfoView.h"
#endif

HexKeyInfoView::HexKeyInfoView(BRect rect, char *name)
	: BView(rect, name, B_FOLLOW_ALL, B_WILL_DRAW)
{
	aBoxRect = rect;
	aBoxRect.InsetBy(10, 10);
}

void HexKeyInfoView::AttachedToWindow() 
{
    
    BBox *aBox;
    //BRect aBoxRect;
	//aBoxRect.Set(10, 10, 390, 250);
    
    aBox = new BBox(aBoxRect, "Box1", B_FOLLOW_NONE);
    aBox->SetLabel(LABEL_KEYINFO_BOX_TITLE);
    AddChild(aBox);
    
    BRect lblIndexRect;
	lblIndexRect.Set(10, 20, 370, 40);
	
	BStringView		*lblIndex;
	BString			 lblIndexString;
	
	lblIndexString.SetTo(LABEL_KEYINFO_SELECTEDKEY);
	
	Hex hexConv;
	hexConv.Set((uint8)KeyMapIndex);
	
	lblIndexString << KeyMapIndex << " - 0x" << hexConv.GetString();
	
	lblIndex = new BStringView(lblIndexRect, "lblIndex", lblIndexString.String(), B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	lblIndex->SetFont(be_fixed_font);
	aBox->AddChild(lblIndex);
    
    BRect lblRect;
	lblRect.Set(10, 55, 370, 70);
	
	lbl0 = new BStringView(lblRect, "lbl0", LABEL_KEYINFO_MODIFIER, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	lbl0->SetFont(be_fixed_font);
	aBox->AddChild(lbl0);
    
    BRect buttonRect;
	buttonRect.Set(380, 50, 430, 70);

	BButton * button = new BButton(buttonRect, NULL, LABEL_MODIFY, new BMessage(COMMAND_MODIFIER), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	aBox->AddChild(button);
	
	lblRect.Set(10, 80, 370, 95);
	
	lbl1 = new BStringView(lblRect, "lbl1", LABEL_KEYINFO_NORMAL, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	lbl1->SetFont(be_fixed_font);
	aBox->AddChild(lbl1);
	
	buttonRect.Set(380, 75, 430, 95);

	button = new BButton(buttonRect, NULL, LABEL_MODIFY, new BMessage(COMMAND_NORMAL), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	aBox->AddChild(button);
	
	lblRect.Set(10, 105, 370, 120);
	
	lbl2 = new BStringView(lblRect, "lbl2", LABEL_KEYINFO_SHIFT, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	lbl2->SetFont(be_fixed_font);
	aBox->AddChild(lbl2);
	
	buttonRect.Set(380, 100, 430, 120);

	button = new BButton(buttonRect, NULL, LABEL_MODIFY, new BMessage(COMMAND_SHIFT), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	aBox->AddChild(button);
	
	lblRect.Set(10, 130, 370, 145);
	
	lbl3 = new BStringView(lblRect, "lbl3", LABEL_KEYINFO_CAPS, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	lbl3->SetFont(be_fixed_font);
	aBox->AddChild(lbl3);
	
	buttonRect.Set(380, 125, 430, 145);

	button = new BButton(buttonRect, NULL, LABEL_MODIFY, new BMessage(COMMAND_CAPS), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	aBox->AddChild(button);
	
	lblRect.Set(10, 155, 370, 170);
	
	lbl4 = new BStringView(lblRect, "lbl4", LABEL_KEYINFO_CAPS_SHIFT, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	lbl4->SetFont(be_fixed_font);
	aBox->AddChild(lbl4);
	
	buttonRect.Set(380, 150, 430, 170);

	button = new BButton(buttonRect, NULL, LABEL_MODIFY, new BMessage(COMMAND_CAPS_SHIFT), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	aBox->AddChild(button);
	
	lblRect.Set(10, 180, 370, 195);
	
	lbl5 = new BStringView(lblRect, "lbl5", LABEL_KEYINFO_OPTION, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	lbl5->SetFont(be_fixed_font);
	aBox->AddChild(lbl5);
	
	buttonRect.Set(380, 175, 430, 195);

	button = new BButton(buttonRect, NULL, LABEL_MODIFY, new BMessage(COMMAND_OPTION), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	aBox->AddChild(button);
	
	lblRect.Set(10, 205, 370, 220);
	
	lbl6 = new BStringView(lblRect, "lbl6", LABEL_KEYINFO_OPTION_SHIFT, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	lbl6->SetFont(be_fixed_font);
	aBox->AddChild(lbl6);
	
	buttonRect.Set(380, 200, 430, 220);

	button = new BButton(buttonRect, NULL, LABEL_MODIFY, new BMessage(COMMAND_OPTION_SHIFT), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	aBox->AddChild(button);
	
	lblRect.Set(10, 230, 370, 245);
	
	lbl7 = new BStringView(lblRect, "lbl7", LABEL_KEYINFO_OPTION_CAPS, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	lbl7->SetFont(be_fixed_font);
	aBox->AddChild(lbl7);
	
	buttonRect.Set(380, 225, 430, 245);

	button = new BButton(buttonRect, NULL, LABEL_MODIFY, new BMessage(COMMAND_OPTION_CAPS), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	aBox->AddChild(button);
	
	lblRect.Set(10, 245, 370, 270);
	
	lbl8 = new BStringView(lblRect, "lbl8", LABEL_KEYINFO_OPTIONS_CAPS_SHIFT, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	lbl8->SetFont(be_fixed_font);
	aBox->AddChild(lbl8);
	
	buttonRect.Set(380, 250, 430, 270);

	button = new BButton(buttonRect, NULL, LABEL_MODIFY, new BMessage(COMMAND_OPTIONS_CAPS_SHIFT), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	aBox->AddChild(button);
	
	lblRect.Set(10, 280, 370, 295);
	
	lbl9 = new BStringView(lblRect, "lbl9", LABEL_KEYINFO_CONTROL, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	lbl9->SetFont(be_fixed_font);
	aBox->AddChild(lbl9);
	
	buttonRect.Set(380, 275, 430, 295);

	button = new BButton(buttonRect, NULL, LABEL_MODIFY, new BMessage(COMMAND_CONTROL), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	aBox->AddChild(button);
	
	UptadeLabels();
	
}

void HexKeyInfoView::SetIndex(int index)
{
	KeyMapIndex = index;
}

int HexKeyInfoView::GetIndex()
{
	return (KeyMapIndex);
}

void HexKeyInfoView::SetSelectedKeymap(int index)
{
	SelectedKeyMapNum = index;
}

void HexKeyInfoView::SetSelectedChar(char arrChars[3], int count)
{
	for (int i = 0; i < count; i++)
	{
		SelectedChar[i] = arrChars[i];
	}
	
	SelectedCharCount = count;
	
}

BString HexKeyInfoView::RetrieveKeyFromKeymap(BChar aChar)
{
	BString KeyString;
	
	Hex    hexConv;
	
	KeyString.SetTo("");
	
	/*
	BString DebugString;
	DebugString.SetTo("");
	BAlert *myAlert = new BAlert("Debug", "Prima della BKeymap", "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
	myAlert->Go();
	*/
	
	//aKeymap.DumpToFile();
	
	switch(aChar.GetLenght())
	{
		case 0:
			// Not mapped
			KeyString << LALEL_KEYINFO_NOT_MAPPED;
		break;
		
		case 1:
			// 1-byte UTF-8/ASCII character
			KeyString << LABEL_UTF8_ASCII << aChar.GetUtf8();
		
			for (int i = KeyString.CountChars(); i <= 20; i++)
			{
				KeyString << " ";
			}
		
			KeyString << "- \"" << aChar.GetString() << "\"";
		break;
		
		default:
			// 2-, 3-byte UTF-8 character
		{	
			KeyString << LABEL_UTF8;
			char arrChars[3];
			int  len;
			Hex hexConv;
			
			aChar.GetPascalArray(arrChars, &len);
			
			for (int i = 0; i < len; i++)
			{
				hexConv.Set(arrChars[i]);
				KeyString << "x" << hexConv.GetString();
			}
			
			for (int i = KeyString.CountChars(); i <= 20; i++)
			{
				KeyString << " ";
			}
		
			KeyString << "- \"" << aChar.GetString() << "\"";
			
		}
		break;
	
	}
	
	return (KeyString);

}

void HexKeyInfoView::UptadeLabels()
{
	BKeymap  aKeymap;
	BString  lblString;
	BChar    aChar;
	
	lblString.SetTo(LABEL_KEYINFO_MODIFIER);
	lblString << aKeymap.ModifierName(KeyMapIndex);
	lbl0->SetText(lblString.String());
	
	lblString.SetTo(LABEL_KEYINFO_NORMAL);
	aChar = aKeymap.GetKey(KeyMapIndex, 1);
	lblString << RetrieveKeyFromKeymap(aChar);
	lbl1->SetText(lblString.String());
	
	lblString.SetTo(LABEL_KEYINFO_SHIFT);
	aChar = aKeymap.GetKey(KeyMapIndex, 2);
	lblString << RetrieveKeyFromKeymap(aChar);
	lbl2->SetText(lblString.String());
	
	lblString.SetTo(LABEL_KEYINFO_CAPS);
	aChar = aKeymap.GetKey(KeyMapIndex, 3);
	lblString << RetrieveKeyFromKeymap(aChar);
	lbl3->SetText(lblString.String());
	
	lblString.SetTo(LABEL_KEYINFO_CAPS_SHIFT);
	aChar = aKeymap.GetKey(KeyMapIndex, 4);
	lblString << RetrieveKeyFromKeymap(aChar);
	lbl4->SetText(lblString.String());
	
	lblString.SetTo(LABEL_KEYINFO_OPTION);
	aChar = aKeymap.GetKey(KeyMapIndex, 5);
	lblString << RetrieveKeyFromKeymap(aChar);
	lbl5->SetText(lblString.String());
	
	lblString.SetTo(LABEL_KEYINFO_OPTION_SHIFT);
	aChar = aKeymap.GetKey(KeyMapIndex, 6);
	lblString << RetrieveKeyFromKeymap(aChar);
	lbl6->SetText(lblString.String());
	
	lblString.SetTo(LABEL_KEYINFO_OPTION_CAPS);
	aChar = aKeymap.GetKey(KeyMapIndex, 7);
	lblString << RetrieveKeyFromKeymap(aChar);
	lbl7->SetText(lblString.String());
	
	lblString.SetTo(LABEL_KEYINFO_OPTIONS_CAPS_SHIFT);
	aChar = aKeymap.GetKey(KeyMapIndex, 8);
	lblString << RetrieveKeyFromKeymap(aChar);
	lbl8->SetText(lblString.String());
	
	lblString.SetTo(LABEL_KEYINFO_CONTROL);
	aChar = aKeymap.GetKey(KeyMapIndex, 9);
	lblString << RetrieveKeyFromKeymap(aChar);
	lbl9->SetText(lblString.String());
	
}

void HexKeyInfoView::Draw(BRect)
{
	
}
