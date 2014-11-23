#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1000006;
int minl=MAXN, maxl=-1;
struct ed{int v,key;};
struct nd
{
	vector<ed> to;
}from[MAXN];
int d[MAXN];
int e;
int i, j;
queue<int> q;
bool vis[MAXN];
int main()
{
	int u, v, key;
	cin >> e;
	for(i = 0; i < e; i++)
	{
		cin >> u >> v >> key;
		if(u<minl) minl=u;
		if(v>maxl) maxl=v;
		from[u].to.push_back((ed){v, key});
	}
	d[minl] = 0;
	q.push(minl);
	while(!q.empty())
	{
		u = q.front(); q.pop();
		for(i = 0; i < from[u].to.size(); i++)
		{
			v = from[u].to[i].v;
			key = from[u].to[i].key;
			if(d[v] < d[u] + key)
			{
				d[v] = d[u] + key;
				if(vis[v])
				{
					q.push(v);
					vis[v] = 1;
				}
			}
		}
		vis[u] = 0;
	}
	cout << d[maxl] << endl;
	return 0;
}

