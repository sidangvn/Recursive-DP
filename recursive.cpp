#include "recursive.hpp"
#include <iostream>
using namespace std;


//Order matters algorithm (permutations)
int RecursiveAlgo(int len, std::deque<int> arr, int total){
    int count = 0;
    int size = arr.size();
    //returns 1 if target length is met
    if (total == len){
        return 1;
    }
    //returns 0 if target length is missed
    if (total > len){
        return 0;
    }
    //# of iterations depends on size of array
    for(int i=0; i < size; i++){
        count += RecursiveAlgo(len, arr, total + arr[i]);
    }
    return count;
}


//Order does not matter
/*
int RecursiveAlgo1(int len, std::deque<int> arr, int total, int index){
    int count = 0;
    int size = arr.size();
    //returns 1 if target length is met
    if (total == len){
        return 1;
    }
    //returns 0 if target length is missed
    if (total > len){
        return 0;
    }
    //# of iterations depends on size of array
    for(int i=index; i < size; i++){
        count += RecursiveAlgo1(len, arr, total + arr[i], index);
    }
    return count;
}
*/



int RecursiveAlgo1(std::deque<int> arr, int i, int target, int total) 
{
	cout << "i: " << i << "   targ: " << target << "     sum: " << total << endl;
	//Making sure we don't access out of bounds
	if (i >= arr.size()) 
	{
		return 0;
	//	total = 0;
		//i = 0;
	}
	//Lets see if we summed up to target value
	else if (total == target) 
	{
		cout << "Hit!!!!" << endl;
		//sum = 0;
		return 1;
	}
	//Stop recursion if our sum is above target value
	else if (total > target) 
	{
		//sum = 0;
		//i = 0;
		return 0;
	}
	else 
	{
		// myAlgo(incArr, i, targ, sum + incArr[i]) left side recursion on excel ********** myAlgo(incArr, i + 1, targ, sum) right side of the tree on excel
		return RecursiveAlgo1(arr, i, target, total + arr[i]) + RecursiveAlgo1(arr, i + 1, target, total);
	}
}



















