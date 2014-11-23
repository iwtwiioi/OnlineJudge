#include <iostream>
using namespace std;
#define FOR(i, a, n) for(i=a;i<=n;++i)
int max(const int& a, const int& b) { return a > b ? a : b; }

const int MOD=100, maxn=30;
int f[maxn][maxn][MOD], n, a[maxn][maxn], ans;
int main() {
	cin >> n;
	int i, j, k;
	FOR(i, 1, n) FOR(j, 1, i) cin >> a[i][j];
	f[1][1][a[1][1]%MOD]=1;
	FOR(i, 1, n) FOR(j, 1, i) for(k=MOD-1; k>=0; --k)
		if(f[i-1][j-1][k] || f[i-1][j][k]) f[i][j][(k+a[i][j])%MOD]=1;
	FOR(j, 1, n) FOR(k, 0, MOD-1) ans=f[n][j][k]?max(ans, k):ans;
	cout << ans;
	return 0;
}
