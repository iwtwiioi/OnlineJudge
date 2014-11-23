#include <iostream>
using namespace std;
int prime[40], a[20], vis[20], n;
void dfs(int c)
{
	if(c == n)
	{
		int i;
		for(i = 2; i <= n; i++) if(!vis[i]) break;
		a[c] = i;
		if(!prime[a[1]+a[c]]) return;
		for(int i = 1; i <= n; i++)
			cout << a[i] << ' ';
		cout << endl;
		return;
	}
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i] && prime[i+a[c-1]])
		{
			vis[i] = 1;
			a[c] = i;
			dfs(c+1);
			vis[i] = 0;
		}
	}
}

int main()
{
	prime[2]=prime[3]=prime[5]=prime[7]=prime[11]=prime[13]=prime[17]=prime[19]=prime[23]=prime[29]=prime[31]=prime[37]=prime[41]=prime[43]=prime[47]=1;
	cin >> n;
	a[1] = 1;
	dfs(2);
	return 0;
}