#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n, a[10005], b[10005], ans;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
	sort(a+1, a+1+n); sort(b+1, b+1+n);
	for(int i = 1; i <= n; ++i) ans += abs(a[i]-b[n-i+1]);
	printf("%d", ans);
	return 0;
}
