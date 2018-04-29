//
// Created by 刘敬 on 18/3/28.
//

/**************************************************************************************************/

// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

/*Length为数组string的总容量*/
void ReplaceBlank(char string[], int length){
    if(string == nullptr || length <= 0) return;

    int originalLength = 0; // 数组的实际长度
    int numberOfBlank = 0;
    int i = 0;
    while(string[i] != '\0'){
        originalLength++;

        if(string[i] == ' ') numberOfBlank++;

        ++i;
    }

    int newLength = originalLength + 2 * numberOfBlank;
    if(newLength >= length) return;

    int indexOfOriginal = originalLength; //指向原字符串最后面的'\0'
    int indexOfNew = newLength; //同理指向新位置的'\0'

    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal){
        if(string[indexOfOriginal] == ' '){
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        }else{
            string[indexOfNew--] = string[indexOfOriginal];
        }

        --indexOfOriginal;
    }
}

