//
// Created by 刘敬 on 18/4/8.
//

long long Fibonacci(unsigned n){

    int result[2] = {0, 1}; // 边界处理
    if(n < 2){
        return result[n];
    }

    long long fibNMinusOne = 1;
    long long fibNMinusTwo = 0;
    long long fibN = 0;
    for(unsigned int i = 2; i <= n; i++){
        fibN = fibNMinusOne + fibNMinusTwo;

        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }

    return fibN;
}