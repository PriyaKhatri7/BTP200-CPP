/*
Name: Priya Khatri Email: pkhatri4@myseneca.ca ID: 110149176

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_WORD_H
#define SDDS_WORD_H

//holds functions relating to word processing and analysis

namespace sdds
{
	int StrCmp(const char* s1, const char* s2);
	void StrCpy(char* des, const char* src);
	int StrLen(const char* str);
	void title(const char* value, int len);
	void endList();
	void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
	//int findMaxLen(const Word words[], int noOfWords);
	//void listWords(const Word words[], int noOfWords, const char* theTitle);
	void wordStats();
	void programTitle();


}

#endif // !SDDS_WORD_H

