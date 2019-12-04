
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>


int main(int argc, const char * argv[]){

    //get seed to generate random number
    unsigned seed;
    seed = int(time(0));
    srand(seed);
    std::ofstream ofs;
    std::string filename;
    std::cin >> filename;
    ofs.open(filename);

    ofs << 20 << " ";
    std::cout << std::endl;
    int itemNumber = 0;
    for(int i = 0; i < 20; i++){
        int capacity = rand()%500 + 500;
        itemNumber += 500;
        ofs << capacity << " ";
        ofs << itemNumber << std::endl;
        int list[itemNumber];
        for(int i = 0; i < itemNumber; i++){
            list[i] = rand()% 500;
            ofs << list[i] << " ";
        }
        std::cout << std::endl;
    }
    ofs.close();
    return 0;
}

    