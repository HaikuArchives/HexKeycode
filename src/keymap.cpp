/*
	BKeymap.cpp
	Mattia Tristo
	2004
*/

#ifndef _KEYMAP_H
#include "keymap.h"
#endif

#ifndef _STDIO_H
#include <stdio.h>
#endif

BKeymap::BKeymap()
{
	key_map *keys;
	char *chars;
	get_key_map(&keys, &chars);
	
	int32  offset = 0;
	int    size;
	char   arrChars[3];
	
	for (int i = 0; i < 128; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			switch(j)
   			{  
	  			case 1:
	  			offset = keys->normal_map[i];
	  			break;
			
				case 2:
				offset = keys->shift_map[i];
				break;
			
				case 3:
				offset = keys->caps_map[i];
				break;
			
				case 4:
				offset = keys->caps_shift_map[i];
				break;
			
				case 5:
				offset = keys->option_map[i];
				break;
			
				case 6:
				offset = keys->option_shift_map[i];
				break;
			
				case 7:
				offset = keys->option_caps_map[i];
				break;
			
				case 8:
				offset = keys->option_caps_shift_map[i];
				break;
			
				case 9:
				offset = keys->control_map[i];
				break;
			
			}
			
			size = chars[offset];
			for (int32 k = 0; k < size; k++) arrChars[k] = chars[offset + k + 1];
			
			switch(j)
   			{  
	  			case 1:
	  			normal_map[i].SetPascal(arrChars, size);
	  			break;
			
				case 2:
				shift_map[i].SetPascal(arrChars, size);
				break;
			
				case 3:
				caps_map[i].SetPascal(arrChars, size);
				break;
			
				case 4:
				caps_shift_map[i].SetPascal(arrChars, size);
				break;
			
				case 5:
				option_map[i].SetPascal(arrChars, size);
				break;
			
				case 6:
				option_shift_map[i].SetPascal(arrChars, size);
				break;
			
				case 7:
				option_caps_map[i].SetPascal(arrChars, size);
				break;
			
				case 8:
				option_caps_shift_map[i].SetPascal(arrChars, size);
				break;
			
				case 9:
				control_map[i].SetPascal(arrChars, size);
				break;
			
			}
		
		}
		
	}
	
	//Version
	version = keys->version;
	
	/*
	BString aString;
		
	aString.SetTo("");
		
	aString << "Version : " << version;
		
	BAlert *myAlert = new BAlert("Arrivato", aString.String(), "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
	myAlert->Go();
	*/
		
	//Modifiers
	
	modifiers[0] = keys->caps_key;
	modifiers[1] = keys->scroll_key;
	modifiers[2] = keys->num_key;
	modifiers[3] = keys->left_shift_key;
	modifiers[4] = keys->right_shift_key;
	modifiers[5] = keys->left_command_key;
	modifiers[6] = keys->right_command_key;
	modifiers[7] = keys->left_control_key;
	modifiers[8] = keys->right_control_key;
	modifiers[9] = keys->left_option_key;
	modifiers[10] = keys->right_option_key;
	modifiers[11] = keys->menu_key;
	
	//Lock Settings
	lock_settings = keys->lock_settings;
	
	/*
	aString.SetTo("");
		
	aString << "Lock Settings : " << lock_settings;
		
	myAlert = new BAlert("Arrivato", aString.String(), "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
	myAlert->Go();
	*/
	
	free(chars);
	free(keys);
	
	Changed = false;
	
}

BKeymap::~BKeymap()
{
	
}

void BKeymap::ApplyChanges()
{
	if (Changed)
	{
		/*
		key_map *keys;
		char *mapchars;
		char *chars;
		
		chars = (char *)malloc(4610);
		//mapchars = (char *)malloc(4610);
		
		get_key_map( &keys, &mapchars );
		
		int32  offset;
		int    size;
		char   arrChars[3];
		
		offset = 0;
		
		BAlert *myAlert = new BAlert("Arrivato", "Normal Map", "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
		myAlert->Go();
		
		//NormalMap
		for (int i = 0; i < 128; i++)
		{
	  		normal_map[i].GetPascalArray(arrChars, &size);
	  		chars[offset] = (char)size;
	  		
	  		//myAlert = new BAlert("Arrivato", "chars[offset]", "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
			//myAlert->Go();
			
	  		for (int k = 0; k < size; k++) chars[offset + k + 1] = arrChars[k];
	  		keys->normal_map[i] = offset;
	  		offset = offset + size + 1;
	  	}
	  	
	  	myAlert = new BAlert("Arrivato", "Shift Map", "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
		myAlert->Go();
	  	
	  	//ShiftMap
	  	for (int i = 0; i < 128; i++)
		{
	  		shift_map[i].GetPascalArray(arrChars, &size);
	  		chars[offset] = (char)size;
	  		for (int k = 0; k < size; k++) chars[offset + k + 1] = arrChars[k];
	  		keys->shift_map[i] = offset;
	  		offset = offset + size + 1;
	  	}
		
		BString aString;
		
		aString.SetTo("");
		
		aString << "CapsMap; Offset : " << offset;
		
		myAlert = new BAlert("Arrivato", aString.String(), "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
		myAlert->Go();
		
		//CapsMap
		for (int i = 0; i < 128; i++)
		{
	  		caps_map[i].GetPascalArray(arrChars, &size);
	  		chars[offset] = (char)size;
	  		for (int k = 0; k < size; k++) chars[offset + k + 1] = arrChars[k];
	  		keys->caps_map[i] = offset;
	  		offset = offset + size + 1;
	  	}
		
		aString.SetTo("");
		
		aString << "CapsShiftMap; Offset : " << offset;
		
		myAlert = new BAlert("Arrivato", aString.String(), "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
		myAlert->Go();
		
		//CapsShiftMap
		for (int i = 0; i < 128; i++)
		{
	  		caps_shift_map[i].GetPascalArray(arrChars, &size);
	  		chars[offset] = (char)size;
	  		for (int k = 0; k < size; k++) chars[offset + k + 1] = arrChars[k];
	  		keys->caps_shift_map[i] = offset;
	  		offset = offset + size + 1;
	  	}
		
		myAlert = new BAlert("Arrivato", "OptionMap", "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
		myAlert->Go();
		
		//OptionMap
		for (int i = 0; i < 128; i++)
		{
	  		option_map[i].GetPascalArray(arrChars, &size);
	  		chars[offset] = (char)size;
	  		for (int k = 0; k < size; k++) chars[offset + k + 1] = arrChars[k];
	  		keys->option_map[i] = offset;
	  		offset = offset + size + 1;
	  	}
		
		myAlert = new BAlert("Arrivato", "OptionShiftMap", "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
		myAlert->Go();
		
		//OptionShiftMap
		for (int i = 0; i < 128; i++)
		{
	  		option_shift_map[i].GetPascalArray(arrChars, &size);
	  		chars[offset] = (char)size;
	  		for (int k = 0; k < size; k++) chars[offset + k + 1] = arrChars[k];
	  		keys->option_shift_map[i] = offset;
	  		offset = offset + size + 1;
	  	}
		
		myAlert = new BAlert("Arrivato", "OptionCapsMap", "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
		myAlert->Go();
		
		//OptionCapsMap
		for (int i = 0; i < 128; i++)
		{
	  		option_caps_map[i].GetPascalArray(arrChars, &size);
	  		chars[offset] = (char)size;
	  		for (int k = 0; k < size; k++) chars[offset + k + 1] = arrChars[k];
	  		keys->option_caps_map[i] = offset;
	  		offset = offset + size + 1;
	  	}
		
		myAlert = new BAlert("Arrivato", "OptionCapsShiftMap", "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
		myAlert->Go();
		
		//OptionCapsShiftMap
		for (int i = 0; i < 128; i++)
		{
	  		option_caps_shift_map[i].GetPascalArray(arrChars, &size);
	  		chars[offset] = (char)size;
	  		for (int k = 0; k < size; k++) chars[offset + k + 1] = arrChars[k];
	  		keys->option_caps_shift_map[i] = offset;
	  		offset = offset + size + 1;
	  	}
		
		myAlert = new BAlert("Arrivato", "ControlMap", "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
		myAlert->Go();
		
		//ControlMap
		for (int i = 0; i < 128; i++)
		{
	  		control_map[i].GetPascalArray(arrChars, &size);
	  		chars[offset] = (char)size;
	  		for (int k = 0; k < size; k++) chars[offset + k + 1] = arrChars[k];
	  		keys->control_map[i] = offset;
	  		offset = offset + size + 1;
	  	}
	  	
	  	myAlert = new BAlert("Arrivato", "Fine Map", "Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
		myAlert->Go();
		
		mapchars = chars;
		
		free(keys);
		free(mapchars);
		free(chars);
		
		Changed = false;
		*/
	}
	
}

void BKeymap::SetKey(int key, int map, BChar value)
{
	switch(map)
   	{  
	  	case 1:
	  	normal_map[key].SetUtf8(value.GetUtf8());
	  	break;
			
		case 2:
		shift_map[key].SetUtf8(value.GetUtf8());
		break;
			
		case 3:
		caps_map[key].SetUtf8(value.GetUtf8());
		break;
			
		case 4:
		caps_shift_map[key].SetUtf8(value.GetUtf8());
		break;
			
		case 5:
		option_map[key].SetUtf8(value.GetUtf8());
		break;
			
		case 6:
		option_shift_map[key].SetUtf8(value.GetUtf8());
		break;
			
		case 7:
		option_caps_map[key].SetUtf8(value.GetUtf8());
		break;
			
		case 8:
		option_caps_shift_map[key].SetUtf8(value.GetUtf8());
		break;
			
		case 9:
		control_map[key].SetUtf8(value.GetUtf8());
		break;
			
	}
	
	Changed = true;
}

void BKeymap::ClearKey(int key, int map)
{
	BChar aChar;
	
	aChar.Clear();
	
	SetKey(key, map, aChar);
	
}

BChar BKeymap::GetKey(int key, int map)
{
	switch(map)
   	{  
	  	case 1:
	  	return(normal_map[key]);
	  	break;
			
		case 2:
		return(shift_map[key]);
		break;
			
		case 3:
		return(caps_map[key]);
		break;
			
		case 4:
		return(caps_shift_map[key]);
		break;
			
		case 5:
		return(option_map[key]);
		break;
			
		case 6:
		return(option_shift_map[key]);
		break;
			
		case 7:
		return(option_caps_map[key]);
		break;
			
		case 8:
		return(option_caps_shift_map[key]);
		break;
			
		case 9:
		return(control_map[key]);
		break;
		
		default:
		{
			BChar aChar;
			return(aChar);
		}
		break;
	}
	
}

void BKeymap::ClearModifier(int key)
{
	for (int i = 0; i < 12; i++)
	{
		if ((int)modifiers[i] == key) modifiers[i] = 0;
	}
}

void BKeymap::SetModifier(int mod, int key)
{
	ClearModifier(key);
	
	mod--;
	
	if ((mod >= 0) && (mod <= 11)) modifiers[mod] = (uint32)key;
	
}

bool BKeymap::IsModifier(int key)
{
	int modifier;
	
	for (int i = 0; i < 12; i++)
	{
		modifier = (int)modifiers[i];
		if (key == modifier) return (true);
	} 

	return (false);

}

BString BKeymap::ModifierName(int key)
{
	BString aString;
	
	int modifier;
	int num;
	
	num = -1;
	
	aString.SetTo("");
	
	for (int i = 0; i < 12; i++)
	{
		modifier = (int)modifiers[i];
		if (key == modifier) num = i;
	}
	
	switch (num)
	{
		case -1:
			aString << "Not a modifier";
		break;
		
		case 0:
			aString << "Caps Lock";
		break;
		
		case 1:
			aString << "Scroll Lock";
		break;
		
		case 2:
			aString << "Num Lock";
		break;
		
		case 3:
			aString << "Left Shift";
		break;
		
		case 4:
			aString << "Right Shift";
		break;
		
		case 5:
			aString << "Left Command";
		break;
		
		case 6:
			aString << "Right Command";
		break;
		
		case 7:
			aString << "Left Control";
		break;
		
		case 8:
			aString << "Right Control";
		break;
		
		case 9:
			aString << "Left Option";
		break;
		
		case 10:
			aString << "Right Option";
		break;
		
		case 11:
			aString << "Menu";
		break;
		
	}
	
	return (aString);
	
}

int BKeymap::ModifierNum(int key)
{
	int modifier;
	int num;
	
	num = -1;
	
	for (int i = 0; i < 12; i++)
	{
		modifier = (int)modifiers[i];
		if (modifier == key) num = i;
	}
	
	num++;
	
	return (num);
	
}

BString BKeymap::BCharToBStringFile(BChar value)
{
	BString aString;
	Hex     hexConv;
	
	if (value.IsAsciiWithGlimphs())
	{
		if (value.GetUtf8() == 0)
		{
			aString << "''";
		}
		else if (value.GetUtf8() == 39)
		{
			aString << "'\\''";
		}
		else if (value.GetUtf8() == 92)
		{
			aString << "'\\\\'";
		}
		else
		{
			aString << "'" << value.GetString() << "'"; // << " " << value.GetUtf8();
		}
	}
	else
	{
		hexConv.Set(value);
		aString << "0x" << hexConv.GetString();
	}
		
	for (int i = aString.Length(); i <= 20; i++) aString << " ";
	
	return (aString);
	
}

void BKeymap::DumpToFile()
{
	BString aString;
	
	FILE *aFile;
	
	aFile = fopen("/tmp/HexKeyCodeFinderKeymap.txt", "w");
	
	aString.SetTo("#!/bin/keymap -l\n#\n");
	fputs(aString.String(), aFile);
	
	aString.SetTo("#	Raw key numbering for 101 keyboard...\n");
	fputs(aString.String(), aFile);
	
	aString.SetTo("#                                                                                        [sys]       [brk]\n");
	fputs(aString.String(), aFile);
	
	aString.SetTo("#                                                                                         0x7e        0x7f\n");
	fputs(aString.String(), aFile);
	
	aString.SetTo("# [esc]       [ f1] [ f2] [ f3] [ f4] [ f5] [ f6] [ f7] [ f8] [ f9] [f10] [f11] [f12]    [prn] [scr] [pau]\n");
	fputs(aString.String(), aFile);
	
	aString.SetTo("#  0x01        0x02  0x03  0x04  0x05  0x06  0x07  0x08  0x09  0x0a  0x0b  0x0c  0x0d     0x0e  0x0f  0x10     K E Y P A D   K E Y S\n");
	fputs(aString.String(), aFile);
	
	aString.SetTo("#\n# [ ` ] [ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ] [ 6 ] [ 7 ] [ 8 ] [ 9 ] [ 0 ] [ - ] [ = ] [bck]    [ins] [hme] [pup]    [num] [ / ] [ * ] [ - ]\n");
	fputs(aString.String(), aFile);
	
	aString.SetTo("#  0x11  0x12  0x13  0x14  0x15  0x16  0x17  0x18  0x19  0x1a  0x1b  0x1c  0x1d  0x1e     0x1f  0x20  0x21     0x22  0x23  0x24  0x25\n");
	fputs(aString.String(), aFile);
	
	aString.SetTo("#\n# [tab] [ q ] [ w ] [ e ] [ r ] [ t ] [ y ] [ u ] [ i ] [ o ] [ p ] [ [ ] [ ] ] [ \\ ]    [del] [end] [pdn]    [ 7 ] [ 8 ] [ 9 ] [ + ]\n");
	fputs(aString.String(), aFile);
	
	aString.SetTo("#  0x26  0x27  0x28  0x29  0x2a  0x2b  0x2c  0x2d  0x2e  0x2f  0x30  0x31  0x32  0x33     0x34  0x35  0x36     0x37  0x38  0x39  0x3a\n");
	fputs(aString.String(), aFile);
	
	aString.SetTo("#\n# [cap] [ a ] [ s ] [ d ] [ f ] [ g ] [ h ] [ j ] [ k ] [ l ] [ ; ] [ ' ] [  enter  ]                         [ 4 ] [ 5 ] [ 6 ]\n");
	fputs(aString.String(), aFile);
	
	aString.SetTo("#  0x3b  0x3c  0x3d  0x3e  0x3f  0x40  0x41  0x42  0x43  0x44  0x45  0x46     0x47                             0x48  0x49  0x4a\n");
	fputs(aString.String(), aFile);
	
	aString.SetTo("#\n# [shift]     [ z ] [ x ] [ c ] [ v ] [ b ] [ n ] [ m ] [ , ] [ . ] [ / ]     [shift]          [ up]          [ 1 ] [ 2 ] [ 3 ] [ent]\n");
	fputs(aString.String(), aFile);
	
	aString.SetTo("#   0x4b       0x4c  0x4d  0x4e  0x4f  0x50  0x51  0x52  0x53  0x54  0x55       0x56            0x57           0x58  0x59  0x5a  0x5b\n");
	fputs(aString.String(), aFile);
	
	aString.SetTo("#\n# [ctr]             [cmd]             [  space  ]             [cmd]             [ctr]    [lft] [dwn] [rgt]    [ 0 ] [ . ]\n");
	fputs(aString.String(), aFile);
	
	aString.SetTo("#  0x5c              0x5d                 0x5e                 0x5f              0x60     0x61  0x62  0x63     0x64  0x65\n");
	fputs(aString.String(), aFile);
	
	aString.SetTo("Version = ");
	aString << version << "\n";
	fputs(aString.String(), aFile);
	
	Hex hexConv;
	
	aString.SetTo("CapsLock = 0x");
	hexConv.Set((uint8)modifiers[0]);
	aString << hexConv.GetString() << "\n";
	fputs(aString.String(), aFile);
	
	aString.SetTo("ScrollLock = 0x");
	hexConv.Set((uint8)modifiers[1]);
	aString << hexConv.GetString() << "\n";
	fputs(aString.String(), aFile);
	
	aString.SetTo("NumLock = 0x");
	hexConv.Set((uint8)modifiers[2]);
	aString << hexConv.GetString() << "\n";
	fputs(aString.String(), aFile);
	
	aString.SetTo("LShift = 0x");
	hexConv.Set((uint8)modifiers[3]);
	aString << hexConv.GetString() << "\n";
	fputs(aString.String(), aFile);
	
	aString.SetTo("RShift = 0x");
	hexConv.Set((uint8)modifiers[4]);
	aString << hexConv.GetString() << "\n";
	fputs(aString.String(), aFile);
	
	aString.SetTo("LCommand = 0x");
	hexConv.Set((uint8)modifiers[5]);
	aString << hexConv.GetString() << "\n";
	fputs(aString.String(), aFile);
	
	aString.SetTo("RCommand = 0x");
	hexConv.Set((uint8)modifiers[6]);
	aString << hexConv.GetString() << "\n";
	fputs(aString.String(), aFile);
	
	aString.SetTo("LControl = 0x");
	hexConv.Set((uint8)modifiers[7]);
	aString << hexConv.GetString() << "\n";
	fputs(aString.String(), aFile);
	
	aString.SetTo("RControl = 0x");
	hexConv.Set((uint8)modifiers[8]);
	aString << hexConv.GetString() << "\n";
	fputs(aString.String(), aFile);
	
	aString.SetTo("LOption = 0x");
	hexConv.Set((uint8)modifiers[9]);
	aString << hexConv.GetString() << "\n";
	fputs(aString.String(), aFile);
	
	aString.SetTo("ROption = 0x");
	hexConv.Set((uint8)modifiers[10]);
	aString << hexConv.GetString() << "\n";
	fputs(aString.String(), aFile);
	
	aString.SetTo("Menu = 0x");
	hexConv.Set((uint8)modifiers[11]);
	aString << hexConv.GetString() << "\n";
	fputs(aString.String(), aFile);
	
	aString.SetTo("LockSettings =");
	
	if (lock_settings & B_CAPS_LOCK) aString << " CapsLock";
	if (lock_settings & B_NUM_LOCK) aString << " NumLock";
	if (lock_settings & B_SCROLL_LOCK) aString << " ScrollLock";
	
	aString << "\n";
	
	fputs(aString.String(), aFile);
	
	aString.SetTo("# Key      n        s        c        o        os       C        Cs       Co       Cos\n");
	fputs(aString.String(), aFile);
	
	for (int i = 0; i < 128; i++)
	{
		aString.SetTo("Key 0x");
		hexConv.Set((uint8)i);
		aString << hexConv.GetString() << " = ";
		aString << BCharToBStringFile(normal_map[i]);
		aString << BCharToBStringFile(shift_map[i]);
		aString << BCharToBStringFile(control_map[i]);
		aString << BCharToBStringFile(option_map[i]);
		aString << BCharToBStringFile(option_shift_map[i]);
		aString << BCharToBStringFile(caps_map[i]);
		aString << BCharToBStringFile(caps_shift_map[i]);
		aString << BCharToBStringFile(option_caps_map[i]);
		aString << BCharToBStringFile(option_caps_shift_map[i]);
		
		aString << "\n";
		
		fputs(aString.String(), aFile);
		
	}
	
	fclose(aFile);
	
}
