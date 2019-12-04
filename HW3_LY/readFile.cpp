#include "readFile.hpp"

/**********************************************************
 * Read numbers from file called shopping.txt 
 * and store to array or integer 
 * ********************************************************/
void readNumbersFromFile(){

    string filename;
    ifstream ifs;
    ofstream ofs;
    
    //open file
    ifs.open("shopping.txt");

    if(ifs){
        cout <<"File open successfully!\n";
    }
    else{
        cout <<"Please enter a filename: ";
        cin >> filename;
        ifs.open(filename);
    }

    int testCase;
     //read first number, which is the total test cases
    ifs >> testCase;

    ofs.open("results.txt", std::fstream::app);
     //within each test case, the first number is item number  item[itemNumber][price][weight]
     //then will have one line for each item with weight and price of that item
     //next number will be number of family member
     //then will be maximum weight can be carried for each family member
    for(int i =0; i < testCase; i++){
        int numOfItems;
        ifs >> numOfItems;

        //int item[numOfItems][2];
        int P[numOfItems];
        int M[numOfItems];

        for(int n = 0; n < numOfItems; n++){
             ifs >> P[n];
             ifs >> M[n];
        }

        int F;
        ifs >> F;
        int weight[F];
         for(int fi = 0; fi < F; fi++){
            ifs>> weight[fi];
        }

        ofs << " Test Case " << i+1 << endl;

        
        //output all possible items each family membe able to carry
        ofs << "Member Items: " << endl;
        int **matrix2D = familyMemberMatrix(numOfItems, M, F, weight);
        int **profit;
        profit = new int*[F];
        for(int o = 0; o < F; o++){
            profit[o] = new int[numOfItems];
        }
     
        for(int c = 0; c < F; c++){

            ofs << c+1 <<": ";
            for(int d = 0; d < numOfItems; d++){
                if(matrix2D[c][d] != 0){
                    ofs << matrix2D[c][d] << " ";
                }
            }
            ofs << endl;
        }
        int finalValue = knapSack(matrix2D, numOfItems, P, F, profit);
        ofs << "Total Price " << finalValue << endl;


       
        for(int c = 0; c < F; c++){

            ofs << c+1 <<": ";
            for(int d = 0; d < numOfItems; d++){
                if(matrix2D[c][d] != 0){
                    ofs << matrix2D[c][d] << " ";
                }
            }
            ofs << endl;
        }


       for(int i = 0; i < F; i++)
       {
           delete [] matrix2D[i];
       }
       delete [] matrix2D;

        for(int i = 0; i < F; i++)
        {
            delete [] profit[i];
        }
        delete [] profit;
 
       
    }
     ifs.close();
        ofs.close();

    
}