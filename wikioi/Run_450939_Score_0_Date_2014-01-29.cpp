#include <cstdio>
using namespace std;
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
#define MID (l+r)>>1
#define lc rt << 1
#define rc rt << 1 | 1

const int maxn = 1000000+10;
int sum[maxn << 2], add[maxn << 2], n, m, L, R, _add;

void pushup(int rt) {
	sum[rt] = sum[lc] + sum[rc];
}

void pushdown(int rt, int m) {
	if(add[rt]) { 
		add[lc] += add[rt];
		add[rc] += add[rt];
		sum[lc] += add[rt] * (m - (m >> 1)); 
		sum[rc] += add[rt] * (m >> 1);
		add[rt] = 0; 
	}
}

void build(int l, int r, int rt) {
	add[rt] = 0; 
	if(l == r) {
		scanf("%d", &sum[rt]);
		return;
	}
	int m = MID;
	build(lson); build(rson);
	pushup(rt);
}

void update(int l, int r, int rt) {
	if(L <= l && r <= R) {
		add[rt] += _add; 
		sum[rt] += _add * (r-l+1);
		return;
	}
	pushdown(rt, r-l+1); 
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
		if(sum[1] < 0) { printf("-1\n%d", i); return 0;}
	}
	printf("0");
	return 0;
}

			