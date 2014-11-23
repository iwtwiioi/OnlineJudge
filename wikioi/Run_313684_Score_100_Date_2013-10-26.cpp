#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
//如果某个爱心天使被其他所有人或爱心天使所爱则请输出这个爱心天使是由哪些人构成的
//注意，还可以是某个爱心天使所爱(即找爱心天使是否为所有人的都可达，如果没有就输出-1，不是就不用输出)
const int MAXN = 1010, MAXE = 10010;
int ans = 0, nn = 0;
int p[MAXN], sum[MAXN], FF[MAXN], LL[MAXN], NT = 0;
int head[MAXN], u[MAXN], v[MAXE], next[MAXE];
bool key[MAXN][MAXN];
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
		p[t1] = ++nn;
		sum[nn] = 1;
		vis[t1] = 0; //出栈标志
		if(t1 != r) //不是本节点，即有连通的
		{
			ans++;  //建立一个爱心天使
					//将这个节点绑定建立起的爱心天使
			while(r != t1) //一直循环下去
			{
				t1 = s.top(); s.pop();
				sum[nn]++;
				p[t1] = nn;  //缩点
				vis[t1] = 0; //标记
			}
		}
	}
}
//缩点后再判断是否为连通图

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
	cout << ans << endl;
	//建边
	for(int i = 1; i <= M; i++)
		key[p[u[i]]][p[v[i]]] = 1;
	int i, j, k;
	//Floyd，判断连通图
	for(k = 1; k <= nn; k++)
		for(i = 1; i <= nn; i++)
			for(j = 1; j <= nn; j++)
				if(i!=j && key[i][k] && key[k][j]) //此处必须2条路都通，即i->k && k->j
					key[i][j] = 1;
	int ok = 1, no = 1;
	for(i = 1; i <= nn; i++)
	{
		if(sum[i] == 1) continue;
		ok = 1;
		for(j = 1; j <= nn; j++) //看看每一个节点是否通i，因为前面初始化边时有本身，所以不用判断是否一条边
			if(!key[j][i])
				ok = 0;
		if(ok)
		{
			no = 0;
			for(j = 1; j <= N; j++)
				if(p[j] == i)
					cout << j << ' ';
			cout << endl;
		}
	}
	if(no) cout << "-1\n";

	return 0;
}
