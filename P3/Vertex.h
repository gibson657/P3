
#include <iostream>
#include <string>
#include<vector>
#include<queue>

using namespace std;

struct Edge
{
	int val;
	struct Edge *next;
};
class Vertex
{
private:
	struct Edge* head;
	

public:
	int nodeDegree;
	Vertex();
	struct Edge* getHeadVal();
	void addElement(int value);
	void degreeDistribution();
	void dijkstra(Edge* Node, int start, int location);
};


Vertex::Vertex()
{
	head = NULL;

}
struct Edge* Vertex::getHeadVal()
{
	return head;
};

void Vertex::addElement(int value)
{
	if (head == NULL)
	{
		head = new Edge();
		head->val = value;
		head->next = NULL;
	}

	else
	{
		Edge* tempHead = head;
		while (tempHead != NULL)
		{
			if (tempHead->next == NULL)
			{
				tempHead->next = new Edge();
				tempHead->next->val = value;
				tempHead->next->next = NULL;
				break;
			}

			tempHead = tempHead->next;

		}

	}


}
void Vertex::degreeDistribution()
{
	int counter = 0;
	Edge* tempHead = head;

	while (tempHead != NULL)
	{
		counter++;
		tempHead = tempHead->next;
	}

	nodeDegree = counter;



}


