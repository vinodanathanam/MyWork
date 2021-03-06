/*
 * Tree.h
 *
 *  Created on: 21 Mar 2015
 *      Author: vinod
 */

#ifndef TREE_H_
#define TREE_H_

#include <list>

struct tResult{
	int lVal;
	int rVal;
	int mVal;
	tResult(){
		lVal = rVal = mVal = 0;
	}
	tResult(int l, int r, int m):lVal(l), rVal(r), mVal(m){}
};

struct tNode{
	int data;
	tNode* left;
	tNode* right;
	tNode* parent;
	tNode(int d):data(d), left(NULL), right(NULL), parent(NULL){

	}
};

int myMax(int a, int b)
{
	return (a > b)?a:b;
}

tNode* Insert(tNode* node, int data)
{
	if(NULL == node)
	{
		tNode* t = new tNode(data);
		return t;
	}
	else if (data >= node->data)
		node->right = Insert(node->right, data);
	else
		node->left = Insert(node->left, data);

	return node;
}

void cleanup(tNode* node)
{
	while(NULL != node)
	{
		cleanup(node->left);
		cleanup(node->right);
		delete node;
		node = NULL;
	}
}

tNode* findMin(tNode* node)
{
	tNode* temp = node;
	while(temp->left){
		temp = temp->left;
	}
	return temp;
}

void inorder(tNode* node)
{
	if(NULL != node)
	{
		inorder(node->left);
		printf("%d ", node->data);
		inorder(node->right);
	}
}

void printSameLevel(tNode* node)
{
	if(NULL == node)
		return;
	list<tNode*> Q;
	Q.push_back(node);
	while(false == Q.empty())
	{
		tNode* t = Q.front();
		Q.pop_front();
		printf("%d ",t->data);
		if(NULL != t->left)
			Q.push_back(t->left);
		if(NULL != t->right)
			Q.push_back(t->right);
	}
}

tNode* deleteNode(tNode* node, int d)
{
	if(NULL == node)
		return node;

	if(d > node->data)
		node->right = deleteNode(node->right, d);
	else if(d < node->data)
		node->left = deleteNode(node->left, d);
	else{
		//case leaf
		if(NULL == node->left && NULL == node->right)
		{
			delete node;
			node = NULL;
		}
		//case 1 child
		else if(NULL == node->left)
		{
			tNode* temp = node;
			node = node->right;
			delete temp;
			temp = NULL;
		}
		else if(NULL == node->right)
		{
			tNode* temp = node;
			node = node->left;
			delete temp;
			temp = NULL;
		}
		//case 2 children
		else{
			tNode* temp = findMin(node->right);
			node->data = temp->data;
			node->right = deleteNode(node->right, temp->data);
		}
	}
	return node;
}

tResult desMaxPath(tNode* node)
{

	if(NULL == node)
		return tResult(0,0,0);
	else
	{
		tResult leftVal = desMaxPath(node->left);
		tResult rightVal = desMaxPath(node->right);

		int l = 1 + leftVal.lVal;
		int r = 1 + rightVal.rVal;

		int m = myMax( myMax(l,r), myMax(leftVal.mVal, rightVal.mVal) );
		return tResult(l,r,m);
	}
}

void TestTree()
{
	tNode* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4);
	root = Insert(root,1); root = Insert(root,11);

	printf("Samelevel start: ");
	//inorder(root);
	printSameLevel(root);

// Deleting node with value 5, change this value to test other cases
	root = deleteNode(root,3);

//Print Nodes in Inorder
	printf("\nSamelevel after deletion: ");
	//inorder(root);
	printSameLevel(root);
	printf("\n");

	printf("\nMax desc path : %d\n",desMaxPath(root).mVal);

	cleanup(root);
}

#endif /* TREE_H_ */
