//
//  mergeSort.cpp
//  exercise
//
//  Created by Lifang Yan on 2019/10/6.
//  Copyright © 2019 Lifang Yan. All rights reserved.
//



#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "mergeSort.hpp"


using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;


//reference: https://www.geeksforgeeks.org/merge-sort/

//merge function is used to merge two subarrays
//n1, n2 are the size of two subarrays, l, r, are the index of left array and right array, k is the index of total new array
void merge(int* a, int l, int m, int r){
    
    int n1= m - l + 1;
    int n2 = r-m;
    
    int left[n1], right[n2];
    
    for(int i = 0; i < n1; i++){
        left[i] = a[l+i];
    }
    for(int j = 0; j < n2; j++){
        right[j] = a[m+1+j];
    }
    
    
    int i = 0; int j = 0; int k = l;
    
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            a[k] = left[i];
            i++;
        }
        else{
            a[k] = right[j];
            j++;
        }
        k++;
    }
        
    while(i < n1){
        a[k] = left[i];
        i++;
        k++;
    }
    
    while(j < n2){
        a[k] = right[j];
        j++;
        k++;
    }
}
            
    

//l is left index, r is right index
void mergeSort(int *a, int l, int r){
    
    if(l < r){
        //find the mid potin
        int m = l + (r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        
        merge(a, l, m, r);
    }
}

//pass the file from open file function
//read the file line by line, then read numbers one by one using istringstream
//place each number to an array, then sort the array and output the array to output file
void main_mergeSort(std::ifstream &ifs){
    std::ofstream ofs;
    std::string fileName;
    std::string line;
    std::istringstream iss;

    ofs.open("merge.txt");
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

        mergeSort(array, 1, count-1);
            //output numbers to output file
        for(int i = 0; i < count; i++)
        {
            ofs << array[i] <<" ";
        }
            
        //start a new line for 2nd line, and clear the string variableline, so line can get new numbers from 2nd line
        ofs << std::endl;
        delete [] array;
        iss.clear();
    }
    ofs.close();
}
