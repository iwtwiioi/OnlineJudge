#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 105;
int t[MAXN], n, k, V;
int v1[MAXN], w1[MAXN];
int v[MAXN], w[MAXN], nn = 0;
int f[MAXN];
bool m[MAXN];
int ans = 0;

int main()
{
	int i, j;
	double temp;
	int tem;
	cin >> n >> k >> temp;
	V=(int)(temp*10);
	for(i = 1; i <= n; i++)	{cin >> temp; v1[i] = (int)(temp*10);}
	for(i = 1; i <= n; i++)	cin >> w1[i];
	for(i = 1; i <= n; i++)	cin >> t[i];
	for(i = 1; i <= k; i++)
	{
		cin >> tem;
		m[tem] = 1;
		for(j = 1; j <= n; j++)
			if(tem == t[i])
			{
				ans += w1[i];
				V -= v1[i];
				break;
			}
	}
	if(V == 0) {cout << ans << endl;return 0;}
	for(i = 1; i <= n; i++)
		if(!m[t[i]])
			w[++nn]=w1[i], v[nn]=v1[i], m[t[i]]=1;
	for(i = 1; i <= nn; i++)
		for(j = V; j > 0; j--)
			if(j-v[i] >= 0)
				f[j] = max(f[j], f[j-v[i]]+w[i]);
	int maxw = 0;
	for(i = 1; i <= V; i++)
		maxw = max(maxw, f[i]);
	cout << ans+maxw << endl;
	return 0;
}
