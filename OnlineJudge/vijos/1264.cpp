#include <cstring>
#include <iostream>
using namespace std;
#define FOR(i, a, n) for(i = a; i <= n; ++i)
#define clear(a) memset(a, 0, sizeof(a))

const int maxn = 550;
int f[maxn], a[maxn], b[maxn], maxi, ans;
int sa, sb, i, j;
int max(const int& _a, const int& _b) { return _a < _b ? _b : _a; }

int main() {
	int n;
	cin >> n;
	while(n--) {
		clear(a); clear(b); clear(f);
		cin >> sa; FOR(i, 1, sa) cin >> a[i];
		cin >> sb; FOR(i, 1, sb) cin >> b[i];
		ans = 0;
		FOR(i, 1, sa) {
			maxi = 0;
			FOR(j, 1, sb)
				if(a[i] > b[j] && maxi < f[j]) maxi = f[j];
				else if(a[i] == b[j]) 
					f[j] = maxi + 1, ans = max(ans, f[j]);
		}
		cout << ans << endl;
	}
	return 0;
}

