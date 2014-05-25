/*
	BChar.cpp
	Mattia Tristo
	2004
*/

#ifndef _CHAR_H
#include "char.h"
#endif

BChar::BChar()
{
	Utf8Value = 0;
	
	for (int i = 0; i < 3; i++) PascalChars[i] = 0;
	PascalCharsLenght = 0;
	
}

BChar::~BChar()
{

}

void BChar::SetUtf8(int index)
{
	Clear();
	
	Utf8Value = index;
	
	ToPascal();
}

void BChar::SetPascal(char arrPascal[3], int lenght)
{
	for (int i = 0; i < 3; i++) PascalChars[i] = arrPascal[i];
	PascalCharsLenght = lenght;
	
	ToUtf8();
}

int BChar::GetUtf8()
{
	return (Utf8Value);
}

void BChar::GetPascalArray(char values[3], int *lenght)
{
	for (int i = 0; i < PascalCharsLenght; i++) values[i] = PascalChars[i];
	for (int i = PascalCharsLenght; i < 3; i++) values[i] = 0;
	*lenght = PascalCharsLenght;
}

BString BChar::GetString()
{
	BString aString;

	aString.SetTo("");
	
	for (int i = 0; i < PascalCharsLenght; i++) aString << PascalChars[i];
	
	return (aString);
}

int BChar::GetLenght()
{
	return (PascalCharsLenght);
}

bool BChar::IsMapped()
{
	return ((PascalCharsLenght != 0));
}

bool BChar::IsAsciiWithGlimphs()
{
	bool ascii;
	
	ascii = false;
	
	ascii = (Utf8Value == 0);
	
	ascii = (ascii || ((Utf8Value >= 32) && (Utf8Value <= 126)));
	
	return (ascii);
	
}

void BChar::Clear()
{
	Utf8Value = 0;
	
	for (int i = 0; i < 3; i++) PascalChars[i] = 0;
	PascalCharsLenght = 0;
	
}

void BChar::ToUtf8()
{
	switch (PascalCharsLenght)
	{
		case 1:
		{
			Utf8Value = PascalChars[0];
		}
		break;	
				
		case 2:
		{
			int tmp1;
			int tmp2;
			
			tmp1 = PascalChars[1] & 63;
			tmp2 = PascalChars[0] & 31;
			tmp2 = tmp2 << 6;
			Utf8Value = tmp1 | tmp2;
		}
		break;
					
		case 3:
		{
			int tmp1;
			int tmp2;
			int tmp3;
			
			tmp1 = PascalChars[2] & 63;
			tmp2 = PascalChars[1] & 63;
			tmp2 = tmp2 << 6;
			tmp3 = PascalChars[0] & 15;
			tmp3 = tmp3 << 10;
			Utf8Value = tmp1 | tmp2 | tmp3;
		}
		break;
		
	}
}

void BChar::ToPascal()
{
	if (Utf8Value <= 127)
	{
		PascalCharsLenght = 1;
		PascalChars[0] = Utf8Value;
	}
	else
	{
		if (Utf8Value <= 2047)
		{
			PascalCharsLenght = 2;
					
			int bitmask;
			int tmpchar;
					
			bitmask = 63;
			tmpchar = Utf8Value & bitmask;
					
			PascalChars[1] = (char)tmpchar;
			PascalChars[1] = PascalChars[1] | 128;
					
			bitmask = 1984;
			tmpchar = Utf8Value & bitmask;
			tmpchar = tmpchar >> 6;
					
			PascalChars[0] = (char)tmpchar;
			PascalChars[0] = PascalChars[0] | 192;
		}
		else
		{
			// From 2048 to 65535
					
			PascalCharsLenght = 3;
					
			int bitmask;
			int tmpchar;
					
			bitmask = 63;
			tmpchar = Utf8Value & bitmask;
					
			PascalChars[2] = (char)tmpchar;
			PascalChars[2] = PascalChars[2] | 128;
					
			bitmask = 4032;
			tmpchar = Utf8Value & bitmask;
			tmpchar = tmpchar >> 6;
					
			PascalChars[1] = (char)tmpchar;
			PascalChars[1] = PascalChars[1] | 128;
					
			bitmask = 61440;
			tmpchar = Utf8Value & bitmask;
			tmpchar = tmpchar >> 12;
					
			PascalChars[0] = (char)tmpchar;
			PascalChars[0] = PascalChars[0] | 224;
		}
	}
}
