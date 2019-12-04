#include "knapSack.hpp"

//int max(int a, int b) { return (a > b) ? a:b;}

int knapSack(int** arrayMatrix, int N, int P[], int F, int **profit){

    if(N == 0){
        return 0;
    }

    //initialize array to 0 
    int total = 0;

    for(int m = 0; m < F; m++){
        profit[m][0] = arrayMatrix[m][0];
        for(int p = 0; p < N; p++){
            if((P[p] + knapSack(arrayMatrix, N, P, F-1, profit)) > profit[m][p-1]){
                profit[m][p] = P[p] + knapSack(arrayMatrix, N, P, F-1, profit);

                arrayMatrix[m][p] = p + 1;
            }
            else
            {
                profit[m][p] = profit[m][p-1];
            }
            total = profit[m][p];
        }
    }
   
     //return valueArray[F-1][N-1];
     return total;

}