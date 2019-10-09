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
//n1, n2 are the size of two subarrays, i, j, are the index of left array and right array, k is the index of total new array
std::vector<int> merge(std::vector<int> l, std::vector<int> r){
    std::vector<int> result;

    while((int)l.size() > 0 && (int)r.size() > 0){
        if((int)l.front() <= (int)r.front()){
            result.push_back((int)l.front());
            l.erase(l.begin());
        }
        else
        {
            result.push_back((int)r.front());
            r.erase(r.begin());
        }
    }
        
    while((int)l.size() > 0){
        for(int i = 0; i < (int)l.size(); i++){
            result.push_back(l[i]);
            l.erase(l.begin());
        }
    }
    
    while((int)r.size() > 0){
        for(int i =0; i < r.size(); i++){
            result.push_back(r[i]);
            r.erase(r.begin());
        }
    }
    
    return result;
}
    
//divide array part
//divide the array into two subarrays recursively until each array has one number
//after divide the array then call merge function to merge back
//define three new vectors, one for left half, one for right half, and result for store sorted elements
std::vector<int> mergeSort(std::vector<int> a){
    
    if(a.size() <= 1) return a;
    
    std::vector<int> left, right, result;
    int m = ((int)a.size()+1)/2;
    
    for(int i = 0; i < m; i++){
             left.push_back(a[i]);
    }
    for(int i = m; i < (int)a.size(); i++){
        right.push_back(a[i]);
    }

    left = mergeSort(left);
    right = mergeSort(right);
    result = merge(left, right);
    
    return result;
}


void openFileForMegerSort(){
    ifstream ifs;
    ofstream ofs;
    ifs.open("data.txt");
   
    string fileName;
    string line;
    std::istringstream iss;

    ofs.open("merge.txt");
    if(ofs){
        cout << "Output file exists!\n";
    }
    else{
        cout << "What is the name of output file: " << endl;
        cin >> fileName;
        ofs.open(fileName);
    }
    //check if output file exists, if not, ask user to enter a output file name or create a new one by enter a new name
               
    //read number from file line by line
    //use istringstream iss to read number one by one from line
    if(ifs){
        std::cout<<"File open successfully!"<<std::endl;
        while(std::getline(ifs, line)){
            std::vector<int> numberVector;
            /*int *array = nullptr;
            array = new int;
            int num, count;
            count = 0;*/
            
            iss.str(line);
            int num;
        
            while(iss >> num){
                //array[count] = num;
                numberVector.push_back(num);
            }
                       
            //sort numbers line by line using insertionSort
            std::vector<int> results = mergeSort(numberVector);
            //output numbers to output file
            
            for(std::vector<int>::iterator it = results.begin(); it != results.end(); it++){
                ofs << *it <<" ";
            }
            
            //start a new line for 2nd line, and clear the string variable line, so line can get new numbers from 2nd line
            ofs << endl;
            iss.clear();
            //free allocated memory for array, so array can read new numbers
        }
    }
    else{
        std::cout << "File open failed!\n";
    }
    
    ifs.close();
    ofs.close();
}

   
    
