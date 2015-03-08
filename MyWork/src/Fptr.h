/*
 * Fptr.h
 *
 *  Created on: 8 Mar 2015
 *      Author: vinod
 */

#ifndef FPTR_H_
#define FPTR_H_

typedef int (*fptr1)(int, int);

int add(int a, int b)
{
	return a+b;
}


void testfptr()
{
	fptr1 pt = &add;
	int res = pt(3,5);
}



#endif /* FPTR_H_ */
