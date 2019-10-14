//
//  main.cpp
//  CS325_HW2_Q4_LY
//
//  Created by Lifang Yan on 2019/10/12.
//  Copyright © 2019 Lifang Yan. All rights reserved.
//

//
//  main.cpp
//  CS325-HW1
//  Date: 10-12-19
//  Created by Lifang Yan on 2019/10/3.
//  Copyright © 2019 Lifang Yan. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "openFile.hpp"
#include "insertionSort.hpp"
#include "mergeSort.hpp"
#include "stoogeTime.hpp"


using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;




int main(int argc, const char * argv[]) {

    //use openfile function to open txt file, count the number of the file
    //then sort numbers using insertionSort
    openfile();
    
    //use mergeSort file to open file and read numbers to array, then divide, conquer, and combine to an ordered list
    //openFileForMegerSort();
    
    timing();
    
    return 0;
}
