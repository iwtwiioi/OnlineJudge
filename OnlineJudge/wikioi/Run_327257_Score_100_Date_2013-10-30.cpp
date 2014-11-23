#include <iostream>
#include <algorithm>
using namespace std;
const int MAXV = 200010;
int f[MAXV], w, v, m, N, V;
void zop(int v, int w)
{
	for(int j = V; j >= v; j--)
		f[j] = max(f[j], f[j-v]+w);
}
void cp(int v, int w)
{
	for(int j = v; j <= V; j++)
		f[j] = max(f[j], f[j-v]+w);
}
void mp(int v, int w, int m)
{
	if(m*v >= V) {cp(v, w); return;}
	//把第 i 种物品换成 n[i] 件01背包中的物品，则得到了物品数为
	//二进制思想：1 2 4 8...n^2的和能表示任何数。所以，将物品n[i]件转换为1 2 4 8...n^2件物品
	int k = 1;
	while(k < m)
	{
		zop(k*v, k*w);
		m -= k;
		k *= 2;
	}
	zop(m*v, m*w);
}

int main()
{
	cin >> N >> V;
	int i, j, k;
	for(i = 1; i <= N; i++)
	{
		cin >> v >> w >> m;
		if(m == -1)
			cp(v, w);
        else if(m == 1)
            zop(v, w);
		else
			mp(v, w, m);
	}
	cout << f[V];
	return 0;
}
