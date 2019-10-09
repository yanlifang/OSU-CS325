//
//  insertionSort.cpp
//  exercise
//
//  Created by Lifang Yan on 2019/10/5.
//  Copyright © 2019 Lifang Yan. All rights reserved.
//

#include "insertionSort.hpp"

void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//compare 2nd number with 1st number, if 2nd number smaller than 1st number, then switch
void insertionSort(int* number, int n){
        for(int i = 1; i < n; i++){
            int j = i;
            while(j > 0 && number[j] < number[j-1]){
                swap(&number[j], &number[j-1]);
                j = j -1;
            }
    }
}

void insertionSort(std::vector<int> number, int n){
        for(int i = 1; i < n; i++){
            int j = i;
            while(j > 0 && number[j] < number[j-1]){
                swap(&number[j], &number[j-1]);
                j = j -1;
            }
    }
}
