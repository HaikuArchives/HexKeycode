/*
	GuiHexKeyTablesView.h
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYTABLESVIEW_H
#define GUIHEXKEYTABLESVIEW_H
#endif

#ifndef _VIEW_H
#include <View.h>
#endif

#ifndef _LISTVIEW_H
#include <ListView.h>
#endif

#ifndef _LISTITEM_H
#include <ListItem.h>
#endif

#ifndef _STRING_H
#include <String.h> 
#endif

#ifndef _SCROLLVIEW_H
#include <ScrollView.h>
#endif

#ifndef _BUTTON_H
#include <Button.h>
#endif

#ifndef _UNICODETABLE_H
#include "UnicodeTable.h"
#endif

class HexKeyTablesView : public BView
{

public:
              HexKeyTablesView(BRect frame, char *name);
virtual	void  AttachedToWindow();
virtual	void  Draw(BRect updateRect);
	   int32  GetSelectedIndex();

private:

   BListView  *list;

};

