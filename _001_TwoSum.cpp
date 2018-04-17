//
// Created by 刘敬 on 18/3/30.
//

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 */

#include "add.h"

vector<int> twoSum(vector<int>& nums, int target) {

    //Key is the number and value is its index in the vector.
    unordered_map<int, int> hash;
    vector<int> result;

    for(int i = 0; i < nums.size(); i++){
        int numToFind = target - nums[i];

        if(hash.find(numToFind) != hash.end()){
            result.push_back(hash[numToFind]);
            result.push_back(i);
            return result;
        }else{
            //if number was not found. Put it in the map, the val is the index.
            hash[nums[i]] = i;
        }
    }

    return result;

}

