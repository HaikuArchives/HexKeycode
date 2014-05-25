/*
	GuiHexKeyApp.h
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

int main(int32 argc, char**argv)
{	
    HexKeyApplication *keyApp;

    keyApp = new HexKeyApplication();
    keyApp->Run();
	
    delete(keyApp);
    return(0);
}

HexKeyApplication::HexKeyApplication()
		  		  : BApplication("application/x-vnd.triber-hexkey")
{
    HexKeyWindow	*aWindow;
    BRect 			 aRect;

    aRect.Set(20, 20, 400, 320);
    aWindow = new HexKeyWindow(aRect);	
}
