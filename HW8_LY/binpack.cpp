/***************************************************
 * Name: Lifang Yan
 * Homework: 8
 * Date: 12-3-19
 * Course: CS325
 * ****************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <time.h>
#include <algorithm>


//Reference: https://www.geeksforgeeks.org/bin-packing-problem-minimize-number-of-used-bins

/*********************************************************
 * firstFit
 * define the bin number, and track the remaining space of bin
 * if the item weight over the remaining space, start a new bin
 * otherwise, place in the previous bin and update the remaining space of bin
 * ***********************************************************/
int firstFit(int S[], int n, int c);

int firstFitDecreasing(int S[], int n, int c);

int bestFit(int S[], int n, int c);

int main(int argc, const char * argv[]){
    std::ifstream ifs;
    ifs.open("bin.txt");
    //ifs.open("random.txt");
    int testCase, capacity, itemNumber;
    ifs >> testCase;

    while(testCase > 0){
        ifs >> capacity >> itemNumber;
        int listNum[itemNumber];
        for(int m = 0; m < itemNumber; m++){
            ifs >> listNum[m];
        }

        //track the time span of firstFit algorithm
        auto start1 = std::chrono::high_resolution_clock::now();
        int FF = firstFit(listNum, itemNumber, capacity);
        std::cout << FF << "  bins " << std::endl;
        auto stop1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_FF = stop1 - start1;
        std::cout <<testCase << "Test Case " << 3 - testCase + 1 << " First Fit: "  << FF << ", " << duration_FF.count() << " seconds. ";

        //track the time span of firstFitDecreasing algorithm
        auto start2 = std::chrono::high_resolution_clock::now();
        int FFD = firstFitDecreasing(listNum, itemNumber, capacity);
        auto stop2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_FFD = stop2 - start2;
        std::cout << "First Fit Decreasing: " << FFD << ", " <<duration_FFD.count() << " seconds. ";

        //track the time span of bestFit algorithm
        auto start3 = std::chrono::high_resolution_clock::now();
        int BF = bestFit(listNum, itemNumber, capacity);
        auto stop3 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_BF = stop3-start3;
        std::cout << "Best Fit: " << BF << ", " << duration_BF.count() << " seconds.\n";

        testCase--; 
    }

    ifs.close();
    return 0;

}

/*******************************************************************
 * bestFit function
 * compare to first fit, bestFit will check all open bins to see if the new item will fit and compare the remaining of each bin
 * Return the minimum bin numbers from bestFit algorithm
 * *******************************************************************/
int bestFit(int S[], int n, int c){
    int bin = 0;
    int bin_rem[n];
    for(int i = 0; i < n; i++){
        int j;
        int minCap = c + 1; 
        int binNumber = 0;
        for(j = 0; j < bin; j++){
            if(bin_rem[j] >= S[i] && bin_rem[j]-S[i] < minCap){ //compare the bin_rem[j] and the remaining cap
                binNumber = j;
                minCap = bin_rem[j]-S[i];
            }
        }
        
        if(minCap == c+1){ //to start a new bin 
            bin_rem[bin] = c - S[i];
            bin++;
        }
        else{
            bin_rem[binNumber] -= S[i];
        }
    }

    return bin;
}

//Reference: https://www.geeksforgeeks.org/bin-packing-problem-minimize-number-of-used-bins/
/*********************************************************
 * firstFit function
 * ref from geeksforgeeks
 * Parameters: array, capacity and number of array items
 * Post-conditions: return the min bin number
 * ********************************************************/
int firstFit(int S[], int n, int c){
    int bin = 0;
    int bin_rem[n];

    for(int i = 0; i < n; i++){
        int j;
        for(j = 0; j < bin; j++){
            if(bin_rem[j] >= S[i]){
                bin_rem[j] -= S[i];
                break;
            }
        }
        if(j == bin){
            bin_rem[bin] = c - S[i];
            bin++;
        }
    }
    return bin;
}

/**********************************************************
 * First Fid Descreasing Function
 * First we will sort the array 
 * Call firstFit function we have before to return the minimum bin
 * ***********************************************************/
int firstFitDecreasing(int S[], int n, int c){
    //using sort algorithm from algorithm library 
    //time complexity is O(nlogn)
    sort(S, S+n, std::greater<int>());
    //after sort the array, call first fit function to return the min bins
    int bin = firstFit(S, n, c);
    return bin;
}


