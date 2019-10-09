//
//  main.cpp
//  CS325-HW1
//  Date: 10-06-19
//  Created by Lifang Yan on 2019/10/3.
//  Copyright © 2019 Lifang Yan. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <time.h>
#include "timing.hpp"
#include "insertionSort.hpp"
#include "mergeSort.hpp"

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::ofstream;


void timing() {
    
    
    unsigned seed;
    seed = int(time(0));
    srand(seed);
    ofstream ofs;
    ofs.open("comparison.txt");
    
    cout << "I will generate array using random number from 0 to 10000 for array size 5000, 10000, 15000, 20000 ... 50000!";
   
    int arrayOfSize;
    cout <<"Time unit used for comparing insertion sort and merge sort:  microseconds!\n" << endl;
    cout << "Insertion Sort    " << "Meger Sort " << endl;
    for(arrayOfSize = 5000; arrayOfSize <= 50000; arrayOfSize += 5000 ){
        //int array[arrayOfSize];
        std::vector<int> vectorList;
        int num;
        for(int i =0; i < arrayOfSize; i++){
            //array[i] = rand()%10001;
            num = rand()%10001;
            vectorList.push_back(num);
        }
        
        auto start1 = std::chrono::high_resolution_clock::now();
        insertionSort(vectorList, arrayOfSize);
        auto stop1 = std::chrono::high_resolution_clock::now();
        auto duration_insert = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);
        
        //use mergeSort file to open file and read numbers to array, then divide, conquer, and combine to an ordered list
        
        auto start2 = std::chrono::high_resolution_clock::now();
        insertionSort(vectorList, arrayOfSize);
        //mergeSort(array, 0, arrayOfSize-1);
        std::vector<int> result = mergeSort(vectorList);
        auto stop2 = std::chrono::high_resolution_clock::now();
        auto duration_merge = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);
        ofs << duration_insert.count() << "            ";
        ofs << duration_merge.count()  << endl;
        cout << duration_insert.count() << "        " << duration_merge.count() << endl;
    }
    
}

