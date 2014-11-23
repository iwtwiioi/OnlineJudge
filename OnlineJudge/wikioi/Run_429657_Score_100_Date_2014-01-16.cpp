#include <cstdio>

using namespace std;

#define WHI(i,a,n) for(i=(a);i<(n);++i)
#define REP(i,a,n) for(int i=(a);i<(n);++i)

const int MAXi = 1e5+10, oo = ~0u<<1;

typedef long long lli;

lli cnt = 0;
int arr[MAXi], L[MAXi], R[MAXi], s;

void mi_cnt(int f, int l){
	if(f < l-1){
		int m = (f+l) >> 1, i = 0, j = 0;
		mi_cnt(f, m);
		mi_cnt(m, l);
		WHI(i, 0, m-f) L[i] = arr[f+i];
		WHI(j, 0, l-m) R[j] = arr[m+j];
		L[i] = R[j] = oo; i = j = 0;
		while(f < l)
			if(L[i] > R[j]){
				arr[f++] = L[i++];
				cnt += l-m-j;
			}
			else
				arr[f++] = R[j++];
	}
}

int main(){
	scanf("%d", &s);
	REP(i, 0, s) scanf("%d", &arr[i]);
	mi_cnt(0, s);
	printf("%lld", cnt);
	return 0;
}