/*
 * codility.h
 *
 *  Created on: 16 Apr 2015
 *      Author: vinod
 */

#ifndef CODILITY_H_
#define CODILITY_H_

#include <vector>
#include <algorithm>

using namespace std;

//triangle
//complimentary pairs
//number of identical pairs


class checkTriangle:public binary_function<int, int, bool>
{
private:
	int a;

public:

	checkTriangle(int aa):a(aa){}

	bool operator()(int b, int c) const
	{
		return ( a + b > c &&
			 b + c > a &&
			 c + a > b );
	}
};

int findtriangle(const vector<int> v)
{
	vector<int>::const_iterator itr1, itr2, itr3;

	bool found(false);

	for(itr1 = v.begin(); itr1 != v.end() - 2 && found == false; itr1++)
	{
		for(itr2 = itr1+1; itr2 != v.end() -1 && found == false; itr2++)
		{
			itr3 = find_if(itr2+1, v.end(), bind1st(checkTriangle(*itr1),*itr2) );
			if(itr3 != v.end())
				found = true;
		}
	}

	return found?1:0;
}


class comp: public binary_function<int, int, bool>
{
private:
	int a;
public:
	comp(int aa):a(aa){}

	bool operator()(int b, int K) const
	{
		return (K == (a + b));
	}

};

int findCompPairs(const vector<int> vec, int K)
{
	vector<int>::const_iterator itr;
	int count(0);
	for(itr = vec.begin(); itr != vec.end(); itr++)
	{
		count += count_if(vec.begin(), vec.end(), bind2nd(comp(*itr), K) );
	}
	return count;
}


class identicalPairs: public binary_function<int, int, bool>
{
public:

	bool operator()(int a, int b) const
	{
		return (a == b);
	}

};

int solution(vector<int>& A)
{
	int count(0);

	for(vector<int>::iterator itr = A.begin();itr != A.end(); itr++)
	{
		count += count_if(itr+1, A.end(), bind1st(identicalPairs(), *itr) );
	}

	return count;
}

#endif /* CODILITY_H_ */
