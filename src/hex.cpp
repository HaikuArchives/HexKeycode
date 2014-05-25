/*
	hex.cpp
	Mattia Tristo
	2004
*/

#ifndef _HEX_H
#include "hex.h"
#endif

Hex::Hex()
{
	HexString.SetTo("");
}

Hex::~Hex()
{

}

void Hex::Set(char value)
{
	HexString.SetTo("");
	
	uint8 uintvalue;
	
	uintvalue = (uint8)value;
	
	UInt8ToString(uintvalue);
}

void Hex::Set(uint8 value)
{
	HexString.SetTo("");
	
	UInt8ToString(value);
}

void Hex::Set(int value)
{
	HexString.SetTo("");
	
	uint8 uintvalue;
	int tmpvalue;
	
	tmpvalue = value >> 8;
	uintvalue = (uint8)tmpvalue;
	
	UInt8ToString(uintvalue);
	
	tmpvalue = value & 255;
	uintvalue = (uint8)tmpvalue;
	
	UInt8ToString(uintvalue);
}

void Hex::Set(BChar value)
{
	HexString.SetTo("");
	
	uint8 uintvalue;
	char  arrChars[3];
	int   len;
	
	value.GetPascalArray(arrChars, &len);
	
	for (int i = 0; i < len; i++)
	{
		uintvalue = (uint8)arrChars[i];
		
		UInt8ToString(uintvalue);
	}
	
	if (len == 0) HexString << "00"; 
	
}

BString Hex::GetString()
{
	return (HexString);
}

void Hex::UInt8ToString(uint8 decimal)
{
	BString   tempString;
	BString	  HexDigits;
	int		  remainder;
	
	tempString.SetTo("");
	HexDigits.SetTo("0123456789ABCDEF");
	
	while (decimal > 0)
	{
		remainder = decimal % 16;	
		tempString << HexDigits[remainder];
		decimal = decimal / 16;
	}
	
	//Fill with a 0 if one digit, with 00 if no digits
	if (tempString.CountChars() <= 1)
	{
		for (int i = tempString.CountChars(); i < 2; i++) tempString << "0";
	}
	
	for (int i = tempString.CountChars() - 1; i >= 0; i--)
	{
		HexString << tempString[i];
	}
	
}
