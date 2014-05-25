/*
	UnicodeTable.cpp
	Mattia Tristo
	2004
*/

#ifndef _UNICODETABLE_H
#include "UnicodeTable.h"
#endif

UnicodeTable::UnicodeTable()
{
	TableName[0].SetTo("Basic Latin");
	TableStart[0] = 0x0000;
	
	TableName[1].SetTo("Latin-1 Supplement");
	TableStart[1] = 0x0080;
	
	TableName[2].SetTo("Latin Extended-A");
	TableStart[2] = 0x0100;
	
	TableName[3].SetTo("Latin Extended-B");
	TableStart[3] = 0x0180;
	
	TableName[4].SetTo("IPA Extensions");
	TableStart[4] = 0x0250;
	
	TableName[5].SetTo("Spacing Modifier Letters");
	TableStart[5] = 0x02B0;
	
	TableName[6].SetTo("Combining Diacritical Marks");
	TableStart[6] = 0x0300;
	
	TableName[7].SetTo("Greek");
	TableStart[7] = 0x0370;
	
	TableName[8].SetTo("Cyrillic");
	TableStart[8] = 0x0400;
	
	TableName[9].SetTo("Cyrillic Supplement");
	TableStart[9] = 0x0500;
	
	TableName[10].SetTo("Armenian");
	TableStart[10] = 0x0530;
	
	TableName[11].SetTo("Hebrew");
	TableStart[11] = 0x0590;
	
	TableName[12].SetTo("Arabic");
	TableStart[12] = 0x0600;
	
	TableName[13].SetTo("Syriac");
	TableStart[13] = 0x0700;
	
	TableName[14].SetTo("Thaana");
	TableStart[14] = 0x0780;
	
	TableName[15].SetTo("Devanagari");
	TableStart[15] = 0x0900;
	
	TableName[16].SetTo("Bengali");
	TableStart[16] = 0x0980;
	
	TableName[17].SetTo("Gurmukhi");
	TableStart[17] = 0x0A00;
	
	TableName[18].SetTo("Gujarati");
	TableStart[18] = 0x0A80;
	
	TableName[19].SetTo("Oriya");
	TableStart[19] = 0x0B00;
	
	TableName[20].SetTo("Tamil");
	TableStart[20] = 0x0B80;
	
	TableName[21].SetTo("Telugu");
	TableStart[21] = 0x0C00;
	
	TableName[22].SetTo("Kannada");
	TableStart[22] = 0x0C80;
	
	TableName[23].SetTo("Malayalam");
	TableStart[23] = 0x0D00;
	
	TableName[24].SetTo("Sinhala");
	TableStart[24] = 0x0D80;
	
	TableName[25].SetTo("Thai");
	TableStart[25] = 0x0E00;
	
	TableName[26].SetTo("Lao");
	TableStart[26] = 0x0E80;
	
	TableName[27].SetTo("Tibetan");
	TableStart[27] = 0x0F00;
	
	TableName[28].SetTo("Myanmar");
	TableStart[28] = 0x1000;
	
	TableName[29].SetTo("Georgian");
	TableStart[29] = 0x10A0;
	
	TableName[30].SetTo("Hangul Jamo");
	TableStart[30] = 0x1100;
	
	TableName[31].SetTo("Ethiopic");
	TableStart[31] = 0x1200;
	
	TableName[32].SetTo("Cherokee");
	TableStart[32] = 0x13A0;
	
	TableName[33].SetTo("Unified Canadian");
	TableStart[33] = 0x1400;
	
	TableName[34].SetTo("Ogham");
	TableStart[34] = 0x1680;
	
	TableName[35].SetTo("Runic");
	TableStart[35] = 0x16A0;
	
	TableName[36].SetTo("Tagalog");
	TableStart[36] = 0x1700;
	
	TableName[37].SetTo("Hanunoo");
	TableStart[37] = 0x1720;
	
	TableName[38].SetTo("Buhid");
	TableStart[38] = 0x1740;
	
	TableName[39].SetTo("Tagbanwa");
	TableStart[39] = 0x1760;
	
	TableName[40].SetTo("Khmer");
	TableStart[40] = 0x1780;
	
	TableName[41].SetTo("Mongolian");
	TableStart[41] = 0x1800;
	
	TableName[42].SetTo("Limbu");
	TableStart[42] = 0x1900;
	
	TableName[43].SetTo("Tai Le");
	TableStart[43] = 0x1950;
	
	TableName[44].SetTo("Khmer Symbols");
	TableStart[44] = 0x19E0;
	
	TableName[45].SetTo("Phonetic Extensions");
	TableStart[45] = 0x1D00;
	
	TableName[46].SetTo("Latin Extended Additional");
	TableStart[46] = 0x1E00;
	
	TableName[47].SetTo("Greek Extended");
	TableStart[47] = 0x1F00;
	
	TableName[48].SetTo("General Punctuation");
	TableStart[48] = 0x2000;
	
	TableName[49].SetTo("Superscripts and Subscripts");
	TableStart[49] = 0x2070;
	
	TableName[50].SetTo("Currency Symbols");
	TableStart[50] = 0x20A0;
	
	TableName[51].SetTo("Combining Marks for Symbols");
	TableStart[51] = 0x20D0;
	
	TableName[52].SetTo("Letterlike Symbols");
	TableStart[52] = 0x2100;
	
	TableName[53].SetTo("Number Forms");
	TableStart[53] = 0x2150;
	
	TableName[54].SetTo("Arrows");
	TableStart[54] = 0x2190;
	
	TableName[55].SetTo("Mathematical Operators");
	TableStart[55] = 0x2200;
	
	TableName[56].SetTo("Miscellaneous Technical");
	TableStart[56] = 0x2300;
	
	TableName[57].SetTo("Control Pictures");
	TableStart[57] = 0x2400;
	
	TableName[58].SetTo("Optical Character Recognition");
	TableStart[58] = 0x2440;
	
	TableName[59].SetTo("Enclosed Alphanumerics");
	TableStart[59] = 0x2460;
	
	TableName[60].SetTo("Box Drawing");
	TableStart[60] = 0x2500;
	
	TableName[61].SetTo("Block Elements");
	TableStart[61] = 0x2580;
	
	TableName[62].SetTo("Geometric Shapes");
	TableStart[62] = 0x25A0;
	
	TableName[63].SetTo("Miscellaneous Symbols");
	TableStart[63] = 0x2600;
	
	TableName[64].SetTo("Dingbats");
	TableStart[64] = 0x2700;
	
	TableName[65].SetTo("Miscellaneous Mathematical Symbols-A");
	TableStart[65] = 0x27C0;
	
	TableName[66].SetTo("Supplemental Arrows-A");
	TableStart[66] = 0x27F0;
	
	TableName[67].SetTo("Braille Patterns");
	TableStart[67] = 0x2800;
	
	TableName[68].SetTo("Supplemental Arrows-B");
	TableStart[68] = 0x2900;
	
	TableName[69].SetTo("Miscellaneous Mathematical Symbols-B");
	TableStart[69] = 0x2980;
	
	TableName[70].SetTo("Supplemental Mathematical Operators");
	TableStart[70] = 0x2A00;
	
	TableName[71].SetTo("Miscellaneous Symbols and Arrows");
	TableStart[71] = 0x2B00;
	
	TableName[72].SetTo("CJK Radicals Supplement");
	TableStart[72] = 0x2E80;
	
	TableName[73].SetTo("Kangxi Radicals");
	TableStart[73] = 0x2F00;
	
	TableName[74].SetTo("Ideographic Description Characters");
	TableStart[74] = 0x2FF0;
	
	TableName[75].SetTo("CJK Symbols and Punctuation");
	TableStart[75] = 0x3000;
	
	TableName[76].SetTo("Hiragana");
	TableStart[76] = 0x3040;
	
	TableName[77].SetTo("Katakana");
	TableStart[77] = 0x30A0;
	
	TableName[78].SetTo("Bopomofo");
	TableStart[78] = 0x3100;
	
	TableName[79].SetTo("Hangul Compatibility Jamo");
	TableStart[79] = 0x3130;
	
	TableName[80].SetTo("Kanbun");
	TableStart[80] = 0x3190;
	
	TableName[81].SetTo("Bopomofo Extended");
	TableStart[81] = 0x31A0;
	
	TableName[82].SetTo("Katakana Phonetic Extensions");
	TableStart[82] = 0x31F0;
	
	TableName[83].SetTo("Enclosed CJK Letters and Months");
	TableStart[83] = 0x3200;
	
	TableName[84].SetTo("CJK Compatibility");
	TableStart[85] = 0x3300;
	
	TableName[85].SetTo("CJK Unified Ideographs Extension A");
	TableStart[85] = 0x3400;
	
	TableName[86].SetTo("Yijing Hexagram Symbols");
	TableStart[86] = 0x4DC0;
	
	TableName[87].SetTo("CJK Unified Ideographs");
	TableStart[87] = 0x4E00;
	
	TableName[88].SetTo("Yi Syllables");
	TableStart[88] = 0xA000;
	
	TableName[89].SetTo("Yi Radicals");
	TableStart[89] = 0xA490;
	
	TableName[90].SetTo("Hangul Syllables");
	TableStart[90] = 0xAC00;
	
	TableName[91].SetTo("High Surrogates");
	TableStart[91] = 0xD800;
	
	TableName[92].SetTo("Low Surrogates");
	TableStart[92] = 0xDC00;
	
	TableName[93].SetTo("Private Use Area");
	TableStart[93] = 0xE000;
	
	TableName[94].SetTo("CJK Compatibility Ideographs");
	TableStart[94] = 0xF900;
	
	TableName[95].SetTo("Alphabetic Presentation Forms");
	TableStart[95] = 0xFB00;
	
	TableName[96].SetTo("Arabic Presentation Forms-A");
	TableStart[96] = 0xFB50;
	
	TableName[97].SetTo("Variation Selectors");
	TableStart[97] = 0xFE00;
	
	TableName[98].SetTo("Combining Half Marks");
	TableStart[98] = 0xFE20;
	
	TableName[99].SetTo("CJK Compatibility Forms");
	TableStart[99] = 0xFE30;
	
	TableName[100].SetTo("Small Form Variants");
	TableStart[100] = 0xFE50;
	
	TableName[101].SetTo("Arabic Presentation Forms-B");
	TableStart[101] = 0xFE70;
	
	TableName[102].SetTo("Halfwidth and Fullwidth Forms");
	TableStart[102] = 0xFF00;
	
	TableName[103].SetTo("Specials");
	TableStart[103] = 0xFFF0;
	
	TableStart[104] = 0xFFFF;
	
	/*
	TableName[104].SetTo("Linear B Syllabary");
	TableStart[104] = 0x10000;
	
	TableName[105].SetTo("Linear B Ideograms");
	TableStart[105] = 0x10080;
	
	TableName[106].SetTo("Aegean Numbers");
	TableStart[106] = 0x10100;
	
	TableName[107].SetTo("Old Italic");
	TableStart[107] = 0x10300;
	
	TableName[108].SetTo("Gothic");
	TableStart[108] = 0x10330;
	
	TableName[109].SetTo("Ugaritic");
	TableStart[109] = 0x10380;
	
	TableName[110].SetTo("Deseret");
	TableStart[110] = 0x10400;
	
	TableName[111].SetTo("Shavian");
	TableStart[111] = 0x10450;
	
	TableName[112].SetTo("Osmanya");
	TableStart[112] = 0x10480;
	
	TableName[113].SetTo("Cypriot Syllabary");
	TableStart[113] = 0x10800;
	
	TableName[114].SetTo("Byzantine Musical Symbols");
	TableStart[114] = 0x1D000;
	
	TableName[115].SetTo("Musical Symbols");
	TableStart[115] = 0x1D100;
	
	TableName[116].SetTo("Tai Xuan Jing Symbols");
	TableStart[116] = 0x1D300;
	
	TableName[117].SetTo("Mathematical Alphanumeric Symbols	");
	TableStart[117] = 0x1D400;
	
	TableName[118].SetTo("CJK Unified Ideographs Extension B");
	TableStart[118] = 0x20000;
	
	TableName[119].SetTo("CJK Compatibility Ideographs Supplement");
	TableStart[119] = 0x2F800;
	
	TableName[120].SetTo("Tags");
	TableStart[120] = 0xE0000;
	
	TableName[121].SetTo("Variation Selectors Supplement");
	TableStart[121] = 0xE0100;
	
	TableName[122].SetTo("Supplementary Private Use Area-A");
	TableStart[122] = 0xF0000;
	
	TableName[123].SetTo("Supplementary Private Use Area-B");
	TableStart[123] = 0x100000;
	*/
	
}

UnicodeTable::~UnicodeTable()
{
	
}

int UnicodeTable::GetTableNum(int value)
{	
	for (int i = 0; i < (TABLENUM + 1); i++)
	{
		if (TableStart[i] == value) return (i);
		
		if (TableStart[i] > value) return (i - 1);
		
	}
	
	return (-1);
}

BString UnicodeTable::GetTableNameByValue(int value)
{
	int tablenum = 0;
	
	tablenum = GetTableNum(value);
	
	return (TableName[tablenum]);
	
}

BString UnicodeTable::GetTableNameByTableNum(int value)
{
	if ((value < FIRSTTABLE) || (value > LASTTABLE))
	{
		BString  aString;
		
		aString.SetTo("Out of range");
		
		return (aString);
	}
	
	return (TableName[value]);
}

int UnicodeTable::GetFirst()
{
	return (FIRSTTABLE);
}

int UnicodeTable::GetLast()
{
	return (LASTTABLE);
}

int UnicodeTable::GetNum()
{
	return (TABLENUM);
}

bool UnicodeTable::IsInTable(int value, int table)
{
	int first;
	int last;
	
	if ((table < FIRSTTABLE) || (table > LASTTABLE)) return (false);
	
	first = TableStart[table];
	last = TableStart[table + 1];
	
	return ((value >= first) && (value <= last));
	
}
