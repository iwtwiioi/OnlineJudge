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
		//判断是否重合十分麻烦额= =
		bool ok = 1;
		for(j = 1; j < x; j++)
		{
			if(map[i][j]) {ok = 0; break;} //判断行
			//判断左斜
			for(int k = 1; k <= n; k++)
				if((k-j == i-x || k+j == i+x) && map[k][j]) {ok = 0; break;}
		}
		//因为是按列放的，所以不用判断
		/*for(j = 1; j < i; j++)
			if(map[j][x]) {ok = 0; break;} //判断列*/

		if(ok)
		{
			map[i][x] = 1; //我是按，即x是第x列放的
			dfs(x+1);
			map[i][x] = 0; //清除标志
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

