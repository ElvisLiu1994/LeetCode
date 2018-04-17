//
// Created by 刘敬 on 18/4/2.
//

#ifndef LEETCODE_SORT_H
#define LEETCODE_SORT_H

#include <vector>
#include <iostream>

template <class T>
class Sort{
public:
    virtual void sort(std::vector<T> &a) = 0;

    bool less(T v1, T v2){
        return v1 < v2;
    }

    void exch(std::vector<T> &a, int i, int j){
        T tmp = a[i]; a[i] = a[j]; a[j] = tmp;
    }

    void show(std::vector<T> &a){
        for(int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;
    }

    bool isSorted(std::vector<T> &a){
        for(int i = 1; i < a.size(); i++)
            if(less(a[i],a[i-1]))
                return false;
        return true;
    }
};

template<class T>
class Selection : public Sort<T>{
public:
    void sort(std::vector<T> &a){ // 平均比较N^2/2次，交换N次
        int N = a.size();
        for(int i = 0; i < N; i++){
            int min = i;
            for(int j = i+1; j < N; j++){
                if(this->less(a[j], a[i])) min = j;
            }
            this->exch(a, min, i);
        }
    }
};

template<class T>
class Insertion : public Sort<T>{
public:
    void sort(std::vector<T> &a){ // 平均比较N^2/2次，交换N^2/2次，因为每次都要移动一部分元素
        int N = a.size();
        for(int i = 1; i < N; i++){
            for(int j = i; j > 0 && this->less(a[j], a[j-1]); j--){
                this->exch(a, j, j-1);
            }
        }
    }
};

template<class T>
class Shell : public Sort<T>{
public:
    void sort(std::vector<T> &a){
        int N = a.size();
        int h = 1;
        while(h < N/3) h = 3*h+1;

        while(h >= 1){
            // 将数组变为h有序,h开始的所有数都要进行插入排序，插入不同的子序列中，使数组h有序
            for(int i = h; h < N; i++){
                for(int j = i; j >= h && this->less(a[j], a[j-h]); j -= h)
                    this->exch(a, j, j-h);
            }

            h = h/3;
        }
    }
};

template<class T>
class Merge : public Sort<T>{
public:
    void sort(std::vector<T> &a){
        aux.resize(a.size());
        sort(a, 0, a.size()-1);
    }

private:

    std::vector<T> aux;

    void sort(std::vector<T>&a, int lo, int hi){
        if(hi <= lo) return;
        int mid = lo + (hi - lo)/2;
        sort(a, lo, mid);
        sort(a, mid+1, hi);
        merge(a, lo, mid, hi);
    }

    void merge(std::vector<T> &a, int lo, int mid, int hi){
        int i = lo, j = mid+1;

        for(int k = lo; k <= hi; k++)
            aux[k] = a[k];

        for(int k = lo; k <= hi; k++){
            if(i > mid)     a[k] = aux[j++];
            else if(j > hi) a[k] = aux[i++];
            else if(this->less(aux[j], aux[i])) a[k] = aux[j++];
            else a[k] = aux[i++];
        }
    }
};

template<class T>
class QuickSort : Sort<T>{

};


#endif //LEETCODE_SORT_H
