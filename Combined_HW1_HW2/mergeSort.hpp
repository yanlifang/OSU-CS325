//
//  mergeSort.hpp
//  exercise
//
//  Created by Lifang Yan on 2019/10/6.
//  Copyright © 2019 Lifang Yan. All rights reserved.
//

#ifndef mergeSort_hpp
#define mergeSort_hpp

#include <stdio.h>
#include <vector>
#include "openFile.hpp"

//std::vector<int> merge(std::vector<int> l, std::vector<int> r);
//std::vector<int> mergeSort(std::vector<int> a);
void mergeSort(int*a, int l, int r);
void merge(int*a, int l, int m, int r);

void main_mergeSort(std::ifstream &ifs);

#endif /* mergeSort_hpp */
