#include <iostream>
#include <string>
using namespace std;

const int maxq = 10000000,
		  maxn = 52;

struct Map {
	int x, y, c;
	Map& operator= (Map& a) { x = a.x; y = a.y; c = a.c; return *this; }
}q[maxq];

int map[maxn][maxn], R, C, n;
bool vis[maxn][maxn][1003];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int fx[1003];

void bfs() {
	int f = 0, l = 1;
	Map t;
	while(f != l) {
		if(q[f].c > n) { map[q[f].x][q[f].y] = 2; f++; continue; }
		t = q[f]; int w = fx[t.c];
		t.c = q[f].c + 1;
		while(1) {
			t.x += dx[w]; t.y += dy[w];
			if(t.x >= 1 && t.x <= R && t.y >= 1 && t.y <= C && map[t.x][t.y] != 1 && !vis[t.x][t.y][t.c]) {
				vis[t.x][t.y][t.c] = 1;
				q[l++] = t;
			}
			else break;
		}
		f++;
	}
}

int main() {
	cin >> R >> C;
	int i, j;
	char t;
	string str;
	for(i = 1; i <= R; ++i) for(j = 1; j <= C; ++j) {
		cin >> t;
		if(t == 'X') map[i][j] = 1;
		if(t == '*') q[0].x = i, q[0].y = j;
	}
	cin >> n;
	for(i = 1; i <= n; ++i) {
		cin >> str;
		if(str[0] == 'N') fx[i] = 0;
		else if(str[0] == 'S') fx[i] = 1;
		else if(str[0] == 'W') fx[i] = 2;
		else fx[i] = 3;
	}
	q[0].c = 1;
	bfs();
	for(i = 1; i <= R; ++i) {
		for(j = 1; j <= C; ++j) if(map[i][j] == 0) cout << '.'; else if(map[i][j] == 1) cout << 'X'; else cout << '*';
		cout << endl;
	}
	return 0;
}
