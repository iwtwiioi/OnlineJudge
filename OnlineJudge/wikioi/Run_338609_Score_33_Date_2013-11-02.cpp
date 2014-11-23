#include <iostream>
using namespace std;
const int MAXP = 1000;
int notprime[MAXP];
int a[20], vis[20];
int n;
void dfs(int c)
{
	if(c == n)
	{
		int i;
		for(i = 2; i <= n; i++) if(!vis[i]) break;
		a[c] = i;
			if(notprime[a[1]+a[c]]) return;
		for(int i = 1; i <= n; i++)
			cout << a[i] << ' ';
		cout << endl;
		return;
	}
	int i;
	for(i = 2; i <= n; i++)
	{
		//cout << i+a[c-1] << " is prime:"<< notprime[i+a[c-1]] << endl;
		if(!vis[i] && !notprime[i+a[c-1]])
		{
			vis[i] = 1;
			//cout << i << " is already done\n";
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
	for(i = 2; i <= 500; i++)
	{
		j = 2; t = i<<1;
		while(t<=1000) 
			notprime[t] = 1, t = i*(++j);
	}
	a[1] = 1;
	dfs(2);
	return 0;
}