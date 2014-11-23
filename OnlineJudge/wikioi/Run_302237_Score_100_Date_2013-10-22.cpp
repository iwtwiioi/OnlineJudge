#include <iostream>

using namespace std;
int n, ans = 0;
int map[14];
void dfs(int x)
{
	if(x > n) {ans++; return;}
	int i, j;
	for(i = 1; i <= n; i++) //放在某行
    {
        map[x] = i;
		for(j = 1; j < x; j++)
			//因为是按列放的，所以不用判断列
			if((map[j] == map[x]) ||
			   (x-map[x] == j-map[j] || x+map[x] == j+map[j]))
            	break;
		if(j == x)
			dfs(x+1);
	}
}

int main()
{
	cin >> n;
	dfs(1);
	cout << ans;
	return 0;
}
