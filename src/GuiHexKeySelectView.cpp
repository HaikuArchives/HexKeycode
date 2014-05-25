/*
	GuiHexKeySelectView.cpp
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYAPP_H
#include "GuiHexKeyApp.h"
#endif

#ifndef GUIHEXKEYINFOVIEW_H
#include "GuiHexKeyInfoView.h"
#endif

#ifndef GUIHEXKEYSELECTWINDOW_H
#include "GuiHexKeySelectWindow.h"
#endif

#ifndef GUIHEXKEYSELECTVIEW_H
#include "GuiHexKeySelectView.h"
#endif

HexKeySelectView::HexKeySelectView(BRect rect, char *name, int numKeymap, int numKey)
	: BView(rect, name, B_FOLLOW_ALL, B_WILL_DRAW)
{
	PageIndex = 0;
	Selected = false;
	KeymapNum = numKeymap;
	KeyNum = numKey;
	
	initTablesPages();
	
}

void HexKeySelectView::NextPage()
{
	if (PageIndex < 87) 
	{
		PageIndex++;
	
		BString aString;
	
		aString.SetTo(LABEL_PAGE);
		aString << (PageIndex + 1) << "/88";
	
		lbl2->SetText(aString.String());
	
		Draw(Bounds());
	}
}

void HexKeySelectView::PrevPage()
{
	if (PageIndex > 0) 
	{
		PageIndex--;
	
		BString aString;
	
		aString.SetTo(LABEL_PAGE);
		aString << (PageIndex + 1) << "/88";
	
		lbl2->SetText(aString.String());
	
		Draw(Bounds());
	}
}

void HexKeySelectView::initTablesPages()
{
	TablePages[0] = 1;
	TablePages[1] = 1;
	TablePages[2] = 1;
	TablePages[3] = 1;
	TablePages[4] = 1;
	TablePages[5] = 1;
	TablePages[6] = 2;
	TablePages[7] = 2;
	TablePages[8] = 2;
	TablePages[9] = 2;
	TablePages[10] = 2;
	TablePages[11] = 2;
	TablePages[12] = 3;
	TablePages[13] = 3;
	TablePages[14] = 3;
	TablePages[15] = 4;
	TablePages[16] = 4;
	TablePages[17] = 4;
	TablePages[18] = 4;
	TablePages[19] = 4;
	TablePages[20] = 4;
	TablePages[21] = 5;
	TablePages[22] = 5;
	TablePages[23] = 5;
	TablePages[24] = 5;
	TablePages[25] = 5;
	TablePages[26] = 5;
	TablePages[27] = 6;
	TablePages[28] = 6;
	TablePages[29] = 6;
	TablePages[30] = 6;
	TablePages[31] = 7;
	TablePages[32] = 7;
	TablePages[33] = 7;
	TablePages[34] = 8;
	TablePages[35] = 8;
	TablePages[36] = 8;
	TablePages[37] = 8;
	TablePages[38] = 8;
	TablePages[39] = 9;
	TablePages[40] = 9;
	TablePages[41] = 9;
	TablePages[42] = 9;
	TablePages[43] = 9;
	TablePages[44] = 9;
	TablePages[45] = 10;
	TablePages[46] = 11;
	TablePages[47] = 11;
	TablePages[48] = 11;
	TablePages[49] = 12;
	TablePages[50] = 12;
	TablePages[51] = 12;
	TablePages[52] = 12;
	TablePages[53] = 12;
	TablePages[54] = 12;
	TablePages[55] = 12;
	TablePages[56] = 12;
	TablePages[57] = 13;
	TablePages[58] = 13;
	TablePages[59] = 13;
	TablePages[60] = 13;
	TablePages[61] = 13;
	TablePages[62] = 13;
	TablePages[63] = 14;
	TablePages[64] = 14;
	TablePages[65] = 14;
	TablePages[66] = 14;
	TablePages[67] = 14;
	TablePages[68] = 15;
	TablePages[69] = 15;
	TablePages[70] = 15;
	TablePages[71] = 15;
	TablePages[72] = 16;
	TablePages[73] = 17;
	TablePages[74] = 17;
	TablePages[75] = 17;
	TablePages[76] = 17;
	TablePages[77] = 17;
	TablePages[78] = 17;
	TablePages[79] = 17;
	TablePages[80] = 17;
	TablePages[81] = 17;
	TablePages[82] = 18;
	TablePages[83] = 18;
	TablePages[84] = 18;
	TablePages[85] = 18;
	TablePages[86] = 27;
	TablePages[87] = 27;
	TablePages[88] = 55;
	TablePages[89] = 57;
	TablePages[90] = 59;
	TablePages[91] = 74;
	TablePages[92] = 76;
	TablePages[93] = 77;
	TablePages[94] = 86;
	TablePages[95] = 86;
	TablePages[96] = 87;
	TablePages[97] = 87;
	TablePages[98] = 87;
	TablePages[99] = 87;
	TablePages[100] = 88;
	TablePages[101] = 88;
	TablePages[102] = 88;
	TablePages[103] = 88;
	
}

void HexKeySelectView::TableChanged()
{
	
	BString aString;
	int index;
	bool pagechanged;
	
	index = (int)textlist->CurrentSelection();
	
	pagechanged = !(PageIndex == (TablePages[index] - 1));
	
	PageIndex = TablePages[index] - 1;
	
	/*
	BString tmpString;
	
	tmpString.SetTo("");
	tmpString << "Index : " << index << " Page : " << PageIndex;
	
	BAlert *myAlert = new BAlert("Debug", tmpString.String(), "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT);
	myAlert->Go();
	*/
	
	if (PageIndex == -1) PageIndex = 0;
	
	aString.SetTo(LABEL_PAGE);
	aString << (PageIndex + 1) << "/88";
		
	lbl2->SetText(aString.String());
	
	SetColorByTableNum(index);
	
	BRect aRect;
	
	aRect.Set(205, 455, 370, 470);
	
	FillRect(aRect, B_SOLID_HIGH);
	
	aRect.InsetBy(-1, -1);
	
	SetHighColor(0, 0, 0);
	
	StrokeRect(aRect, B_SOLID_HIGH);
	
	SetFontSize(12);
	
	MovePenTo(245, 467);
		
	DrawString(LABEL_SELECTED_TABLE);		
	
	if (pagechanged) Draw(Bounds());
}

void HexKeySelectView::initChoiceList()
{
	aChoiceList = new BStringChoiceList;
	
	BString      aString;
	UnicodeTable aTable;
	
	for (int i = 0; i < aTable.GetNum(); i++)
	{
		aString = aTable.GetTableNameByTableNum(i);
		aChoiceList->AddChoice(aString.String(), i);
	}
	
	aChoiceList->SetOwner(textlist);
	
	//aChoiceList->Lock();
}

void HexKeySelectView::AttachedToWindow() 
{
    BRect lblRect;
	
	lblRect.Set(70, 470, 180, 490);
	
	lbl1 = new BStringView(lblRect, "lbl1", LABEL_SELECTED_KEY, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	AddChild(lbl1);
    
    lblRect.Set(380, 470, 439, 490);
	
	BString aString;
	
	aString.SetTo(LABEL_PAGE);
	aString << "1/87";
	
	lbl2 = new BStringView(lblRect, "lbl2", aString.String(), B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	AddChild(lbl2);
	
    BRect buttonRect;
	buttonRect.Set(440, 470, 490, 490);
	
	BButton * button = new BButton(buttonRect, NULL, LABEL_PREVIOUS, new BMessage(COMMAND_PREV), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	AddChild(button);
	
	buttonRect.Set(500, 470, 550, 490);
	
	button = new BButton(buttonRect, NULL, LABEL_NEXT, new BMessage(COMMAND_NEXT), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	AddChild(button);
	
	buttonRect.Set(570, 470, 620, 490);
	
	button = new BButton(buttonRect, NULL, LABEL_CANCEL, new BMessage(COMMAND_CANCEL), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	AddChild(button);
	
	buttonRect.Set(630, 470, 680, 490);
	
	button = new BButton(buttonRect, NULL, LABEL_MODIFY, new BMessage(COMMAND_MODIFY), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	AddChild(button);
	
	buttonRect.Set(181, 477, 370, 492);
	
	initChoiceList();
	
	textlist = new BTextListControl(buttonRect, "Tables", " ", "Primo", new BMessage(COMMAND_TABLE_CHANGED), aChoiceList);
	textlist->SetDivider(20);
	textlist->SelectByKey(0, true);
	textlist->SetTarget(this);
	AddChild(textlist);
	
}

void HexKeySelectView::MouseDown(BPoint point)
{
	int row, col;
	BString aString;
	
	aString.SetTo(LABEL_SELECTED_KEY);
	
	row = ((int)point.y - 10) / 20;
	col = ((int)point.x - 10) / 20;
	
	if ((row < 22) && (col < 34))
	{
		int index;
		
		index = PageIndex * 748 + row * 34 + col;
		
		if (!((PageIndex == 87) && (index > 65535))) 
		{
			aString << index << " - ";
		
			Hex hexConv;
		
			hexConv.Set(index);
		
			aString << hexConv.GetString();
		
			lbl1->SetText(aString.String());
		
			//BChar aChar;
		
			Selected = true;
		
			SelectedChar.SetUtf8(index);
			aString = SelectedChar.GetString();
		
			BRect aRect;
	
			aRect.Set(10, 451, 55, 500);
			SetHighColor(ui_color(B_PANEL_BACKGROUND_COLOR));
			FillRect(aRect, B_SOLID_HIGH);
			Sync();
		
			SetHighColor(0, 0, 0);
			SetLowColor(ui_color(B_PANEL_BACKGROUND_COLOR));
			SetFontSize(30);
			MovePenTo(20, 490);
			DrawString(aString.String());
			
			UnicodeTable table;
			
			int tableNum;
			tableNum = table.GetTableNum(index);
			
			textlist->SelectByKey(tableNum, true);
			
			TableChanged();
			
		}
		
	}
	
}

void HexKeySelectView::ModifyRequested()
{   		
	/*
	BString aString;
	
	aString.SetTo("Fino a qui tutto ok, keymap : ");
	aString << KeymapNum << ", key : " << KeyNum << ", len : ";
	aString << SelectedChar.GetLenght() << ", " << SelectedChar.GetString();
	
	BAlert *myAlert = new BAlert("Arrivato", "Fatto", "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
	myAlert->Go();
	*/
	
	BKeymap modKeymap;
	
	modKeymap.SetKey(KeyNum, KeymapNum, SelectedChar);
	
	//modKeymap.ApplyChanges();
	
	modKeymap.DumpToFile();
	
	system("keymap -l < /tmp/HexKeyCodeFinderKeymap.txt");
	
}

bool HexKeySelectView::HasBeenSelected()
{
	return (Selected);
}

bool HexKeySelectView::CheckHasGlimphs(BChar aChar)
{
	char  arrChar[3];
	int numChars;
	bool  hasGlymphs[3];
	
	aChar.GetPascalArray(arrChar, &numChars);
	
	be_plain_font->GetHasGlyphs(arrChar, numChars, hasGlymphs);
				
	HasGlymphs = hasGlymphs[0];
	
}

void HexKeySelectView::SetColorByTableNum(int tablenum)
{
	int n;
	
	n = tablenum;
	
	while (!(n < 10))
	{
		n = n % 10;
	}
	
	switch (n)
	{
		case 0:
			SetHighColor(255, 140, 140);
			SetLowColor(255, 140, 140);
		break;
		
		case 1:
			SetHighColor(140, 255, 210);
			SetLowColor(140, 255, 210);
		break;
		
		case 2:
			SetHighColor(255, 140, 210);
			SetLowColor(255, 140, 210);
		break;
		
		case 3:
			SetHighColor(200, 255, 140);
			SetLowColor(200, 255, 140);
			
		break;
		
		case 4:
			SetHighColor(140, 240, 255);
			SetLowColor(140, 240, 255);
		break;
		
		case 5:
			SetHighColor(255, 200, 140);
			SetLowColor(255, 200, 140);
		break;
		
		case 6:
			SetHighColor(170, 140, 255);
			SetLowColor(170, 140, 255);
		break;
		
		case 7:
			SetHighColor(140, 210, 255);
			SetLowColor(140, 210, 255);
		break;
		
		case 8:
			SetHighColor(230, 140, 255);
			SetLowColor(230, 140, 255);
		break;
		
		case 9:
			SetHighColor(140, 155, 255);
			SetLowColor(140, 155, 255);
		break;
	}
}

void HexKeySelectView::FillRegion(int i, int j, int value)
{
	UnicodeTable table;
	
	int tableNum;
	
	tableNum = table.GetTableNum(value);
	
	SetColorByTableNum(tableNum);
	
	int x, y;
			
	x = 10 + 20 * j;
	y = 10 + 20 * i;
	
	BRect aRect;
	
	aRect.Set(x + 1, y + 1, x + 19, y + 19);
	
	FillRect(aRect, B_SOLID_HIGH);
	
}

void HexKeySelectView::Draw(BRect updateRect)
{
	BRect aRect;
	
	aRect = Bounds();
	aRect.bottom = aRect.bottom - 49;
	SetHighColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	FillRect(aRect, B_SOLID_HIGH);
	
	Sync();
	
	SetHighColor(0, 0, 0);
	
	aRect = Bounds();
	aRect.InsetBy(10, 10);
	aRect.bottom = aRect.bottom - 40;
	
	for (int i = (int)aRect.top; i <= (int)aRect.bottom; i = i + 20)
	{
		BPoint P1, P2;
		
		P1.x = aRect.left;
		P1.y = i;
		
		P2.x = aRect.right;
		P2.y = i;
		
		StrokeLine(P1, P2, B_SOLID_HIGH);
		
	}
	
	for (int i = (int)aRect.left; i <= (int)aRect.right; i = i + 20)
	{
		BPoint P1, P2;
		
		P1.x = i;
		P1.y = aRect.top;
		
		P2.x = i;
		P2.y = aRect.bottom;
		
		StrokeLine(P1, P2, B_SOLID_HIGH);
		
	}
	
	Sync();
	
	//SetFont(be_fixed_font);
	
	SetFontSize(15);
	
	BString aString;
	int     count;
	
	count = 748 * PageIndex;
	
	// 748 values in a page
	
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 34; j++)
		{
			if (count <= 65565)
			{
				BChar aChar;
			
				aChar.SetUtf8(count);
			
				CheckHasGlimphs(aChar);
			
				aString = aChar.GetString();
				
				FillRegion(i, j, count);
				
				int x, y;
			
				x = 15 + 20 * j;
				y = 25 + 20 * i;
			
				MovePenTo(x, y);
				
				SetHighColor(0, 0, 0);
				
				if ((HasGlymphs) && (!((count >= 8350) && (count <= 8380)))) DrawString(aString.String());
			
				//snooze(100);
			
				count++;
			}
			
		}
		
	}
	
	Sync();
	
}
