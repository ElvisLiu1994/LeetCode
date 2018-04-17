/**
 * Say you have an array for which the ith element is the price of a given stock on day i.

 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like
 * (ie, buy one and sell one share of the stock multiple times). However,
 * you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

#include "add.h"

int maxProfit(vector<int>& prices) {

    if(prices.empty()) return 0;

    int totalProfit = 0;

    for(int i = 1; i < prices.size(); i++){
        if(prices[i] > prices[i-1]){
            totalProfit += prices[i] - prices[i-1];

        }
    }

    return totalProfit;
}

int main(){
    int a[] = {1,2,4};
    vector<int> prices(a, a + sizeof(a)/ sizeof(*a));

    cout << maxProfit(prices) << endl;
}