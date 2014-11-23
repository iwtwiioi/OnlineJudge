#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i,j) for(i=1;i<=(j);i++)
const int MAXN = 60, MAXM = 60;
int n, m, map[MAXN][MAXM], f[MAXN][MAXM][MAXN][MAXM];

int main()
{
	int i1, i2, j1, j2;
	cin >> n >> m;
	FOR(i1,n) FOR(j1,m) cin >> map[i1][j1];
	FOR(i1,n) FOR(j1,m) FOR(i2,n) FOR(j2,m)
		if((i1!=i2&&j1!=j2) || (i1==n&&j1==m&&i1==i2&&j1==j2))
			f[i1][j1][i2][j2] = map[i1][j1] + map[i2][j2] +
					max(max(max(f[i1-1][j1][i2-1][j2], f[i1-1][j1][i2][j2-1]),
								f[i1][j1-1][i2-1][j2]),f[i1][j1-1][i2][j2-1]);
	cout << f[n][m][n][m] << endl;
	return 0;
}

