#include <cstdio>
using namespace std;
#define lowbit(x) (x&-x)
#define max(a,b) ((a)>(b)?(a):(b))
const int N=200005;
int num[N], c[N], cnt;
int getk(int l, int r) {
	int ret=num[r];
	while(l<=r) {
		ret=max(ret, num[r]);
		for(--r; r-l>=lowbit(r); r-=lowbit(r))
			ret=max(ret, c[r]);
	}
	return ret;
}

int main() {
	int n, d, t=0, a;
	char ch[3];
	scanf("%d%d", &n, &d);
	while(n--) {
		scanf("%s%d", ch, &a);
		if(ch[0]=='A') {
			num[++cnt]=(t+a)%d;
			c[cnt]=max(getk(cnt-lowbit(cnt)+1, cnt-1), num[cnt]);
		}
		else {
			printf("%d\n", t=getk(cnt-a+1, cnt));
		}
	}
	return 0;
}

