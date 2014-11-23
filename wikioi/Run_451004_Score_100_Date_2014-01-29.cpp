#include <cstdio>
using namespace std;
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
#define MID (l+r)>>1
#define lc rt << 1
#define rc rt << 1 | 1

int min(const int& a, const int& b){return a < b ? a : b;}

const int maxn = 1e6+10;
int minx[maxn << 2], add[maxn << 2], n, m, L, R, _add;

void pushup(int rt) {
	minx[rt] = min(minx[lc], minx[rc]);
}

void pushdown(int rt) {
	if(add[rt]) {
		add[lc] += add[rt];
		add[rc] += add[rt];
		minx[lc] += add[rt];
		minx[rc] += add[rt];
		add[rt] = 0;
	}
}

void build(int l, int r, int rt) {
	add[rt] = 0;
	if(l == r) {
		scanf("%d", &minx[rt]);
		return;
	}
	int m = MID;
	build(lson); build(rson);
	pushup(rt);
}

void update(int l, int r, int rt) {
	if(L <= l && r <= R) {
		add[rt] += _add;
		minx[rt] += _add;
		return;
//		printf("l:%d r:%d rt:%d sum:%d add:%d\n", l, r, rt, sum[rt], add[rt]);
	}
	pushdown(rt);
	int m = MID;
	if(L <= m) update(lson);
	if(m < R) update(rson);
	pushup(rt);
}

int main() {
	scanf("%d%d", &n, &m);
	build(1, n, 1);
	int i;
	for(i = 1; i <= m; ++i) {
		scanf("%d%d%d", &_add, &L, &R);
		_add = -_add;
		update(1, n, 1);
		if(minx[1] < 0) { printf("-1\n%d", i); return 0;}
	}
	printf("0");
	return 0;
}
