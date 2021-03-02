#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+69;
vector<int>adj[MAXN];
int color [MAXN];
bool vis[MAXN];
int level[MAXN];
int id;
void bfs(int s)
{
	queue<int>q;
	q.push(s);
	level[s] = 0;
	vis[s] = true;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(int u : adj[v])
		{
			if(!vis[u])
			{
				level[u] = level[v] + 1;
				vis[u] = true;
				q.push(u);
			}
		}
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		--u;
		--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		color[i] = --a;
	}
	cin>>id;
	memset(vis,false,sizeof(vis));
	memset(level,0,sizeof(level));
	bfs(id);
	int minim = 1e9+7;
	for(int i=0;i<n;i++)
	{
		if(level[i] - level[id] == 0 )
			continue;
		if(color[i] == id)
			minim = min(minim, level[i] - level[id]);
	}
	if(minim == 1e9+7)
		cout<<-1<<endl;
	else
		cout<<minim<<endl;
}