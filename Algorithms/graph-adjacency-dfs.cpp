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
	Node **head;
	int time;
	int *color, *tin, *tout, *ancesty;
	
	Node* getAdjListNode(int dest, Node* t)
	{
		Node* newNode = new Node;
		newNode->id = dest;
		newNode->next = t;
		
		return newNode;
	}
public:
	Graph(vector<Edge> edges, int n)
	{
		this->N = n; 
		head = new Node*[N];
		color = new int[N];
		tin = new int[N];
		tout = new int[N];
		ancesty = new int[N];
		
		for(int i = 0; i < N; ++i)
			head[i] = nullptr;
		
		for(uint i = 0;i < edges.size();++i)
		{
			int src = edges[i].source;
			int dest = edges[i].destination;
			Node* newNode = nullptr;
			newNode = getAdjListNode(dest, head[src]);
			
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
	
	void Print(bool dfs_info)
	{
		for(int i = 0;i < N; ++i)
		{
			Node* ptr = head[i];
			if(dfs_info)
				cout<< i <<"["<<tin[i]<<","<<tout[i]<<","<<color[i]<<"] -";
			else
				cout<< i << " -";
			
			while(ptr != nullptr)
			{
				cout<<"-> "<<ptr->id<<" ";
				ptr = ptr->next;
			}
			cout<<endl;
		}
	}
	
	void Dfs()
	{
		memset(color, 0, sizeof(int)*N);
		memset(tin, -1, sizeof(int)*N);
		memset(tout, -1, sizeof(int)*N);
		memset(ancesty, -1, sizeof(int)*N);
		time = 0; 
		
		for(int i = 0;i < N; ++i)
		{
			if(color[i] == 0)
				this->DfsVisit(i);
		}
	}
	
	void DfsVisit(int currentNode)
	{
		color[currentNode] += 1;
		tin[currentNode] = ++time;
		Node* neighborhood = head[currentNode];
		while(neighborhood != nullptr)
		{
			if(color[neighborhood->id] == 0)
			{
				ancesty[neighborhood->id] = currentNode;
				DfsVisit(neighborhood->id);
			}
				
			neighborhood = neighborhood->next;
		}
		color[currentNode] += 1;
		tout[currentNode] = ++time;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<Edge> edges;
	
	for(int i = 0; i < n; ++i)
	{
		int d;
		cin>>d;
		if(d!=-1)
		{
			Edge e = { source: i, destination:d-1 };
			edges.push_back(e);
		}
	}	

	Graph graph(edges, n);
	graph.Dfs();
	graph.Print(true);

	return 0;
}
