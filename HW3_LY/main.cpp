/* *************************************
 Homework3
 Lifang Yan
 10-21-19
 *********************/

#include <iostream>
#include <fstream>
#include <vector>
#include <array>

#include "readFile.hpp"
#include "familyMatrix.hpp"

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;


int main(int argc, const char *argv[]){

    readNumbersFromFile();

     return  0;


}

 /*int maxProfit(int tests, int numOfItems, int P[], int M[], int F, int weight[]){

     
     
     //define a 2d array to store the items each family member can carry 
     int familyMatrix[F][numOfItems];

     int k =0;
     for(int m = 0; m < F; m++){
         for(int n = 0; n < numOfItems; n++){
             if(weight[m] >= M[n]){
                 familyMatrix[m][n] = M[n];
                 k++;
             }
             else{
                 familyMatrix[m][n] = 0 ;
             }
         }
     }
     ofstream ofs;
    ofs.open("results.txt", std::fstream::app);
     
    ofs << "Test Case " << tests + 1 << endl;

    int totalValue = 0;
    if(numOfItems == 0 || F == 0)
     {
         totalValue = 0;
     }

    if(k == 0){
        ofs << "Total Price " << familyMatrix[F-1][numOfItems-1] << endl;
        //output all possible items each family membe able to carry
    }
    else{
            for(int m = 0; m < F; m++){
                familyMatrix[m][0] = P[0];
            }

            for(int i = 1; i < F; i++){
                for(int j = 0; j < numOfItems; j++){
                    familyMatrix[i][j] = max(familyMatrix[i-1][j], maxProfit(tests, numOfItems, P, M, F, weight) + P[j]);
            }
        }
    }
    
    ofs << "Member Items: " << endl;
    
   

    for(int i = 0; i < F; i++){
         ofs << i + 1 << ": ";
         for(int j = 0; j < numOfItems; j++){
             if(familyMatrix[i][j] != 0){
                ofs << j+1 << " ";
             }
         }
         ofs << endl;
    }

   
    
    
        
     
     ofs.close();
     
     return totalValue;
     
 }*/
