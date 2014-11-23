#include <iostream>

using namespace std;
const int MAXV = 510, MAXN = 50;
int Q, N, V, f[MAXV];
int q, w, v;

int main()
{
	cin >> N >> V >> Q;
	int i, j;
	for(i = 1; i <= N; i++)
	{
		cin >> w >> v >> q;
		if(q > Q) continue;
		for(j = V; j >= v; j--)
			f[j] = max(f[j], f[j-v]+w);
	}
	cout << f[j];
	return 0;
}
