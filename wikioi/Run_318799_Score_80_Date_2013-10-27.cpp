#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i,j) for(i=1;i<=j;i++)
const int MAXN = 110;
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
	int i1, i2, j1, j2;
	//四种可能：
	FOR(i1,n) FOR(j1,n) FOR(i2,n) 
	{
		j2 = i1 + j1 - i2;
		if((i1!=i2&&j1!=j2) || (i1==n&&j1==n&&i1==i2&&j1==j2))
			f[i1][j1][i2] = map[i1][j1] + map[i2][j2] +
					max(max(max(f[i1-1][j1][i2-1], f[i1-1][j1][i2]),
								f[i1][j1-1][i2-1]),f[i1][j1-1][i2]);
	}
	cout << f[n][n][n];

	return 0;
}
