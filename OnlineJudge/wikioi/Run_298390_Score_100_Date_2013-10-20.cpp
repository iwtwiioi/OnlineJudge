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
    for(i = 1; i <= n; i++)
        F[i][0] = A[1][i];
	for(k = 1; k <= m; k++)
		for(i = k+1; i <= n; i++)
			for(j = i-1; j >= k; j--)
				F[i][k] = max(F[i][k], A[j+1][i]*F[j][k-1]);
	cout << F[n][m] << endl;
	return 0;
}