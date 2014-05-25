/*
	GuiHexKeyModifiersWindow.h
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYMODIFIERSWINDOW_H
#define GUIHEXKEYMODIFIERSWINDOW_H
#endif

#ifndef _WINDOW_H
#include <Window.h>
#endif

const uint32  OPTION_NOTMODIFIER   = 'MdNM';
const uint32  OPTION_CAPS          = 'MdCL';
const uint32  OPTION_SCROLL        = 'MdSL';
const uint32  OPTION_NUM           = 'MdNL';
const uint32  OPTION_LEFT_SHIFT    = 'MdLS';
const uint32  OPTION_RIGHT_SHIFT   = 'MdRS';
const uint32  OPTION_LEFT_COMMAND  = 'MdLC';
const uint32  OPTION_RIGHT_COMMAND = 'MdRC';
const uint32  OPTION_LEFT_CONTROL  = 'MLCN';
const uint32  OPTION_RIGHT_CONTROL = 'MRCN';
const uint32  OPTION_LEFT_OPTION   = 'MdLO';
const uint32  OPTION_RIGHT_OPTION  = 'MdRO';
const uint32  OPTION_MENU          = 'MdMN';
const uint32  OPTION_CANCEL        = 'Cncl';
const uint32  OPTION_MODIFY        = 'Modf';

class GuiHexKeyModifiersWindow : public BWindow {

public:
              GuiHexKeyModifiersWindow(BRect frame, int KeyNum);
        void  SetModifier();
virtual void  MessageReceived(BMessage * msg);
virtual	bool  QuitRequested();

private:

		 int  KeyIndex;
		 int  ChosenModifier;
};
