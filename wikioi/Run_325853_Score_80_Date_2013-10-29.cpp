#include <iostream>
#include <algorithm>
using namespace std;
const int MAXV = 10010;
int n, m, v, w, f[MAXV];
int main()
{
	cin >> m >> n;
	int i, j, k, sum = 0;
	for(i = 1; i <= n; i++)
	{
		cin >> v >> w;
        sum += w;
		for(j = m; j >= v; j--)
			f[j] = max(f[j], f[j-v]+w);
	}
	cout << sum - f[m];
	return 0;
}
