/*
	GuiHexKeySelectWindow.cpp
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYAPP_H
#include "GuiHexKeyApp.h"
#endif

#ifndef GUIHEXKEYSELECTWINDOW_H
#include "GuiHexKeySelectWindow.h"
#endif

#ifndef GUIHEXKEYSELECTVIEW_H
#include "GuiHexKeySelectView.h"
#endif

#ifndef GUIHEXKEYINFOVIEW_H
#include "GuiHexKeyInfoView.h"
#endif

#ifndef GUIHEXKEYINFOWINDOW_H
#include "GuiHexKeyInfoWindow.h"
#endif

HexKeySelectWindow::HexKeySelectWindow(BRect frame, int numKeymap, int numKey)
    : BWindow(frame, LABEL_SELECT_TITLE, B_TITLED_WINDOW_LOOK , B_MODAL_APP_WINDOW_FEEL, B_NOT_RESIZABLE | B_NOT_ZOOMABLE, B_CURRENT_WORKSPACE)
{
    HexKeySelectView  *aView;
	
    frame.OffsetTo(B_ORIGIN);
    aView = new HexKeySelectView(frame, "HexKeySelectView", numKeymap, numKey);
	aView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
    AddChild(aView);
    
    Show();
}

void HexKeySelectWindow::MessageReceived(BMessage * msg)
{	
	switch(msg->what)
    {  
	  
	  case COMMAND_NEXT:
	  	{
	  		HexKeySelectView *aView;
    		aView = (HexKeySelectView *)FindView("HexKeySelectView");
    
	  		aView->NextPage();
	  		
		}
	  break;
	  
	  case COMMAND_PREV:
	  	{
	  		HexKeySelectView *aView;
    		aView = (HexKeySelectView *)FindView("HexKeySelectView");
    
	  		aView->PrevPage();
	  		
		}
	  break;
	  
	  case COMMAND_CANCEL:
	  	{
	  		Quit();
	  	}
	  break;
	  
	  case COMMAND_MODIFY:
	  	{
	  		HexKeySelectView *aView;
    		aView = (HexKeySelectView *)FindView("HexKeySelectView");
    		
    		//HexKeyInfoView *infoView;
    		//infoView = (HexKeyInfoView *)FindView("HexKeyInfoView");
    		
    		if (aView->HasBeenSelected()) 
    		{
    			aView->ModifyRequested();
    			
    			BWindow *aWindow;
				int32    i = 0;
			
				while ((aWindow = be_app->WindowAt(i++)))
				{
					BString aString;
				
					aString.SetTo(aWindow->Title());
				
					//BAlert *myAlert = new BAlert("Debug", aString.String(), "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
	  				//myAlert->Go();
					
					if (!(aString.Compare(LABEL_KEYINFO_TITLE)))
					{
						//myAlert = new BAlert("Debug", "Spedisco il messaggio", "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
	  			    	//myAlert->Go();
						aWindow->PostMessage(UPDATE_LABELS, aWindow);
					}
				}
    			
    			//PostMessage('prva');
	  			
	  			//infoView->UptadeLabels();
	  			
	  			Quit();
	  			
	  		}
			
	  	}
	  break;
	  
	  case COMMAND_TABLE_CHANGED:
	  {
	  		HexKeySelectView *aView;
    		aView = (HexKeySelectView *)FindView("HexKeySelectView");
	  		
	  		aView->TableChanged();
	 		
	  }
	  break;
	  
	  default:
		BWindow::MessageReceived(msg);
	  break;
	
	}
	
}

bool HexKeySelectWindow::QuitRequested()
{
	return (true);
}
