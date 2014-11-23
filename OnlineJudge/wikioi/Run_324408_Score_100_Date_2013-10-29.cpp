#include <iostream>

using namespace std;
const int MAX = 1010;
int f[MAX][MAX], v[MAX], g[MAX], w[MAX];
int main()
{
	int V, G, N;
	cin >> V >> G >> N;
	int i, j, k;
	for(i = 1; i <= N; i++) cin >> w[i] >> v[i] >> g[i];
	for(i = 1; i < N; i++)
		for(j = V; j >= v[i]; j--)
			for(k = G; k >= g[i]; k--)
				f[j][k] = max(f[j][k], f[j-v[i]][k-g[i]]+w[i]);
	f[V][G] = max(f[V][G], f[V-v[N]][G-g[N]]+w[N]);
	cout << f[V][G];
	return 0;
}
