#include <iostream>
using namespace std;
int prime[40], m[20][20], a[20], vis[20], n;
void dfs(int c)
{
	int i;
	if(c == n)
	{
		for(i = 2; i <= n; i++) if(!vis[i]) break;
		a[c] = i;
		if(!m[a[1]][a[c]] || !m[a[c-1]][a[c]]) return;
		for(int i = 1; i <= n; i++)
			cout << a[i] << ' ';
		cout << endl;
		return;
	}
	for(i = 2; i <= n; i++)
	{
		if(c%2 == i%2 && m[a[c-1]][i] && !vis[i])
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
	cin >> n;
	prime[2]=prime[3]=prime[5]=prime[7]=prime[11]=prime[13]=prime[17]=prime[19]=prime[23]=prime[29]=prime[31]=prime[37]=prime[41]=prime[43]=prime[47]=1;
	int i, j;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(i!=j && prime[i+j])
				m[i][j] = 1;
	a[1] = 1;
	dfs(2);
	return 0;
}