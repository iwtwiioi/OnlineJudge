#include <iostream>

using namespace std;
const int MAXN = 12;
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
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			for(k = 1; k <= n; k++)
				if((i==n&&j==n&&k==n) || (i!=k&&j!=i+j-k))
					f[i][j][k] =
						max(max(max(f[i-1][j][k], f[i-1][j][k-1]),f[i][j-1][k]), f[i][j-1][k-1])
						+ map[i][j] + map[k][i+j-k];
	cout << f[n][n][n];

	return 0;
}
