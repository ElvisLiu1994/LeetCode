//
// Created by 刘敬 on 18/3/30.
//

/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
 */

#include "add.h"

vector<int> twoSumII(vector<int>& numbers, int target) {

    vector<int> res;

    int i = 0;
    int j = numbers.size()-1;
    while(i < j) {
        int tmpSum = numbers[i] + numbers[j];
        if(tmpSum == target){
            res.push_back(i+1);
            res.push_back(j+1);
            return res;
        }else if(tmpSum > target){
            j--;
        }else{
            i++;
        }
    }

    return res;
}

//void _tmain(){
//    vector<int> nums = {2,7,11,15};
//    vector<int> res = twoSumII(nums, 9);
//    for(auto i: res)
//        cout << i << ", ";
//}