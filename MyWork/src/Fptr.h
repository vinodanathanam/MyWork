/*
 * Fptr.h
 *
 *  Created on: 8 Mar 2015
 *      Author: vinod
 */

#ifndef FPTR_H_
#define FPTR_H_

class test;

typedef int (*fptr1)(int, int);
typedef int (test::*fptr2)(int, int);


int add(int a, int b)
{
	return a+b;
}

class test{
public:
	int mul(int a, int b)
	{
		return a*b;
	}
};

void testfptr()
{
	fptr1 pt = &add;
	int res = pt(3,5);
	printf("Sum is %d\n",res);

	fptr2 fp2 = &test::mul;

	test obj;
	int mres = (obj.*fp2)(3,4);
	printf("Mul is %d\n", mres);
}

// first way using the typedef
//pt2Function funcArr1[10] = {NULL};
// 2nd way directly defining the array
//int (*funcArr2[10])(float, char, char) = {NULL};

// Direct solution: Function takes a char and returns a pointer to a
// function which is taking two floats and returns a float. <opCode>
// specifies which function to return
/*
float (*GetPtr1(const char opCode))(float, float){
if(opCode == ’+’)
return &Plus;
else
return &Minus;}
*/

#endif /* FPTR_H_ */
