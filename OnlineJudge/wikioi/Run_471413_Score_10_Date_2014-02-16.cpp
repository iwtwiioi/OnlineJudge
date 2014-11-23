#include <cstring>
#include <iostream>
using namespace std;
#define FOR(i, a, n) for(i = a; i <= n; ++i)
const int maxn = 5500;
int f[maxn], a[maxn], b[maxn], maxi, ans;
int sa, sb, i, j;
int max(const int& _a, const int& _b) { return _a < _b ? _b : _a; }

int main() {
	int n;
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) cin >> b[i];
	ans = 0;
	FOR(i, 1, n) {
		maxi = 0;
		FOR(j, 1, n)
			if(a[i] > b[j]) maxi = f[j];
			else if(a[i] == b[j]) 
				f[j] = maxi + 1, ans = max(ans, f[j]);
	}
	cout << ans << endl;
	return 0;
}
