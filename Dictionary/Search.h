#include<vector>
using namespace std;

template<typename T>
class Search{

private:
	static int binarySearchHelper(vector<T> list, int lowerBound, int upperBound, T target){
		if (lowerBound > upperBound){return -1;}
		int middle = (upperBound + lowerBound)/2;
		if (list[middle] == target) {return middle;}
		else if (list[middle] > target){ return binarySearchHelper, 0, middle - 1, target;}
		else { return binarySearchHelper, middle + 1, list.size()-1, target;}
	}

public:
	static int binarySearch(vector<T> list, T target){
		if (list == 0){ return -2;}
		return binarySearchHelper(list, 0, list.size()-1);
	}
};
