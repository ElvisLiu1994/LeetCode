/**
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */

#include "add.h"

int maxSubArray(vector<int>& nums){
    int ans = nums[0],sum=0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        ans = max(sum, ans);
        sum = max(sum, 0);
    }
    return ans;
}

int main(){
    int n[] = {1,2,3,4};
    vector<int> nums(n, n+4);
    cout << maxSubArray(nums) << endl;
}