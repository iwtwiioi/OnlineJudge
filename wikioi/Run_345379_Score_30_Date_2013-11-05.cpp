#include <iostream>
using namespace std;
const int MAXN = 1000005;
int f[MAXN], ans = -1001;
int mmax(const int& a, const int& b){return a<b?b:a;}
int main()
{
	int n, j, i = 0;
	cin >> n;
	while(cin >> j) f[i+1] = f[i++]+j;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= i; j++)
			ans = mmax(ans, f[i]-f[j-1]);
	cout << ans;
	return 0;
}