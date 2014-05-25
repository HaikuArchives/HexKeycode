/*
	GuiHexKeyTablesWindow.cpp
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

#ifndef GUIHEXKEYSELECTWINDOW_H
#include "GuiHexKeySelectWindow.h"
#endif

HexKeyTablesWindow::HexKeyTablesWindow(BRect frame)
    : BWindow(frame, LABEL_SELECT_TABLE_TITLE, B_TITLED_WINDOW_LOOK , B_MODAL_APP_WINDOW_FEEL, B_NOT_RESIZABLE | B_NOT_ZOOMABLE, B_CURRENT_WORKSPACE)
{
    HexKeyTablesView  *aView;
	
    frame.OffsetTo(B_ORIGIN);
    aView = new HexKeyTablesView(frame, "HexKeyTablesView");
	aView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
    AddChild(aView);
    
    Show();
}

void HexKeyTablesWindow::MessageReceived(BMessage * msg)
{	

	switch(msg->what)
    {  
	  
	  case COMMAND_TABLE_CANCEL:
	  	{
	  		Quit();
	  	}
	  break;
	  
	  case COMMAND_TABLE_MODIFY:
	  	{
	  		
	  		HexKeyTablesView *aView;
    		aView = (HexKeyTablesView *)FindView("HexKeyTablesView");
    		
    		int32 index;
    		
    		index = aView->GetSelectedIndex();
    		
    		if (index >= 0) 
    		{
    			BWindow *aWindow;
				int32    i = 0;
			
				while ((aWindow = be_app->WindowAt(i++)))
				{
					BString aString;
				
					aString.SetTo(aWindow->Title());
					
					if (!(aString.Compare(LABEL_SELECT_TITLE)))
					{
						BMessage  *aMessage = new BMessage(UPDATE_TABLE);
						
						aMessage->AddInt32("Table", index);
						
						aWindow->PostMessage(aMessage, aWindow);
						
					}
				}
	  			
	  			Quit();
	  			
	  		}
			
	  	}
	  break;
	  
	  default:
		BWindow::MessageReceived(msg);
	  break;
	
	}
	
}

bool HexKeyTablesWindow::QuitRequested()
{
	return (true);
}
