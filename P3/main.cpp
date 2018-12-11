
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include "Vertex.h"
#include<queue>


using namespace std;
void components(Vertex V[], int numVertices);
void dijkstra(Vertex V[], int src,int dest, int numVertices);
void diameter(Vertex V[], int numVertices);
void primSpanningTree(Vertex V[],int numVertices, int src, int dest);
int main()
{
	int n, e, u, v;
	int counter;
	string edges;
	cin >> n; //vertices
	cin >> e;//edges
	int numCommand;
	string name;



	Vertex adjList[n];
	for (u = 0; u < n; u++) {
		Vertex(adjList[u]);
	}
	while (counter < e)
	{
		// int vert = stoi(edges.substr(0,edges.find(" ")));
		// int edge = stoi(edges.substr(edges.find(" "), edges.length));
		int vert = 0, edge = 0;
		scanf("%d %d\n", &vert, &edge);
		printf("vert: %d  edge: %d\n", vert, edge);
		/*
				if (adjList[vert])
				{
					printf("adding to new vertex:%i  edge : %i ", vert, edge);
					adjList[vert]->addElement(edge);
				}

				else
				{
					Vertex* tempVert = new Vertex();
					tempVert->addElement(edge);
					adjList[vert] = tempVert;
					printf("adding to new vertex:%i  edge:%i ", vert, edge);
				}
		*/
		adjList[vert].addElement(edge);
		adjList[edge].addElement(vert);
		counter++;
	}
	cin >> name;
	if (name == "degree-distribution")
	{
		for (u = 0; u < n; u++) 
		{
			adjList[u].degreeDistribution;
		}
		
		int maxX = 0;
		for (u = 0; u < n; u++)
		{
			
			if (adjList[u].nodeDegree > maxX)
			{
				maxX = adjList[u].nodeDegree;
			}

		}
		int yV[maxX] = 0;
		for (int i = maxX; i < 0; i--)
		{
			
			printf("%d |", i);
			for (u = 0; u < n; u++)
			{
				if (adjList[u].nodeDegree = i)
				{
					yV[i]++;
					printf("* ");

				}
			}
			printf("\n");
		}
		for (int i = 0; i < yV; i++)
		{
			printf(" __________ ");
			
		}
		printf("\n");
		for (int i = 0; i < yV; i++)
		{
			printf("%d",i);
		}
	}
	else if (name == "components")
	{
		components(adjList, n);

		
	}
	else if(name == "shorest-path")
	{
		int src;
		int dest;
		cin >> src;
		cin >> dest;
		dijkstra(adjList, src, dest, n);
	}
	else if (name == "diameter")
	{
		diameter(adjList, n);
	}
	else if (name == " minimum spanning tree ")
	{

	}
}



void components(Vertex V[], int numVertices)
{
	int counter = 0;
	int white = 1;
	int grey = 2;
	int black = 3;


	queue<Vertex> Queue1;


	int colorArray[numVertices];
	int parent[numVertices];
	int v[numVertices];
	Edge* tempHead;

	for (int i = 0; i < numVertices; i++)
	{
		colorArray[i] = white;
		parent[i] = -1;
	}

	for (int i = 0; i < numVertices; i++)
	{
		int comVert = 0;
		if (colorArray[i] == white)
		{
			colorArray[i] = grey;
			//tempHead->next;
			v[i] = 0;
			Queue1.push(V[i]);
			tempHead = V[i].getHeadVal();

			while (tempHead != NULL)
			{
				if (colorArray[tempHead->val] == white);
				{
					Queue1.push(V[tempHead->val]);
					tempHead = tempHead->next;
				}
			}

			while (!Queue1.empty())
			{
				tempHead = Queue1.front().getHeadVal();
				int U = tempHead->val;
				while (tempHead != NULL)
				{


					if (colorArray[tempHead->val] == white)
					{
						colorArray[tempHead->val] == grey;

						parent[tempHead->val] = U;
						Queue1.push(V[tempHead->val]);

					}
				}



				Queue1.pop();
				comVert++;
				colorArray[U] = black;
				
			}
			counter++;
			printf("comonentNum %d \t number of verts %d\n", counter,comVert);
		}
	}


}
bool inList(Edge* head,int v)
{
	Edge* tempHead = head;
	while (tempHead != NULL)
	{
		if (tempHead->val == v)
		{
			return true;
		}

	}
	return false;
}
void dijkstra(Vertex V[], int src,int dest,int numVertices)
{
	
	int dest[numVertices];
	int min = INT_MAX, min_INDEX;
	bool spSet[numVertices];
	int dist[numVertices];
	int parent[numVertices];


	for (int i = 0; i < numVertices; i++)
	{
		dist[i] = INT_MAX, spSet[i] = false,parent[i]=-1;

		dist[src] = 0;


		for (int count = 0; count < numVertices - 1; count++)
		{
			int min_INDEX;
			for (int v = 0; v < numVertices; v++)
			{
				if (spSet[v] == false && dist[v] <= min)
					min = dist[v], min_INDEX = v;
			}

			

			spSet[min_INDEX] = true;

			for (int v = 0; v < numVertices; v++)
			{
				if (!spSet[v] && inList(V[min_INDEX].getHeadVal, v) && dist[min_INDEX] != INT_MAX && dist[min_INDEX] + 1 < dist[v])

				{
					dist[v] = dist[min_INDEX] + 1;
					parent[v] = min_INDEX;
				}
				
			}


		}
	}
	printf("distance:%d\n", dist[dest]);
	printf("path: %d ", dest);
	int par = parent[dest];
	while (par != src)
	{
		printf("% d", par);
		par = parent[par];
	}
	printf("%d\n", src);
	
	/*int dist[numVertices];
	bool shortPath[numVertices];
	int counter = 0;
	int white = 1;
	int grey = 2;
	int black = 3;


	queue<Vertex> Queue1;

	int min = INT_MAX;

	



	
	int colorArray[numVertices];
	int parent[numVertices];
	int v[numVertices];
	Edge* tempHead;

	for (int i = 0; i < numVertices; i++)
	{
		colorArray[i] = white;
		parent[i] = -1;
	}

	
	
		
	colorArray[src] = grey;
	//tempHead->next;
	dist[src] = 0;
	Queue1.push(V[src]);
	tempHead = V[src].getHeadVal();

	while (tempHead != NULL)
	{
		if (colorArray[tempHead->val] == white);
		{
			Queue1.push(V[tempHead->val]);
			dist[tempHead->val] = 1;
			tempHead = tempHead->next;
		}
	}

	while (!Queue1.empty())
	{
				
		tempHead = Queue1.front().getHeadVal();
		int U = tempHead->val;
		if (dest == U)
		{
			int compcounter =

		}

		while (tempHead != NULL)
		{


			if (colorArray[tempHead->val] == white)
			{
				colorArray[tempHead->val] == grey;
				dist[tempHead->val] = dist[U] + 1;
				parent[tempHead->val] = U;
				Queue1.push(V[tempHead->val]);

			}
		}



		Queue1.pop();
		colorArray[U] = black;

	}
	
	*/
}
void diameter(Vertex V[], int numVertices)
{
	int dist[numVertices];
	int dest[numVertices];

	for (int i = 0; i < numVertices; i++)
	{
		for (int v = 0; v < numVertices; v++)
		{
			dist[v] = V[v];
		}
	}

	for (int k = 0; k < numVertices; k++)
	{
		for (int i = 0; i < numVertices; i++)

		{
			for (int v = 0; v < numVertices; v++)
			{
				if (dist[i] + dist[k]+dist[v] < dist[i]+dist[v])
				{
					dist[i] = dist[k] + dist[v];
				}
			}
		}
	}
	
	printf("Longest-shortest path:%d", dist[dest]);
}

void primSpanningTree(Vertex V[], int numVertices, int src, int dest)
{
	int parent[numVertices];
	int min = INT_MAX, min_INDEX;
	bool minSet[numVertices];
	int src[numVertices];
	int dist[numVertices];
	int dest[numVertices];

	for (int i = 0; i < numVertices; i++)
	{
		dist[i] = INT_MAX, minSet[i] = false;



		dist[src] = 0;
		parent[i] = -1;

		for (int count = 0; count < numVertices - 1; count++)
		{
			int min_INDEX;
			for (int v = 0; v < numVertices; v++)
			{
				if (minSet[v] == false && dist[v] <= min)
					min = dist[v], min_INDEX = v;
			}



			minSet[min_INDEX] = true;

			for (int v = 0; v < numVertices; v++)
			{
				if (inList(V[min_INDEX].getHeadVal, v) && minSet[v] == false && dist[min_INDEX] < dist[v])
				{
					parent[v] = min,dist[v] = dist[min_INDEX] + 1;
				}


			}


			int par = parent[dest];

			printf("path: %d ", dest);
		
			while (par != src)
			{
				printf("% d", par);
				par = parent[par];
			}
			printf("%d\n", src);
		}
	}
}

	