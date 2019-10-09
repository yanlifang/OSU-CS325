//
//  main.cpp
//  CS325_HW1_Q3_LY
//
//  Created by Lifang Yan on 2019/10/7.
//  Copyright © 2019 Lifang Yan. All rights reserved.
//

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
#include "openFile.hpp"
#include "mergeSort.hpp"
#include "timing.hpp"


using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;




int main(int argc, const char * argv[]) {

    //use openfile function to open txt file, count the number of the file
    //then sort numbers using insertionSort
    //openfile();
    
    //use mergeSort file to open file and read numbers to array, then divide, conquer, and combine to an ordered list
    openFileForMegerSort();
    
    timing();
    
    return 0;
}
