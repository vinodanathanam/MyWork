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
	lNode(int d):data(d), next(NULL){}
};

lNode* head(NULL);
lNode* tail(NULL);

void insertToList(int d)
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

void clearlist()
{
	if(NULL == head)
		return;

	lNode* node = head;
	while(node)
	{
		lNode* temp = node;

		node = node->next;
		delete temp;
		temp = NULL;

	}
	head = tail = NULL;
}

void traverseList()
{
	if(NULL == head)
		return;

	lNode* node = head;

	while(node)
	{
		printf("%d ",node->data);
		node = node->next;
	}
	printf("\n");
}

void reverseList()
{
	if(NULL == head)
		return;

	lNode* curr = head;
	lNode* prev = NULL;

	while(curr)
	{
		lNode* nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}
	tail = head;
	head = prev;
}

void recRev(lNode* node)
{
	if(NULL == node->next)
	{
		head = node;
		return;
	}

	recRev(node->next);

	lNode* nxt = node->next;
	nxt->next = node;
	node->next = NULL;

}

void testlist()
{
	insertToList(2);
	insertToList(5);
	insertToList(9);
	insertToList(7);
	insertToList(5);
	insertToList(1);
	insertToList(4);

	traverseList();

	recRev(head);

	traverseList();
	clearlist();
}

#endif /* LIST_H_ */
