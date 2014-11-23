#include <iostream>

using namespace std;
const int MAXM = 1000000, MAXN = 1010;
int f[MAXM], n, m, v;
int main()
{
	cin >> n >> m;
	int i, j;
	for(i = 1; i <= n; i++)
	{
		cin >> v;
		for(j = m; j >= v; j--)
			f[j] = max(f[j], f[j-v]+v);
	}
	cout << m - f[m];
	return 0;
}
