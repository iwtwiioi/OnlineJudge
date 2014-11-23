#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int d[20], c[10];
bool f[10][10]; //c[i]代表数值为i的有多少中变的方法
//坑的是，数据里面应该有0.。。。
int ans[10000], l = 1;
void mul(int k)
{
    int i;
    for(i = 1; i <= l; i++)
        ans[i] *= k;
    for(i = 1; i <= l; i++)
    {
        ans[i+1] += ans[i]/10;
        ans[i] %= 10;
        while(ans[l+1] > 0) l++;
    }
}
int main()
{
	string n;
	int k, i, j, u, v;
    cin >> n >> k;
	for(i = 1; i <= k; i++)
	{
		cin >> u >> v;
		f[u][v] = 1; 
	}
	for(k = 0; k < 10; k++)
		for(i = 0; i < 10; i++)
			for(j = 0; j < 10; j++)
				f[i][j] = (f[i][j] || (f[i][k] && f[k][j]));
	for(i = 0; i < 10; i++) f[i][i] = 1;
	for(i = 0; i < 10; i++)
		for(j = 0; j < 10; j++)
			if(f[i][j])
				c[i]++;
    ans[1] = 1;
	for(i = 0; i < n.size(); i++)
		mul(c[n[i]-'0']);
    for(i = l; i > 0; i--)
    	cout << ans[i];
    return 0;
}