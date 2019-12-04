//
//  main.cpp
//  CS325_HW5
//
//  Created by Lifang Yan on 2019/11/11.
//  Copyright © 2019 Lifang Yan. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::string;
using std::cin;


//struct to represent the vertices
//value is the name of wrestler, t is the type of wrestler either babyfaces or heels
//bool value to check if it is visited or not
struct mystruct{
    string value;
    string t;
    bool visited;
};


//initialize graph, add add vertices into graph, all type initialize as unknown
void vertices(std::vector<std::vector <mystruct *> >&graph, std::vector<string> v)
{
    for(int i = 0; i < graph.size() ; i++){
        graph[i].push_back(new mystruct);
        graph[i][0]->value = v[i];
        graph[i][0]->t = "unknown";
        graph[i][0]->visited = false;
    }
}

//hash table to track the idnex based on the name provided
int getIndex(std::vector<string> v, string s){
    for(int i = 0; i < v.size(); i++){
        if(s == v[i]){
            return i;
        }
    }
    return -1;
}

//make pairs based on rivalry pair data
//undirected graph, update the connection for 2nd wrestler
//use hash function to get the node locaiton/index
void makePair(std::vector<std::vector <mystruct* > >&graph, string A, string B, std::vector<string> query){
    int p1 = getIndex(query, A);
    int p2 = getIndex(query, B);
    
    graph[p1].push_back(graph[p2][0]);
    graph[p2].push_back(graph[p1][0]);
}

//check if there is one wresler either babyfaces or heels, if yes, impossible to differentiate the wrestler based on input
//otherwise update the paired wrestler to opposite type
void solution(std::vector<std::vector<mystruct* > >& graph, std::vector<string> ref){
    
    std::vector<string> babyfaces;
    std::vector<string> heels;
    
    std::queue <std::vector<mystruct* > > collectionList;
    
    for(int i = 0; i < graph.size(); i++){
        if(!graph[i][0]->visited){
            
            //based on recommendation, initialzie the starting vertex as babyfaces 
            graph[i][0]->t = "babyfaces";
            
            babyfaces.push_back(graph[i][0]->value);
            
            collectionList.push(graph[i]);
            while(!collectionList.empty()){
                std::vector<mystruct*> cur = collectionList.front();
                cur[0]->visited = true;
                collectionList.pop();
                
                for(int i = 1; i < cur.size(); i++){
                    if(cur[i]->visited == false){
                        if(cur[i]->t == "unknown" && cur[0]->t == "babyfaces"){
                            cur[i]->t = "Heels";
                            heels.push_back(cur[i]->value);
                        }
                        else if(cur[i]->t == "unknown" && cur[0]->t == "Heels"){
                            cur[i]->t = "Babyfaces";
                            babyfaces.push_back(cur[i]->value);
                        }
                        else if(cur[i]->t == cur[0]->t){
                            cout <<"Impossible" << endl;
                            return;
                        }
                        collectionList.push(graph[getIndex(ref, cur[i]->value)]);
                    }
                }
            }
            
        }
    }
    cout << "Yes, possible" << endl;
    cout << "Babyfaces: ";
    for(int i = 0; i < babyfaces.size(); i++){
        cout << babyfaces[i] << " ";
    }
    cout << endl;
    cout << "Heels: ";
    for(int i = 0; i < heels.size(); i++){
        cout << heels[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    ifstream ifs;
    ifs.open(argv[1]);
    
    //define the graph, and add vertices into graph
    int number;
    std::vector<string> wrestlerList;
    
    //store the wreslers name in array
    ifs >> number;

    std::vector<std::vector<mystruct *> > graph(number);
    string readValue;
    
    //store the name into an array, define array using pointer
    for(int i = 0; i < number; i++){
        ifs >> readValue;
        wrestlerList.push_back(readValue);
    }
    
    vertices(graph, wrestlerList);
    int rivalriesNumber;
    ifs >> rivalriesNumber;
    
    //Get the edges of graph
    for(int i = 0; i < rivalriesNumber; i++){
        string A, B;
        ifs >> A;
        ifs >> B;
        makePair(graph, A, B, wrestlerList);
    }
 
    solution(graph, wrestlerList);
    ifs.close();
    
    return 0;
        
}
