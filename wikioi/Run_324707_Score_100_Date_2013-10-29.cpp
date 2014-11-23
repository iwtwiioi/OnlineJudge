#include <iostream>
#include <algorithm>
using namespace std;
const int MAXV = 10010;
int n, m, v, w, f[MAXV];
int main()
{
	cin >> n >> m;
	int i, j, k;
	for(i = 1; i <= n; i++)
	{
		cin >> v >> w;
		for(j = m; j >= v; j--)
			f[j] = max(f[j], f[j-v]+w);
	}
	cout << f[m];
	return 0;
}
