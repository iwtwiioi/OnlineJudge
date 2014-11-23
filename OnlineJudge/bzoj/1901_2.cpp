#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define lowbit(x) (x&-x)
#define read(x) x=getint()
#define rep(i, n) for(int i=0; i<n; ++i)
#define for1(i, a, n) for(int i=a; i<=(n); ++i)
#define MID (l+r)>>1
inline const int getint() { char c=getchar(); int k=1, r=0; for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
const int N=10005;
struct ND { int l, r, s; } t[N*200];
int tot, n, m, a[N], root[N], R[N], L[N], ans[N+N], cl, cr, cnt, QL[N], QR[N], K[N], num;
bool ask[N];
void update(const int &l, const int &r, int &pos, const int &key, const int &siz) {
	t[++tot]=t[pos]; t[tot].s+=siz; pos=tot;
	if(l==r) return;
	int m=MID;
	if(key<=m) update(l, m, t[pos].l, key, siz); else update(m+1, r, t[pos].r, key, siz);
}
inline void change(int x, const int &key, const int &siz) { for(; x<=n; x+=lowbit(x)) update(1, num, root[x], key, siz); }
int query(const int &l, const int &r, const int &k) {
	if(l==r) return l;
	int suml=0, sumr=0;
	for1(i, 1, cl) suml+=t[t[L[i]].l].s;
	for1(i, 1, cr) sumr+=t[t[R[i]].l].s;
	int s=sumr-suml, m=MID;
	if(k<=s) {
		for1(i, 1, cl) L[i]=t[L[i]].l;
		for1(i, 1, cr) R[i]=t[R[i]].l;
		return query(l, m, k);
	}
	else {
		for1(i, 1, cl) L[i]=t[L[i]].r;
		for1(i, 1, cr) R[i]=t[R[i]].r;
		return query(m+1, r, k-s);
	}
}
inline int getans(int l, int r, const int &k) {
	for(cl=0; l>0; l-=lowbit(l)) L[++cl]=root[l];
	for(cr=0; r>0; r-=lowbit(r)) R[++cr]=root[r];
	return query(1, num, k);
}
int main() {
	read(n); read(m); char c;
	for1(i, 1, n) read(a[i]), ans[++cnt]=a[i];
	for1(i, 1, m) {
		for(c=getchar(); c<'A'||c>'Z'; c=getchar());
		read(QL[i]); read(QR[i]);
		if(c=='Q') read(K[i]), ask[i]=1;
		else ans[++cnt]=QR[i];
	}
	sort(ans+1, ans+1+cnt); //咱们先离散，在这里用不着再开个域id了
	ans[cnt+1]=1000000013;
	for1(i, 1, cnt) if(ans[i]!=ans[i+1]) ans[++num]=ans[i]; //将重复的累起来，缩小主席树的区间
	for1(i, 1, n) a[i]=lower_bound(ans+1, ans+1+num, a[i])-ans; //查找原来数据在新数据的位置，这里可以直接覆盖了
	for1(i, 1, n) change(i, a[i], 1);
	for1(i, 1, m) {
		if(ask[i]) printf("%d\n", ans[getans(QL[i]-1, QR[i], K[i])]);
		else {
			change(QL[i], a[QL[i]], -1); //先将原来的剪掉
			a[QL[i]]=lower_bound(ans+1, ans+1+num, QR[i])-ans; //改变位置
			change(QL[i], a[QL[i]], 1); //再将新的加上
		}
	}

	return 0;
}