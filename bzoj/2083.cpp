#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define read(a) a=getint()
#define print(a) printf("%d", a)
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define error(x) (!(x)?puts("error"):0)
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
vector<int> x[1000005];
int main() {
	int n=getint();
	for1(i, 1, n) x[getint()].push_back(i);
	int m=getint();
	while(m--) {
		n=getint();
		int pos=0, flag=0;
		for1(i, 1, n) {
			int a=getint();
			if(flag) continue;
			vector<int>::iterator it=upper_bound(x[a].begin(), x[a].end(), pos);
			if(it==x[a].end()) flag=1;
			else pos=*it;
		}
		flag?puts("NIE"):puts("TAK");
	}
	return 0;
}