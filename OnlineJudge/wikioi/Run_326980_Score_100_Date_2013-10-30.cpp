#include <iostream>
#include <algorithm>
using namespace std;
const int N = 105, V = 10005;
int f[V], w[N], n, m, v[N];
int main()
{
	cin >> n >> m;
    int i, j;
	for(i = 1; i <= n; i++) cin >> v[i];
    for(i = 1; i <= n; i++) cin >> w[i];
    for(i = 1; i <= n; i++)
        for(j = m; j >= v[i]; j--)
			f[j] = max(f[j], f[j-v[i]]+w[i]);
	cout << f[m];
	return 0;
}
