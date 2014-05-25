/*
	GuiHexKeyApp.h
	Mattia Tristo
	2004
*/

#ifndef GUIHEXKEYAPP_H
#define GUIHEXKEYAPP_H
#endif

#ifndef _APPLICATION_H
#include <Application.h>
#endif

#ifndef _LOCALE_H
#include <Locale.h>
#endif

#ifndef GUIHEXKEYWINDOW_H
#include "GuiHexKeyWindow.h"
#endif

class HexKeyApplication : public BApplication {

public:
              HexKeyApplication();
    
};

#define		LABEL_WINDOW_TITLE					_T("Hex Key's Code Finder")
#define		LABEL_BOX_TITLE						_T("Keyboard Layout")
#define		LABEL_TITLE_KEY_PRESSED				_T("Key(s) pressed hex value :")
#define		LABEL_KEY_PRESSED					_T("No key(s) pressed")
#define		LABEL_INSTRUCTIONS					_T("Click over a key to see the keymap info")
#define		LABEL_KEYINFO_TITLE					_T("Key Mapping")
#define		LABEL_KEYINFO_BOX_TITLE				_T("Key Mapping Details")
#define		LABEL_KEYINFO_SELECTEDKEY			_T("Selected key index : ")
#define     LABEL_KEYINFO_MODIFIER              _T("Modifier              : ")
#define		LABEL_KEYINFO_NORMAL				_T("Normal Map            : ")
#define		LABEL_KEYINFO_SHIFT					_T("Shift Map             : ")
#define		LABEL_KEYINFO_CAPS					_T("Caps Map              : ")
#define		LABEL_KEYINFO_CAPS_SHIFT			_T("Caps Shift Map        : ")
#define		LABEL_KEYINFO_OPTION				_T("Option Map            : ")
#define		LABEL_KEYINFO_OPTION_SHIFT			_T("Option Shift Map      : ")
#define		LABEL_KEYINFO_OPTION_CAPS			_T("Option Caps Map       : ")
#define		LABEL_KEYINFO_OPTIONS_CAPS_SHIFT	_T("Option Caps Shift Map : ")
#define		LABEL_KEYINFO_CONTROL				_T("Control Map           : ")
#define     LALEL_KEYINFO_NOT_MAPPED            _T("Not mapped")
#define     LABEL_SELECT_TITLE                  _T("Select a character")
#define     LABEL_MODIFIER_TITLE                _T("Choose a modifier")
#define     LABEL_MODIFIER_BOX_TITLE            _T("Select a modifier")
#define     LABEL_MODIFIER_NOT_MODIFIER         _T("None")
#define     LABEL_MODIFIER_CAPS_LOCK            _T("Caps Lock")
#define     LABEL_MODIFIER_SCROLL_LOCK          _T("Scroll Lock")
#define     LABEL_MODIFIER_NUM_LOCK             _T("Num Lock")
#define     LABEL_MODIFIER_LEFT_SHIFT           _T("Left Shift")
#define     LABEL_MODIFIER_RIGHT_SHIFT          _T("Right Shift")
#define     LABEL_MODIFIER_LEFT_COMMAND         _T("Left Command")
#define     LABEL_MODIFIER_RIGHT_COMMAND        _T("Right Command")
#define     LABEL_MODIFIER_LEFT_CONTROL         _T("Left Control")
#define     LABEL_MODIFIER_RIGHT_CONTROL        _T("Right Control")
#define     LABEL_MODIFIER_LEFT_OPTION          _T("Left Option")
#define     LABEL_MODIFIER_RIGHT_OPTION         _T("Right Option")
#define     LABEL_MODIFIER_MENU                 _T("Menu")
#define		LABEL_UTF8_ASCII					_T("UTF-8/ASCII Code ")
#define		LABEL_UTF8							_T("UTF-8 Code ")
#define     LABEL_PAGE                          _T("Page ")
#define     LABEL_SELECTED_KEY                  _T("Selected : ")
#define     LABEL_SELECTED_TABLE                _T("Selected Table")
#define     LABEL_FILE                          _T("File")
#define     LABEL_RESTORE                       _T("Restore Keymap")
#define     LABEL_QUIT                          _T("Quit")
#define		LABEL_ABOUT							_T("About")
#define		LABEL_ABOUT_BOX_MESSAGE				_T("      Hex Key's Code Finder\n\n           written  by\n          Mattia Tristo\n\n         to contact me :\n     mattia_tristo@libero.it\n\n      Padova - Italy - 2004\n\n")
#define		LABEL_OK							_T("Ok")
#define     LABEL_MODIFY                        _T("Modify")
#define     LABEL_CANCEL                        _T("Cancel")
#define     LABEL_PREVIOUS                      _T("Prev")
#define     LABEL_NEXT                          _T("Next")
