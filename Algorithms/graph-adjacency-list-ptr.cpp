#include <bits/stdc++.h>
using namespace std;

struct Node 
{
	int id; 
	Node* next;
};

struct Edge
{
	int source, destination;
};

class Graph 
{
	int N; // nodes number 
	
	Node* getAdjListNode(int dest, Node* t)
	{
		Node* newNode = new Node;
		newNode->id = dest;
		newNode->next = t;
		
		return newNode;
	}
public:
	Node** head;

	Graph(Edge edges[], int e, int n)
	{
		this->N = n; 
		head = new Node*[N];
		
		for(int i = 0; i < N; ++i)
			head[i] = nullptr;
		
		for(int i=0;i<e;++i)
		{
			int src = edges[i].source;
			int dest = edges[i].destination;
			
			Node* newNode = getAdjListNode(dest, head[src]);
			
			head[src] = newNode;
		}
	}
	
	~Graph()
	{
		for(int i=0;i<N;++i)
		{
			delete head[i];
		}
		delete[] head;
	}
	
	void Print()
	{
		for(int i = 0;i < N; ++i)
		{
			Node* ptr = head[i];
			cout<< i << "-";
			while(ptr != nullptr)
			{
				cout<<"-> "<<ptr->id<<" ";
				ptr = ptr->next;
			}
			cout<<endl;
		}
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	Edge edges[] =
	{
		// pair (x, y) represents edge from x to y
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	// Number of vertices in the graph
	int N = 6;

	// calculate number of edges
	int n = sizeof(edges)/sizeof(edges[0]);

	// construct graph
	Graph graph(edges, n, N);

	graph.Print();

	return 0;
}
