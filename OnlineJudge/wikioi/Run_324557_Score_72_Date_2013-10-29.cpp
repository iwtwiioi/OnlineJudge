#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 105;
int sum[MAXN], a[MAXN];
int n, t, ans = 2147483647;
int main()
{
	cin >> n >> t;
	int i, j;
	for(i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for(i = 1; i <= n; i++)
		sum[i] = a[i]+sum[i-1];
	for(i = 1; i <= n; i++)
		for(j = 1; j <= i; j++)
			if(ans > abs(sum[i]-sum[j-1]-t))
				ans = abs(sum[i]-sum[j-1]-t);
	cout << ans;
	return 0;
}
