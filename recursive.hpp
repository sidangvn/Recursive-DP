#ifndef __RECURSIVE_HPP
#define __RECURSIVE_HPP

#include <vector>
#include <deque>

//class to hold information read in from input.txt
class InfoHolder{
    private:
        int target;
        int arraySize;
	int index;
        std::deque<int> info;
    public:
        //Constructor
        InfoHolder(int t, int a, std::deque<int> i) : target(t), arraySize(a), info(i) {};
        //getter functions
        const int getTarget() { return target; };
        const int getArraySize() { return arraySize; };
        const std::deque<int> getInfo() { return info; };
};

//recursive algorithm
int RecursiveAlgo(int len, std::deque<int> arr, int total);
int RecursiveAlgo1(int len, std::deque<int> arr, int total, int index);

#endif
