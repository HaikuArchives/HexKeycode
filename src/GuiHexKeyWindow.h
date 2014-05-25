/*
	GuiHexKeyWindow.h
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYWINDOW_H
#define GUIHEXKEYWINDOW_H
#endif

#ifndef _WINDOW_H
#include <Window.h>
#endif

#ifndef _MENUBAR_H
#include <MenuBar.h>
#endif

#ifndef _MENU_H
#include <Menu.h>
#endif

#ifndef _MENUITEM_H
#include <MenuItem.h>
#endif

#ifndef _ALERT_H
#include <Alert.h>
#endif

#ifndef _TEXTVIEW_H
#include <TextView.h>
#endif

#define MENU_BAR_HEIGHT   18.0
#define MENU_RESTORE	  'mnrs'
#define MENU_QUIT		  'mnqt'
#define MENU_ABOUT		  'mnab'

class HexKeyWindow : public BWindow {

public:
              HexKeyWindow(BRect frame);
virtual void  MessageReceived(BMessage * msg);
virtual	bool  QuitRequested();

private:

	BMenuBar	*fMenuBar;
};
