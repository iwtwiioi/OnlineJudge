#include <iostream>
#include <cstdio>
using namespace std;

#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
#define MID ((l+r) >> 1)
#define lc rt << 1
#define rc rt << 1 | 1

const int maxn = 10e5 + 10;
int add[maxn << 1], L, R, _add;

void pushdown(int rt, int m) {
	if(add[rt]) {
		add[lc] += add[rt];
		add[rc] += add[rt];
		add[rt] = 0;
	}
}

void build(int l, int r, int rt) {
	if(l == r) {
		scanf("%d", &add[rt]);
		return;
	}
	int m = MID;
	build(lson); build(rson);
}

void update(int l, int r, int rt) {
	if(L <= l && r <= R) {
		add[rt] += _add;
		return;
	}
	pushdown(rt, r-l+1);
	int m = MID;
	if(L <= m) update(lson);
	if(m < R) update(rson);
}

void query(int l, int r, int rt) {
	if(l == r) {
		printf("%d\n", add[rt]);
		return;
	}
	pushdown(rt, r-l+1);
	int m = MID;
	if(L <= m) query(lson);
	else query(rson);
}

int main() {
	int n, q, t;
	cin >> n;
	build(1, n, 1);
	cin >> q;
	for(int i = 0; i < q; ++i) {
		cin >> t >> L;
		if(t == 1) { cin >> R >> _add; update(1, n, 1); }
		else query(1, n, 1);
	}
	
	return 0;
}