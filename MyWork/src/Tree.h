/*
 * Tree.h
 *
 *  Created on: 21 Mar 2015
 *      Author: vinod
 */

#ifndef TREE_H_
#define TREE_H_

struct tNode{
	int data;
	tNode* left;
	tNode* right;
	tNode* parent;
	tNode(int d){
		data = d;
		left = right = parent = NULL;
	}
};

tNode* Insert(tNode* node, int data)
{
	if(NULL == node)
	{
		tNode t = new tNode(data);
		return t;
	}
	else if (data >= node->data)
		node->right = Insert(node->right, data);
	else
		node->left = Insert(node->left, data);

	return node;
}

tNode* findMin(tNode* node)
{
	tNode* temp = node;
	while(temp->left){
		temp = temp->left;
	}
	return temp;
}




#endif /* TREE_H_ */
