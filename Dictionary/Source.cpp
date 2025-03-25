#include "ArrayDictionary.h"
#include <iostream>
using namespace std;
	void printMe(double& d) {
		printf("%.2f\n", d);
	}
int main() {
		ArrayDictionary<int, double> testDict;
		testDict.add(1, 2.1);
		testDict.add(11, 2.5);
		testDict.add(13, 2.2);
		testDict.traverse(printMe);
	return 0;
}