/**
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.
 */

#include "add.h"

/*
 * 解法一：两次扫描，第一次正向扫描，计算前i天进行一次交易能获得的最大收益
 * 第二次逆向扫描，计算后n-i天进行一次交易能获得的最大收益，选择一个i，使得前i天的最大收益与后n-i天的最大收益之和最大
 * 时间开销O(n),空间开销O(n)
 */
int maxProfit(vector<int>& prices) {

    if(prices.size() <= 1) return 0;

    int* A = new int[prices.size()](); // 不能用int A[]
    int minPrice = prices[0];
    int maxProf = 0;
    for(int i = 1; i < prices.size(); i++){
        maxProf = max(maxProf, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
        A[i] = maxProf;
    }

    int* B = new int[prices.size()]();
    int maxPrice = prices[prices.size() - 1];
    maxProf = 0;
    for(int i = prices.size() - 2; i >= 0; i--){
        maxProf = max(maxProf, maxPrice - prices[i]);
        maxPrice = max(maxPrice, prices[i]);
        B[i] = maxProf;
    }

    maxProf = 0;
    for(int i = 0; i < prices.size(); i++){
        maxProf = max(maxProf, A[i]+B[i]);
    }
    return maxProf;
}

/*
 * 算法二：该算法的核心是直接计算当前手上最多的钱，卖出则+prices[i]，买入则-prices[i]
 * 它定义了4个状态：

Buy1[i]表示前i天做第一笔交易买入股票后剩下的最多的钱；

Sell1[i]表示前i天做第一笔交易卖出股票后剩下的最多的钱；

Buy2[i]表示前i天做第二笔交易买入股票后剩下的最多的钱；

Sell2[i]表示前i天做第二笔交易卖出股票后剩下的最多的钱；

那么    Sell2[i]=max{Sell2[i-1],Buy2[i-1]+prices[i]}

       Buy2[i]=max{Buy2[i-1],Sell[i-1]-prices[i]}

       Sell1[i]=max{Sell[i-1],Buy1[i-1]+prices[i]}

       Buy1[i]=max{Buy[i-1],-prices[i]}

可以发现上面四个状态都是只与前一个状态有关，所以可以不使用数组而是使用变量来存储即可。
 四个语句也可以打乱顺序
 */
int maxProfit2(vector<int>& prices){
    int buy1=INT_MIN;
    int buy2=INT_MIN;
    int sell1=0;
    int sell2=0;
    for(int i=0;i<prices.size();i++)
    {
        sell2=max(sell2,buy2+prices[i]);
        buy2=max(buy2,sell1-prices[i]);
        sell1=max(sell1,buy1+prices[i]);
        buy1=max(buy1,-prices[i]);
    }
    return sell2;
}

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << maxProfit2(prices) << endl;

}