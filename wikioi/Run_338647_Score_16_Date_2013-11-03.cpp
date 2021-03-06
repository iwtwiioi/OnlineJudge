#include <iostream>
using namespace std;
int notprime[40], a[20], vis[20], n;
void dfs(int c)
{
	if(c == n)
	{
		int i;
		for(i = 2; i <= n; i++) if(!vis[i]) break;
		a[c] = i;
		if(notprime[a[1]+a[c]] && notprime[a[c-1]+a[c]]) return;
		for(int i = 1; i <= n; i++)
			cout << a[i] << ' ';
		cout << endl;
		return;
	}
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i] && !notprime[i+a[c-1]])
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
	int i, j, t;
	for(i = 2; i <= 20; i++)
	{
		j = 2; t = i<<1;
		while(t<=40) 
			notprime[t] = 1, t = i*(++j);
	}
	a[1] = 1;
	dfs(2);
	return 0;
}