#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 220;
int w[MAXN], f[MAXN][MAXN];
int main()
{
	int n, i, j, k, l, ans = 0;
	cin >> n;
	for(i = 1; i <= n; i++){cin >> w[i]; w[i+n] = w[i];}
	for(l = 1; l <= n; l++)
	{
        memset(f, 0, sizeof(f));
		for(j = l; j <= l+n; j++)
			for(i = j; i >= l; i--)
				for(k = i+1; k < j; k++)
					f[i][j] = max(f[i][j], f[i][k]+f[k+1][j]+w[i]*w[k]*w[j]);
		ans = max(ans, f[l][l+n]);
	}
	cout << ans << endl;
	return 0;
}

