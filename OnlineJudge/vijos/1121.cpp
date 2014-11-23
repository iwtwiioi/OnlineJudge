#include <cstdio>
using namespace std;

const int maxn = 40;
int f[maxn][maxn], i, j, n, m, x, y;
bool map[maxn][maxn];

int main() {
	scanf("%d%d%d%d", &n, &m, &x, &y);
	n += 2; m += 2; x += 2; y += 2;
	map[x][y]=map[x-1][y-2]=map[x-1][y+2]=map[x+1][y-2]=map[x+1][y+2]=map[x+2][y-1]=map[x-2][y-1]=map[x+2][y+1]=map[x-2][y+1]=1;
	f[2][2] = 1;
	for(i = 2; i <= n; ++i) 
		for(j = 2; j <= m; ++j) 
			if(i == 2 && j == 2) continue;
			else if(!map[i][j]) 
				f[i][j] = f[i-1][j] + f[i][j-1];
	printf("%d", f[n][m]);
	return 0;
}
