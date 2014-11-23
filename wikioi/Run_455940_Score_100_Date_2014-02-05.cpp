#include <iostream>
#include <cstring>
using namespace std;

struct Map {
	int m[4][4], x1, x2, y1, y2;
	int ans, who;
	Map& operator= (Map& a) { memcpy(m, a.m, sizeof(a.m)); x1=a.x1; x2=a.x2; y1=a.y1; y2=a.y2; ans=a.ans; who=a.who; return *this; }
}q[600009];
Map t;

const int mod = 40700017;
bool Hash[mod];

bool check(int f) {
	for(int i = 0; i < 4; ++i)
		if( (q[f].m[i][0]==q[f].m[i][1] && q[f].m[i][1]==q[f].m[i][2] && q[f].m[i][2]==q[f].m[i][3]) ||
			(q[f].m[0][i]==q[f].m[1][i] && q[f].m[1][i]==q[f].m[2][i] && q[f].m[2][i]==q[f].m[3][i]) )
			return true;
	if( (q[f].m[0][0]==q[f].m[1][1] && q[f].m[1][1]==q[f].m[2][2] && q[f].m[2][2]==q[f].m[3][3]) ||
		(q[f].m[0][3]==q[f].m[1][2] && q[f].m[1][2]==q[f].m[2][1] && q[f].m[2][1]==q[f].m[3][0]) )
		return true;
	return false;
}

void swap(int x, int y, int xx, int yy, int w) {
	t.m[x][y] = t.m[xx][yy];
	t.m[xx][yy] = 0;
	if(w == 1) t.x1 = xx, t.y1 = yy;
	else	   t.x2 = xx, t.y2 = yy;
	t.who = t.m[x][y];
}

bool hash(Map& s) {
	int i, j, k = 1, h = 0;
	for(i = 0; i < 4; ++i)
		for(j = 0; j < 4; ++j) {
			h += s.m[i][j] * k;
			k *= 3;
		}
	h %= mod;
	if(Hash[h]) return false;
	Hash[h] = 1;
	return true;
}

void bfs() {
	int f = 0, l = 1;
	int x1, y1, x2, y2;
	while(f != l) {
		if(check(f)) { cout << q[f].ans; break; }
		q[f].ans++;
		x1 = q[f].x1; y1 = q[f].y1; x2 = q[f].x2; y2 = q[f].y2;
		if(x1 > 0 && q[f].m[x1-1][y1] != q[f].who) { t = q[f]; swap(x1, y1, x1-1, y1, 1); if(hash(t)) q[l++] = t; }
		if(x1 < 3 && q[f].m[x1+1][y1] != q[f].who) { t = q[f]; swap(x1, y1, x1+1, y1, 1); if(hash(t)) q[l++] = t; }
		if(y1 > 0 && q[f].m[x1][y1-1] != q[f].who) { t = q[f]; swap(x1, y1, x1, y1-1, 1); if(hash(t)) q[l++] = t; }
		if(y1 < 3 && q[f].m[x1][y1+1] != q[f].who) { t = q[f]; swap(x1, y1, x1, y1+1, 1); if(hash(t)) q[l++] = t; }
		if(x2 > 0 && q[f].m[x2-1][y2] != q[f].who) { t = q[f]; swap(x2, y2, x2-1, y2, 2); if(hash(t)) q[l++] = t; }
		if(x2 < 3 && q[f].m[x2+1][y2] != q[f].who) { t = q[f]; swap(x2, y2, x2+1, y2, 2); if(hash(t)) q[l++] = t; }
		if(y2 > 0 && q[f].m[x2][y2-1] != q[f].who) { t = q[f]; swap(x2, y2, x2, y2-1, 2); if(hash(t)) q[l++] = t; }
		if(y2 < 3 && q[f].m[x2][y2+1] != q[f].who) { t = q[f]; swap(x2, y2, x2, y2+1, 2); if(hash(t)) q[l++] = t; }
		f++;
	}
}

int main() {
	char t; bool ok = 1;
	for(int i = 0; i < 4; ++i) for(int j = 0; j < 4; ++j) {
		cin >> t;
		switch(t) {
		case 'B': q[0].m[i][j] = 2; break;
		case 'W': q[0].m[i][j] = 1; break;
		case 'O': q[0].m[i][j] = 0;
				  if(ok) q[0].x1 = i, q[0].y1 = j, ok = 0;
				  else	 q[0].x2 = i, q[0].y2 = j;
				  break;
		}
	}
	bfs();
	return 0;
}
