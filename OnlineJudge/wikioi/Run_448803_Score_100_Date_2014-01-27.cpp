#include <cstdio>
using namespace std;

#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
#define MID ((l+r)>>1)
#define lc rt << 1
#define rc rt << 1 | 1

const int maxn = 10e5 + 10;
int sum[maxn];

void pushUp(int rt){
	sum[rt] = sum[lc] + sum[rc];
}

void build(int l, int r, int rt){
	if(l == r){
		scanf("%d", &sum[rt]);
		return;
	}
	int m = MID;
	build(lson); build(rson);
	pushUp(rt);
}

void update(int p, int key, int l, int r, int rt){
	if(l == r){
		sum[rt] += key;
		return;
	}
	int m = MID;
	if(p <= m) update(p, key, lson);
	else update(p, key, rson);
	pushUp(rt);
}

int query(int L, int R, int l, int r, int rt){
	if(L <= l && r <= R) return sum[rt];
	int m = MID, ret = 0;
	if(L <= m) ret += query(L, R, lson);
	if(m+1 <= R) ret += query(L, R, rson);
	return ret;
}

int main(){
	int n, m, a, b, c;
	scanf("%d", &n);
	build(1, n, 1);
	scanf("%d", &m);
	for(int i = 0; i < m; ++i){
		scanf("%d%d%d", &c, &a, &b);
		if(c == 1) update(a, b, 1, n, 1);
		else printf("%d\n", query(a, b, 1, n, 1));
	}
	return 0;
}
