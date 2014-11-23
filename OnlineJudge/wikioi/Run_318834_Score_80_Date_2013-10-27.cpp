#include <iostream>

using namespace std;
const int MAXN = 14;
int map[MAXN][MAXN];
int f[MAXN][MAXN][MAXN];
//x1+y1=x2+y2,所以y2=x1+y1-x2，所以可以少开一维
int main()
{
	int n;
	cin >> n;
	int x, y, c;
	while(cin >> x >> y >> c)
		if(!x&&!y&&!c) break;
		else  map[x][y] = c;
	int i, j, k;
	//四种可能：
	f[1][1][1] = map[1][1]; //注意初始化，太坑了
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			for(k = 1; k <= n; k++)
				if(i!=k&&j!=i+j-k)
					f[i][j][k] = map[i][j] + map[k][i+j-k] +
					max(max(max(f[i-1][j][k], f[i-1][j][k-1]),
								f[i][j-1][k]),f[i][j-1][k-1]);
	f[n][n][n] = map[n][n] +
			max(max(max(f[n-1][n][n], f[n-1][n][n-1]),
						f[n][n-1][n]),f[n][n-1][n-1]);
	cout << f[n][n][n];

	return 0;
}
