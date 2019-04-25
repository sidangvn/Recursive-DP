//compiles and runs with the command g++ -o mover *.cpp
//If not, compiles with a Makefile using command make
//Read in input file "input.txt"
//Output to file "output.txt"

//Input format:
//Line 1: x				, where x = the number of problem instances
//Line 2: t n			, where t = target value, n = size of array
//Line 3: a b c d...	, contains n positive integers, in sorted order (no duplicates)
//Repeats 2 and 3 until end of file

//Output format:
//	n x					, where n = number of sums when order matters, x = number of sums when order doesn't matter

#include "recursive.hpp"
#include <iostream>
#include <fstream>
#include <deque>

using namespace std;
int main(){
    //variable declarations
    int len, target, size, temp, outputOrdered, outputUnordered;
    std::vector<InfoHolder*> list;
    std::deque<int> tempArr;

    //read in input.txt
    std::ifstream inFile;
    inFile.open("input.txt");
    if(!inFile.is_open()){
        std::cout << "Could not open file" << std::endl;
        return 1;
    }

    //create output.txt file
    std::ofstream outFile;
    outFile.open("output.txt");

    //read in first line as number of problem instances (times the recursive algorithm is called by main)
    inFile >> len;
    //reads in information based on given format
    while (!inFile.eof()){
        //sets temp target integer
        inFile >> target;
        //sets temp size integer
        inFile >> size;
        //copies integers into a temp array based on temp size
        for (int i=0; i < size; i++){
            inFile >> temp;
            tempArr.push_back(temp);
        }
        //creates information object for easier grouping
        InfoHolder *information = new InfoHolder(target, size, tempArr);
        //adds information to a list
        list.push_back(information);
        tempArr.clear();
    }
    //loop to call recursive algorithm for each item in list, and write results to output.txt file
    
    //int banana = 0;
    int something = 0;
    
    for(int i = 0; i < len; i++){
        int target = list.at(i)->getTarget();
        std::deque<int> array = list.at(i)->getInfo();
        outputOrdered = RecursiveAlgo(target, array, 0);
        
        outputUnordered = RecursiveAlgo1(array, something, target, 0);
        
        //outputUnordered = 0; //change 0 to new algorithm
        outFile << outputOrdered << " " << outputUnordered << "\n";
    }

    inFile.close();
    outFile.close();
    
    return 0;
}
