//
//  main.cpp
//  CS325-HW1
//  Date: 10-06-19
//  Created by Lifang Yan on 2019/10/3.
//  Copyright © 2019 Lifang Yan. All rights reserved.
//

#include "stoogeTime.hpp"

void timing() {
    
    
    unsigned seed;
    seed = int(time(0));
    srand(seed);
    ofstream ofs;
    ofs.open("comparison.txt");
    
    int arrayOfSize;
    cout <<"Time unit used for comparing insertion sort and merge sort:  microseconds!\n" << endl;
    
    cout << std::setw(10) <<std::left << "Size " << std::setw(10) <<std::left << "Insertion " << std::setw(10) <<std::left << "Merge " << std::setw(10) <<std::left <<"Stooge " << endl;
    int *array;
    array = new int;
    
    for(arrayOfSize = 250; arrayOfSize <= 2500; arrayOfSize += 250 ){
        //int array[arrayOfSize];
       // std::vector<int> vectorList;
        //int num;
        for(int i =0; i < arrayOfSize; i++){
            array[i] = rand()%10001;
        }
            //num = rand()%10001;
            //vectorList.push_back(num);
        
    auto start1 = std::chrono::high_resolution_clock::now();
    //insertionSort(vectorList, arrayOfSize);
    insertionSort(array, arrayOfSize);
    
    auto stop1 = std::chrono::high_resolution_clock::now();
        auto duration_insert = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);
        
        //use mergeSort file to open file and read numbers to array, then divide, conquer, and combine to an ordered list
        
        auto start2 = std::chrono::high_resolution_clock::now();
        //insertionSort(vectorList, arrayOfSize);
        mergeSort(array, 0, arrayOfSize-1);
    
        auto stop2 = std::chrono::high_resolution_clock::now();
        auto duration_merge = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);
        auto start3 = std::chrono::high_resolution_clock::now();
        stoogeSort(array, 0, arrayOfSize-1);
        auto stop3 = std::chrono::high_resolution_clock::now();
        auto duration_stooge = std::chrono::duration_cast<std::chrono::microseconds>(stop3 - start3);
        ofs << duration_insert.count() << "           ";
        ofs << duration_merge.count()  << "                 ";
        ofs << duration_stooge.count()  << endl;
        cout << std::setw(10) << std::left << arrayOfSize << std::setw(10) << std::left << duration_insert.count() << std::setw(10) << std::left << duration_merge.count() <<std::setw(10) << std::left  << duration_stooge.count() <<  endl;
    }
    
}

