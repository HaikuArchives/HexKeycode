/*
	GuiHexKeyInfoWindow.h
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYINFOWINDOW_H
#define GUIHEXKEYINFOWINDOW_H
#endif

#ifndef _WINDOW_H
#include <Window.h>
#endif

const uint32 COMMAND_MODIFIER           = 'Mdmd';
const uint32 COMMAND_NORMAL             = 'Edt1';
const uint32 COMMAND_SHIFT              = 'Edt2';
const uint32 COMMAND_CAPS               = 'Edt3';
const uint32 COMMAND_CAPS_SHIFT         = 'Edt4';
const uint32 COMMAND_OPTION             = 'Edt5';
const uint32 COMMAND_OPTION_SHIFT       = 'Edt6';
const uint32 COMMAND_OPTION_CAPS        = 'Edt7';
const uint32 COMMAND_OPTIONS_CAPS_SHIFT = 'Edt8';
const uint32 COMMAND_CONTROL            = 'Edt9';
const uint32 UPDATE_LABELS              = 'UpLb';

class HexKeyInfoWindow : public BWindow {

public:
              HexKeyInfoWindow(BRect frame, int index);
virtual void  MessageReceived(BMessage * msg);
virtual	bool  QuitRequested();

private:

		 int  keyIndex;

};
