//
// Created by liujing on 18-4-19.
//

/*
 *
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
 */

#include "add.h"

int lo, maxLen;

void extendPalindrome(string s, int i, int j){

    while(i >= 0 && j < s.length() && s[i--] == s[j++]) ;

    if(maxLen < j - i - 1){
        lo = i+1;
        maxLen = j - i - 1;
    }

}

string longestPalindrome(string s) {
    if(s.length() <= 1) return s;

    for(int i = 0; i < s.length(); i++){
        extendPalindrome(s, i, i);
        extendPalindrome(s, i, i+1);
    }

    return s.substr(lo, lo+maxLen);
}

void _tmain(){
    string s = "abba";
    cout << longestPalindrome(s) << endl;
}
