//
// Created by 刘敬 on 18/4/2.
//

#include "Sort.h"


void _main(){
    std::vector<int> v = {1,3,2,5,4};
    QuickSort<int> s;
    s.show(v);
    s.sort(v);
    s.show(v);
}