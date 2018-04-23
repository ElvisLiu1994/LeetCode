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
class Merge : public Sort<T>{ // NlgN
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
class QuickSort : public Sort<T>{ // NlgN
public:
    void sort(std::vector<T>& a){
        sort(a, 0, a.size()-1);
    }

private:
    void sort(std::vector<T>& a, int lo, int hi){
        if(hi <= lo) return;
        int j = partition(a, lo, hi);
        sort(a, lo, j-1);
        sort(a, j+1, hi);
    }

    int partition(std::vector<T>& a, int lo, int hi){
        int i = lo, j = hi+1;
        T v = a[lo];

        while(true){
            while(this->less(a[++i], v)) if(i == hi) break;
            while(this->less(v, a[--j])) if(j == lo) break;
            if(i >= j) break;
            this->exch(a, i, j);
        }

        this->exch(a, lo, j);
        return j;
    }
};

template <class T>
class HeapSort : public Sort<T>{ // 升序使用大顶堆（因为每次可以将最大的数与最后一个叶子结点交换，然后堆调整，相当于最大的放在最后） 降序小顶堆
public:
    void sort(std::vector<T>& a){ // 如果以1开始的话，2k和2k+1是子结点，如果以0开始的话，2k+1和2k+2是子结点
        int N = a.size();
        for(int k = N/2 - 1; k >= 0; k--) // 从最后一个非叶子结点开始，从右往左进行调整
            sink(a, k, N);
        while(N > 1){
            this->exch(a, 0, --N);
            sink(a, 0, N);
        }
    }

private:
    void swim(std::vector<T>& a, int k){
        while(k > 0 && this->less(a[k-1/2], a[k])){
            this->exch(a, (k-1)/2, k);
            k = (k-1)/2;
        }
    }

    void sink(std::vector<T>& a, int k, int N){ //这里需要N这个参数，表示只对前N个进行调整，a后面的都已经排好序了
        while(2*k+1 < N){
            int j = 2*k+1;
            if(j+1 < N && this->less(a[j], a[j+1])) j++;
            if(!this->less(a[k],a[j])) break;
            this->exch(a, k, j);
            k = j;
        }
    }
};


#endif //LEETCODE_SORT_H
