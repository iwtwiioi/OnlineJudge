#include <cstdio>
using namespace std;

#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
#define MID (l+r)>>1
#define lc rt << 1
#define rc rt << 1 | 1

const int maxn = 2 * 10e5 + 10;
int col[maxn << 2], sum[maxn << 2], L, R;
int n, m;

void pushup(int rt) {
	sum[rt] = sum[lc] + sum[rc];
}

void pushdown(int rt, int m) {
	if(col[rt]) {
		col[lc] = 1;
		col[rc] = 1;
		sum[lc] = m - (m >> 1);
		sum[rc] = m >> 1;
		col[rt] = 0;
	}
}

void update(int l, int r, int rt) {
	if(L <= l && r <= R) {
		col[rt] = 1;
		sum[rt] = r-l+1;
		return;
	}
	pushdown(rt, r-l+1);
	int m = MID;
	if(L <= m) update(lson);
	if(m < R) update(rson);
	pushup(rt);
}

int query(int l, int r, int rt) {
	if(1 <= l && r <= n)
		return sum[rt];
	int m = MID, ret = 0;
	if(1 <= m) ret += query(lson);
	if(m < n) ret += query(rson);
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d%d", &L, &R);
		update(1, n, 1);
		printf("%d\n", n-query(1, n, 1));
	}
	
	return 0;
}