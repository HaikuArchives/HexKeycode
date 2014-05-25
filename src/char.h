/*
	BChar.h
	Mattia Tristo
	2004
*/

#ifndef _CHAR_H
#define _CHAR_H
#endif

#ifndef _STRING_H
#include <String.h> 
#endif

class BChar {

public:
			  BChar();
			  ~BChar();
        void  SetUtf8(int index);
        void  SetPascal(char arrPascal[3], int lenght);
		 int  GetUtf8();
        void  GetPascalArray(char values[3], int *lenght);
	 BString  GetString();
		 int  GetLenght();
		bool  IsMapped();
		bool  IsAsciiWithGlimphs();
        void  Clear();

private:

		 int  Utf8Value;
		char  PascalChars[3];
		 int  PascalCharsLenght;
		 
        void  ToUtf8();
        void  ToPascal();

};
