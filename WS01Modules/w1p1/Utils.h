/*
Name: Priya Khatri Email: pkhatri4@myseneca.ca ID: 110149176

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

//holds general helper functions with no direct relation to word analysis
const int MAX_WORD_LEN = 21;
const int MAX_NO_OF_WORDS = 500;
const int SORT_BY_OCCURANCE = 1;
const int SORT_ALPHABETICALLY = 0;

struct Word {
    char letters[MAX_WORD_LEN];
    int count;
};

namespace sdds
{
    char ToLower(char ch);
    bool isAlpha(char ch);
    void trim(char word[]);
    void toLowerCaseAndCopy(char des[], const char source[]);
    int searchWords(const Word words[], int num, const char word[]);
    void addWord(Word words[], int* index, const char newWord[]);
    void print(const Word* w, bool gotoNextLine, int len);
    int findMaxLen(const Word words[], int noOfWords);
    void listWords(const Word words[], int noOfWords, const char* theTitle);
    void swap(Word* p1, Word* p2);
    void sort(Word words[], int cnt, int sortType);
    int totalCount(const Word* words, int num);
}

#endif // !SDDS_UTILS_H

