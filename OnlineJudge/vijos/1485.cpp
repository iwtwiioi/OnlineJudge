#include <cstdio>
using namespace std;

const int MAX = 40;
int i, j, n, m, f[MAX][MAX];
int main() {
	scanf("%d%d", &n, &m);
	f[0][0] = 1;
	for(i = 1; i <= m; ++i) for(j = 0; j < n; ++j) {
		if(j == n-1) f[j][i] = f[j-1][i-1] + f[0][i-1];
		else if(j == 0) f[j][i] = f[n-1][i-1] + f[1][i-1];
		else f[j][i] = f[j-1][i-1] + f[j+1][i-1];
	}
	printf("%d", f[0][m]);
	return 0;
}
