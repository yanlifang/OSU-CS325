/*****************************************************************
 ***********************Homework 4 **************************
 ***Author: Lifang Yan****************************************
 ***Date: 10-38-19************************************************/

#include <fstream>
#include <iterator>
#include <vector>
#include <iostream>

using std::ifstream;
using std::ofstream;
using std::istream_iterator;
using std::cout;
using std::endl;

//swap function used to swap the number in that address
void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int main(int argc, const char * argv[]) {
    ifstream ifs;
    ifs.open("act.txt");
       
       int set_num = 0;
       int num_activities = 0;
       int number;
       
       if(ifs.fail()){
           std::cerr << "Error opening file" << std::endl;
           exit(1);
       }
       
       while(!ifs.eof()){
           ifs >> number;
           num_activities = number;
           set_num++;
          
           //use 2d array to store data read from file
           //1st column is activities, 2nd column is start time, and 3rd column is finish time
           //read number one by one and store to 2d array
           int **matrix = 0;
           matrix = new int*[num_activities];
           
           for(int i = 0; i < num_activities; i++){
               matrix[i] = new int[3];
               for(int j = 0; j < 3; j++){
                   ifs >> number;
                   matrix[i][j] = number;
               }
           }
           
           //use insertion sort algorithm to sort matrix based on 3rd column - finish time
           //comparing the finish time of activity from first one to the last one, if there is a finish time earlier than the one in front of that location, swap the data of these two rows
           //next time we start from 2nd activity until we sort the whole column three
           for(int i = 0; i < num_activities; i++){
                   int j = i;
                   while(j > 0 && matrix[j][2] < matrix[j-1][2]){
                       swap(&matrix[j][2], &matrix[j-1][2]);
                       swap(&matrix[j][1], &matrix[j-1][1]);
                       swap(&matrix[j][0], &matrix[j-1][0]);
                       j = j -1;
                   }
           }
           
           //perform activity backwards and start from last one
           int* output = nullptr;
           output = new int;
          
           int selected_activity = 0;
           
           //include the last activity first because we start from last activity
           output[selected_activity] = matrix[num_activities-1][0];
           selected_activity++;
           
           //then we check the activity before last one to find next activity has finish time earlier than start fime of current activity
           //loop over the whole activity until reach first activity
           for(int i = num_activities -1; i > 0; i--)
           {
               for(int j = i-1; j>=0; j--){
                   if(matrix[j][2] <= matrix[i][1]){
                       output[selected_activity] = matrix[j][0];
                       selected_activity++;
                       i = j;
                   }
               }
           }
           cout << "Set " << set_num << endl;
           cout << "Number of activities selected = " << selected_activity <<endl;
           
           //output vector
           cout << "Activities: ";
           for(int i = selected_activity-1; i >= 0; i--){
               cout << output[i] << " ";
           }
           cout << endl;
           delete [] output;
       }
    
    return 0;
}
