/*
	GuiHexKeyWindow.cpp
	Mattia Tristo
	2004
*/

#ifndef _APPLICATION_H
#include <Application.h>
#endif

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

HexKeyWindow::HexKeyWindow(BRect frame)
    : BWindow(frame, LABEL_WINDOW_TITLE, B_TITLED_WINDOW, B_NOT_RESIZABLE | B_NOT_ZOOMABLE)
{
    HexKeyView  *aView;
	
    frame.OffsetTo(B_ORIGIN);
    frame.top += MENU_BAR_HEIGHT + 1;
    aView = new HexKeyView(frame, "HexKeyView");
	aView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
    AddChild(aView);
    
    BMenu *menu;
    BRect menuBarRect;
    
    menuBarRect.Set(0, 0, 10000, MENU_BAR_HEIGHT);
    fMenuBar = new BMenuBar(menuBarRect, "MenuBar");
    AddChild(fMenuBar);
    
    menu = new BMenu(LABEL_FILE);
    fMenuBar->AddItem(menu);
    
    menu->AddItem(new BMenuItem(LABEL_RESTORE, new BMessage(MENU_RESTORE)));
    menu->AddItem(new BMenuItem(LABEL_QUIT, new BMessage(MENU_QUIT)));
    
    menu = new BMenu(LABEL_ABOUT);
    fMenuBar->AddItem(menu);
    
    menu->AddItem(new BMenuItem(LABEL_ABOUT, new BMessage(MENU_ABOUT)));
    
	system("rm -f /tmp/HexKeyCodeFinderBackupKeymap.txt");
	system("keymap -d > /tmp/HexKeyCodeFinderBackupKeymap.txt");
    
    Show();
}

void HexKeyWindow::MessageReceived(BMessage * msg)
{

   switch(msg->what)
   {
	  case MENU_RESTORE:
	  	{
	  		system("keymap -l < /tmp/HexKeyCodeFinderBackupKeymap.txt");
		}
	  break;
	  
	  case MENU_QUIT:
	  	{
	  		be_app->PostMessage(B_QUIT_REQUESTED);
	  		Quit();
		}
	  break;
	  
	  case MENU_ABOUT:
	  	{
	  		BAlert *myAlert = new BAlert(LABEL_ABOUT, LABEL_ABOUT_BOX_MESSAGE, LABEL_OK, NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
	  		BTextView *myAlertTextView;
	  		myAlertTextView = myAlert->TextView();
	  		myAlertTextView->SetFontAndColor(be_fixed_font);
	  		myAlert->Go();
		 }
	  break;
	  
	  case B_KEY_DOWN:
	  	{
			
	  		DrawView *aView;
    		aView = (DrawView *)FindView("DrawView");
	  		
	  		aView->KeyPressDetected();	  		
	  		
	  	}
	  
	  case B_UNMAPPED_KEY_DOWN:
	  	{
	  		DrawView *aView;
    		aView = (DrawView *)FindView("DrawView");
	  		
	  		aView->KeyPressDetected();
	  		
	  	}
	  
	  case B_MODIFIERS_CHANGED:
	  	{
	  		DrawView *aView;
    		aView = (DrawView *)FindView("DrawView");
	  		
	  		aView->KeyPressDetected();
	  		
	  	}
	  	
      default:
         BWindow::MessageReceived(msg);
      break;
   }
}

bool HexKeyWindow::QuitRequested()
{
    be_app->PostMessage(B_QUIT_REQUESTED);
    return(true);
}
