#include <iostream>

using namespace std;
const int MAXV = 510, MAXN = 50;
int Q, N, M, S, V, f[MAXV];
int q, w, v;

int main()
{
	cin >> N >> M >> V >> Q >> S;
	int i, j;
	for(i = 1; i <= N; i++)
	{
		cin >> v >> q >> w;
		if(q > Q) continue;
		for(j = V; j >= v; j--)
			f[j] = max(f[j], f[j-v]+w);
	}
	if(M+f[V] > S) cout << "YES\n";
	else cout << "NO\n";
	cout << M+f[V];
	return 0;
}
