#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 32010, MAXM = 65;
int n, m;
int v[MAXM], p[MAXM], w[MAXM], q[MAXM]; //w[i]代表v[i]*p[i]
bool yes[MAXN][MAXM]; //yes[v][i]表示v容量背包是否拿了i物品
int f[MAXN];
int main()
{
	cin >> n >> m;
	int i, j;
	for(i = 1; i <= m; i++)
	{
		cin >> v[i] >> p[i] >> q[i];
		w[i] = v[i] * p[i];
	}
	for(i = 1; i <= m; i++)
		for(j = n; j >= v[i]; j--)
			if(f[j] < f[j-v[i]]+w[i])
				if((q[i] && yes[j-v[i]][q[i]]) || !q[i])
				{
					f[j] = f[j-v[i]]+w[i];
					yes[j][i] = 1;
				}
	cout << f[n];
	return 0;
}
