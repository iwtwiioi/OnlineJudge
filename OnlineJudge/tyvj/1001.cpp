#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 10005;
int arr[maxn], n, k, i, ans, ok = 1;

int main() {
	scanf("%d%d", &n, &k);
	for(; i <= n; scanf("%d", &arr[++i]));
	sort(arr+1, arr+n+1);
	ans = arr[n-k+1] - arr[k];
	int sqr = sqrt(ans)+1;
	if(ans < 2) ok = 0;
	else for(i = 2; i <= sqr; ++i) if(!(ans % i)) { ok = 0; break; }
	if(ans == 2) ok = 1;
	printf((ok ? "YES\n" : "NO\n"));
	printf("%d\n", ans);
	return 0;
}
