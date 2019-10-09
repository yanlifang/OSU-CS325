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

std::vector<int> merge(std::vector<int> l, std::vector<int> r);
std::vector<int> mergeSort(std::vector<int> a);

void openFileForMegerSort();

#endif /* mergeSort_hpp */
