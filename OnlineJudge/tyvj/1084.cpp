#include <iostream>
using namespace std;
#define FOR(i, a, n) for(i=a;i<=n;++i)
int max(const int& a, const int& b) { return a > b ? a : b; }

const int MOD=100, maxn=30;
int f[maxn][maxn], n, a[maxn][maxn], ans, x, y;
int main() {
	cin >> n;
	int i, j;
	FOR(i, 1, n) FOR(j, 1, i) cin >> a[i][j];
	cin >> x >> y;
	FOR(i, 1, x) FOR(j, 1, i) 
		f[i][j]=max(f[i-1][j-1], f[i-1][j])+a[i][j];
	FOR(j, x, n) f[j][y-1]=0; f[x][y+1]=0; 
	FOR(i, 1, n-x) FOR(j, 0, i) 
		f[x+i][y+j]=max(f[x+i-1][y+j-1], f[x+i-1][y+j])+a[x+i][y+j];
	FOR(i, 0, n-x+1) ans=max(ans, f[n][y+i]);
	cout << ans;
	return 0;
}
