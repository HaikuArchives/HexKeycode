/*
	GuiHexKeyModifiersWindow.cpp
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYAPP_H
#include "GuiHexKeyApp.h"
#endif

#ifndef GUIHEXKEYINFOWINDOW_H
#include "GuiHexKeyInfoWindow.h"
#endif

#ifndef GUIHEXKEYMODIFIERSWINDOW_H
#include "GuiHexKeyModifiersWindow.h"
#endif

#ifndef GUIHEXKEYMODIFIERSVIEW_H
#include "GuiHexKeyModifiersView.h"
#endif

GuiHexKeyModifiersWindow::GuiHexKeyModifiersWindow(BRect frame, int KeyNum)
    : BWindow(frame, LABEL_MODIFIER_TITLE, B_TITLED_WINDOW_LOOK , B_MODAL_APP_WINDOW_FEEL, B_NOT_RESIZABLE | B_NOT_ZOOMABLE, B_CURRENT_WORKSPACE)
{
    KeyIndex = KeyNum;
    
    GuiHexKeyModifiersView  *aView;
	
    frame.OffsetTo(B_ORIGIN);
    aView = new GuiHexKeyModifiersView(frame, "GuiHexKeyModifiersView", KeyNum);
	aView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
    AddChild(aView);
    
    Show();
}

void GuiHexKeyModifiersWindow::SetModifier()
{
	BKeymap modKeymap;
	
	if (ChosenModifier == 0)
	{
		modKeymap.ClearModifier(KeyIndex);
	}
	else
	{
		modKeymap.SetModifier(ChosenModifier, KeyIndex);
	}
	
	modKeymap.DumpToFile();
	
	system("keymap -l < /tmp/HexKeyCodeFinderKeymap.txt");
	
}

void GuiHexKeyModifiersWindow::MessageReceived(BMessage * msg)
{	
	switch(msg->what)
    {  
	  case OPTION_NOTMODIFIER:
	  	{
	  		ChosenModifier = 0;
		}
	  break;
	  
	  case OPTION_CAPS:
	  	{
	  		ChosenModifier = 1;
		}
	  break;
	  
	  case OPTION_SCROLL:
	  	{
	  		ChosenModifier = 2;
		}
	  break;
	  
	  case OPTION_NUM:
	  	{
	  		ChosenModifier = 3;
		}
	  break;
	  
	  case OPTION_LEFT_SHIFT:
	  	{
	  		ChosenModifier = 4;
		}
	  break;
	  
	  case OPTION_RIGHT_SHIFT:
	  	{
	  		ChosenModifier = 5;
		}
	  break;
	  
	  case OPTION_LEFT_COMMAND:
	  	{
	  		ChosenModifier = 6;
		}
	  break;
	  
	  case OPTION_RIGHT_COMMAND:
	  	{
	  		ChosenModifier = 7;
		}
	  break;
	  
	  case OPTION_LEFT_CONTROL:
	  	{
	  		ChosenModifier = 8;
		}
	  break;
	  
	  case OPTION_RIGHT_CONTROL:
	  	{
	  		ChosenModifier = 9;
		}
	  break;
	  
	  case OPTION_LEFT_OPTION:
	  	{
	  		ChosenModifier = 10;
		}
	  break;
	  
	  case OPTION_RIGHT_OPTION:
	  	{
	  		ChosenModifier = 11;
		}
	  break;
	  
	  case OPTION_MENU:
	  	{
	  		ChosenModifier = 12;
		}
	  break;
	  
	  case OPTION_CANCEL:
	  	{
	  		Quit();
		}
	  break;
	  
	  case OPTION_MODIFY:
	  	{
	  		SetModifier();
	  		
	  		BWindow *aWindow;
			int32    i = 0;
			
			while ((aWindow = be_app->WindowAt(i++)))
			{
				BString aString;
				
				aString.SetTo(aWindow->Title());
					
				if (!(aString.Compare(LABEL_KEYINFO_TITLE)))
				{
					aWindow->PostMessage(UPDATE_LABELS, aWindow);
				}
			}
			
			Quit();
			
		}
	  break;
	  
	  
	  default:
		BWindow::MessageReceived(msg);
	  break;
	
	}
	
}

bool GuiHexKeyModifiersWindow::QuitRequested()
{
	return (true);
}
