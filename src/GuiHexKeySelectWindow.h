/*
	GuiHexKeySelectWindow.h
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYSELECTWINDOW_H
#define GUIHEXKEYSELECTWINDOW_H
#endif

#ifndef _WINDOW_H
#include <Window.h>
#endif

const uint32 COMMAND_NEXT          = 'Next';
const uint32 COMMAND_PREV          = 'Prev';
const uint32 COMMAND_MODIFY        = 'Modf';
const uint32 COMMAND_CANCEL        = 'Cncl';
const uint32 COMMAND_TABLE_CHANGED = 'tbch';

class HexKeySelectWindow : public BWindow {

public:
              HexKeySelectWindow(BRect frame, int numKeymap, int numKey);
virtual void  MessageReceived(BMessage * msg);
virtual	bool  QuitRequested();
		
};
