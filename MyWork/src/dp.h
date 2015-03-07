/*
 * dp.h
 *
 *  Created on: 7 Mar 2015
 *      Author: vinod
 */

#ifndef DP_H_
#define DP_H_


#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

//fib
//number of ways
//cut rod
//lcs

long fib(int n, vector<long>& res)
{
	if(n < 0)
		return 0;

	if(res[n] == -1 && n <= 1)
	{
		res[n] = n;
	}
	else if(res[n] == -1)
	{
		res[n] = fib(n-1, res) + fib(n-2, res);
	}
	return res[n];
}

int numberOfWays(int n)
{
	if(n < 0)
		return 0;

	if(0 == n)
		return 1;

	return numberOfWays(n-1) + numberOfWays(n - 2) + numberOfWays(n -3);
}

int numberofWaysDP(int n, vector<int>& res)
{
	if(n < 0)
		return 0;

	if(0 == n)
		return 1;

	if(-1 == res[n])
	{
		res[n] = numberofWaysDP(n-1, res) + numberofWaysDP(n-2, res) + numberofWaysDP(n-3, res);
	}

	return res[n];
}

int cutrod(vector<int> prices, int n)
{
	if(n == 0)
		return 0;

	int max = prices[n-1]; //reduce 1 to get the correct position in the vector. We are assigning the price of the n'th slice
	for(int i = 0; i < n; i++)
	{
		int temp = prices[i] + cutrod(prices, n-i-1);
		if(temp > max)
			max = temp;
	}
	return max;
}

int cutrodDP(vector<int> prices, int n)
{
	if(n == 0)
		return 0;

	vector<int> res(n);
	res.assign(n, 0);

	for(int i = 0; i < n; i++)
	{
		int max = prices[i];

		for(int j = 0; j < i; j++)
		{
			int temp = prices[j] + res[i-j-1];
			if(temp > max)
				max = temp;
		}

		res[i] = max;
	}

	return res[n-1];
}

int getVal(int x, int y, vector< vector<int> >& tab)
{
	if(x < 0 || y < 0)
		return -1;

	return tab[x][y];

}

int lcs(const string& str1, const string& str2)
{
	int l1 = str1.length();
	int l2 = str2.length();

	if(l1 == 0 || l2 == 0)
		return 0;

	vector< vector<int> > table(l1+1, vector<int>(l2+1));

	for(int i = 0; i <= l1; i++)
	{
		for(int j = 0; j <= l2; j++)
		{
			if(i == 0 || j == 0)
				table[i][j] = 0;
			else if(str1[i-1] == str2[j-1])
			{
				table[i][j] = getVal(i-1, j-1, table) + 1;
			}
			else
			{
				table[i][j] = max(getVal(i-1, j, table), getVal(i, j-1, table));
			}
		}
	}

	return getVal(l1, l2, table);
}


#endif /* DP_H_ */
