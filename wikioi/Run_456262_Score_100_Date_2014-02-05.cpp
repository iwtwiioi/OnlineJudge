#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 17;
int map[maxn][maxn], m, n;
struct nod {
	int x, y;
	nod(int _x = 0, int _y = 0) : x(_x), y(_y) {}
}s;
queue<nod> q;
bool vis[maxn][maxn];

int main() {
	cin >> m;
	int i, j, x, y, ok;
	char t;
	while(m--) {
		cin >> n;
		memset(vis, 0, sizeof(vis));
		while(!q.empty()) q.pop();
		for(i = 1; i <= n; ++i) for(j = 1; j <= n; ++j) { cin >> t; if(t == '#') map[i][j] = 1; }
		q.push(nod(1, 1));
		ok = 1;
		while(!q.empty()) {
			s = q.front(); q.pop();
			x = s.x, y = s.y;
			if(x == n && y == n) { cout << "YES\n"; ok = 0; break; }
			if(x > 1 && !vis[x-1][y] && !map[x-1][y]) { q.push(nod(x-1, y)); vis[x-1][y] = 1; }
			if(x < n && !vis[x+1][y] && !map[x+1][y]) { q.push(nod(x+1, y)); vis[x+1][y] = 1; }
			if(y > 1 && !vis[x][y-1] && !map[x][y-1]) { q.push(nod(x, y-1)); vis[x][y-1] = 1; }
			if(y < n && !vis[x][y+1] && !map[x][y+1]) { q.push(nod(x, y+1)); vis[x][y+1] = 1; }
		}
		if(ok) cout << "NO\n";
	}
	return 0;
}