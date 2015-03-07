//============================================================================
// Name        : MyWork.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "dp.h"

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	vector<long> res(100);
	res.assign(100, -1);
	int n = 20;

	printf("Fib of %d is %ld\n", n, fib(n, res));

	return 0;
}
