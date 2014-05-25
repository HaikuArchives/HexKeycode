/*
	GuiHexKeyInfoWindow.cpp
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

#ifndef GUIHEXKEYSELECTWINDOW_H
#include "GuiHexKeySelectWindow.h"
#endif

#ifndef GUIHEXKEYMODIFIERSWINDOW_H
#include "GuiHexKeyModifiersWindow.h"
#endif

HexKeyInfoWindow::HexKeyInfoWindow(BRect frame, int index)
    : BWindow(frame, LABEL_KEYINFO_TITLE, B_TITLED_WINDOW_LOOK , B_MODAL_APP_WINDOW_FEEL, B_NOT_RESIZABLE | B_NOT_ZOOMABLE, B_CURRENT_WORKSPACE)
{
    keyIndex = index;
    
    HexKeyInfoView  *aView;
	
    frame.OffsetTo(B_ORIGIN);
    aView = new HexKeyInfoView(frame, "HexKeyInfoView");
	aView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
    aView->SetIndex(index);
    AddChild(aView);
    
    Show();
}

void HexKeyInfoWindow::MessageReceived(BMessage * msg)
{
	switch(msg->what)
    {  
	  case COMMAND_MODIFIER:
	  	{
	  		GuiHexKeyModifiersWindow	*aWindow;
    		BRect 			 	 aRect;
    		
			aRect.Set(350, 150, 510, 490);
    		aWindow = new GuiHexKeyModifiersWindow(aRect, keyIndex);
      	}
      break;
	  
	  case COMMAND_NORMAL:
	  	{	
	  		HexKeySelectWindow *aWindow;
			BRect 			 	aRect;
	  		
			aRect.Set(50, 50, 750, 550);
	  		aWindow = new HexKeySelectWindow(aRect, 1, keyIndex);
	  		
		}
	  break;
	  
	  case COMMAND_SHIFT:
	  	{
	  		HexKeySelectWindow *aWindow;
	  		BRect 			 	aRect;
	  		
	  		aRect.Set(50, 50, 750, 550);
	  		aWindow = new HexKeySelectWindow(aRect, 2, keyIndex);
		}
	  break;
	  
	  case COMMAND_CAPS:
	  	{
	  		HexKeySelectWindow *aWindow;
	  		BRect 			 	aRect;
	  		
	  		aRect.Set(50, 50, 750, 550);
	  		aWindow = new HexKeySelectWindow(aRect, 3, keyIndex);
		}
	  break;
	  
	  case COMMAND_CAPS_SHIFT:
	  	{
	  		HexKeySelectWindow *aWindow;
	  		BRect 			 	aRect;
	  		
	  		aRect.Set(50, 50, 750, 550);
	  		aWindow = new HexKeySelectWindow(aRect, 4, keyIndex);
		}
	  break;
	  
	  case COMMAND_OPTION:
	  	{
	  		HexKeySelectWindow *aWindow;
	  		BRect 			 	aRect;
	  		
	  		aRect.Set(50, 50, 750, 550);
	  		aWindow = new HexKeySelectWindow(aRect, 5, keyIndex);
		}
	  break;
	  
	  case COMMAND_OPTION_SHIFT:
	  	{
	  		HexKeySelectWindow *aWindow;
	  		BRect 			 	aRect;
	  		
	  		aRect.Set(50, 50, 750, 550);
	  		aWindow = new HexKeySelectWindow(aRect, 6, keyIndex);
		}
	  break;
	  
	  case COMMAND_OPTION_CAPS:
	  	{
	  		HexKeySelectWindow *aWindow;
	  		BRect 			 	aRect;
	  		
	  		aRect.Set(50, 50, 750, 550);
	  		aWindow = new HexKeySelectWindow(aRect, 7, keyIndex);
		}
	  break;
	  
	  case COMMAND_OPTIONS_CAPS_SHIFT:
	  	{
	  		HexKeySelectWindow *aWindow;
	  		BRect 			 	aRect;
	  		
	  		aRect.Set(50, 50, 750, 550);
	  		aWindow = new HexKeySelectWindow(aRect, 8, keyIndex);
		}
	  break;
	  
	  case COMMAND_CONTROL:
	  	{
	  		HexKeySelectWindow *aWindow;
	  		BRect 			 	aRect;
	  		
	  		aRect.Set(50, 50, 750, 550);
	  		aWindow = new HexKeySelectWindow(aRect, 9, keyIndex);
		}
	  break;
	  
	  case UPDATE_LABELS:
	  	{
	  		//BAlert *myAlert = new BAlert("Debug", "Messaggio arrivato", "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
	  		//myAlert->Go();
	  		
	  		HexKeyInfoView *infoView;
    		infoView = (HexKeyInfoView *)FindView("HexKeyInfoView");
    
    		infoView->UptadeLabels();
    		
	  	}
	  
	  default:
	  	BWindow::MessageReceived(msg);
	  break;
	}
}

bool HexKeyInfoWindow::QuitRequested()
{
	return (true);
}
