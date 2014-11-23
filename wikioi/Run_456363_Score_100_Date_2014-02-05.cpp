#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MOD = 47000011, ans = 12893741;
bool Hash[MOD];

struct state {
	int m[3][3], n;
	int x, y;
	state& operator= (state& a) { memcpy(m, a.m, sizeof(m)); x = a.x; y = a.y; n = a.n; return *this; }
}t, q[1000000];

int hash(state& s) {
	int i, j, k = 1, h = 0;
	for(i = 0; i < 3; ++i) for(j = 0; j < 3; ++j) h = (h + k*s.m[i][j])%MOD, k *= 9;
	return h;
}

bool chash() {
	int h = hash(t);
	if(Hash[h]) return 0;
	Hash[h] = 1;
	return 1;
}

void swap(int x, int y, int xx, int yy) {
	t.m[x][y] = t.m[xx][yy];
	t.m[xx][yy] = 0;
	t.x = xx, t.y = yy;
}

void bfs() {
	int f = 0, l = 1, x, y;
	while(f != l) {
		if(hash(q[f]) == ans) { cout << q[f].n; return; }
		q[f].n++;
		x = q[f].x; y = q[f].y;
		if(x > 0) { t = q[f]; swap(x, y, x-1, y); if(chash()) q[l++] = t; }
		if(x < 2) { t = q[f]; swap(x, y, x+1, y); if(chash()) q[l++] = t; }
		if(y > 0) { t = q[f]; swap(x, y, x, y-1); if(chash()) q[l++] = t; }
		if(y < 2) { t = q[f]; swap(x, y, x, y+1); if(chash()) q[l++] = t; }
		f++;
	}
}

int main() {
	int i, j;
	string str; cin >> str; int c = 0;
	for(i = 0; i < 3; ++i) for(j = 0; j < 3; ++j) {
		if(str[c] == '0') q[0].x = i, q[0].y = j;
		q[0].m[i][j] = str[c++]-'0';
	}
	bfs();
	return 0;
}
