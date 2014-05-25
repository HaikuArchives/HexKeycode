/*
	hex.h
	Mattia Tristo
	2004
*/

#ifndef _HEX_H
#define _HEX_H
#endif

#ifndef _STRING_H
#include <String.h> 
#endif

#ifndef _CHAR_H
#include "char.h"
#endif

class Hex
{

public:
			  Hex();
			  ~Hex();
        void  Set(char value);
        void  Set(uint8 value);
        void  Set(int value);
        void  Set(BChar value);
	 BString  GetString();

private:

	 BString  HexString;

        void  UInt8ToString(uint8 decimal);

};
