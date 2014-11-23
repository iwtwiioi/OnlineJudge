#include <cstdio>
using namespace std;
#define FOR(i, a, n) for(i=a;i<=n;++i)
const int maxn = 1010, oo = 10000000;
int n, f[maxn][maxn][2], R, M, r[maxn], m[maxn], t[maxn];

int main() {
	scanf("%d", &n);
	int i, j, k;
	FOR(i, 1, n) scanf("%d%d%d", &m[i], &r[i], &t[i]);
	scanf("%d%d", &M, &R);
	//这里有两个最的约束，所以我们要分别背包
	//f[i][j][0]表示最多能泡到的数量，f[i][j][1]在最多的前提下最少的钱
	FOR(i, 1, n)
		for(j = M; j >= m[i]; --j) 
			for(k = R; k >= r[i]; --k)
				if( (f[j][k][0] < f[j-m[i]][k-r[i]][0] + 1) ||
					(f[j][k][0] == f[j-m[i]][k-r[i]][0] + 1 && 
					 f[j][k][1] > f[j-m[i]][k-r[i]][1] + t[i]) )
					f[j][k][0] = f[j-m[i]][k-r[i]][0] + 1,
					f[j][k][1] = f[j-m[i]][k-r[i]][1] + t[i];
	printf("%d\n", f[M][R][1]);
	return 0;
}

