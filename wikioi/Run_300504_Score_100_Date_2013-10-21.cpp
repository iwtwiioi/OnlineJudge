#include <iostream>

using namespace std;
bool map[9][9];
int c[9]; //随便命名四种颜色
int ans = 0, N;
void dfs(int n)
{
	int i, j;
	if(n > N) {ans++; return;}
	for(j = 1; j <= 4; j++)
	{
        for(i = 1; i < n; i++) if(map[i][n] && c[i] == j) break;
        if(i == n)
		{
			c[n] = j;
			dfs(n+1);
            c[n] = 0;
        }
	}
}
int main()
{
	cin >> N;
	int i, j;
	for(i = 1; i <= N; i++) for(j = 1; j <= N; j++) cin >> map[i][j];
	dfs(1);
	cout << ans;
	return 0;
}