//
//  openFile.cpp
//  exercise
//
//  Created by Lifang Yan on 2019/10/6.
//  Copyright © 2019 Lifang Yan. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "insertionSort.hpp"
#include "openFile.hpp"

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

void openfile(){
    ifstream ifs;
    ofstream ofs;
    ifs.open("data.txt");
      
    string fileName;
    string line;
    std::istringstream iss;

    ofs.open("insert.txt");

    //check if output file exists, if not, ask user to enter a output file name or create a new one by enter a new name
    if(ofs){
        cout << "Output file exists!\n";
    }
    else{
        cout << "What is the name of output file: " << endl;
        cin >> fileName;
        ofs.open(fileName);
    }
               
    //read number from file line by line
    //use istringstream iss to read number one by one from line
    if(ifs){
        std::cout<<"File open successfully!"<<std::endl;

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
            //sort numbers line by line using insertionSort
            insertionSort(array, count);
            //output numbers to output file
            for(int i = 0; i < count; i++)
             {
                 ofs << array[i] <<" ";
             }
            //start a new line for 2nd line, and clear the string variable line, so line can get new numbers from 2nd line
            ofs << endl;
            iss.clear();
            //free allocated memory for array, so array can read new numbers
            delete [] array;
        }
    }
    else{
        std::cout << "File open failed!\n";
    }
    
    ifs.close();
    ofs.close();
}

