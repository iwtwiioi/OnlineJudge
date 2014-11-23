#include <cstdio>
using namespace std;
const int MAXN = 100;
const int INF = 1000000000;
int n, d[MAXN][MAXN], q, u, v;
int i, j, k;
int main()
{
	scanf("%d", &n);
	for(i = 0; i < n; i++)for(j = 0; j < n; j++) d[i][j] = INF;
	for(i = 0; i < n; i++)for(j = 0; j < n; j++) scanf("%d",&d[i][j]);
	for(k = 0; k < n; k++)
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				if(d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
	scanf("%d", &q);
	for(i = 0; i < q; i++)
	{
		scanf("%d%d",&u,&v);
		printf("%d\n",d[u-1][v-1]);
	}
	return 0;
}