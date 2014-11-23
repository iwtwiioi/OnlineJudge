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

void update(int L, int R, int key, int l, int r, int rt){
	if(L <= l && r <= R){
		sum[rt] += key;
		return;
	}
	int m = MID;
	if(L <= m) update(L, R, key, lson);
	if(m < R) update(L, R, key, rson);
	pushUp(rt);
}

int main(){
	int n, m, a, b, c, x;
	scanf("%d", &n);
	build(1, n, 1);
	scanf("%d", &m);
	for(int i = 0; i < m; ++i){
		scanf("%d%d", &c, &a);
		if(c == 1) {scanf("%d%d", &b, &x);update(a, b, x, 1, n, 1);}
		else printf("%d\n", sum[a]);
	}
	return 0;
}
