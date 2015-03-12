/*
 * QSort.h
 *
 *  Created on: 12 Mar 2015
 *      Author: vinod
 */

#ifndef QSORT_H_
#define QSORT_H_

#include <algorithm>
using namespace std;

void swap(int& a, int& b)
{
	int t = a^b;
	a = t^a;
	b = t^a;
}

int partition(int* arr, int l, int r)
{
	int x = arr[r];
	int i = l-1;

	for(int j = l; j <= r; j++)
	{
		if(arr[j] <= x)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[++i], arr[r]);
	return i;
}

void qSort(int* arr, int l, int r)
{
	if(l < r)
	{
		int p = partition(arr, l, r);
		qSort(arr, l, p-1);
		qSort(arr, p+1, r);
	}
}

class printval
{
public:
	void operator()(int n)
	{
		printf("%d ", n);
	}
};

void myQuickSort()
{
	int a[] = {2,5,9,7,5,1,4,8,11,3};
	qSort(a, 0,9);

	for_each(a,a + 9, printval());
}

#endif /* QSORT_H_ */
