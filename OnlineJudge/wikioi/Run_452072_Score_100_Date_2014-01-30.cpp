#include <cstdio>
using namespace std;

#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
#define MID (l+r) >> 1
#define lc rt << 1
#define rc rt << 1 | 1

const int maxn = 30000 + 10;
int n, m, sum[maxn << 2];

void pushup(int rt) {
	sum[rt] = sum[lc] + sum[rc];
}

void build(int l, int r, int rt) {
	if(l == r) {
		sum[rt] = 1;
		return;
	}
	int m = MID;
	build(lson); build(rson);
	pushup(rt);
}

void update(int p, int l, int r, int rt) {
	sum[rt]--;
    if(l == r) {
        printf("%d ", l);
        return;
    }
	int m = MID;
	if(p <= sum[lc]) update(p, lson);
	else update(p-sum[lc], rson);
    pushup(rt);
}

int main(){
	scanf("%d%d", &n, &m);
    build(1, n, 1);
    int seq = 1;
	for(int i = 1; i <= n; ++i) {
		seq = (seq + m - 1) % sum[1];
		if(!seq) seq = sum[1];
		update(seq, 1, n, 1);
	}
	return 0;
}


