#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1000006;
int min1=MAXN, max1=-1, maxl=-1;
int ans = 0;
struct ed{int v,key;};
struct nd
{
	vector<ed> to;
}from[MAXN];
int d[MAXN];
int e;
int i, j, u, v, key;
queue<int> q;
bool node[MAXN];
bool vis[MAXN];
bool qvis[MAXN];
void spfa(int b)
{
	memset(qvis, 0, sizeof(qvis));
	d[b] = 0;
	maxl=-1;
	q.push(b);
	while(!q.empty())
	{
		u = q.front(); q.pop();
		if(u>maxl) maxl=u;
		vis[u]=1;
		for(i = 0; i < from[u].to.size(); i++)
		{
			v = from[u].to[i].v;
			key = from[u].to[i].key;
			if(d[v] < d[u] + key)
			{
				d[v] = d[u] + key;
				if(!qvis[v])
				{
					q.push(v);
					qvis[v] = 1;
				}
			}
		}
		qvis[u] = 0;
	}
	ans+=d[maxl];
}

int main()
{
	cin >> e;
	for(i = 0; i < e; i++)
	{
		cin >> u >> v >> key;
		if(v>max1)max1=v;
		if(u<min1)min1=u;
		node[u]=node[v]=1;
		from[u].to.push_back((ed){v, key});
	}
	for(i = min1; i <= max1; i++)
	{
		if(node[i]&&!vis[i])
			spfa(i);
	}
	cout << ans << endl;
	return 0;
}

