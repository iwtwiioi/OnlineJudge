#include <cstdio>
using namespace std;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define MID (l+r) >> 1
#define lc rt << 1
#define rc rt << 1 | 1
#define min(a,b) ((a)<(b)?(a):(b))

const int maxn = 10000005, oo=1000000000;
int sum[maxn], t, k, L, R;

void pushup(int rt) {
	sum[rt]=min(sum[lc], sum[rc]);
}

void build(int l, int r, int rt) {
	if(l==r) {
		scanf("%d", &sum[rt]);
		return;
	}
	int m=MID;
	build(lson); build(rson);
	pushup(rt);
}

void updata(int l, int r, int rt) {
	if(l==r) {
		sum[rt]=k;
		return;
	}
	int m=MID;
	if(t<=m) updata(lson);
	else updata(rson);
	pushup(rt);
}

int ask(int l, int r, int rt) {
	if(L<=l && r<=R) return sum[rt];
	int m=MID, ret=oo;
	if(L<=m) ret=min(ret, ask(lson));
	if(m<R) ret=min(ret, ask(rson));
	return ret;
}

int main(){
	int n, m, a, b, c;
	scanf("%d%d", &n, &m);
	build(1, n, 1);
	for(int i=0; i<m; ++i){
		scanf("%d%d%d", &c, &a, &b);
		if(c==1) {
			L=a; R=b;
			printf("%d ", ask(1, n, 1));
		}
		else {
			t=a; k=b;
			updata(1, n, 1);
		}
	}
	return 0;
}
