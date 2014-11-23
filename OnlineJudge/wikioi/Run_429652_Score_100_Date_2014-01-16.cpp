#include <iostream>

using namespace std;

#define WHI(i,a,n) for(i=(a);i<(n);++i)
#define REP(i,a,n) for(int i=(a);i<(n);++i)

const int MAXi = 1e5+10, oo = ~0u<<1;

typedef unsigned long long ull;

ull cnt = 0;
int A[MAXi], L[MAXi], R[MAXi], s;

void mi_cnt(int* arr, int f, int l){
	if(f < l-1){
		int m = (f+l) >> 1, i = 0, j = 0;
		mi_cnt(arr, f, m);
		mi_cnt(arr, m, l);
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
	cin >> s;
	REP(i, 0, s) cin >> A[i];
	mi_cnt(A, 0, s);
	cout << cnt << endl;
	return 0;
}