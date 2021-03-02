#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+69;
vector<vector<int>>adj;
int color [MAXN];
bool vis[MAXN];
vector <int> dist(MAXN), par(MAXN);
int id;
void bfs(int source)
{
	queue<int>q;
	q.push(source);
	vis[source] = true;
	par[source] = -1;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(int u : adj[v])
		{
			if(!vis[u])
			{
				if(color[u] == id)
				{
					dist[v] = dist[u] + 1;
				}
				vis[u] = true;
				q.push(u);
				par[u] = v;
			}
		}
	}
}
int main()
{
	cout<<"woi";
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<n;i++)
	{
		cin>>color[i];
	}
	cin>>id;
	memset(vis,false,sizeof(vis));
	bfs(id);
	int minim = 1e9+7;
	for(int i=0;i<n;i++)
	{
		minim = min(minim, dist[i] - dist[id]);
	}
	cout<<minim<<endl;
}