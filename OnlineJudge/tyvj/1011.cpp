#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i,j) for(i=1;i<=j;i++)
const int MAX = 100;
int n, m, map[MAX][MAX], f[MAX][MAX][MAX];

int main()
{
	int i1, i2, j1, j2;
	cin >> n >> m;
	FOR(i1,n) FOR(j1,m) cin >> map[i1][j1];
	FOR(i1,n) FOR(j1,m) FOR(i2,n) 
	{
		j2 = i1 + j1 - i2;
		if((i1!=i2&&j1!=j2) || (i1==n&&j1==m&&i1==i2&&j1==j2))
			f[i1][j1][i2] = map[i1][j1] + map[i2][j2] +
					max(max(max(f[i1-1][j1][i2-1], f[i1-1][j1][i2]),
								f[i1][j1-1][i2-1]),f[i1][j1-1][i2]);
	}
	cout << f[n][m][n] << endl;
	return 0;
}


