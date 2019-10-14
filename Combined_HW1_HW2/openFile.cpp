//
//  openFile.cpp
//  exercise
//
//  Created by Lifang Yan on 2019/10/6.
//  Copyright © 2019 Lifang Yan. All rights reserved.
//


#include "openFile.hpp"

void openfile(){
    ifstream ifs;
    ifs.open("data.txt");
    string fileName;
    
    //check if file exist, if not, ask user to enter a filename 
    while(!ifs){
              cout << "Please enter your data file name: \n" ;
              cin >> fileName;
              ifs.open(fileName);
    }
    
    main_insertionSort(ifs);
    ifs.close();
    
    ifs.open("data.txt");
    main_mergeSort(ifs);
    ifs.close();
    
    ifs.open("data.txt");
    main_stoogeSort(ifs);
    ifs.close();
}

