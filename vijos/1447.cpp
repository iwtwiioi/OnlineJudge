#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,(a),sizeof(i))
#define read(a) a=getint()
#define print(a) printf("%d", a)
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }
 
const int N=100005;
int f[11][N+5], tp1[N+5], tp2[N+5], tp3[N+5], tp4[N+5], Ten[N+5], One[N+5], Two[N+5];
char s[N+5];
void Plus(int *a, int *b, int *c);
void Print(int *a);
inline void fix1(int *a, int len) { while(len>1 && !a[len]) --len; a[0]=len; }
inline void fix2(int *a, int *b, int *c) { c[N]=(a[N]^b[N])&&(!(c[0]==1 && c[1]==0)); }
inline void upd(int *a) { memset(a, 0, sizeof(int)*(a[0]+1)); a[0]=1; }
inline void Init() { Ten[0]=2; Ten[2]=1; One[0]=One[1]=1; Two[0]=1; Two[1]=2; }
bool cmp(int *a, int *b) {
	if(a[N]^b[N]) return a[N];
	if(a[N]==1) swap(a, b);
	if(a[0]<b[0]) return 1; else if(a[0]>b[0]) return 0;
	for3(i, a[0], 1) if(a[i]<b[i]) return 1; else if(a[i]>b[i]) return 0;
	return 0;
}
void Minus(int *a, int *b, int *c) {
	int i, flag=0;
	if(a[N] && b[N]) { b[N]=a[N]=0; Minus(b, a, c); b[N]=a[N]=1; return; }
	if(b[N]) { b[N]=0; Plus(a, b, c); b[N]=1; return; }
	if(a[N]) { b[N]=1; Plus(a, b, c); b[N]=0; return; }
	if(cmp(a, b)) flag=1, swap(a, b);
	upd(c);
	for(i=1; i<=a[0]; ++i) {
		c[i]+=a[i]-b[i];
		while(c[i]<0) c[i]+=10, c[i+1]-=1;
	}
	fix1(c, i); if(flag) c[N]=1;
}
void Plus(int *a, int *b, int *c) {
	if(a[N]^b[N]) { if(a[N]) { a[N]=0; Minus(b, a, c); a[N]=1; } else { b[N]=0; Minus(a, b, c); b[N]=1; } return; }
	upd(c);
	int k=0, len=max(a[0], b[0]), i;
	for(i=1; i<=len || k; ++i) {
		c[i]=a[i]+b[i]+k;
		k=c[i]/10; if(c[i]>=10) c[i]%=10;
	}
	fix1(c, i); c[N]=a[N];
}
void Multi(int *a, int *b, int *c) {
	upd(c);
	for1(i, 1, a[0]) for1(j, 1, b[0]) c[i+j-1]+=a[i]*b[j];
	int k=0, i, len=a[0]+b[0]-1;
	for(i=1; i<=len || k; ++i) {
		c[i]+=k;
		k=c[i]/10; if(c[i]>=10) c[i]%=10;
	}
	fix1(c, i); fix2(a, b, c);
}
void Div(int *a, int *b, int *c) {
	upd(c); upd(tp1); upd(tp2); upd(tp3);
	int i, *t=tp1, *ans=tp2, *k=tp3, flag=b[N]; b[N]=0;
	for(i=a[0]; i>=1; --i) {
		Multi(k, Ten, t); swap(k, t);
		k[1]=a[i];
		Multi(ans, Ten, t); swap(ans, t);
		while(!cmp(k, b)) {
			Plus(ans, One, t); swap(ans, t);
			Minus(k, b, t); swap(k, t);
		}
	}
	memcpy(c, ans, sizeof(int)*(ans[0]+1));
	b[N]=flag;
	fix1(c, a[0]); fix2(a, b, c);
}
void Print(int *a) {
	if(a[N]) printf("-");
	for3(i, a[0], 1) print(a[i]);
	puts("");
}
void stoi(char *x, int *a) {
	int len=strlen(s), i=0;
	if(x[0]=='-') a[N]=1, ++i; a[0]=len-i;
	for(; i<len; ++i) a[len-i]=s[i]-'0';
}
void sqrt(int *a, int *c) {
	upd(c);
	int *l=f[3], *r=f[4], *m=f[5], *t=f[6];
	l[0]=1; r[a[0]+1]=1; r[0]=a[0]+1;
	while(cmp(l, r)) {
		upd(t); upd(m); 
		Plus(l, r, t); 
		Div(t, Two, m);
		Multi(m, m, t);
		if(!cmp(a, t)) { swap(l, m); Plus(l, One, t); swap(l, t); }
		else swap(r, m);
	}
	Minus(l, One, t); swap(l, t);
	memcpy(c, l, sizeof(int)*(N+5));
}
int main() {
	Init();
	scanf("%s", s); stoi(s, f[1]);
	sqrt(f[1], f[2]);
	Print(f[2]);
	return 0;
}