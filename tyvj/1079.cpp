#include <iostream>
using namespace std;
#define FOR(i, a, n) for(i=a;i<=n;++i)
int max(const int& a, const int& b) { return a > b ? a : b; }

const int MOD=100, maxn=30;
int f[maxn][maxn], n, a[maxn][maxn], ans;
int main() {
	cin >> n;
	int i, j;
	FOR(i, 1, n) FOR(j, 1, i) cin >> a[i][j];
	int mid=n>>1, mid2=n-mid;
	FOR(i, 1, mid) FOR(j, 1, i) 
		f[i][j]=max(f[i-1][j-1], f[i-1][j])+a[i][j];
	FOR(j, mid, n) f[j][mid-1]=0; 
	FOR(i, 1, n-mid) FOR(j, 0, i) 
		f[mid+i][mid+j]=max(f[mid+i-1][mid+j-1], f[mid+i-1][mid+j])+a[mid+i][mid+j];
	FOR(i, mid, n) ans=max(ans, f[n][i]);
	cout << ans;
	return 0;
}
