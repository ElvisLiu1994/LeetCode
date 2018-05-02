//
// Created by 刘敬 on 18/3/28.
//

#include "../add.h"

/**************************************************************************************************/

// 找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        duplication: (输出) 数组中的一个重复的数字
// 返回值:
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，或者数组中没有重复的数字
bool duplicate(int numbers[], int length, int* duplication){
    if(numbers == nullptr || length <= 0) return false;

    for(int i = 0; i < length; ++i){
        if(numbers[i] < 0 || numbers[i] >= length) return false;
    }

    for(int i = 0; i < length; i++){
        while(numbers[i] != i){
            if(numbers[i] == numbers[numbers[i]]){
                *duplication = numbers[i];
                return true;
            }
            int tmp = numbers[i];
            numbers[i] = numbers[tmp];
            numbers[tmp] = tmp;
        }
    }

    return false;
}

/**************************************************************************************************/

// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。

bool Find(int* matrix, int rows, int cols, int number){
    bool found = false;

    if(matrix != nullptr && rows > 0 && cols > 0){
        int i = 0, j = cols - 1; // 从右上角节点开始分析（也可以从左下角开始分析）
        while(i < rows && j > 0){
            int rt = matrix[i * rows + j];
            if(rt == number){
                found = true;
                break;
            }else if(rt > number)
                j--;
            else
                i++;
        }
    }

    return found;
}

/**************************************************************************************************/

// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。

void ReorderOddEven(vector<int> data){
    if(data.size() <= 1)
        return;

    int p1 = 0; // 指向第一个元素
    int p2 = data.size()-1; // 指向最后一个元素

    while(p1 < p2){

        // 向后移动p1，直到它指向偶数
        while(p1 < p2 && data[p1] & 0x1 != 0)
            p1++;

        // 向后移动p2，直到它指向奇数
        while(p1 < p2 && data[p2] & 0x1 == 0)
            p2--;

        if(p1 < p2){
            int tmp = data[p1];
            data[p1] = data[p2];
            data[p2] = tmp;
        }
    }
}



/**************************************************************************************************/