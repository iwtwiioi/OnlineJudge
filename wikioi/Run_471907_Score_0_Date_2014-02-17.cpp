#include <iostream>
#include <cstdio>
using namespace std;

#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
#define MID (l+r) >> 1
#define lc rt << 1
#define rc rt << 1 | 1

typedef long long ll;

const int maxn = 100000;
ll sum[maxn << 2], add[maxn << 2], L, R, _add;

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
		scanf("%lld", &sum[rt]);
		return;
	}
	int m = MID;
	build(lson); build(rson);
	pushup(rt);
}

void update(int l, int r, int rt) {
	if(L <= l && r <= R) {
		sum[rt] += _add;
		add[rt] += _add;
		return;
	}
	pushdown(rt, r-l+1);
	int m = MID;
	if(L <= m) update(lson);
	if(m < R) update(rson);
	pushup(rt);
}

ll query(int l, int r, int rt) {
	if(L <= l && r <= R) return sum[rt];
	int m = MID;
	ll ret = 0;
	pushdown(rt, r-l+1);
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
		scanf("%d%lld%lld", &t, &L, &R);
		if(t == 1) { scanf("%lld", &_add); update(1, n, 1); }
		else printf("%lld\n", query(1, n, 1));
	}
	
	return 0;
}