#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 205, MAXV = 200005;
int f[MAXV], w, v, m, N, V;
int main()
{
	cin >> N >> V;
	int i, j, k;
	for(i = 1; i <= N; i++)
	{
		cin >> v >> w >> m;
		if(m == -1)
			for(j = v; j <= V; j++)
				f[j] = max(f[j], f[j-v]+w);
		else
			for(k = 1; k <= m; k++)
				for(j = V; j >= v; j--)
					f[j] = max(f[j], f[j-v]+w);
	}
	cout << f[V];
	return 0;
}
