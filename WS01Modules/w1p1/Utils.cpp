/*
Name: Priya Khatri Email: pkhatri4@myseneca.ca ID: 110149176

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include <iostream>
#include <iomanip> //setw
#include <cstring>
#include "Utils.h"
#include "Word.h"

using namespace std;

namespace sdds
{
    char ToLower(char ch) {
        if (ch >= 'A' && ch <= 'Z') ch += ('a' - 'A');
        return ch;
    }

    bool isAlpha(char ch)
    {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    void trim(char word[])
    {
        int i;
        while (word[0] && !isAlpha(word[0])) {
            StrCpy(word, word + 1);
        }
        i = StrLen(word);
        while (i && !isAlpha(word[i - 1])) {
            word[i-- - 1] = 0;
        }
    }

    void toLowerCaseAndCopy(char des[], const char source[]) {
        int i = 0, j = 0;
        for (; source[i] != 0; i++) {
            des[j++] = ToLower(source[i]);
        }
        des[j] = 0;
    }

    int searchWords(const Word words[], int num, const char word[]) {
        int i;
        int foundIndex = -1;  // will be set to found index; if not found sould be less than 0
        for (i = 0; foundIndex == -1 && i < num; i++) { // while not found and i is less than number of words
            if (StrCmp(words[i].letters, word) == 0) { // if word is already read and found in the list of previous words
                foundIndex = i;   // set the index to be returned.
            }
        }
        return foundIndex;
    }

    void addWord(Word words[], int* index, const char newWord[]) {
        StrCpy(words[*index].letters, newWord);
        words[*index].count++;
        (*index)++;
    }

    void print(const Word* w, bool gotoNextLine, int len) { // uses iomanip header file
        cout << setw(len) << left << w->letters;
        cout << setw(3) << right << w->count;
        if (gotoNextLine) cout << endl;
    }

    int findMaxLen(const Word words[], int noOfWords) {
        int longest = 0;
        int i;
        for (i = 0; i < noOfWords; i++) {
            if (longest < StrLen(words[i].letters))
                longest = StrLen(words[i].letters);
        }
        return longest;
    }

    void listWords(const Word words[], int noOfWords, const char* theTitle) {
        int i;
        int maxLen = findMaxLen(words, noOfWords);
        title(theTitle, maxLen);
        for (i = 0; i < noOfWords; i++) {
            print(&words[i], true, maxLen);
        }
        endList();
    }

    void swap(Word* p1, Word* p2) {
        Word w;
        w = *p1;
        *p1 = *p2;
        *p2 = w;
    }

    void sort(Word words[], int cnt, int sortType) {
        int i, j;
        for (i = 0; i < cnt - 1; i++) {
            for (j = 0; j < cnt - i - 1; j++) {
                if (sortType == SORT_BY_OCCURANCE) {
                    if (words[j].count < words[j + 1].count) {
                        swap(&words[j], &words[j + 1]);
                    }
                }
                else if (sortType == SORT_ALPHABETICALLY) {
                    if (StrCmp(words[j].letters, words[j + 1].letters) > 0) {
                        swap(&words[j], &words[j + 1]);
                    }
                }
                else {

                }
            }
        }
    }

    int totalCount(const Word* words, int num) {
        int total = 0;
        do {
            total += words[--num].count;
        } while (num);
        return total;
    }

}