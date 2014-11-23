#include <iostream>

using namespace std;
const int MAXN = 14;
int map[MAXN][MAXN];
int f[MAXN][MAXN][MAXN][MAXN];
//x1+y1=x2+y2,所以y2=x1+y1-x2，所以可以少开一维
int main()
{
	int n;
	cin >> n;
	int x, y, c;
	while(cin >> x >> y >> c)
		if(!x&&!y&&!c) break;
		else  map[x][y] = c;
	int i1, j1, i2, j2;
	//四种可能：
	for(i1 = 1; i1 <= n; i1++)
		for(j1 = 1; j1 <= n; j1++)
			for(i2 = 1; i2 <= n; i2++)
				for(j2 = 1; j2 <= n; j2++)
				{
					f[i1][j1][i2][j2] = map[i1][j1] +
							max(max(max(f[i1-1][j1][i2][j2-1], f[i1-1][j1][i2-1][j2]),
										f[i1][j1-1][i2][j2-1]),f[i1][j1-1][i2-1][j2]);
						if(i1!=i2&&j1!=j2)
							f[i1][j1][i2][j2] += map[i2][j2];
				}
	cout << f[n][n][n][n];

	return 0;
}
