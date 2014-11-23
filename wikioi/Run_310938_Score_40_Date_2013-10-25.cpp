#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
//如果某个爱心天使被其他所有人或爱心天使所爱则请输出这个爱心天使是由哪些人构成的
//注意，还可以是某个爱心天使所爱(即找爱心天使是否为所有人的都可达，如果没有就输出-1，不是就不用输出)
const int MAXN = 3000, MAXE = 5000;
int ans = 0;
int p[MAXN], sum[MAXN>>1], FF[MAXN], LL[MAXN], NT = 0;
int head[MAXN], u[MAXE], v[MAXE], next[MAXE];
bool ok[MAXN>>1][MAXN>>1];

int N, M;
stack<int> s;
bool vis[MAXN];
void Tarjan(int r)
{
	FF[r] = LL[r] = ++NT;
	s.push(r); //压入
	vis[r] = 1;
	for(int i = head[r]; i; i = next[i])
	{
		if(!FF[v[i]])
		{
			Tarjan(v[i]);
			if(LL[v[i]] < LL[r])
				LL[r] = LL[v[i]];
		}
		else if(vis[v[i]] && FF[v[i]] < LL[r])
			LL[r] = FF[v[i]];
	}
	if(FF[r] == LL[r])
	{
		int t1 = s.top(); s.pop(); //先取第一个，因为只要2个以上节点的强连通图
		vis[t1] = 0; //出栈标志
		if(t1 != r) //不是本节点，即有连通的
		{
			int su = 1;
			ans++; //建立一个爱心天使
			p[t1] = ans; //将这个节点绑定建立起的爱心天使
			while(r != t1) //一直循环下去
			{
				t1 = s.top(); s.pop();
				p[t1] = ans;
				su++;
				vis[t1] = 0; //标记
			}
			sum[ans] = su;
		}
	}
}

int main()
{
	cin >> N >> M;
	for(int i = 1; i <= M; i++)
	{
		cin >> u[i] >> v[i];
		next[i]=head[u[i]];
		head[u[i]]=i;
	}
	for(int i = 1; i <= N; i++)
		if(!FF[i])
			Tarjan(i);
	for(int i = 1; i <= M; i++)
	{
		if(!p[u[i]] && p[v[i]])
			sum[p[v[i]]]++;
		else if(p[u[i]] != p[v[i]] && !ok[p[u[i]]][p[v[i]]])
		{
			sum[p[v[i]]] += sum[p[u[i]]];
			ok[p[u[i]]][p[v[i]]] = 1;
		}
	}
	cout << ans << endl;
	int nok = 1;
	for(int i = 1; i <= ans; i++)
	{
		if(sum[i] != N) continue;
		nok = 0;
		for(int j = 1; j <= N; j++)
			if(p[j] == i)
					cout << j << ' ';
			cout << endl;
	}
	if(nok) cout << "-1\n";
	return 0;
}

