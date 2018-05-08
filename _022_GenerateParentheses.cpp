//
// Created by 刘敬 on 18/5/4.
//

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 */

#include "add.h"

void solver(vector<string> &res, string cur, int l, int r, int n);

vector<string> generateParenthesis(int n) {
    vector<string> res;
    solver(res, "", 0, 0, n);
    return res;
}

void solver(vector<string> &res, string cur, int l, int r, int n){
    if(cur.length() == 2*n) {
        res.push_back(cur);
        return;
    }

    if(l < n)
        solver(res, cur+'(', l+1, r, n);
    if(r < l)
        solver(res, cur+')', l, r+1, n);
}

void _tmain(){
    vector<string> res = generateParenthesis(3);

    for(string s : res){
        cout << s << endl;
    }
}