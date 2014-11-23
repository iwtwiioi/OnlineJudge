#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m, i, j, k;
const int MAXK = 10;
const int MAXN = 100;
int c[MAXN] = {0}, A[MAXN][MAXN] = {{0,0}}, F[MAXN][MAXK] = {{0,0}};
int makeConut(int x, int y)
{
	int ans = 0;
	while(x <= y) ans = ans * 10 + c[x++];
	return ans;
}

int main()
{
	string str;
	cin >> n >> m;
	cin >> str;
	for(i = 1; i <= n;i++) c[i] = (str[i-1]-'0');
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			A[i][j] = makeConut(i, j);
    //f[n,k]=max{f[n-1,k-1]*c[n,n],  f[n-2,k-1]*c[n-1,n],  .......  , f[k,k-1]*c[k+1,n]}
	//初始化k为1时的状态
    //f[n,1]=max{c[1,1]*c[2,n],  c[1,2]*c[3,n],  ……  ,  c[1,n-1]*c[n,n]}
   // F[1][1] = A[1][1];
    for(i = 2; i <= n; i++)
		for(j = 1; j < i; j++)
            F[i][1] = max(F[i][1], A[1][j]*A[j+1][i]);
	for(k = 2; k <= m; k++)
		for(i = k+1; i <= n; i++)
			for(j = i-1; j >= k; j--)
				F[i][k] = max(F[i][k], A[j+1][i]*F[j][k-1]);
	cout << F[n][m] << endl;
	return 0;
}
