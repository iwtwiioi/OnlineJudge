#include <iostream>
#include <algorithm>
using namespace std;
int d[20], s = 0, n, k, c[11];
bool f[11][11]; //c[i]代表数值为i的有多少中变的方法
//坑的是，数据里面应该有0.。。。
unsigned long long ans = 1;
int main()
{
    cin >> n >> k;
	int i, j, u, v;
	for(i = 1; i <= k; i++)
	{
		cin >> u >> v;
		f[u][v] = 1; 
	}
	for(k = 0; k <= 10; k++)
		for(i = 0; i <= 10; i++)
			for(j = 0; j <= 10; j++)
				f[i][j] = (f[i][j] || (f[i][k] && f[k][j]));
	for(i = 0; i <= 10; i++)
		for(j = 0; j <= 10; j++)
			if(f[i][j])
				c[i]++;
    for(i = 0; i <= 10; i++)
        c[i]++;
	while(n)
	{
		k = n%10;
		ans *= c[k];
		n /= 10;
	}
    cout << ans;
    return 0;
}