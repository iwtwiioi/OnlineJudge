#include <cstdio>
using namespace std;
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
#define MID (l+r)>>1
#define lc rt << 1
#define rc rt << 1 | 1

int min(const int& a, const int& b){return a < b ? a : b;}

const int maxn = 1e6+10;
int sum[maxn << 2], add[maxn << 2], n, m, L, R, _add;
bool ok;

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


bool update(int l, int r, int rt) {
	if(L <= l && r <= R) {
		add[rt] += _add;
		sum[rt] += (_add * (r-l+1));
//		printf("l:%d r:%d rt:%d sum:%d add:%d\n", l, r, rt, sum[rt], add[rt]);
		if(sum[rt] < 0) return 1;
		return 0;
	}
	pushdown(rt, r-l+1);
	int m = MID;
	bool a = 0, b = 0;
	if(L <= m) a = update(lson);
	if(m < R) b = update(rson);
	pushup(rt);
	return a || b;
}

int main() {
	scanf("%d%d", &n, &m);
	build(1, n, 1);
	int i;
	for(i = 1; i <= m; ++i) {
		scanf("%d%d%d", &_add, &L, &R);
		_add = -_add;
		if(update(1, n, 1)) { printf("-1\n%d", i); return 0;}
	}
	if(!ok) printf("0");
	return 0;
}
