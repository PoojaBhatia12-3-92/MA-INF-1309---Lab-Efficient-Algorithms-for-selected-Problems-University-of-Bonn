//http://web.cs.iastate.edu/~cs511/handout10/FPT_VC.pdf

#include<iostream> 
#include <vector>
#include <time.h>
using namespace std; 

struct edge{
  int x;
  int y;
};

bool vertex_Cover(vector<edge> G,int k, int n){
    //cout<<G.size()/2<<endl;
    if(G.size()==0)
        return true;
    if(G.size()>=k*n)
        return false;
    int u= G[G.size()/2].x;
    int v= G[G.size()/2].y;
    vector<edge> g_u;
    for(int i=0;i<G.size();i++){
        if(u != G[i].x && u != G[i].y)
            g_u.push_back(G[i]);
    }
    bool a = vertex_Cover(g_u,k-1,n-1);
    vector<edge> g_v;
    for(int i=0;i<G.size();i++){
        if(v != G[i].x && v != G[i].y)
            g_v.push_back(G[i]);
    }
    bool b = vertex_Cover(g_v,k-1,n-1);
    //cout<<a<<" "<<b<<endl;
    return (a|b);  
}


int main() { 
	int n;
	cin>>n;
    vector<edge> graph;
	int m;
	cin>>m;
	
	for (int i=0; i<m; i++)
	{   int x,y;
	    cin>>x;
	    cin>>y;
	    edge g;
	    g.x=x;
	    g.y=y;
	    graph.push_back(g);
	}
	bool value = vertex_Cover(graph,6,n);
	if(value)
	    cout<<"possible\n";
	else
	    cout<<"impossible\n";
	return 0; 
} 
