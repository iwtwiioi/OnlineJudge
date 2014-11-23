#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define FOR(i, a, n) for(i = a; i <= n; ++i)
#define clear(a) memset(a, 0, sizeof(a))

const int maxn = 550;
int f[maxn][maxn], a[maxn], b[maxn], i, j, k, maxi;
int max(const int& _a, const int& _b) { return _a < _b ? _b : _a; }

int main() {
	int n;
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) cin >> b[i];
	FOR(i, 1, n) FOR(j, 1, n)
		if(a[i] != b[j]) f[i][j] = f[i-1][j];
		else {
			maxi = 0;
			for(k = j-1; k > 0; --k) if(b[j] > b[k]) maxi = max(maxi, f[i-1][k]);
				f[i][j] = maxi + 1;
		}
	cout << f[n][n] << endl;
	return 0;
}
