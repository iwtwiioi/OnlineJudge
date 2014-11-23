#include <cstdio>
using namespace std;

#define MID (l+r) >> 1

const int maxn = 1000000+10;
int sum[maxn], cl[maxn], d[maxn], s[maxn], t[maxn], n, m, last, last_q;

int check(int r) {
	int ret = 0;
	for(int i = 1; i <= n; ++i) {
		ret += sum[i];
		if(ret > cl[i]) return 0;
	}
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	int l = 0, r = m+1, mid, i;
	for(i = 1; i <= n; ++i) scanf("%d", &cl[i]);
	while(l < r-1) {
		mid = MID;
		if(last_q < mid){
			for(i = last+1; i <= mid; ++i) scanf("%d%d%d", &d[i], &s[i], &t[i]);
			last_q = mid;
		}
		for(i = mid+1; i <= last; ++i) sum[s[i]] -= d[i], sum[t[i]+1] += d[i]; //将原来加上去的和减的恢复
		for(i = last+1; i <= mid; ++i) sum[s[i]] += d[i], sum[t[i]+1] -= d[i]; //加上去的和减去新添加的元素
		last = mid;
		if(check(mid)) l = mid;
		else r = mid;
	}
	if(l == m) printf("0");
	else printf("-1\n%d", l+1);
	return 0;
}