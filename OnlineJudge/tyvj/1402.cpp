#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 352;
const int MAX = 41;
int n, m, d[MAX][MAX][MAX][MAX]={{{{0}}}}, a[MAXN], p[5];
int i, j, k, l;
int main()
{
	cin >> n >> m;
	//read
	for(i = 1; i <= n; i++) cin >> a[i];
	for(i = 1; i <= m; i++) {cin >> j; p[j]++;}
	d[0][0][0][0]=a[1];
    for(i=0;i<=p[1];i++)
		for(j=0;j<=p[2];j++)
			for(k=0;k<=p[3];k++)
				for(l=0;l<=p[4];l++)
				{
        			if(!i&&!j&&!k&&!l) continue;
					if(i)d[i][j][k][l]=d[i-1][j][k][l];
					if(j&&d[i][j-1][k][l]>d[i][j][k][l])d[i][j][k][l]=d[i][j-1][k][l];
					if(k&&d[i][j][k-1][l]>d[i][j][k][l])d[i][j][k][l]=d[i][j][k-1][l];
					if(l&&d[i][j][k][l-1]>d[i][j][k][l])d[i][j][k][l]=d[i][j][k][l-1];
					d[i][j][k][l]+=a[i+j*2+k*3+l*4+1];
				}
	cout << d[i-1][j-1][k-1][l-1] << endl;
	return 0;
}

