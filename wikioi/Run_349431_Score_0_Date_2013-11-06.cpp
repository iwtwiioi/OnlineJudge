#include <iostream>
#include <algorithm>
using namespace std;
#define uint unsigned int
const int MAXN = 3005;
uint f[MAXN][MAXN], a[MAXN], b[MAXN];
int n;
int main()
{
	cin >> n;
	int i, j, k;
	for(i = 1; i <= n; i++) cin >> a[i];
	for(i = 1; i <= n; i++) cin >> b[i];
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(a[i]!=b[i]) f[i][j] = f[i-1][j];
			else if(a[i] == b[j])
			{
				for(k = 1; k < j; k++)
					if(b[j] > b[k])
						f[i][j] = max(f[i][j], f[i-1][k]);
				f[i][j]++;
			}
    uint ans = f[1][n];
    for(i = 2; i <= n; i++) ans = max(ans, f[i][n]);
	cout << ans;	
	return 0;
}