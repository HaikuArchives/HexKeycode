/*
	UnicodeTable.h
	Mattia Tristo
	2004
*/

#ifndef _UNICODETABLE_H
#define _UNICODETABLE_H
#endif

#ifndef _STRING_H
#include <String.h> 
#endif

#define		FIRSTTABLE		0
#define		LASTTABLE     103
#define		TABLENUM      104

class UnicodeTable {

public:

			UnicodeTable();
			~UnicodeTable();
	   int  GetTableNum(int value);
   BString  GetTableNameByValue(int value);
   BString  GetTableNameByTableNum(int value);
	   int  GetFirst();
	   int  GetLast();
	   int  GetNum();
	  bool  IsInTable(int value, int table);

private:

   BString  TableName[TABLENUM];
	   int  TableStart[TABLENUM + 1];

};
