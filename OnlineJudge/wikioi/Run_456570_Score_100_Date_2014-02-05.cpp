#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100005, MOD = 99999997, inf = ~0u<<1;
int a[maxn], b[maxn], c[maxn], n, L[maxn], R[maxn], ans;

int find(int l, int r, int key) {
	int m = (l+r) >> 1;
	if(key == b[m]) return m;
	return key < b[m] ? find(l, m, key) : find(m+1, r, key);
}

void merge_sort(int* arr, int l, int r) {
	if(l < r-1) {
		int m = (l+r) >> 1;
		merge_sort(arr, l, m);
		merge_sort(arr, m, r);
		int i, j;
		for(i = 0; i < m-l; ++i) L[i] = arr[l+i];
		for(j = 0; j < r-m; ++j) R[j] = arr[m+j];
		L[i] = R[j] = inf; i = j = 0;
		while(l < r) {
			if(L[i] > R[j]) {
				ans = (ans+r-m-j)%MOD;
				arr[l++] = L[i++];
			}
			else arr[l++] = R[j++];
		}
	}
}

int main() {
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) scanf("%d", &b[i]);
	memcpy(c, b, sizeof(b));
	sort(b, b+n);
	for(i = 0; i < n; ++i) a[find(0, n-1, c[i])] = i;
	for(i = 0; i < n; ++i) scanf("%d", &b[i]);
	memcpy(c, b, sizeof(b));
	sort(b, b+n);
	for(i = 0; i < n; ++i) c[i] = a[find(0, n-1, c[i])];
	merge_sort(c, 0, n);
	printf("%d", ans);
	return 0;
}