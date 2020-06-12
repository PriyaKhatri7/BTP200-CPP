/*
Name: Priya Khatri Email: pkhatri4@myseneca.ca ID: 110149176

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include <iostream>
#include <iomanip> //setw
#include "Word.h"
#include "Utils.h"
using namespace std;

namespace sdds
{
    int StrCmp(const char* s1, const char* s2) 
    {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }

    void StrCpy(char* des, const char* src) 
    {
        int i;
        for (i = 0; src[i]; i++) des[i] = src[i];
        des[i] = 0;
    }

    int StrLen(const char* str) 
    {
        int len;
        for (len = 0; str[len]; len++);
        return len;
    }

    void title(const char* value, int len) 
    { // uses iomanip header file
        cout << value << endl;
        cout << setw(len) << left << "Word";
        cout << "No of  occurrence." << endl << "------------------------------------------------" << endl;
    }

    void endList() 
    {
        cout << "------------------------------------------------" << endl;
    }

    void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord) 
    {
        cout << "Total number of words used: " << totNoWrds << endl;
        cout << "Total number of words overall: " << totalOverAll << endl;
        cout << "Longest word used had " << longestWord << " characters." << endl;
    }

    void wordStats() 
    {
        Word words[MAX_NO_OF_WORDS] = { {"",0} };
        char word[MAX_WORD_LEN];
        char lowerCaseWord[MAX_WORD_LEN];
        int NoOfWords = 0;
        int maxLen = 0;
        int foundIndex = 0;
        int wordCount = 0;
        while (cin >> word) {
            trim(word);
            toLowerCaseAndCopy(lowerCaseWord, word);
            if (lowerCaseWord[0] != 0) {
                wordCount++;
                if (maxLen < StrLen(lowerCaseWord)) {
                    maxLen = StrLen(lowerCaseWord);
                }
                if (NoOfWords == 0) {
                    addWord(words, &NoOfWords, lowerCaseWord);
                }
                else {
                    foundIndex = searchWords(words, NoOfWords, lowerCaseWord);
                    if (foundIndex < 0) { // word not found in list; so word is new and never read before
                        foundIndex = NoOfWords;
                        addWord(words, &NoOfWords, lowerCaseWord);
                    }
                    else {
                        words[foundIndex].count++;
                    }
                }
            }
        }
        cout << "---------------------------------------------------" << endl <<
            "Read " << wordCount << " words!" << endl <<
            "---------------------------------------------------" << endl;
        sort(words, NoOfWords, 1);
        listWords(words, NoOfWords, "List of words Sorted by occurance");
        sort(words, NoOfWords, 0);
        listWords(words, NoOfWords, "List of words Sorted alphabetically");
        totalWordsStat(NoOfWords, totalCount(words, NoOfWords), maxLen);
    }

    void programTitle() 
    {
        cout <<
            "This program reads a text file from the standard input and analyzes and reports" << endl <<
            "the number of words and their occurrences in the text file." << endl;
    }
}