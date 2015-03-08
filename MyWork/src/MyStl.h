/*
 * MyStl.h
 *
 *  Created on: 8 Mar 2015
 *      Author: vinod
 */

#ifndef MYSTL_H_
#define MYSTL_H_

#include <vector>
#include <functional>
using namespace std;

void testAdd(int a, int b)
{
	printf("Add of %d + %d is %d\n", a, b, a + b);
}

class Add :public binary_function < int, int, void >
{
public:
	void operator()(int a, int b) const
	{
		printf("Add of %d + %d is %d\n", a, b, a + b);
	}
};

void testBind1st()
{
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(5);
	vec.push_back(9);
	vec.push_back(7);
	vec.push_back(5);
	vec.push_back(1);
	vec.push_back(4);
	vec.push_back(6);
	vec.push_back(9);

	for_each(vec.begin(), vec.end(), bind2nd(ptr_fun(&testAdd), 10));
	for_each(vec.begin(), vec.end(), bind2nd(Add(), 20));
	for_each(vec.begin(), vec.end(), bind1st(Add(), 30));
}


#endif /* MYSTL_H_ */
