#include<cstdio>
#include<set>
using namespace std;
inline int getnum() { int ret=0; char c; for(c=getchar(); c<'0' || c>'9'; c=getchar()); for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return ret; }
const int inf=~0u>>2;
typedef set<int>::iterator sit;
set<int> S;
int main() {
	int n, a, b, ans=0, type, l, r;
   	n=getnum();
   	S.insert(inf); S.insert(-inf);
   	sit i;
	while(n--) {
		a=getnum(); b=getnum();
		if(S.size()==2) type=a, S.insert(b);
		else if(type==a) S.insert(b);
		else {
			i=S.lower_bound(b);
			r=*i-b, l=b-*(--i);
			if(l<=r) ans+=l, S.erase(i);
			else ans+=r, S.erase(++i);
			ans%=1000000;
		}
	}
	printf("%d\n",ans);
}
