#include <stdio.h>
#include <iostream>

#include "familyMatrix.hpp"

/***************************************************************
 * ***Generate a matrix for each family member 
 * ***Store all the items can carry by that member 
 * ***Pass numOfItems, weight limit of each family member,
 * ***weight of each item, and number of family members
 * ***We will use family members and numOfItems to make a 2d array
 * *************************************************************/
int **familyMemberMatrix(int numOfItems, int M[], int F, int weight[]){

     int** familyMatrix = 0;
     familyMatrix = new int*[F];

     for(int m = 0; m < F; m++){

         familyMatrix[m] = new int[numOfItems];
         for(int n = 0; n < numOfItems; n++){
             if(weight[m] >= M[n]){
                 familyMatrix[m][n] = n+1;
             }
             else{
                 familyMatrix[m][n] = 0 ;
             }
         }
     }

     return familyMatrix;
}