/*
 * list.h
 *
 *  Created on: 16 Apr 2015
 *      Author: vinod
 */

#ifndef LIST_H_
#define LIST_H_

struct lNode
{
	int data;
	lNode* next;
	lNode(int d):data(d){}
};

lNode* head(NULL);
lNode* tail(NULL);

void insert(int d)
{
	lNode* node = new lNode(d);
	if(NULL == head)
	{
		head = tail = node;
	}
	else
	{
		tail->next = node;
		tail = node;
	}

}

#endif /* LIST_H_ */
