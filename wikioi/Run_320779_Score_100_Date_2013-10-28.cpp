#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 32010, MAXM = 65;
int n, m;
int v[MAXM], p[MAXM], w[MAXM], q[MAXM][2]; //w[i]代表v[i]*p[i]
bool nok[MAXM];
int f[MAXN];
int main()
{
	cin >> n >> m;
	int i, j;
	for(i = 1; i <= m; i++)
	{
		cin >> v[i] >> p[i] >> j;
		if(q[j][0]) q[j][1] = i;
		else q[j][0] = i;
		if(j) nok[i] = 1;
		w[i] = v[i] * p[i];
	}
	for(i = 1; i <= m; i++)
	{
		if(nok[i]) continue;
		for(j = n; j >= v[i]; j--)
		{
			if(j-v[i] >= 0)
				f[j] = max(f[j], f[j-v[i]]+w[i]);
			if(j-v[i]-v[q[i][0]] >= 0)
				f[j] = max(f[j], f[j-v[i]-v[q[i][0]]]+w[i]+w[q[i][0]]);
			if(j-v[i]-v[q[i][1]] >= 0)
				f[j] = max(f[j], f[j-v[i]-v[q[i][1]]]+w[i]+w[q[i][1]]);
			if(j-v[i]-v[q[i][0]]-v[q[i][1]] >= 0)
				f[j] = max(f[j], f[j-v[i]-v[q[i][0]]-v[q[i][1]]]+w[i]+w[q[i][0]]+w[q[i][1]]);
		}
	}
	cout << f[n];
	return 0;
}
