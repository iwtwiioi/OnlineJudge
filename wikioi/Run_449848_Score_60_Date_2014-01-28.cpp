#include <cstdio>
using namespace std;

#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
#define MID ((l+r) >> 1)
#define lc rt << 1
#define rc rt << 1 | 1

const int maxn = 200000 + 10;
int sum[maxn << 1], add[maxn << 1], L, R, _add;

void pushup(int rt) {
	sum[rt] = sum[lc] + sum[rc];
}

void pushdown(int rt, int m) {
	if(add[rt]) {
		add[lc] += add[rt];
		add[rc] += add[rt];
		sum[lc] += add[rt] * (m-(m >> 1));
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

int query(int l, int r, int rt) {
	if(L <= l && r <= R)
		return sum[rt];
	pushdown(rt, r-l+1);
	int m = MID, ret = 0;
	if(L <= m) ret += query(lson);
	if(m < R) ret += query(rson);
	return ret;
}

int main() {
	int n, q, t;
	scanf("%d", &n);
	build(1, n, 1);
	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
		scanf("%d%d%d", &t, &L, &R);
		if(t == 1) { scanf("%d", &_add); update(1, n, 1); }
		else printf("%d\n", query(1, n, 1));
	}
	
	return 0;
}