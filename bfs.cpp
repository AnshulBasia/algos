#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;//pointer to array of lists
	char *color;
	int *distance;
	int *pred;
public:
	Graph(int V); //Constructor
	void addEdge(int v,int w);
	void BFS(int s);
	void print_path(int i,int f);
	void print(int i,int f);

};


Graph::Graph(int V)
{
	this->V=V;
	adj=new list<int>[V];
}

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	cout << "Following is Breadth First Traversal (starting from vertex "<<s<<" )\n";
	color=new char[V];
	distance=new int[V];
	pred=new int[V];
	for(int i=0;i<V;i++)
	{
		color[i]='w';
		distance[i]=-1;
		pred[i]=-1;
	}

	list<int> queue;
	color[s]='g';
	distance[s]=0;
	queue.push_back(s);

	list<int>::iterator i;

	while(!queue.empty())
	{
		s=queue.front();
		cout<<s<<" ";
		queue.pop_front();
		for(i=adj[s].begin();i!=adj[s].end();++i)
		{
			if(color[*i]=='w')
			{
				color[*i]='g';
				distance[*i]=distance[s]+1;
				pred[*i]=s;
				queue.push_back(*i);
			}
		}
		color[*i]='b';
	}
	cout<<endl;

}

void Graph::print(int i,int f)
{
	if(f==i){cout<<i;}
	else
	{
		if(pred[f]==-1){cout<<" There's no path between "<<i<<"and "<<f<<endl;}
		else
		{
			print(i,pred[f]);
			cout<<" "<<f;
		}
	}
}

void Graph::print_path(int i,int f)
{
	BFS(i);
	cout<<"Path from "<<i<<" to "<<f<<" is "<<endl;
	print(i,f);

}

int main()
{
	 Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    
    g.BFS(2);
    g.print_path(0,3);
 
    return 0;

}