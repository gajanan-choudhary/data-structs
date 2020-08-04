#pragma once

#include <iostream>
#include "debugmacro.h"

/* All functions need [], <, and customized std::swap defined. */

//! \brief Bubble sort
template<typename T>
void bubblesort(T& arr, const int &start, const int &end){
    int n = end-1;
    for (int i=start; i<n; ++i){
        for (int j=start; j<n; ++j){
            if (arr[j+1] < arr[j]) std::swap(arr[j], arr[j+1]);
        }
    }
}

//! \brief Insert sort
template<typename T>
void insertsort(T& arr, const int &start, const int &end){
    for (int i=start; i<end; ++i){
        auto curr = arr[i];
        for (int j=i; j>0 && curr < arr[j-1]; --j){
            std::swap(arr[j-1], arr[j]);
        }
    }
}

//! \brief Select sort
template<typename T>
void selectsort(T& arr, const int &start, const int &end){
    for (int i=start; i<end; ++i){
        auto minindex = i;
        for (int j=i+1; j<end; ++j){
            minindex = (arr[j] < arr[minindex] ? j : minindex);
        }
        std::swap(arr[i], arr[minindex]);
    }
}

//! \brief Quick sort
template<typename T>
void quicksort(T& arr, const int &start, const int &end){
    if (end-start < 2){
        insertsort(arr, start, end);
    }
    else{
        int pivotindex = end-1; // Right pivot
        auto &pivot = arr[pivotindex];
        int i=start, j=pivotindex-1;
        while (i<j){
            while (arr[i]<pivot) ++i;
            while (arr[j]>pivot) --j;
            if (i<j) std::swap(arr[i], arr[j]);
        }
        std::swap(arr[i],arr[pivotindex]);
        quicksort(arr, start, i);
        quicksort(arr, i+1, end);
    }
}
