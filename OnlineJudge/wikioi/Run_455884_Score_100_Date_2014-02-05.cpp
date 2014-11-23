#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct Map {
	int m[4][4], x1, x2, y1, y2;
	int ans, who;
	Map() : x1(0), x2(0), y1(0), y2(0), ans(0), who(-1) { memset(m, 0, sizeof(m)); }
	Map& operator= (Map& a) { memcpy(m, a.m, sizeof(a.m)); x1=a.x1; x2=a.x2; y1=a.y1; y2=a.y2; ans=a.ans; who=a.who; return *this; }
}q[600009];

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

void swap(int p, int x, int y, int xx, int yy, int w) {
	q[p].m[x][y] = q[p].m[xx][yy];
	q[p].m[xx][yy] = 0;
	if(w == 1) q[p].x1 = xx, q[p].y1 = yy;
	else	   q[p].x2 = xx, q[p].y2 = yy;
	q[p].who = q[p].m[x][y];
}

void bfs() {
	int f = 0, l = 1;
	int x1, y1, x2, y2;
	while(f != l) {
		if(check(f)) { cout << q[f].ans; break; }
		q[f].ans++;
		x1 = q[f].x1; y1 = q[f].y1; x2 = q[f].x2; y2 = q[f].y2;
		if(x1 > 0 && q[f].m[x1-1][y1] != q[f].who) { q[l] = q[f]; swap(l, x1, y1, x1-1, y1, 1); l++; }
		if(x1 < 3 && q[f].m[x1+1][y1] != q[f].who) { q[l] = q[f]; swap(l, x1, y1, x1+1, y1, 1); l++; }
		if(y1 > 0 && q[f].m[x1][y1-1] != q[f].who) { q[l] = q[f]; swap(l, x1, y1, x1, y1-1, 1); l++; }
		if(y1 < 3 && q[f].m[x1][y1+1] != q[f].who) { q[l] = q[f]; swap(l, x1, y1, x1, y1+1, 1); l++; }
		if(x2 > 0 && q[f].m[x2-1][y2] != q[f].who) { q[l] = q[f]; swap(l, x2, y2, x2-1, y2, 2); l++; }
		if(x2 < 3 && q[f].m[x2+1][y2] != q[f].who) { q[l] = q[f]; swap(l, x2, y2, x2+1, y2, 2); l++; }
		if(y2 > 0 && q[f].m[x2][y2-1] != q[f].who) { q[l] = q[f]; swap(l, x2, y2, x2, y2-1, 2); l++; }
		if(y2 < 3 && q[f].m[x2][y2+1] != q[f].who) { q[l] = q[f]; swap(l, x2, y2, x2, y2+1, 2); l++; }
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
