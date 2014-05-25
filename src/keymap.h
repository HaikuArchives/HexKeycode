/*
	BKeymap.h
	Mattia Tristo
	2004
*/

#ifndef _KEYMAP_H
#define _KEYMAP_H
#endif

#ifndef _CHAR_H
#include "char.h"
#endif

#ifndef _HEX_H
#include "hex.h"
#endif

#ifndef _INTERFACEDEFS_H
#include <interface/InterfaceDefs.h>
#endif

#ifndef _CSTDLIB
#include <cstdlib>
#endif

class BKeymap {

public:
			  BKeymap();
	   		  ~BKeymap();
        void  ApplyChanges();
        void  SetKey(int key, int map, BChar value);
       BChar  GetKey(int key, int map);
        void  ClearKey(int key, int map);
        void  ClearModifier(int key);
        void  SetModifier(int mod, int key);
        bool  IsModifier(int key);
     BString  ModifierName(int key);
         int  ModifierNum(int key);  
        void  DumpToFile();

private:
	   BChar  normal_map[128];
	   BChar  shift_map[128];
	   BChar  caps_map[128];
	   BChar  caps_shift_map[128];
	   BChar  option_map[128];
	   BChar  option_shift_map[128];
	   BChar  option_caps_map[128];
	   BChar  option_caps_shift_map[128];
	   BChar  control_map[128];
	   uint32 version;
	   uint32 modifiers[12];
	   uint32 lock_settings;
	    bool  Changed;

	 BString  BCharToBStringFile(BChar value);
	 
};
