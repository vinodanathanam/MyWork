/*
 * General.h
 *
 *  Created on: 12 Mar 2015
 *      Author: vinod
 */

#ifndef GENERAL_H_
#define GENERAL_H_

void TOUPPER(char* str)
{
	char* c = str;
	while(*c != '\0')
	{
		*c = (*c >= 'a' && *c <= 'z')?(*c - ('a' - 'A')):*c;
		c++;
	}
}

void tolower(char* str)
{
	char* c = str;

	while(*c != '\0')
	{
		*c = (*c >= 'A' && *c <= 'Z')?(*c + ('a'-'A')):*c;
		c++;
	}
}

bool GetBit(int num, int index)
{
	return ((num & (1 << index)) > 0);
}

void SetBit(int num, int index, bool b)
{
	if(b)
		num | (1 << index);
	else
		num & ~(1 << index);
}

#endif /* GENERAL_H_ */
