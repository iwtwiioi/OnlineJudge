#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int maxq = 10000000,
		  maxn = 52;

struct Map {
	int x, y, c;
	Map& operator= (Map& a) { x = a.x; y = a.y; c = a.c; return *this; }
}q[maxq];

int map[maxn][maxn], R, C, n;
bool vis[maxn][maxn][1001];
enum en{N, S, W, E};
en fx[1001];

void bfs() {
	int f = 0, l = 1, x, y, c;
	Map t;
	while(f != l) {
		x = q[f].x; y = q[f].y; c = q[f].c;
		if(c > n) { map[x][y] = 2; f++; continue; }
		q[f].c++;
		if(fx[c] == N) {
			t = q[f];
			while(t.x > 0 && map[t.x-1][y] != 1 && !vis[t.x-1][y][t.c]) {
				t.x--;
				q[l++] = t;
			}
		}
		if(fx[c] == S) {
			t = q[f];
			while(t.x < R && map[t.x+1][y] != 1 && !vis[t.x+1][y][t.c]) {
				t.x++;
				if(!vis[t.x][y][t.c]) q[l++] = t;
			}
		}
		if(fx[c] == W) {
			t = q[f];
			while(t.y > 0 && map[x][t.y-1] != 1 && !vis[x][t.y-1][t.c]) {
				t.y--;
				if(!vis[x][t.y][t.c]) q[l++] = t;
			}
		}
		if(fx[c] == E) {
			t = q[f];
			while(t.y < C && map[x][t.y+1] != 1 && !vis[x][t.y+1][t.c]) {
				t.y++;
				if(!vis[x][t.y][t.c]) q[l++] = t;
			}
		}
		f++;
	}
}

int main() {
	cin >> R >> C;
	int i, j;
	char t;
	string str;
	for(i = 0; i < R; ++i) for(j = 0; j < C; ++j) {
		cin >> t;
		if(t == 'X') map[i][j] = 1;
		if(t == '*') q[0].x = i, q[0].y = j;
	}
	cin >> n;
	for(i = 1; i <= n; ++i) {
		cin >> str;
		if(str[0] == 'N') fx[i] = N;
		else if(str[0] == 'S') fx[i] = S;
		else if(str[0] == 'W') fx[i] = W;
		else fx[i] = E;
	}
	q[0].c = 1;
	bfs();
	for(i = 0; i < R; ++i) {
		for(j = 0; j < C; ++j) if(map[i][j] == 0) cout << '.'; else if(map[i][j] == 1) cout << 'X'; else cout << '*';
		cout << endl;
	}
	return 0;
}
