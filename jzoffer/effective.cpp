//
// Created by 刘敬 on 18/3/16.
//

#include "../add.h"
/**************************************************************************************************/

int GetSize(int data[]){
    return sizeof(data); // 当数组作为参数进行传递时，数组就自动退化为同类型的指针，因此尽管data被声明为数组，但它会退化为指针。
}

/**************************************************************************************************/

int _tmain(int argc, char* argv[]){

    /*********************************************/

    int data1[] = {1,2,3,4,5};
    int size1 = sizeof(data1);

    int* data2 = data1;
    int size2 = sizeof(data2);

    int size3 = GetSize(data1);

    printf("%d %d %d\n", size1, size2, size3);

    /*********************************************/

    char str1[] = "hello world";
    char str2[] = "hello world";

    char *str3 = "hello world";
    char *str4 = "hello world";

    cout << (str1==str2) << endl; // 数组分配不同的空间，然后把同一个字符串拷贝进去
    cout << (str3==str4) << endl; // str3与str4是指针，他们指向同一个字符串空间

    /*********************************************/


}


