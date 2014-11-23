#include <iostream>

using namespace std;
int n, ans = 0;
bool map[14][14];
int l[14][14], r[14][14];
void dfs(int x)
{
	if(x > n) {ans++; return;}
	int i, j;
	for(i = 1; i <= n; i++)
	{
		//判断是否重合十分麻烦额= =
		bool ok = 1;
		for(j = 1; j < x; j++)
		{
			if(map[i][j]) {ok = 0; break;} //判断行
			//判断左斜
			for(int k = 1; k <= n; k++)
				if((l[k][j] == l[i][x] || r[k][j] == r[i][x]) && map[k][j]) {ok = 0; break;}
			if(!ok) break;
		}
		//因为是按列放的，所以不用判断
		/*for(j = 1; j < i; j++)
			if(map[j][x]) {ok = 0; break;} //判断列*/

		if(ok)
		{
			map[i][x] = true; //我是按，即x是第x列放的
			dfs(x+1);
			map[i][x] = false; //清除标志
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			l[i][j] = j-i, r[i][j] = j+i;
	dfs(1);
	cout << ans;
	return 0;
}

