/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 148 ms, faster than 100.00% of C++ online submissions for Longest Palindrome by Concatenating Two Letter Words.
Memory Usage: 171.7 MB, less than 12.69% of C++ online submissions for Longest Palindrome by Concatenating Two Letter Words.
*/

#include <vector>       // std::vector
#include <iostream>     // std::iostream
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        const int n = 26*26;
        int count[n] = {0};
        int reverse[n];
        for (int i=0;i<26;++i){
            for (int j=0;j<26;++j){
                reverse[i*26 + j] = j*26 + i;
            }
        }
        int words_size = words.size();
        vector<int> hashed_words(words_size);
        for (int i=0;i<words_size;++i){
            int hash = (words[i].at(0)-'a') * 26 + (words[i].at(1)-'a');
            count[hash]++;
            hashed_words[i] = hash;
        }
        int length = 0;
        bool center_reserved = false;
        for (int i=0;i<26;++i){
            for (int j=i;j<26;++j){
                int hashed_word = i*26 + j;
                if (count[hashed_word] == 0){
                    continue;
                } else if (hashed_word%27 > 0 && count[reverse[hashed_word]]){
                    int t = min(count[hashed_word], count[reverse[hashed_word]]);
                    length += t*4;
                } else if (hashed_word%27 == 0){
                    int t = count[hashed_word]/2;
                    length += t*4;
                    if (count[hashed_word]%2 && !center_reserved){
                        center_reserved = true;
                        length +=2;
                    }
                }
            }
        }
        return length;
    }
};
// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);