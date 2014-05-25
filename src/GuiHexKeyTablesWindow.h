/*
	GuiHexKeyTablesWindow.h
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYTABLESWINDOW_H
#define GUIHEXKEYTABLESWINDOW_H
#endif

#ifndef _WINDOW_H
#include <Window.h>
#endif

const uint32 COMMAND_TABLE_MODIFY = 'TMdf';
const uint32 COMMAND_TABLE_CANCEL = 'TCnc';

class HexKeyTablesWindow : public BWindow {

public:
              HexKeyTablesWindow(BRect frame);
virtual void  MessageReceived(BMessage * msg);
virtual	bool  QuitRequested();
		
};
