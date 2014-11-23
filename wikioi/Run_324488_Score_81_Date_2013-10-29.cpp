#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 105;
long long sum[MAXN], t;
unsigned long long n, ans = 2147484648;
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
			if(ans > abs(sum[i]-sum[j-1]-t))
				ans = abs(sum[i]-sum[j-1]-t);
	cout << ans;
	return 0;
}
