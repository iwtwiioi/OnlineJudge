#include <iostream>
using namespace std;
int n, ans = 0;
int map[14][14];
void dfs(int x)
{
	if(x > n) {ans++; return;}
	int i, j;
	for(i = 1; i <= n; i++)
	{
		bool ok = 1;
		for(j = 1; j < x; j++)
		{
			if(map[i][j]) {ok = 0; break;}
			for(int k = 1; k <= n; k++)
				if((k-j == i-x || k+j == i+x) && map[k][j]) {ok = 0; break;}
            if(!ok) break;
		}
		if(ok)
		{
			map[i][x] = 1; 
			dfs(x+1);
			map[i][x] = 0; 
		}
	}
}

int main()
{
	cin >> n;
	dfs(1);
	cout << ans;
	return 0;
}

