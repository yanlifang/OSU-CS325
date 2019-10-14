//
//  stooge_sort.cpp
//  CS325_HW1_Q3_LY
//
//  Created by Lifang Yan on 2019/10/12.
//  Copyright © 2019 Lifang Yan. All rights reserved.
//

#include <string>
#include <fstream>
#include <iostream>

#include "stooge_sort.hpp"

void stoogeSort(int *a, int l, int r){
    if(a[r] < a[l]){
        swap(&a[r], &a[l]);
    }
    
    if (r - l > 1){
        int t = (r-l+1)/3;
        stoogeSort(a, l, r-t);
        stoogeSort(a, l+t, r);
        stoogeSort(a, l, r-t);
    }
        
}

void main_stoogeSort(std::ifstream &ifs){
    std::ofstream ofs;
    std::string fileName;
    std::string line;
    std::istringstream iss;
    ofs.open("stooge.txt");
     
    //read number from file line by line
    //use istringstream iss to read number one by one from line
    //store each number to array
    while(std::getline(ifs, line)){
        int *array = nullptr;
        array = new int;
        int num, count;
        count = 0;
               
        iss.str(line);
       
        while(iss >> num){
            array[count] = num;
            count++;
        }

        stoogeSort(array, 1, count-1);
    
        //output numbers to output file
        for(int i = 0; i < count; i++)
        {
            ofs << array[i] <<" ";
        }
        ofs << std::endl;
        delete [] array;
    //start a new line for 2nd line, and clear the string variable line, so line can get new number ofs << std::endl;
        iss.clear();
    }
    ofs.close();
}
