#include <cstdio>
using namespace std;
#define FOR(i, a, n) for(i=a;i<n;++i)
const int maxn = 105;
int imap[maxn][maxn], d[maxn][maxn], r, c, ans;

int max(const int& a, const int& b) { return a > b ? a : b; }

int dfs(int i, int j) {
	if(d[i][j]) return d[i][j];
	if((i > 1) && (imap[i][j] > imap[i-1][j])) d[i][j] = max(d[i][j], dfs(i-1, j)+1);
	if((i < r) && (imap[i][j] > imap[i+1][j])) d[i][j] = max(d[i][j], dfs(i+1, j)+1);
	if((j > 1) && (imap[i][j] > imap[i][j-1])) d[i][j] = max(d[i][j], dfs(i, j-1)+1);
	if((j < c) && (imap[i][j] > imap[i][j+1])) d[i][j] = max(d[i][j], dfs(i, j+1)+1);
	return d[i][j];
}

int main() {
	scanf("%d%d", &r, &c);
	int i, j;
	FOR(i, 1, r+1) FOR(j, 1, c+1) { scanf("%d", &imap[i][j]);}
	FOR(i, 1, r+1) FOR(j, 1, c+1) ans = max(ans, dfs(i, j));
	printf("%d", ans+1);
	return 0;
}
