#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 105;
int sum[MAXN];
int n, t, ans = 2147483647;
int main()
{
	cin >> n >> t;
	int i, j;
	for(i = 1; i <= n; i++)
	{
		cin >> sum[i];
		sum[i] += sum[i-1];
	}
	for(i = 1; i <= n; i++)
		for(j = 1; j <= i; j++)
			ans = min(ans, int(abs(sum[i]-sum[j-1]-t)));
	cout << ans;
	return 0;
}
