/*
 * Graph.h
 *
 *  Created on: 7 Mar 2015
 *      Author: vinod
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include <set>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

typedef map<int, set<int> > graphSet;

graphSet g_graph;

void addVertices(int b, int e)
{
	if(g_graph.end() == g_graph.find(b))
	{
		set<int> temp;
		temp.insert(e);
		g_graph.insert(make_pair(b, temp));
	}
	else
	{
		g_graph[b].insert(e);
	}
}

void DFS(int start)
{
	if(true == g_graph.empty())
		return;

	if(g_graph.end() == g_graph.find(start))
		return;

	//track visited
	vector<int> visited(100);
	visited.assign(100, 0);

	//stack
	list<int> stack;

	//check visited
	//print
	//mark as visited
	//add to stack;

	printf("%d ", start);
	visited[start] = 1;
	stack.push_front(start);

	while(false == stack.empty())
	{
		//get the top of the stack
		int temp = stack.front();

		//find the vertices
		set<int> verts = g_graph[temp];

		//find the first non visited
		bool allVisited(true);
		for(set<int>::iterator it = verts.begin(); it != verts.end(); it++)
		{
			if(visited[*it] == 0)
			{
				allVisited = false;
				printf("%d ", *it);
				visited[*it] = 1;
				stack.push_front(*it);
				break;
			}
		}
		if(true == allVisited)
			stack.pop_front();
	}
	printf("\n");
}

void BFS(int start)
{
	if(true == g_graph.empty())
		return;

	if(g_graph.end() == g_graph.find(start))
		return;

	//track visited
	vector<int> visited(100);
	visited.assign(100, 0);

	//queue
	list<int> Q;

	//check visited
	//print
	//mark as visited
	//add to queue;

	printf("%d ", start);
	visited[start] = 1;
	Q.push_back(start);

	while(false == Q.empty())
	{
		int front = Q.front();
		Q.pop_front();
		//find the vertices
		set<int> verts = g_graph[front];

		//find the first non visited
		for(set<int>::iterator it = verts.begin(); it != verts.end(); it++)
		{
			if(visited[*it] == 0)
			{
				printf("%d ", *it);
				visited[*it] = 1;
				Q.push_front(*it);
			}
		}
	}
	printf("\n");
}

void TestDFSBFS()
{
	addVertices(1, 2);
	addVertices(1, 3);
	addVertices(2, 4);
	addVertices(2, 1);
	addVertices(3, 1);
	addVertices(3, 4);
	addVertices(3, 6);
	addVertices(4, 7);
	addVertices(4, 3);
	addVertices(5, 6);
	addVertices(5, 7);
	addVertices(6, 3);
	addVertices(6, 5);
	addVertices(7, 5);
	addVertices(7, 4);

	for(int i = 0; i < 10; i++)
	{
		DFS(i);
		BFS(i);
		printf("\n");
	}
}

#endif /* GRAPH_H_ */
