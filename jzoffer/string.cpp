//
// Created by 刘敬 on 18/3/28.
//

bool scanUnsignedInteger(const char** str);
bool scanInteger(const char** str);

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

/**************************************************************************************************/

// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
// 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是

// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，其中A和C都是
// 整数（可以有正负号，也可以没有），而B是一个无符号整数
bool isNumeric(const char* str){
    if(str == nullptr)
        return false;

    bool numeric = scanInteger(&str); // 因为扫描的过程中改变了str的指向位置，所以需要使用指针的指针

    // 如果出现'.'，则接下来是数字的小数部分
    if(*str == '.'){
        str++;

        // 下面一行代码用||的原因：
        // 1. 小数可以没有整数部分，例如.123等于0.123；
        // 2. 小数点后面可以没有数字，例如233.等于233.0；
        // 3. 当然小数点前面和后面可以有数字，例如233.666
        numeric = scanUnsignedInteger(&str) || numeric;
    }

    if(*str == 'e' || *str == 'E'){
        str++;

        // 下面一行代码用&&的原因：
        // 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
        // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4
        numeric = numeric && scanInteger(&str);
    }

    return numeric && *str == '\0';
}

bool scanUnsignedInteger(const char** str)
{
    const char* before = *str;
    while(**str != '\0' && **str >= '0' && **str <= '9')
        ++(*str);

    // 当str中存在若干0-9的数字时，返回true
    return *str > before;
}

// 整数的格式可以用[+|-]B表示, 其中B为无符号整数
bool scanInteger(const char** str)
{
    if(**str == '+' || **str == '-')
        ++(*str);
    return scanUnsignedInteger(str);
}

/**************************************************************************************************/

// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
// 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
// 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。

bool match(const char* str, const char* pattern)
{
    if(str == nullptr || pattern == nullptr)
        return false;

    return matchCore(str, pattern);
}

bool matchCore(const char* str, const char* pattern){

    if(*str == '\0' && *pattern == '\0')
        return true;

    if(*str != '\0' && *pattern == '\0')
        return false;

    if(*(pattern + 1) == '*'){
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            return matchCore(str+1, pattern+2) || matchCore(str+1, pattern) || matchCore(str, pattern+2);
        else
            return matchCore(str, pattern+2);
    }

    if(*str == *pattern || (*pattern == '.' && *str != '\0'))
        return matchCore(str+1, pattern+1);

    return false;
}

/**************************************************************************************************/