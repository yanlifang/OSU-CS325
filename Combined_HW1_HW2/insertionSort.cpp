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
        for(int i = 2; i < n; i++){
            int j = i;
            while(j > 1 && number[j] < number[j-1]){
                swap(&number[j], &number[j-1]);
                j = j -1;
            }
    }
}

/**************************************************************************
 **  Open output file, read lines from input file
 **  then sort the number
 **  output to a new file
 *****************************************************************************/
void main_insertionSort(std::ifstream &ifs){
    
    std::ofstream ofs;
    std::string fileName;
    std::string line;
    std::istringstream iss;

    ofs.open("insert.txt");
     
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
  
        insertionSort(array, count);
        //output numbers to output file
        for(int i = 0; i < count; i++)
        {
            ofs << array[i] <<" ";
        }
        
            //start a new line for 2nd line, and clear the string variable line, so line can get new numbers from 2nd line
        ofs << std::endl;
        delete [] array;
        iss.clear();
    }
    ofs.close();
}
