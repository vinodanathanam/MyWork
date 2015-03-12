/*
 * QSort.h
 *
 *  Created on: 12 Mar 2015
 *      Author: vinod
 */

#ifndef QSORT_H_
#define QSORT_H_

int partition(int* arr, int l, int r)
{
	return 1;
}

void qSort(int* arr, int l, int r)
{
	if(l < r)
	{
		int p = partition(arr, l, r);
		qSort(arr, l, p);
		qSort(arr, p+1, r);
	}
}



#endif /* QSORT_H_ */
