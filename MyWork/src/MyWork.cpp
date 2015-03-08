//============================================================================
// Name        : MyWork.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "dp.h"
#include "Queen.h"
#include "Paths.h"
#include "Graph.h"
#include "Fptr.h"
#include "MyStl.h"

using namespace std;

int main() {
	cout << "" << endl; // prints !!!Hello World!!!
	/*vector<long> res(100);
	res.assign(100, -1);
	int n = 20;

	printf("Fib of %d is %ld\n", n, fib(n, res));
*/

	//placeQueens(5,0);

	//findGridPath();

	//TestDFSBFS();

	//testfptr();

	testBind1st();

	return 0;
}
