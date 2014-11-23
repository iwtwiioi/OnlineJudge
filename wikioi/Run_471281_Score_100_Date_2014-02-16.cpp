#include <cstdio>
using namespace std;
#define FOR(i, a, n) for(i = a; i <= n; ++i)
const int maxn = 5000;
int n, a[maxn], f[maxn], i, j, ans;

int max(const int& a, const int& b){return a > b ? a : b;}

int main() {
	scanf("%d", &n);
	FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, n) FOR(j, 1, i-1) {
        f[i] = 1;
		if(a[j] < a[i] && f[i] < f[j] + 1)
			f[i] = f[j] + 1, ans = max(ans, f[i]);
    }
	printf("%d", ans);
	return 0;
}
