//
//  insertionSort.hpp
//  exercise
//
//  Created by Lifang Yan on 2019/10/5.
//  Copyright © 2019 Lifang Yan. All rights reserved.
//

#ifndef insertionSort_hpp
#define insertionSort_hpp

#include <stdio.h>
#include <vector>

void swap(int* a, int* b);

void insertionSort(int* a, int number);

//void insertionSort(int* number, int n);
void insertionSort(std::vector<int> number, int n);

#endif /* insertionSort_hpp */
