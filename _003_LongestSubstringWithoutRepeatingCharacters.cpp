//
// Created by liujing on 18-4-18.
//

/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3.
 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include "add.h"

int lengthOfLongestSubstring(string s) {
    vector<int> dict(256, -1);     // 哈希表不只是能存储该变量是否出现过，还能存储出现的位置。
    int maxLen = 0, start = 0;    // start表示当前不重复串的起始位置
    for (int i = 0; i != s.length(); i++) {
        if (dict[s[i]] >= start)
            start = dict[s[i]] + 1; // 直接跳到重复位置
        dict[s[i]] = i;
        maxLen = max(maxLen, i - start + 1);
    }
    return maxLen;
}

int lols(string s){
    unordered_map<char, int> hash;
    int maxLen = 0, start = 0;
    for(int i = 0; i < s.length(); i++){
        hash[s[i]]++;
        while(hash[s[i]] > 1){
            hash[s[start]]--;
            start++;
        }
        maxLen = max(maxLen, i-start+1);
    }
    return maxLen;
}

void _tmain(){
    string s("pwwkew");
    cout << lengthOfLongestSubstring(s) << endl;
}